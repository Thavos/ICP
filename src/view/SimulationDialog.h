#ifndef ICP_SIMULATION_DIALOG_H
#define ICP_SIMULATION_DIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
#include "src/model/Robot.h"
#include "src/controller/SimulationController.h"
#include "SimulationMapView.h"

class SimulationDialog : public QDialog {
    Q_OBJECT
public:
    SimulationDialog(QWidget *parent = nullptr);
    ~SimulationDialog();

private:
    Map map;
    SimulationMapView view;
    SimulationController controller;
};

#endif //ICP_SIMULATION_DIALOG_H
