#include "Vector2D.h"

// xhruzs00

/**
 * @brief Constructs a new Vector2D object.
 */
Vector2D::Vector2D() : x(0.0f), y(0.0f) {}
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

/**
 * @brief Destroys the Vector2D object.
 */
Vector2D::~Vector2D() {}

double Vector2D::getRotation() {
    return atan2(y, x) * 180.0 / M_PI;
}

// double Vector2D::getRotation(double x, double y) {
//     return atan2(y, x) * 180.0 / M_PI;
// }

// double Vector2D::getRotation(Vector2D dir) {
//     return atan2(dir.getY(), dir.getX()) * 180.0 / M_PI;
// }