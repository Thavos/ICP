#ifndef MYMAPVIEW_H
#define MYMAPVIEW_H

#include <math.h>
#include <vector>
#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QVBoxLayout>
#include "./src/controller/SimulationController.h"
#include "./src/util/Vector2D.h"
#include "./src/model/Map.h"
#include "./src/model/Robot.h"
#include "./src/model/Obstacle.h"
#include <QDebug>

class MyMapView : public QWidget {
  Q_OBJECT

public:
  explicit MyMapView(SimulationController* controller, Map* map, QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent* event) override;

private:
  void drawMap(QPainter* painter);
  void drawRobot(QPainter* painter);
  void drawObstacles(QPainter* painter);
  SimulationController* controller;
  Map* map;
};

#endif