#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility>
#include "src/util/Vector2D.h"
#include "src/model/Obstacle.h"
#include "src/model/Robot.h"

// xhruzs00

/**
 * @brief The Map class represents the simulation environment.
 *
 * This class stores the layout and properties of the simulation environment,
 * including obstacles and robots.
 */
class Map {
public:
    Map();
    Map(double x, double y);
    Map(Vector2D size);
    ~Map();

    void setRobots(const std::vector<Robot>& robots);
    void setObstacles(const std::vector<Obstacle>& obstacles);

    const std::vector<Robot>& getRobots() const;
    const std::vector<Obstacle>& getObstacles() const;
    
    Vector2D getSize();

private:
    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;
    Vector2D size;
};

#endif
