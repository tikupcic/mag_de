//
// Created by Timi on 6. 07. 2017.
//

#include <iostream>
#include "../headers/DifferentialEvolution.h"

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

    DifferentialEvolution *DE = new DifferentialEvolution(1000, 6, 500, .5, .9);

    clock_t begin = clock();
    DE->start(new float[3]{350,350,350});
    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout<<"Elapsed: " << elapsed_secs  << "s"<< std::endl;

    delete DE;
    return 0;
}