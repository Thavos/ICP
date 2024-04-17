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
    explicit SimulationDialog(QWidget *parent = nullptr);
    virtual ~SimulationDialog() override;

private:

};

#endif //ICP_SIMULATION_DIALOG_H
