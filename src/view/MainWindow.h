#ifndef CENTEREDWINDOW_H
#define CENTEREDWINDOW_H

#include <QScreen>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QGuiApplication>

#include "EditorView.h"
#include "SimulationView.h"

// xsnope04

/**
 * @brief The MainWindow class represents the main window of the application.
 * 
 * This winow shows four buttons total:
 * - Simulation    -    Starts the simulation window.
 * - New Map       -    Opens the editor without loading a file.
 * - Editor        -    Opens the editor with an option to load an initial map configuration.
 * - Quit          -    Exits the application.
 */
class MainWindow : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Displays the simulation view.
     */
    void showSimulationView();

    /**
     * @brief Displays the editor view.
     * @param fromExisting Flag indicating whether we want to open editor and load initial data.
     */
    void showEditorView(bool fromExisting);
};

#endif