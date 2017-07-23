//
// Created by Timi on 6. 07. 2017.
//

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

    DifferentialEvolution *DE = new DifferentialEvolution(1000, 6, 100, .5, .9);
    DE->start(new float[3]{3,7,5});

    delete DE;
    return 0;
}