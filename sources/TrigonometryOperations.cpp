//
// Created by Timi on 11. 07. 2017.
//

#include <math.h>
#include "../headers/TrigonometryOperations.h"

#define RAD_TO_ANGLE 3.14159265 / 180

float sin(float angle) {
    return sinf((float) (angle * RAD_TO_ANGLE));
}

float cos(float angle) {
    return cosf((float) (angle * RAD_TO_ANGLE));
}
