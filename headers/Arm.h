//
// Created by timi on 2.8.2017.
//

#ifndef MAG_DE_ARM_H
#define MAG_DE_ARM_H


class Arm {
private:
    // length in "mm"
    float maxLength = 0;
    float minLength = 0;

    // rotation in "degrees"
    float maxRotation = 0;
    float minRotation = 0;

    // error in percentage regarding to rotation (example: .05f equals 5% error)
    const float error = 0;

public:
    Arm();

    Arm(const float length, const float rotation);

    Arm(const float length, const float rotation, const float error);

    const float getMaxLength() const;

    const float getMinLength() const;

    const float getMaxRotation() const;

    const float getMinRotation() const;

    const float getError() const;
};

#endif //MAG_DE_ARM_H