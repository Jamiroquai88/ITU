#include "mainwindow.h"
#include "objects.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent, QApplication *app) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pimageScene(0),
    m_papp(0),
    m_objCount(0)
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Ray Tracer");

    m_colorDialog = new QColorDialog;

    addCube = new QAction(tr("&Add Cube"), this);
    addCube->setStatusTip(tr("Add a cube to the scene"));
    connect(addCube, SIGNAL(triggered()), this, SLOT(s_addCube()));

    addSphere = new QAction(tr("&Add Sphere"), this);
    addSphere->setStatusTip(tr("Add a sphere to the scene"));
    connect(addSphere, SIGNAL(triggered()), this, SLOT(s_addSphere()));

    addPlane = new QAction(tr("&Add Plane"), this);
    addPlane->setStatusTip(tr("Add a plane to the scene"));
    connect(addPlane, SIGNAL(triggered()), this, SLOT(s_addPlane()));

    m_addMenu = new QMenu;
    m_addMenu->addAction(addCube);
    m_addMenu->addAction(addSphere);
    m_addMenu->addAction(addPlane);

    ui->objectButton->setMenu(m_addMenu);

    ui->objectParams->hide();

    m_prenderedWin = new RenderedWindow;

    m_pimageScene = new QGraphicsScene();
    m_pimageScene->setSceneRect(0,0,450,450);

    ui->graphicsView->setScene(m_pimageScene);
    //ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect(), Qt::KeepAspectRatio);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

   // ui->graphicsView->show();
    QDir *dir = new QDir;
    m_workDir = dir->currentPath();

    m_pfileDialog = new QFileDialog;
    m_pfileDialog->setFileMode(QFileDialog::ExistingFile);

    m_papp = app;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGraphicsScene *MainWindow::getScene()
{
    return m_pimageScene;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    painter.drawLine(10,10,100,100);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}


void MainWindow::on_actionNew_Scene_triggered()
{
    on_resetButton_clicked();

}

void MainWindow::on_actionLoad_Scene_triggered()
{
    QStringList fileNames = m_pfileDialog->getOpenFileNames(this, tr("Open File"),m_workDir ,tr("XML Files (*.xml)"));
}

void MainWindow::on_renderButton_clicked()
{
    /** Render Button Event **/
    //m_prenderedWin->SetImage();
    m_prenderedWin->show();
}

void MainWindow::on_objectButton_clicked()
{
    /** Add Object Button Event **/

}

void MainWindow::on_lightButton_clicked()
{
    /** Add Light Button Event **/
    std::ostringstream oss;
    oss << "light_" << m_lightCount;
    ++m_lightCount;

    QPoint point(10, 10);
    light = new Light();
    light->setValues(50, point, ui, oss.str());
    m_pimageScene->addItem(light);

}

void MainWindow::on_resetButton_clicked()
{
    /** Reset Scene Button Event **/

    m_pimageScene->clear();

}

void MainWindow::s_addCube()
{
    std::ostringstream oss;
    oss << "object_" << m_objCount;

    m_objCount++;
    QPoint point(10, 10);
    obj = new Cube();
    obj->setValues(50, point, ui,  oss.str());
    m_pimageScene->addItem(obj);
    return;
}

void MainWindow::s_addSphere()
{
    std::ostringstream oss;
    oss << "object_" << m_objCount;
    m_objCount++;
    QPoint point(10, 10);
    obj = new Sphere();
    obj->setValues(50, point, ui, oss.str());
    m_pimageScene->addItem(obj);
    return;
}
void MainWindow::s_addPlane()
{
    std::ostringstream oss;
    oss << "object_" << m_objCount;
    m_objCount++;
    QPoint point(10, 10);
    obj = new Plain();
    obj->setValues(50, point,  ui, oss.str());
    m_pimageScene->addItem(obj);
    return;
}

void MainWindow::on_sizeSlider_valueChanged(int value)
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   for(it = items.begin(); it != items.end(); ++it) {
        if(typeid(*(static_cast<Object *>(*it)))==typeid(Light))
        {
           static_cast<Light *>(*it)->setPower(value);
        }
        else
        {
           static_cast<Object *>(*it)->setSize(value);
        }
   }
   update();
}

void MainWindow::on_colorBox_currentIndexChanged(const QString &arg1)
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   QColor tmpColor(arg1);

   for(it = items.begin(); it != items.end(); ++it) {
       static_cast<Object *>(*it)->changeColour(tmpColor);
    }
   update();
}

void MainWindow::on_nameEdit_textChanged()
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   for(it = items.begin(); it != items.end(); ++it) {
       static_cast<Object *>(*it)->setName(ui->nameEdit->toPlainText());
    }

}

void MainWindow::on_removeButton_clicked()
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   for(it = items.begin(); it != items.end(); ++it) {
       m_pimageScene->removeItem(static_cast<Object *>(*it));
    }
   ui->objectParams->hide();
   update();
}

void MainWindow::on_reflSlider_valueChanged(int value)
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   for(it = items.begin(); it != items.end(); ++it) {
       static_cast<Object *>(*it)->setRefl(value);
    }
}

void MainWindow::on_gammaSlider_valueChanged(int value)
{
    QList<QGraphicsItem *> items(m_pimageScene->selectedItems());
    QList<QGraphicsItem *>::iterator it;

   for(it = items.begin(); it != items.end(); ++it) {
       static_cast<Object *>(*it)->setGamma(value);
    }
}

void MainWindow::on_actionSave_Scene_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
        m_workDir,
        tr("Scenes (*.xml)"));
}

void MainWindow::on_actionSave_Scene_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
        m_workDir,
        tr("Scenes (*.xml)"));
}

void MainWindow::on_actionRender_Settings_triggered()
{
    m_colorDialog->show();
    QString color = "background-color: " + m_colorDialog->getColor().name() + ";";
    ui->graphicsView->setStyleSheet(color);
    m_colorDialog->close();
    return;
}
