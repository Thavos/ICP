#include <QApplication>
#include "./view/MainWindow.h"

// xhruzs00, xsnope04

/**
 * @brief The main function of the application.
 * 
 * This function initializes the Qt application, creates a MainWindow object,
 * sets its title, and shows the main window.
 * 
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return int The exit code of the application.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Robot Simulator");
    window.show();

    return app.exec();
}