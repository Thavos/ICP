#include "EditorDialog.h"

EditorDialog::EditorDialog(QWidget *parent) : QDialog(parent) {
    setupUI();
}

void EditorDialog::setupUI(){
    setWindowTitle("Map Editor");

    resize(1200, 1000); // Adjust the size according to your needs
    mapView = new EditorMapView(this);
    btnSave = new QPushButton("Save", this);
    btnAddObstacle = new QRadioButton("Add Obstacle", this);
    btnAddRobot = new QRadioButton("Add Robot", this);
    btnAddRobot->setChecked(true);
    modeBox = new QComboBox(this);
    modeBox->addItem("Placement Mode");
    modeBox->addItem("Editing Mode");

    robotDirectionInput = new QLineEdit(this);
    detectionRangeInput = new QLineEdit(this);
    turningAngleInput = new QLineEdit(this);
    turningDirectionInput = new QComboBox(this);
    turningDirectionInput->addItem("Left");
    turningDirectionInput->addItem("Right");

    //Hint messages
    robotDirectionInput->setToolTip("Enter the direction of the robot here(degrees)");
    detectionRangeInput->setToolTip("Enter the detection range of the robot here");
    turningAngleInput->setToolTip("Enter the turning angle of the robot here(degrees)");

    //Robot parameters layout
    auto* robotParamsLayout = new QFormLayout();
    robotParamsLayout->addRow("Direction", robotDirectionInput);
    robotParamsLayout->addRow("Detection Range", detectionRangeInput);
    robotParamsLayout->addRow("Turning Direction", turningDirectionInput);
    robotParamsLayout->addRow("Turning Angle", turningAngleInput);

    auto *groupRobotParams = new QGroupBox("Robot Parameters", this);
    groupRobotParams->setLayout(robotParamsLayout);


    //Layout to arrange the text edit and button
    auto *modeLayout = new QVBoxLayout();
    modeLayout->addWidget(btnAddRobot);
    modeLayout->addWidget(btnAddObstacle);
    modeLayout->addWidget(modeBox);

    auto *groupMode = new QGroupBox("Mode", this);
    groupMode->setLayout(modeLayout);


    auto *verticalLayout = new QVBoxLayout();
    verticalLayout->addWidget(groupMode);
    verticalLayout->addWidget(groupRobotParams);

    auto *layout = new QHBoxLayout();
    layout->addLayout(verticalLayout);
    layout->addWidget(mapView);
    layout->addWidget(btnSave);
    setLayout(layout);

    // Connect the save button to the saveMap slot
    connect(btnSave, &QPushButton::clicked, this, &EditorDialog::saveMap);
    connect(btnAddRobot, &QRadioButton::toggled, [this](bool checked){
        if (checked) mapView->setEditMode("Robot");
    });
    connect(btnAddObstacle, &QRadioButton::toggled, [this](bool checked){
        if (checked) mapView->setEditMode("Obstacle");
    });
    connect(modeBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        QString mode = modeBox->itemText(index);
        printf("Selected mode: %s\n", mode.toStdString().c_str());
        mapView->setMode(mode);
    });
}

void EditorDialog::saveMap() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Map"), "", tr("Map Files (*.txt)"));
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QTextStream out(&file);
    out << mapView->getMapDataAsString(); // Assuming getMapDataAsString() returns a string representation of the map
    file.close();
}