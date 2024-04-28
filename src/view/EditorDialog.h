#ifndef ICP_EDITOR_DIALOG_H
#define ICP_EDITOR_DIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QRadioButton>
#include <QFile>
#include <QTextStream>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QFormLayout>
#include <QStandardPaths>
#include <QCoreApplication>

#include "SimulationMapView.h"
#include "EditorMapView.h"
#include "src/model/RobotParams.h"

class EditorDialog : public QDialog {
    Q_OBJECT
public:
    explicit EditorDialog(QWidget *parent = nullptr);
    RobotParams getRobotParams();
private slots:
    void handleAddRobot(const QPointF &position);
    void handleAddObstacle(const QPointF &position);
    void handleRobotPositionChanged(const Vector2D &newPos, const Vector2D &oldPos);
    void handleObstaclePositionChanged(const Vector2D &newPos, const Vector2D &oldPos);
    void updateRobotParams();
private:
    QLineEdit* robotDirectionInput;
    QLineEdit* detectionRangeInput;
    QComboBox* turningDirectionInput;
    QComboBox* modeBox;
    QLineEdit* turningAngleInput;
    EditorMapView *mapView;
    QPushButton *btnSave;
    QRadioButton *btnAddRobot;
    QRadioButton *btnAddObstacle;
    QPushButton *btnUpdateRobotParams;

    static Vector2D directionVectorFromDegrees(double degrees);
    double directionToDegrees(const Vector2D& direction);
    void setupUI();
    void exportMapToFile();
};


#endif //ICP_EDITOR_DIALOG_H
