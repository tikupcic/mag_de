//
// Created by Timi on 6. 07. 2017.
//

#include <iostream>
#include "../headers/OptimizedDE.h"
#include "../headers/Robot3DOF.h"

/*****************************************************/
/*                                                   */
/*                     y  |         -z /             */
/*                        |          /               */
/*                        |        /                 */
/*                        |      /                   */
/*                        |    /                     */
/*                        |  /                       */
/*   _ _ _ _ _ _ _ _ _ _ _|/_ _ _ _._ _ _ _ _ _ _ x  */
/*   -x                  /|        A                 */
/*                     /  |                          */
/*                   /    |                          */
/*                 /      |                          */
/*               /        |               x  y  z    */
/*             /          |             A(5, 0, 0)   */
/*         z /            | -y                       */
/*                                      angles = CCW */
/*****************************************************/

int main() {
    const int NUMBER_OF_RUNS = 10;
    float sum_error = 0;
    float sum_error_TOA = 0;
    float sum_time = 0;

    Robot3DOF robot(671.83, 431.8, 433.07, 320, 250, 270, .01f, .01f, .01f);
    float point[] = {350, 350, 350};
    std::vector<float> endPoint(point, point + sizeof(point) / sizeof(float));

    OptimizedDE DE(robot, 1000, 100, 5, 30, .5, .9, false);

    for (int i = 0; i < NUMBER_OF_RUNS; i++) {
        clock_t begin = clock();
        DE.begin(endPoint);
        clock_t end = clock();

        sum_error += DE.getError();
        sum_error_TOA += DE.getErrorTOA();

        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::cout << "Run num #" << i << ":" << std::endl;
        std::cout << "> w/o TOA: " << DE.getError() << " mm" << std::endl;
        std::cout << "> w/ TOA: " << DE.getErrorTOA() << " mm" << std::endl;
        std::cout << "> Elapsed: " << elapsed_secs << "sec" << std::endl;
        printf("> params: [%f, %f, %f]\n", DE.getBestIndividual()[0], DE.getBestIndividual()[1], DE.getBestIndividual()[2]);
        sum_time += elapsed_secs;
    }

    std::cout << std::endl << "### SUMMARY:" << std::endl;
    std::cout << "\t+ Error average:\t\t\t" << sum_error / NUMBER_OF_RUNS << " mm" << std::endl;
    std::cout << "\t+ Error average w/ TOA:\t\t" << sum_error_TOA / NUMBER_OF_RUNS << " mm" << std::endl;
    std::cout << "\t+ Time average:\t\t\t\t" << sum_time / NUMBER_OF_RUNS << " sec" << std::endl;

    return 0;
}