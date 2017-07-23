//
// Created by Timi on 6. 07. 2017.
//

#pragma once
#include <random>

class DifferentialEvolution {

private:
    const int POPULATION_SIZE;        //NP
    const int DIMENSION;              //D
    const int MAX_GEN_NUMBER;         //Gmax
    const float CROSSOVER_RATE;       //C
    const float MUTATION_FACTOR;      //F

    float *min_bounds;
    float *max_bounds;

    int current_generation;

    float **donor_vectors;
    float **trial_vectors;
    float *END;

    std::default_random_engine random_engine;
    std::uniform_real_distribution<double> RANDOM_0_1;
    std::uniform_real_distribution<double> RANDOM_0_N;
    std::uniform_int_distribution<int> RANDOM_0_NP;

    float setInitialIndividualValue(const int dimension_index);

    float fitnessFunction(float *x);

    void initialize();

    void mutate(float **population);

    void crossover(float **population, float **donor_vectors);

    void selection(float **population, float **trial_vectors);

    void terminate(float **population);

public:
    DifferentialEvolution(int NP, int D, int Gmax, float C, float F);

    virtual ~DifferentialEvolution();

    void start(float *END);
};