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

const Vector2D Vector2D::zero(0, 0);
const Vector2D Vector2D::one(1, 1);

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    if (scalar == 0) {
        qDebug() << "Division with 0 between Vector2D and scalar value";
        return Vector2D::zero;
    }
    return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(double scalar) {
    if (scalar == 0) {
        qDebug() << "Division with 0 between Vector2D and scalar value";
        return *this;
    }
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2D::operator<(const Vector2D& other) const {
    return x < other.x && y < other.y;
}

bool Vector2D::operator>(const Vector2D& other) const {
    return x > other.x && y > other.y;
}

bool Vector2D::operator<=(const Vector2D& other) const {
    return x <= other.x && y <= other.y;
}

bool Vector2D::operator>=(const Vector2D& other) const {
    return x >= other.x && y >= other.y;
}

bool Vector2D::operator==(const Vector2D& other) const {
    return x == other.x && y == other.y;
}

double Vector2D::getRotation() {
    return atan2(y, x) * 180.0 / M_PI;
}