#ifndef ICP_SIMULATION_DIALOG_H
#define ICP_SIMULATION_DIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include "src/model/Robot.h"
#include "SimulationMapView.h"

class SimulationDialog : public QDialog {
    Q_OBJECT
public:
    explicit SimulationDialog(QWidget *parent = nullptr);
    virtual ~SimulationDialog() override;


private:
    SimulationMapView* mapView;
};

#endif //ICP_SIMULATION_DIALOG_H
