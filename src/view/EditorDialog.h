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

#include "SimulationMapView.h"
#include "EditorMapView.h"

class EditorDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditorDialog(QWidget *parent = nullptr);

private slots:
    void saveMap();

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
    void setupUI();
};


#endif //ICP_EDITOR_DIALOG_H
