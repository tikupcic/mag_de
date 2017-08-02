//
// Created by timi on 30.7.2017.
//

#include <chrono>
#include <iostream>

#include "../headers/OptimizedDE.h"
#include "../headers/VectorOperations.h"
#include "../headers/TrigonometryOperations.h"

// CONSTRUCTOR
OptimizedDE::OptimizedDE(const int POPULATION_SIZE, const int DIMENSION, const int MAX_GEN_NUMBER,
                         const float CROSSOVER_RATE, const float MUTATION_FACTOR) : POPULATION_SIZE(POPULATION_SIZE),
                                                                                    DIMENSION(DIMENSION),
                                                                                    MAX_GEN_NUMBER(MAX_GEN_NUMBER),
                                                                                    CROSSOVER_RATE(CROSSOVER_RATE),
                                                                                    MUTATION_FACTOR(MUTATION_FACTOR) {

    min_bounds = new float[DIMENSION]{ROTATION_WAIST / -2, ROTATION_SHOULDER / -2, ROTATION_ELBOW / -2};
    max_bounds = new float[DIMENSION]{ROTATION_ELBOW / 2, ROTATION_SHOULDER / 2, ROTATION_ELBOW / 2};

    random_engine.seed((unsigned long) std::chrono::system_clock::now().time_since_epoch().count());
    RANDOM_0_1.param(std::uniform_real_distribution<>::param_type{0.0, 1.0});
    RANDOM_0_NP.param(std::uniform_int_distribution<>::param_type{0, POPULATION_SIZE - 1});

    bestIndividualFitness = std::numeric_limits<float>::max();
}

// DESTRUCTOR
OptimizedDE::~OptimizedDE() {
    delete[] min_bounds;
    delete[] max_bounds;
    delete[] ERRORS;

    for (int i = 0; i < POPULATION_SIZE; i++) {
        delete[] population[i];
        delete[] donor_vectors[i];
        delete[] trial_vectors[i];
    }

    delete[] population;
    delete[] donor_vectors;
    delete[] trial_vectors;
    delete bestIndividual;
    delete wantedEndpoint;
}

// METHODS
void OptimizedDE::initialize() {
    population = new float *[POPULATION_SIZE];
    donor_vectors = new float *[POPULATION_SIZE];
    trial_vectors = new float *[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = new float[DIMENSION];
        donor_vectors[i] = new float[DIMENSION];
        trial_vectors[i] = new float[DIMENSION];

        for (int j = 0; j < DIMENSION; j++) {
            population[i][j] = setInitialIndividualValue(j);
        }
    }

    currentGeneration = 0;
    localMinCounter = 0;
    bestIndividualFitness = std::numeric_limits<float>::max();
    bestIndividual = new float[3];
}



float OptimizedDE::begin(float *wantedEndpoint) {
    this->wantedEndpoint = wantedEndpoint;
    initialize();

    do {
        // mutation
        int r1, r2, r3;
        for (int i = 0; i < POPULATION_SIZE; i++) {
            do r1 = RANDOM_0_NP(random_engine); while (r1 == i);
            do r2 = RANDOM_0_NP(random_engine); while (r2 == i || r2 == r1);
            do r3 = RANDOM_0_NP(random_engine); while (r3 == i || r3 == r2 || r3 == r1);

            donor_vectors[i] = mutationVectorOperation(population[r1],
                                                       population[r2],
                                                       population[r3],
                                                       MUTATION_FACTOR,
                                                       DIMENSION);
        }

        // crossover
        for (int i = 0; i < POPULATION_SIZE; i++) {
            trial_vectors[i] = new float[DIMENSION];
            for (int j = 0; j < DIMENSION; j++) {
                if ((float) RANDOM_0_1(random_engine) <= CROSSOVER_RATE) {
                    if (donor_vectors[i][j] < min_bounds[j]) {
                        float temp = min_bounds[j] - donor_vectors[i][j];
                        RANDOM_0_N.param(std::uniform_real_distribution<>::param_type{0.0, temp});
                        trial_vectors[i][j] = min_bounds[j] + (float) RANDOM_0_N(random_engine);
                    } else if (donor_vectors[i][j] > max_bounds[j]) {
                        float temp = donor_vectors[i][j] - max_bounds[j];
                        RANDOM_0_N.param(std::uniform_real_distribution<>::param_type{0.0, temp});
                        trial_vectors[i][j] = max_bounds[j] - (float) RANDOM_0_N(random_engine);
                    } else {
                        trial_vectors[i][j] = donor_vectors[i][j];
                    }
                } else {
                    trial_vectors[i][j] = population[i][j];
                }
            }
        }

        //selection
        bool foundBetter = false;
        for (int i = 0; i < POPULATION_SIZE; i++) {
            float trial = fitnessFunction(trial_vectors[i]);
            float parent = fitnessFunction(population[i]);
            if (trial <= parent) {
                population[i] = trial_vectors[i];
                if (trial < bestIndividualFitness) {
                    bestIndividualFitness = trial;
                    bestIndividual = trial_vectors[i];
                    foundBetter = true;
                }
            }
        }

        if(foundBetter) {
            localMinCounter = 0;
        } else {
            if(++localMinCounter == localMinThreshold) {
                break;
            }
        }
//        printf("\t> CURRENT (gen %d): %.2f mm\n", currentGeneration, bestIndividualFitness);
    } while (++currentGeneration < MAX_GEN_NUMBER && bestIndividualFitness > errorThreshold);

    printf("> BEST: %.2f mm : [%f, %f, %f]\n", bestIndividualFitness, bestIndividual[0], bestIndividual[1], bestIndividual[2]);
    return bestIndividualFitness;
}

float OptimizedDE::fitnessByTaguchiOA(const float *vector) {
    float *temp = new float[DIMENSION];
    float error_sum = 0;
    float error;

    for(int test = 0; test < 4; test++) {
        for (int i = 0; i < DIMENSION; i++) {
            temp[i] = vector[i] + (TAGUCHI_OA[test][i] * ERRORS[i] * vector[i]);
        }
        error = fitnessFunction(temp);
        error_sum += error;
    }
    delete[] temp;
    return error_sum / 4;
};

float OptimizedDE::setInitialIndividualValue(const int index) {
    return min_bounds[index] +
           (float) RANDOM_0_1(random_engine) *
           (max_bounds[index] - min_bounds[index]);
}

float OptimizedDE::fitnessFunction(const float *vector) {
    float a = vector[0];
    float x = LENGTH_ARM_1;
    float b = vector[1];
    float y = LENGTH_ARM_2;
    float c = vector[2];
    float z = LENGTH_ARM_3;

    float *calculatedEndpoint = new float[3]{
            -cos(a) * (z * sin(b + c) + y * sin(b)),
            z * cos(b + c) + y * cos(b) + x,
            sin(a) * (z * sin(b + c) + y * sin(b))
    };

    float sum = 0;
    for (int i = 0; i < DIMENSION; i++) {
        sum += pow(calculatedEndpoint[i] - wantedEndpoint[i], 2);
    }
    delete[] calculatedEndpoint;
    return std::sqrt(sum);
}