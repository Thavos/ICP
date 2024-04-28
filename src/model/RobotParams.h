#ifndef ROBOTPARAMS_H
#define ROBOTPARAMS_H

#include "src/util/Vector2D.h"

class RobotParams {
public:
    Vector2D direction;
    double detectionRange;
    double rotationAngle;
    bool turningDirection;

    // Constructor
    RobotParams( const Vector2D& dir, double range, double angle, bool direction);
};

#endif // ROBOTPARAMS_H
