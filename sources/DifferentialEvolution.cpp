//
// Created by Timi on 4. 07. 2017.
//

#include <iostream>
#include <chrono>

#include "../headers/DifferentialEvolution.h"
#include "../headers/VectorOperations.h"
#include "../headers/TrigonometryOperations.h"

DifferentialEvolution::DifferentialEvolution(int NP, int D, int Gmax, float C, float F)
        : POPULATION_SIZE(NP), DIMENSION(D), MAX_GEN_NUMBER(Gmax), CROSSOVER_RATE(C), MUTATION_FACTOR(F) {

    min_bounds = new float[DIMENSION]{0, 2, 0, 5,0,5};
    max_bounds = new float[DIMENSION]{-360, 5, -90, 5, -90, 5};

    random_engine.seed((unsigned long) std::chrono::system_clock::now().time_since_epoch().count());
    RANDOM_0_1.param(std::uniform_real_distribution<>::param_type{0.0, 1.0});
    RANDOM_0_NP.param(std::uniform_int_distribution<>::param_type{0, NP - 1});
}

DifferentialEvolution::~DifferentialEvolution() {
    delete[] min_bounds;
    delete[] max_bounds;
    delete[] END;

    for (int i = 0; i < POPULATION_SIZE; i++) {
        delete[] donor_vectors[i];
        delete[] trial_vectors[i];
    }
    delete[] donor_vectors;
    delete[] trial_vectors;
}

// INITIALIZE POPULATION
void DifferentialEvolution::initialize() {
    std::cout << "> DE started!" << std::endl;

    float **population = new float *[POPULATION_SIZE];
    current_generation = 0;

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = new float[DIMENSION];
        for (int j = 0; j < DIMENSION; j++) {
            population[i][j] = setInitialIndividualValue(j);
        }
    }

    mutate(population);
}

// MUTATION
void DifferentialEvolution::mutate(float **population) {
    int r1, r2, r3;
    donor_vectors = new float *[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        do r1 = RANDOM_0_NP(random_engine); while (r1 == i);
        do r2 = RANDOM_0_NP(random_engine); while (r2 == i || r2 == r1);
        do r3 = RANDOM_0_NP(random_engine); while (r3 == i || r3 == r2 || r3 == r1);

        donor_vectors[i] = subtractTwoVectors(population[r2], population[r3], DIMENSION);
        donor_vectors[i] = multiplyVectorByScalar(MUTATION_FACTOR, donor_vectors[i], DIMENSION);
        donor_vectors[i] = addTwoVectors(donor_vectors[i], population[r1], DIMENSION);
    }

    crossover(population, donor_vectors);
}

// CROSSOVER
void DifferentialEvolution::crossover(float **population, float **donor_vectors) {
    trial_vectors = new float *[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        trial_vectors[i] = new float[DIMENSION];
        for (int j = 0; j < DIMENSION; j++) {
            if ((float) RANDOM_0_1(random_engine) <= CROSSOVER_RATE) {
                if (donor_vectors[i][j] <= max_bounds[j] && donor_vectors[i][j] >= min_bounds[j]) {
                    trial_vectors[i][j] = donor_vectors[i][j];
                } else {
                    trial_vectors[i][j] = population[i][j];
                }
            } else {
                trial_vectors[i][j] = population[i][j];
            }
        }
    }

    selection(population, trial_vectors);
}

// SELECTION
float bestIndividualFitness = std::numeric_limits<float>::max();
float *bestIndividual;

void DifferentialEvolution::selection(float **population, float **trial_vectors) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        float trial = fitnessFunction(trial_vectors[i]);
        float parent = fitnessFunction(population[i]);
        if (trial <= parent) {
            population[i] = trial_vectors[i];
            if (trial < bestIndividualFitness) {
                bestIndividualFitness = trial;
                bestIndividual = population[i];
            }
        }
    }

    terminate(population);
}

// TERMINATE
void DifferentialEvolution::terminate(float **population) {
    if (++current_generation < MAX_GEN_NUMBER /*&& bestFitness != bestIndividualFitness*/) {
        std::cout << "\t>" << current_generation << " generation: ";
        printf("%.5f", bestIndividualFitness);
        std::cout << std::endl;
        mutate(population);
    } else {
        std::cout << "> DE completed!" << std::endl;
        std::cout << "> Best: ";
        printf("%.5f", bestIndividualFitness);
        std::cout << std::endl << "{";
        for (int i = 0; i < DIMENSION; i++) {
            std::cout << bestIndividual[i] << "f";
            if (i < DIMENSION - 1) std::cout << ",";
        }
        std::cout << "};" << std::endl;
        std::cout << std::endl;
    }
}

float DifferentialEvolution::setInitialIndividualValue(const int dimension_index) {
    return min_bounds[dimension_index] +
           (float) RANDOM_0_1(random_engine) *
           (max_bounds[dimension_index] - min_bounds[dimension_index]);
}

float DifferentialEvolution::fitnessFunction(float *vector) {
    float a = vector[0];
    float x = vector[1];
    float b = vector[2];
    float y = vector[3];
    float c = vector[4];
    float z = vector[5];

    float *HAND_POSITION = new float[3]{
            (cos(a) * cos(b) * (-1) * sin(c) - cos(a) * sin(b) * cos(c)) * z - y * cos(a) * sin(b),
            ((-1) * sin(c) * sin(b) + cos(b) * cos(c)) * z + x + y * cos(b),
            ((-1) * cos(b) * sin(a) * (-1) * sin(c) + sin(a) * sin(b) * cos(c)) * z + y * sin(a) * sin(b)
    };

    float sum = 0;
    for (int i = 0; i < DIMENSION; i++) {
        sum += pow(HAND_POSITION[i] - END[i], 2);
    }
    delete[] HAND_POSITION;
    return (float) sqrt(sum);
}

void DifferentialEvolution::start(float *END) {
    this->END = END;
    initialize();
}
