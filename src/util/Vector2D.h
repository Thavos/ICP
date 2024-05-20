#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <QDebug>

// xhruzs00

/**
 * @brief Custom Vector2D class represents a two-dimensional vector with X and Y components.
 *
 * This class provides functionality for performing vector operations such as addition, subtraction, multiplication, division, and more.
 */
class Vector2D {
public:
    /**
     * @brief Constructs a new Vector2D object with default values (0, 0).
     */
    Vector2D();

    /**
     * @brief Constructs a new Vector2D object with specified X and Y components.
     * @param x The X component of the vector.
     * @param y The Y component of the vector.
     */
    Vector2D(double x, double y);

    /**
     * @brief Destroys the Vector2D object.
     */
    ~Vector2D();

    double x, y; /**< The X and Y components of the vector. */

    /**
     * @brief Calculates the rotation angle of the vector in degrees.
     * @return The rotation angle in degrees.
     */
    double getRotation();

    static const Vector2D zero; /**< The zero vector (0, 0). */
    static const Vector2D one; /**< The unit vector (1, 1). */

    /**
     * @brief Calculates the Euclidean distance between two vectors.
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @return The Euclidean distance between v1 and v2.
     */
    static double Distance(const Vector2D& v1, const Vector2D& v2);
    
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

    /**
     * @brief Calculates the length of the vector.
     * @return The length of the vector.
     */
    double length() const;
    
    /**
     * @brief Returns a normalized copy of the vector.
     * @return A normalized copy of the vector with magnitude of 1.
     */
    Vector2D normalized() const;

    /**
     * @brief Calculates the cross product of this vector and another vector.
     * @param other The other vector.
     * @return The 2D cross product of this vector and other.
     */
    double Cross(Vector2D other) const;
};

#endif
