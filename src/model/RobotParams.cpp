#include "RobotParams.h"

// Constructor definition
RobotParams::RobotParams(const Vector2D& dir, double range, double angle, bool direction)
        :  direction(dir), detectionRange(range), rotationAngle(angle), turningDirection(direction) {}
