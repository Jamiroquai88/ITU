#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QApplication *app) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_prayTracer(0),
    m_pimageScene(0),
    m_papp(0)
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Ray Tracer");
    this->setStyleSheet("background-color: #393939;");

    m_prenderedWin = new RenderedWindow;

    m_prayTracer = new QProcess(this);
    m_pimageScene = new QGraphicsScene();

    //QPixmap image(":/imgs/new.jpg");
    QPoint point(100, 100);
    //objects.push_back(new Cube(20,point));
    cube = new Cube();
    cube->setValues(20, point);

    m_pimageScene->addItem(cube);


    ui->graphicsView->setScene(m_pimageScene);
    ui->graphicsView->fitInView(m_pimageScene->itemsBoundingRect() ,Qt::KeepAspectRatio);

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

void MainWindow::RunRayTracer(QStringList arguments)
{
    QString raytracer = m_workDir + "/raytracer/release-bin/ray-tracer.exe";
    m_prayTracer->start(raytracer, arguments);
    m_prayTracer->waitForFinished();
    qDebug() << "finished";

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

/*
QStringList *MainWindow::CreateRayTracerArguments(QString scene_file, QString out)
{
    QStringList *list = new QStringList;
    QString arg1 = "--scene=" + scene_file;
    QString arg2 = "--resolution_x=" + QString::number(ui->graphicsView->width());
    QString arg3 = "--resolution_y=" + QString::number(ui->graphicsView->height());
    QString arg4 = "--output=" + mworkDir + "/" + out;
    *list << arg1 << arg2 << arg3 << arg4;
    return list;
}
*/

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

}
