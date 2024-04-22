#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "src/util/Vector2D.h"

// xhruzs00

/**
 * @brief The Obstacle class represents an obstacle in the simulation.
 *
 * This class stores the properties of an obstacle. It can be observed
 * by other objects, like robots, to react to its presence or changes.
 */
class Obstacle {
public:
    Obstacle(Vector2D pos);
    Obstacle(double x, double y);
    ~Obstacle();

    Vector2D getPos();

private:
    Vector2D pos;
};

#endif
