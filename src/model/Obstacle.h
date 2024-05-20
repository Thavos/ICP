#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "./src/util/Vector2D.h"

// xhruzs00

/**
 * @brief The Obstacle class represents an obstacle in the simulation.
 *
 * This class stores the properties of an obstacle. It can be observed
 * by other objects, like robots, to react to its presence or changes.
 */
class Obstacle {
public:
    /**
     * @brief Constructs a new Obstacle object.
     *
     * @param pos The position of the obstacle.
     */
    Obstacle(Vector2D pos);

    /**
     * @brief Destroys the Obstacle object.
     */
    ~Obstacle();

    /**
     * @brief Gets the position of the obstacle.
     *
     * @return Vector2D The position of the obstacle.
     */
    Vector2D GetPos() const;

    /**
     * @brief Checks if a line segment intersects with the obstacle.
     *
     * @param start The starting point of the line segment.
     * @param end The ending point of the line segment.
     * @return true if the line segment intersects with the obstacle, false otherwise.
     */
    bool Intersects(Vector2D start, Vector2D end);

    /**
     * @brief Checks if two line segments intersect each other.
     *
     * @param start1 The starting point of the first line segment.
     * @param end1 The ending point of the first line segment.
     * @param start2 The starting point of the second line segment.
     * @param end2 The ending point of the second line segment.
     * @return true if the line segments intersect, false otherwise.
     */
    bool LineIntersects(Vector2D start1, Vector2D end1, Vector2D start2, Vector2D end2);

private:
    Vector2D pos; /**< The position of the obstacle. */
};

#endif
