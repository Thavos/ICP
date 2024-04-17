#ifndef VECTOR2D_H
#define VECTOR2D_H

// xhruzs00

#include <cmath>
#include <QDebug>

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

    static const Vector2D zero;
    static const Vector2D one;
    
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(double scalar);
    Vector2D& operator/=(double scalar);

    bool operator<(const Vector2D& other) const;
    bool operator>(const Vector2D& other) const;
    bool operator<=(const Vector2D& other) const;
    bool operator>=(const Vector2D& other) const;
    bool operator==(const Vector2D& other) const;
};

#endif
