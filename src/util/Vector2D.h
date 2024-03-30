#ifndef VECTOR2D_H
#define VECTOR2D_H

// xhruzs00

#include <cmath>

/**
 * @brief The Vector2D class represents a two flaot values of X and Y.
 *
 */
class Vector2D {
public:
    Vector2D();
    Vector2D(double x, double y);
    ~Vector2D();

    double x, y;
    double getRotation();
    // double getX() const;
    // double getY() const;
    // void setX(double newX);
    // void setY(double newY);

    // double getRotation();
    // double getRotation(double x, double y);
    // double getRotation(Vector2D dir);
};

#endif
