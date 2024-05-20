# Makefile for ICP robot simulation
# xhruzs00

TEMPLATE = app
TARGET = robot-sim
INCLUDEPATH += .
CONFIG += c++17
QT += gui widgets
DEFINES += QT_DEPRECATED_WARNINGS

# Input
HEADERS += src/controller/SimulationController.h \
            src/controller/EditorController.h \
            src/view/MainWindow.h \
            src/view/SimulationView.h \
            src/view/EditorView.h \
            src/model/Map.h \
            src/model/Obstacle.h \
            src/model/Robot.h \
            src/util/Vector2D.h \

SOURCES += src/controller/SimulationController.cpp \
            src/controller/EditorController.cpp \
            src/view/MainWindow.cpp \
            src/view/SimulationView.cpp \
            src/view/EditorView.cpp \
            src/model/Map.cpp \
            src/model/Obstacle.cpp \
            src/model/Robot.cpp \
            src/util/Vector2D.cpp \
            src/main.cpp

# Custom commands
QMAKE_CLEAN += -rf ./doc/latex & rm -rf ./doc/html & rm -rf ./build/moc & rm -rf ./build/obj & rm -rf ./build/robot-sim

run.target = run
run.commands = build/$${TARGET}
QMAKE_EXTRA_TARGETS += run

doxygen.target = doxygen
doxygen.commands = doxygen Doxyfile
QMAKE_EXTRA_TARGETS += doxygen

pack.target = pack
pack.commands = zip -r xhruzs00-xhruzs00.zip doc/ resources/ src/ Makefile README.txt
QMAKE_EXTRA_TARGETS += pack

# Custom buildpath
DESTDIR = build/
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui