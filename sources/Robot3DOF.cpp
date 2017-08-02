//
// Created by timi on 2.8.2017.
//

#include "../headers/Robot3DOF.h"

Robot3DOF::Robot3DOF(float arm1Length, float arm2Length, float arm3Length, float rotationWaist, float rotationShoulder,
                     float rotationElbow) :
        Robot3DOF(arm1Length, arm2Length, arm3Length, rotationWaist, rotationShoulder, rotationElbow, 0, 0, 0) {
}

Robot3DOF::Robot3DOF(float arm1Length, float arm2Length, float arm3Length, float rotationWaist, float rotationShoulder,
                     float rotationElbow, float errorWaist, float errorShoulder, float errorElbow) :
        arm1Length(arm1Length),
        arm2Length(arm2Length),
        arm3Length(arm3Length),
        rotationWaist(rotationWaist),
        rotationShoulder(rotationShoulder),
        rotationElbow(rotationElbow),
        errorWaist(errorWaist),
        errorShoulder(errorShoulder),
        errorElbow(errorElbow) {
    init();
}

void Robot3DOF::init() {
    arms.emplace_back(arm1Length, rotationWaist, errorWaist);
    arms.emplace_back(arm2Length, rotationShoulder, errorShoulder);
    arms.emplace_back(arm3Length, rotationElbow, errorElbow);
}

const std::vector<Arm> &Robot3DOF::getArms() const {
    return arms;
}

const Arm Robot3DOF::getArm(const int armNumber) const {
    return arms.at(armNumber);
}

const int Robot3DOF::getDimension() const {
    return dimension;
}
