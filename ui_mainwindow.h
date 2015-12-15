/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Scene;
    QAction *actionLoad_Scene;
    QAction *actionSave_Scene;
    QAction *actionSave_Scene_As;
    QAction *actionExit;
    QAction *actionRender_Settings;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *sceneHLayout;
    QVBoxLayout *sceneVLayout;
    QHBoxLayout *mainButtonsLayout;
    QPushButton *renderButton;
    QPushButton *objectButton;
    QPushButton *lightButton;
    QPushButton *resetButton;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *parametersLayout;
    QGroupBox *objectParams;
    QTextEdit *nameEdit;
    QLabel *label;
    QSlider *sizeSlider;
    QLabel *sizeLabel;
    QComboBox *colorBox;
    QLabel *label_3;
    QLabel *reflLabel;
    QSlider *reflSlider;
    QSlider *gammaSlider;
    QLabel *gammaLabel;
    QPushButton *removeButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(818, 678));
        actionNew_Scene = new QAction(MainWindow);
        actionNew_Scene->setObjectName(QStringLiteral("actionNew_Scene"));
        actionLoad_Scene = new QAction(MainWindow);
        actionLoad_Scene->setObjectName(QStringLiteral("actionLoad_Scene"));
        actionSave_Scene = new QAction(MainWindow);
        actionSave_Scene->setObjectName(QStringLiteral("actionSave_Scene"));
        actionSave_Scene_As = new QAction(MainWindow);
        actionSave_Scene_As->setObjectName(QStringLiteral("actionSave_Scene_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionRender_Settings = new QAction(MainWindow);
        actionRender_Settings->setObjectName(QStringLiteral("actionRender_Settings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sceneHLayout = new QVBoxLayout();
        sceneHLayout->setSpacing(6);
        sceneHLayout->setObjectName(QStringLiteral("sceneHLayout"));
        sceneVLayout = new QVBoxLayout();
        sceneVLayout->setSpacing(6);
        sceneVLayout->setObjectName(QStringLiteral("sceneVLayout"));
        mainButtonsLayout = new QHBoxLayout();
        mainButtonsLayout->setSpacing(6);
        mainButtonsLayout->setObjectName(QStringLiteral("mainButtonsLayout"));
        renderButton = new QPushButton(centralWidget);
        renderButton->setObjectName(QStringLiteral("renderButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(renderButton->sizePolicy().hasHeightForWidth());
        renderButton->setSizePolicy(sizePolicy1);
        renderButton->setStyleSheet(QLatin1String("background-color: rgb(58, 58, 58);\n"
"color: rgb(255, 255, 255);"));

        mainButtonsLayout->addWidget(renderButton);

        objectButton = new QPushButton(centralWidget);
        objectButton->setObjectName(QStringLiteral("objectButton"));
        objectButton->setMinimumSize(QSize(175, 0));
        objectButton->setStyleSheet(QLatin1String("background-color: rgb(58, 58, 58);\n"
"color: rgb(255, 255, 255);"));

        mainButtonsLayout->addWidget(objectButton);

        lightButton = new QPushButton(centralWidget);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        lightButton->setStyleSheet(QLatin1String("background-color: rgb(58, 58, 58);\n"
"color: rgb(255, 255, 255);"));

        mainButtonsLayout->addWidget(lightButton);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setStyleSheet(QLatin1String("background-color: rgb(58, 58, 58);\n"
"color: rgb(255, 255, 255);"));

        mainButtonsLayout->addWidget(resetButton);


        sceneVLayout->addLayout(mainButtonsLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(175, 0));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));

        sceneVLayout->addWidget(graphicsView);

        sceneVLayout->setStretch(0, 1);
        sceneVLayout->setStretch(1, 12);

        sceneHLayout->addLayout(sceneVLayout);


        horizontalLayout->addLayout(sceneHLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        parametersLayout = new QVBoxLayout();
        parametersLayout->setSpacing(6);
        parametersLayout->setObjectName(QStringLiteral("parametersLayout"));
        objectParams = new QGroupBox(centralWidget);
        objectParams->setObjectName(QStringLiteral("objectParams"));
        objectParams->setStyleSheet(QLatin1String("background-color: rgb(48, 48, 48);\n"
"color: rgb(255, 255, 255);"));
        nameEdit = new QTextEdit(objectParams);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(20, 70, 191, 31));
        label = new QLabel(objectParams);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 57, 15));
        sizeSlider = new QSlider(objectParams);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        sizeSlider->setGeometry(QRect(20, 210, 171, 21));
        sizeSlider->setOrientation(Qt::Horizontal);
        sizeLabel = new QLabel(objectParams);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));
        sizeLabel->setGeometry(QRect(20, 190, 57, 16));
        colorBox = new QComboBox(objectParams);
        colorBox->setObjectName(QStringLiteral("colorBox"));
        colorBox->setGeometry(QRect(20, 140, 111, 21));
        label_3 = new QLabel(objectParams);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 57, 16));
        reflLabel = new QLabel(objectParams);
        reflLabel->setObjectName(QStringLiteral("reflLabel"));
        reflLabel->setGeometry(QRect(20, 240, 71, 16));
        reflSlider = new QSlider(objectParams);
        reflSlider->setObjectName(QStringLiteral("reflSlider"));
        reflSlider->setGeometry(QRect(20, 260, 171, 21));
        reflSlider->setOrientation(Qt::Horizontal);
        gammaSlider = new QSlider(objectParams);
        gammaSlider->setObjectName(QStringLiteral("gammaSlider"));
        gammaSlider->setGeometry(QRect(20, 310, 171, 21));
        gammaSlider->setOrientation(Qt::Horizontal);
        gammaLabel = new QLabel(objectParams);
        gammaLabel->setObjectName(QStringLiteral("gammaLabel"));
        gammaLabel->setGeometry(QRect(20, 290, 57, 15));
        removeButton = new QPushButton(objectParams);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(70, 350, 80, 23));

        parametersLayout->addWidget(objectParams);


        horizontalLayout->addLayout(parametersLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionNew_Scene);
        menuFile->addAction(actionLoad_Scene);
        menuFile->addAction(actionSave_Scene);
        menuFile->addAction(actionSave_Scene_As);
        menuFile->addAction(actionExit);
        menuSettings->addAction(actionRender_Settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew_Scene->setText(QApplication::translate("MainWindow", "New Scene", 0));
        actionLoad_Scene->setText(QApplication::translate("MainWindow", "Load Scene", 0));
        actionSave_Scene->setText(QApplication::translate("MainWindow", "Save Scene", 0));
        actionSave_Scene_As->setText(QApplication::translate("MainWindow", "Save Scene As ...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionRender_Settings->setText(QApplication::translate("MainWindow", "Set background color", 0));
        renderButton->setText(QApplication::translate("MainWindow", "Render", 0));
        objectButton->setText(QApplication::translate("MainWindow", "Add Object", 0));
        lightButton->setText(QApplication::translate("MainWindow", "Add Light", 0));
        resetButton->setText(QApplication::translate("MainWindow", "Reset Scene", 0));
        objectParams->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Name", 0));
        sizeLabel->setText(QApplication::translate("MainWindow", "Size", 0));
        colorBox->clear();
        colorBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "black", 0)
         << QApplication::translate("MainWindow", "blue", 0)
         << QApplication::translate("MainWindow", "green", 0)
         << QApplication::translate("MainWindow", "red", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Color", 0));
        reflLabel->setText(QApplication::translate("MainWindow", "Reflection", 0));
        gammaLabel->setText(QApplication::translate("MainWindow", "Gamma", 0));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
