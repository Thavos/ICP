#include "SimulationDialog.h"


SimulationDialog::SimulationDialog(QWidget *parent)
    : QDialog(parent), mapView(new SimulationMapView(this)) {
    setWindowTitle("Simulation");
    resize(1100, 1100);

   auto simulationMap = std::make_unique<Map>(100, 100);

    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;

    Vector2D pos1(30.0, 200.0), dir1(1.0, 0.0);
    Vector2D pos2(200.0, 30.0), dir2(-1.0, 0.0);
    //make me more pos for some obstacles and robots

    Vector2D pos3(50.0, 50.0), dir3(1.0, 0.0);
    Vector2D pos4(100.0, 100.0), dir4(-1.0, 0.0);
    Vector2D pos5(150.0, 150.0), dir5(1.0, 0.0);
    Vector2D pos6(200.0, 200.0), dir6(-1.0, 0.0);
  

    robots.emplace_back(pos1, dir1);
    robots.emplace_back(pos2, dir2);
    obstacles.emplace_back(pos3);
    obstacles.emplace_back(pos4);
    obstacles.emplace_back(pos5);
    obstacles.emplace_back(pos6);

    simulationMap->setRobots(robots);
    simulationMap->setObstacles(obstacles);

    mapView->setSimulationMap(std::move(simulationMap));

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(mapView);
    setLayout(layout);
}

SimulationDialog::~SimulationDialog() {  }