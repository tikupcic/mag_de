//
// Created by Timi on 6. 07. 2017.
//

#include <iostream>
#include "../headers/OptimizedDE.h"

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
    const int NUMBER_OF_RUNS = 3;
    float sum_error = 0;
    float sum_time = 0;

    auto DE = new OptimizedDE(1000, 3, 500, .5, .9);

    for(int i=0; i< NUMBER_OF_RUNS ; i++) {
        clock_t begin = clock();
        sum_error += DE->begin(new float[3]{350, 350, 350});
        clock_t end = clock();

        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::cout << "> Elapsed: " << elapsed_secs << "sec" << std::endl;
        sum_time += elapsed_secs;
    }

    std::cout << std::endl;
    std::cout << "Error average: " << sum_error / NUMBER_OF_RUNS << " mm" << std::endl;
    std::cout << "Time average: " << sum_time / NUMBER_OF_RUNS << " sec" << std::endl;

    delete DE;
    return 0;
}