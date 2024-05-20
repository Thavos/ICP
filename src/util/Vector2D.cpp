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

const Vector2D Vector2D::zero(0, 0); // Since im not using any comparing to nul vector i might aswell not use it
const Vector2D Vector2D::one(1, 1);  // And this one is never used im pretty sure but it's neat so I'll keep it maybe *//::TODO::\\*

double Vector2D::Distance(const Vector2D& v1, const Vector2D& v2) {
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    return std::sqrt(dx * dx + dy * dy);
}

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

double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalized() const { // Im not sure if this should be static aswell... think about it *//::TODO::\\*
    double length = sqrt(x * x + y * y);
    if (length != 0) {
        return Vector2D(x / length, y / length);
    } else {
        return Vector2D::zero;
    }
}

double Vector2D::Cross(Vector2D other) const {
    return x * other.y - y * other.x;
}