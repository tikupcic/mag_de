//
// Created by timi on 30.7.2017.
//

#ifndef MAG_DE_OPTIMIZEDDE_H
#define MAG_DE_OPTIMIZEDDE_H

#include <random>

class OptimizedDE {

private:
    const int POPULATION_SIZE;        //NP
    const int DIMENSION;              //D
    const int MAX_GEN_NUMBER;         //Gmax
    const float CROSSOVER_RATE;       //C
    const float MUTATION_FACTOR;      //F

    const float LENGTH_ARM_1 = 671.83;
    const float LENGTH_ARM_2 = 431.8;
    const float LENGTH_ARM_3 = 433.07;
    const float ROTATION_WAIST = 320;
    const float ROTATION_SHOULDER= 250;
    const float ROTATION_ELBOW = 270;

    const int localMinThreshold = 15;
    int localMinCounter;

    float *min_bounds;
    float *max_bounds;

    std::default_random_engine random_engine;
    std::uniform_real_distribution<double> RANDOM_0_1;
    std::uniform_real_distribution<double> RANDOM_0_N;
    std::uniform_int_distribution<int> RANDOM_0_NP;

    float **population;
    float **donor_vectors;
    float **trial_vectors;
    float *wantedEndpoint;

    int currentGeneration;

public:
    OptimizedDE(const int POPULATION_SIZE, const int DIMENSION, const int MAX_GEN_NUMBER, const float CROSSOVER_RATE,
                const float MUTATION_FACTOR);

    virtual ~OptimizedDE();

    float setInitialIndividualValue(const int index);
    float fitnessFunction(const float *vector);
    void initialize();
    void begin(float *wantedEndpoint);
};

#endif //MAG_DE_OPTIMIZEDDE_H
