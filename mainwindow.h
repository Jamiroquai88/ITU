#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QProcess>
#include <QFileDialog>
#include <QProgressDialog>
#include <QThread>
#include <QInputDialog>
#include <QtGui>
#include <QtCore>

#include <vector>

#include "renderedwindow.h"
#include "objects.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QApplication *app = 0);
    ~MainWindow();
    QGraphicsScene *getScene();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *ev);


private slots:
    void on_actionExit_triggered();
    void on_actionNew_Scene_triggered();

    void on_actionLoad_Scene_triggered();

    void on_renderButton_clicked();

    void on_objectButton_clicked();

    void on_lightButton_clicked();

    void on_resetButton_clicked();
    void s_addSphere();
    void s_addCube();
    void s_addPlane();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_pimageScene;
    QString m_workDir;
    QFileDialog *m_pfileDialog;
    QApplication *m_papp;
    QMenu *m_addMenu;
    QAction *addCube;
    QAction *addSphere;
    QAction *addPlane;
    //vector<Cube> objects;
    Cube *cube;
    Sphere *sphere;
    Plain *plain;
    Light *light;

    RenderedWindow *m_prenderedWin;

private:
    void resizeEvent(QResizeEvent* event);
    void quit();
};

class Thread : public QThread
{
private:
    void run()
    {
        QMessageBox msgBox;
        msgBox.setText("Wait, new scene is being set...");
        msgBox.exec();
    }
};


#endif // MAINWINDOW_H
