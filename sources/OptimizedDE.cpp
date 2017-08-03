//
// Created by timi on 30.7.2017.
//

#include <chrono>
#include <iostream>

#include "../headers/OptimizedDE.h"
#include "../headers/VectorOperations.h"
#include "../headers/TrigonometryOperations.h"

// CONSTRUCTOR
OptimizedDE::OptimizedDE(const Robot3DOF robot, const int POPULATION_SIZE, const int TERM_MAX_GEN_NUMBER,
                         const float TERM_ERROR_THRESH, const int TERM_REPEAT_THRESH,
                         const float CROSSOVER_RATE, const float MUTATION_FACTOR, const bool USE_TOA) :
        ROBOT(robot),
        POPULATION_SIZE(POPULATION_SIZE),
        DIMENSION(ROBOT.getDimension()),
        TERM_MAX_GEN_NUMBER(TERM_MAX_GEN_NUMBER),
        TERM_ERROR_THRESH(TERM_ERROR_THRESH),
        TERM_REPEAT_THRESH(TERM_REPEAT_THRESH),
        CROSSOVER_RATE(CROSSOVER_RATE),
        MUTATION_FACTOR(MUTATION_FACTOR),
        USE_TOA(USE_TOA) {

    for (auto &arm: ROBOT.getArms()) {
        min_bounds.push_back(arm.getMinRotation());
        max_bounds.push_back(arm.getMaxRotation());
        errors.push_back(arm.getError());
    }

    random_engine.seed((unsigned long) std::chrono::system_clock::now().time_since_epoch().count());
    RANDOM_0_1.param(std::uniform_real_distribution<>::param_type{0.0, 1.0});
    RANDOM_0_NP.param(std::uniform_int_distribution<>::param_type{0, POPULATION_SIZE - 1});
}

// METHODS
void OptimizedDE::initialize() {
    population.clear();
    for (int i = 0; i < POPULATION_SIZE; i++) {
        std::vector<float> temp;
        for (int j = 0; j < DIMENSION; j++) {
            temp.push_back(setInitialIndividualValue(j));
        }
        population.push_back(temp);
    }

    currentGeneration = 0;
    localMinCounter = 0;

    error = 0;
    errorTOA = 0;

    bestIndividualFitness = std::numeric_limits<float>::max();
}

void OptimizedDE::begin(std::vector<float> wantedEndpoint) {
    this->wantedEndpoint = wantedEndpoint;
    initialize();

    do {
        donor_vectors.clear();
        trial_vectors.clear();

        // mutation
        int r1, r2, r3;
        for (int i = 0; i < POPULATION_SIZE; i++) {
            do r1 = RANDOM_0_NP(random_engine); while (r1 == i);
            do r2 = RANDOM_0_NP(random_engine); while (r2 == i || r2 == r1);
            do r3 = RANDOM_0_NP(random_engine); while (r3 == i || r3 == r2 || r3 == r1);

            donor_vectors.push_back(
                    mutationVectorOperation(population[r1],
                                            population[r2],
                                            population[r3],
                                            MUTATION_FACTOR,
                                            DIMENSION));
        }

        // crossover
        for (int i = 0; i < POPULATION_SIZE; i++) {
            std::vector<float> temp;
            for (int j = 0; j < DIMENSION; j++) {
                if ((float) RANDOM_0_1(random_engine) <= CROSSOVER_RATE) {
                    if (donor_vectors[i][j] < min_bounds[j]) {
                        float result = min_bounds[j] - donor_vectors[i][j];
                        RANDOM_0_N.param(std::uniform_real_distribution<>::param_type{0.0, result});
                        temp.push_back(min_bounds[j] + (float) RANDOM_0_N(random_engine));
                    } else if (donor_vectors[i][j] > max_bounds[j]) {
                        float result = donor_vectors[i][j] - max_bounds[j];
                        RANDOM_0_N.param(std::uniform_real_distribution<>::param_type{0.0, result});
                        temp.push_back(max_bounds[j] - (float) RANDOM_0_N(random_engine));
                    } else {
                        temp.push_back(donor_vectors[i][j]);
                    }
                } else {
                    temp.push_back(population[i][j]);
                }
            }
            trial_vectors.push_back(temp);
        }

        //selection
        bool foundBetter = false;
        for (int i = 0; i < POPULATION_SIZE; i++) {
            float trial = USE_TOA ? fitnessByTaguchiOA(trial_vectors[i]) : fitnessFunction(trial_vectors[i]);
            float parent = USE_TOA ? fitnessByTaguchiOA(population[i]) : fitnessFunction(population[i]);
            if (trial <= parent) {
                std::swap(population[i], trial_vectors[i]);
                if (trial < bestIndividualFitness) {
                    bestIndividualFitness = trial;
                    bestIndividual = population[i];
                    foundBetter = true;
                }
            }
        }

        if (foundBetter) {
            localMinCounter = 0;
        } else {
            if (++localMinCounter == TERM_REPEAT_THRESH) {
                break;
            }
        }
//        printf("\t\t> CURRENT (gen %d): %.2f mm\n", currentGeneration, bestIndividualFitness);
    } while (++currentGeneration < TERM_MAX_GEN_NUMBER && bestIndividualFitness > TERM_ERROR_THRESH);

    if (USE_TOA) {
        error = fitnessFunction(bestIndividual);
        errorTOA = bestIndividualFitness;
    } else {
        error = bestIndividualFitness;
        errorTOA = fitnessByTaguchiOA(bestIndividual);
    }
}

float OptimizedDE::setInitialIndividualValue(const int index) {
    return min_bounds[index] +
           (float) RANDOM_0_1(random_engine) *
           (max_bounds[index] - min_bounds[index]);
}

float OptimizedDE::fitnessByTaguchiOA(std::vector<float> vector) {
    std::vector<float> temp;
    float error_sum = 0;
    float error;

    for (int test = 0; test < 4; test++) {
        temp.clear();
        for (int i = 0; i < DIMENSION; i++) {
            temp.push_back(vector[i] + (TAGUCHI_OA[test][i] * errors[i] * vector[i]));
        }
        error = fitnessFunction(temp);
        error_sum += error;
    }
    return error_sum / 4;
};

float OptimizedDE::fitnessFunction(std::vector<float> vector) {
    float a = vector[0];
    float x = ROBOT.getArm(0).getMaxLength();
    float b = vector[1];
    float y = ROBOT.getArm(1).getMaxLength();
    float c = vector[2];
    float z = ROBOT.getArm(2).getMaxLength();

    float calculatedEndpoint[3]{
            -cos(a) * (z * sin(b + c) + y * sin(b)),
            z * cos(b + c) + y * cos(b) + x,
            sin(a) * (z * sin(b + c) + y * sin(b))
    };

    float sum = 0;
    for (int i = 0; i < DIMENSION; i++) {
        sum += pow(calculatedEndpoint[i] - wantedEndpoint[i], 2);
    }

    return std::sqrt(sum);
}

const std::vector<float> &OptimizedDE::getBestIndividual() const {
    return bestIndividual;
}

float OptimizedDE::getError() const {
    return error;
}

float OptimizedDE::getErrorTOA() const {
    return errorTOA;
}
