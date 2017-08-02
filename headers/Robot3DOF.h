//
// Created by timi on 2.8.2017.
//

#ifndef MAG_DE_ROBOT_H
#define MAG_DE_ROBOT_H


#include <vector>
#include "Arm.h"

class Robot3DOF {
private:
    std::vector<Arm> arms;

    // length in "mm"
    const float arm1Length = 0;
    const float arm2Length = 0;
    const float arm3Length = 0;

    // rotation in "degrees"
    const float rotationWaist = 0;
    const float rotationShoulder = 0;
    const float rotationElbow = 0;

    // error in percentage regarding to rotation (example: .05f equals 5% error)
    const float errorWaist = 0;
    const float errorShoulder = 0;
    const float errorElbow = 0;

    const int dimension = 3;

public:
    Robot3DOF(float arm1Length, float arm2Length, float arm3Length, float rotationWaist, float rotationShoulder,
              float rotationElbow);

    Robot3DOF(float arm1Length, float arm2Length, float arm3Length, float rotationWaist, float rotationShoulder,
              float rotationElbow, float errorWaist, float errorShoulder, float errorElbow);

    void init();

    const std::vector<Arm> &getArms() const;

    const Arm getArm(const int armNumber) const;

    const int getDimension() const;
};


#endif //MAG_DE_ROBOT_H
