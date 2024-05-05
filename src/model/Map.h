#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility>
#include <QDebug>
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

    void setSize(Vector2D setSize);
    void setSize(double x, double y);
    void setRobots(std::vector<Robot>&& newRobots);
    void setObstacles(std::vector<Obstacle>&& newObstacles);

    void addRobot(const Robot& newRobot);
    void addObstacle(const Obstacle& newObstacle);

    void moveRobot(const Vector2D& oldPos, const Vector2D& newPos);
    void moveObstacle(const Vector2D& oldPos, const Vector2D& newPos);

    std::vector<Robot>* getRobots();
    std::vector<Obstacle>* getObstacles();

    Robot* getRobot(const Vector2D& pos);
    
    Vector2D getSize();

private:
    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;
    Vector2D size;
};

#endif
