//
// Created by timi on 2.8.2017.
//

#include "../headers/Arm.h"

Arm::Arm() {}

Arm::Arm(const float length, const float rotation) :
        maxLength(length),
        minLength(length),
        maxRotation(rotation / 2),
        minRotation(rotation / -2) {}

Arm::Arm(const float length, const float rotation, const float error) :
        maxLength(length),
        minLength(length),
        maxRotation(rotation / 2),
        minRotation(rotation / -2),
        error(error) {}

const float Arm::getMaxLength() const {
    return maxLength;
}

const float Arm::getMinLength() const {
    return minLength;
}

const float Arm::getMaxRotation() const {
    return maxRotation;
}

const float Arm::getMinRotation() const {
    return minRotation;
}

const float Arm::getError() const {
    return error;
}