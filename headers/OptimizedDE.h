//
// Created by timi on 30.7.2017.
//

#ifndef MAG_DE_OPTIMIZEDDE_H
#define MAG_DE_OPTIMIZEDDE_H

#include <random>
#include "Robot3DOF.h"

class OptimizedDE {

private:
    const Robot3DOF ROBOT;

    const int POPULATION_SIZE;        // NP
    const int DIMENSION;              // D
    const float CROSSOVER_RATE;       // C
    const float MUTATION_FACTOR;      // F

    const int TERM_MAX_GEN_NUMBER;    // terminate if max number of gen. is reached
    const float TERM_ERROR_THRESH;    // terminate if result is better or equal
    const int TERM_REPEAT_THRESH;     // terminate if stuck at local max for N generations

    const bool USE_TOA;             // if true, then Taguchi's process is used instead of regular fitness

    std::vector<float> min_bounds;
    std::vector<float> max_bounds;

    std::default_random_engine random_engine;
    std::uniform_real_distribution<double> RANDOM_0_1;
    std::uniform_real_distribution<double> RANDOM_0_N;
    std::uniform_int_distribution<int> RANDOM_0_NP;

    std::vector<std::vector<float>> population;
    std::vector<std::vector<float>> donor_vectors;
    std::vector<std::vector<float>> trial_vectors;
    std::vector<float> wantedEndpoint;

    int currentGeneration;
    int localMinCounter;

    float bestIndividualFitness;
    std::vector<float> bestIndividual;

    // TAGUCHI's OA dependent array
    std::vector<float> errors;
    const float TAGUCHI_OA[4][3] =
            {
                    { 1,  1,  1},
                    { 1, -1, -1},
                    {-1,  1, -1},
                    {-1, -1,  1}
            };

    // errors used to analyze solution
    float error;
    float errorTOA;

public:
    OptimizedDE(const Robot3DOF robot, const int POPULATION_SIZE, const int TERM_MAX_GEN_NUMBER,
                const float TERM_ERROR_THRESH, const int TERM_REPEAT_THRESH, const float CROSSOVER_RATE,
                const float MUTATION_FACTOR, const bool USE_TOA);

    float setInitialIndividualValue(const int index);

    float fitnessFunction(std::vector<float> vector);

    float fitnessByTaguchiOA(std::vector<float> vector);

    void initialize();

    void begin(std::vector<float> wantedEndpoint);

    const std::vector<float> &getBestIndividual() const;

    float getError() const;

    float getErrorTOA() const;
};

#endif //MAG_DE_OPTIMIZEDDE_H
