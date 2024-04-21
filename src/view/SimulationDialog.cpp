#include "SimulationDialog.h"


SimulationDialog::SimulationDialog(QWidget *parent)
    : QDialog(parent),
      map(1000.0, 1000.0),
      view(this, map),   
      controller(map, view) {
    setWindowTitle("Simulation");
    resize(1100, 1100);

    Vector2D pos1(30.0, 200.0), dir1(1.0, 0.0);
    Vector2D pos2(200.0, 30.0), dir2(-1.0, 0.0);
    Vector2D pos3(50.0, 50.0), dir3(1.0, 0.0);
    Vector2D pos4(100.0, 100.0), dir4(-1.0, 0.0);
    Vector2D pos5(150.0, 150.0), dir5(1.0, 0.0);
    Vector2D pos6(200.0, 200.0), dir6(-1.0, 0.0);

    std::vector<Robot> robots;
    robots.emplace_back(pos1, dir1);
    robots.emplace_back(pos2, dir2);

    std::vector<Obstacle> obstacles;
    obstacles.emplace_back(pos3);
    obstacles.emplace_back(pos4);
    obstacles.emplace_back(pos5);
    obstacles.emplace_back(pos6);

    map.setRobots(std::move(robots));
    map.setObstacles(std::move(obstacles));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view.viewport());
    setLayout(layout);

    controller.startSimulation();
}

SimulationDialog::~SimulationDialog() {  }