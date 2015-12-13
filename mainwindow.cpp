#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QApplication *app) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pimageScene(0),
    m_papp(0)
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Ray Tracer");
    this->setStyleSheet("background-color: #393939;");

    addCube = new QAction(tr("&Add Cube"), this);
    addCube->setStatusTip(tr("Add a cube to the scene"));
    connect(addCube, SIGNAL(triggered()), this, SLOT(s_addCube()));

    addSphere = new QAction(tr("&Add Sphere"), this);
    addSphere->setStatusTip(tr("Add a sphere to the scene"));
    connect(addSphere, SIGNAL(triggered()), this, SLOT(s_addSphere()));

    addPlane = new QAction(tr("&Add Plane"), this);
    addPlane->setStatusTip(tr("Add a plane to the scene"));
    connect(addPlane, SIGNAL(triggered()), this, SLOT(s_addPlane()));

    m_addMenu = menuBar()->addMenu(tr("&Add"));
    m_addMenu->addAction(addCube);
    m_addMenu->addAction(addSphere);
    m_addMenu->addAction(addPlane);

    ui->objectButton->setMenu(m_addMenu);

    m_prenderedWin = new RenderedWindow;

    m_pimageScene = new QGraphicsScene();

    ui->graphicsView->setScene(m_pimageScene);
    ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect(), Qt::KeepAspectRatio);
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

    //QStringList arguments;
    //RunRayTracer(arguments);

    QPixmap image("./basic.png");

    m_pimageScene->addPixmap(image);
    ui->graphicsView->setScene(m_pimageScene);
    ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void MainWindow::on_actionLoad_Scene_triggered()
{
    QStringList fileNames = m_pfileDialog->getOpenFileNames(this, tr("Open File"),m_workDir ,tr("XML Files (*.xml)"));
    //qDebug() << fileNames[0];
    if(fileNames.count() != 0)
    {
        /*QStringList *arg = CreateRayTracerArguments(fileNames[0], "out.png");
        RunRayTracer(*arg);
        QPixmap image("out.png");
        m_pimageScene->addPixmap(image);
        ui->graphicsView->setScene(m_pimageScene);
        ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    */}
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
    QPoint point(10, 10);
    light = new Light();
    light->setValues(50, point);
    m_pimageScene->addItem(light);

}

void MainWindow::on_resetButton_clicked()
{
    /** Reset Scene Button Event **/

    m_pimageScene->clear();

}

void MainWindow::s_addCube()
{
    QPoint point(10, 10);
    cube = new Cube();
    cube->setValues(50, point);
    m_pimageScene->addItem(cube);
    return;
}

void MainWindow::s_addSphere()
{
    QPoint point(10, 10);
    sphere = new Sphere();
    sphere->setValues(50, point);
    m_pimageScene->addItem(sphere);
    return;
}
void MainWindow::s_addPlane()
{
    QPoint point(10, 10);
    plain = new Plain();
    plain->setValues(50, point);
    m_pimageScene->addItem(plain);
    return;
}
