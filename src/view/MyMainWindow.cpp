#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
  QWidget(parent) {
  // Create layout and buttons
  QVBoxLayout* layout = new QVBoxLayout(this);

  startButton = new QPushButton("Start Simulation");
  quitButton = new QPushButton("Quit");

  // Connect button clicks to slots
  connect(startButton, &QPushButton::clicked, this, &MyMainWindow::onStartButtonClicked);
  connect(quitButton, &QPushButton::clicked, qApp, QCoreApplication::quit);

  layout->addWidget(startButton);
  layout->addWidget(quitButton);

  // Set the layout
  setLayout(layout);
  setWindowTitle("Robot Simulator");
  this->setMinimumSize(400, 300);
}

void MyMainWindow::onStartButtonClicked() {
  // // this->hide();

  // // Create a new map, robots, and obstacles
  // Map map(100, 100);
  // std::vector<Robot> robots;

  // Vector2D pos1(10.0, 10.0);
  // Vector2D dir1(1.0, 0.0);
  // Robot robot1(pos1, dir1);

  // Vector2D pos2(20.0, 20.0);
  // Vector2D dir2(-1.0, 0.0);
  // Robot robot2(pos2, dir2);

  // robots.push_back(robot1);
  // robots.push_back(robot2);
  // map.setRobots(robots);

  // std::vector<Obstacle> obstacles;

  // Vector2D pos3(30.0, 10.0);
  // Obstacle obstacle1(pos3);

  // Vector2D pos4(20.0, 50.0);
  // Obstacle obstacle2(pos4);

  // obstacles.push_back(obstacle1);
  // obstacles.push_back(obstacle2);
  // map.setObstacles(obstacles);

  // // Create a SimulationController instance
  // SimulationController simCon;

  // // Create and show MyMapView
  // MyMapView* newMapView = new MyMapView(&simCon, &map, this);
  // // layout->addWidget(newMapView);
  // newMapView->show();
}

void MyMainWindow::onQuitButtonClicked() {
  qApp->quit();
}