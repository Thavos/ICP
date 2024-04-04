#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>

#include "src/view/MainWindow.h"
#include "src/view/MyMainWindow.h"
#include "src/controller/SimulationController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
//    MyMainWindow mainWindow;
//    mainWindow.show();MyMainWindow mainWindow;
//    mainWindow.show();
    return app.exec();
}
