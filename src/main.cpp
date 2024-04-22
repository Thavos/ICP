#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QPropertyAnimation>

#include "src/view/MainWindow.h"
#include "src/controller/SimulationController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    // SimulationController simulationController();
    
//    MyMainWindow mainWindow;
//    mainWindow.show();MyMainWindow mainWindow;
//    mainWindow.show();
    return app.exec();
} 