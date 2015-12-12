#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QProcess>
#include <QGraphicsScene>
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

private:
    Ui::MainWindow *ui;
    QProcess *m_prayTracer;
    QGraphicsScene *m_pimageScene;
    QString m_workDir;
    QFileDialog *m_pfileDialog;
    QApplication *m_papp;
    QStringList m_arg;
    //vector<Cube> objects;
    Cube *cube;

    RenderedWindow *m_prenderedWin;

private:
    void RunRayTracer(QStringList arguments);
    void resizeEvent(QResizeEvent* event);
    QStringList *CreateRayTracerArguments(QString scene_file, QString out);
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
