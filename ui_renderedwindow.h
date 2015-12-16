/********************************************************************************
** Form generated from reading UI file 'renderedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDEREDWINDOW_H
#define UI_RENDEREDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderedWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *RenderedWindow)
    {
        if (RenderedWindow->objectName().isEmpty())
            RenderedWindow->setObjectName(QStringLiteral("RenderedWindow"));
        RenderedWindow->resize(1024, 768);
        gridLayout = new QGridLayout(RenderedWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(RenderedWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 86, 86);"));

        verticalLayout->addWidget(pushButton);

        graphicsView = new QGraphicsView(RenderedWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(RenderedWindow);

        QMetaObject::connectSlotsByName(RenderedWindow);
    } // setupUi

    void retranslateUi(QWidget *RenderedWindow)
    {
        RenderedWindow->setWindowTitle(QApplication::translate("RenderedWindow", "Form", 0));
        pushButton->setText(QApplication::translate("RenderedWindow", "Save Image", 0));
    } // retranslateUi

};

namespace Ui {
    class RenderedWindow: public Ui_RenderedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEREDWINDOW_H
