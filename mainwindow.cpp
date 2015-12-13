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

    m_prenderedWin = new RenderedWindow;

    m_pimageScene = new QGraphicsScene(0, 0, 650, 700);

    QPoint point(m_pimageScene->height() / 2, m_pimageScene->width() / 2);
    //objects.push_back(new Cube(20,point));
    cube = new Cube();
    cube->setValues(2, point);

    sphere = new Sphere();
    //point.setX(20);
   // point.setY(20);
    sphere->setValues(4, point);

    plain = new Plain();
   // point.setX(50);
    //point.setY(50);
    plain->setValues(2, point);

    light = new Light();
    light->setValues(10, point);

    m_pimageScene->addItem(cube);
    m_pimageScene->addItem(sphere);
    m_pimageScene->addItem(plain);
    m_pimageScene->addItem(light);


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

}

void MainWindow::on_resetButton_clicked()
{
    /** Reset Scene Button Event **/

    m_pimageScene->clear();

}
