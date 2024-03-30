#include "Robot.h"

// xhruzs00

Robot::Robot(Vector2D pos, Vector2D dir) : pos(pos), dir(dir) {}
Robot::Robot(Vector2D pos, Vector2D dir, double rotationAngle, double detectionRange, double speed) 
    : pos(pos), dir(dir), rotationAngle(rotationAngle), detectionRange(detectionRange), speed(speed) {}
Robot::~Robot() {}

void Robot::setPos(Vector2D newPos) { pos = newPos; }
void Robot::setDirection(Vector2D newDir) { dir = newDir; }

Vector2D Robot::getPos() { return pos; }
Vector2D Robot::getDir() { return dir; }
double Robot::getSpeed() { return speed; }
double Robot::getRotationAngle() { return rotationAngle; }
double Robot::getDetectionRange() { return detectionRange; }

void Robot::updatePos() {}