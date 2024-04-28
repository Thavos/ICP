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
#include <QFileDialog>
#include <QPushButton>
#include "src/model/Robot.h"
#include "src/controller/SimulationController.h"
#include "SimulationMapView.h"
#include "src/model/RobotParams.h"

class SimulationDialog : public QDialog {
    Q_OBJECT
public:
    SimulationDialog(QWidget *parent = nullptr);
    ~SimulationDialog();

    void startSimulation();
    void stopSimulation();
    void closeWindow();

private:
    Map map;
    SimulationMapView view;
    SimulationController controller;
    bool firstStart = true;

    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *menuButton;

    void loadFile();
};

#endif //ICP_SIMULATION_DIALOG_H
