#include "renderedwindow.h"
#include "ui_renderedwindow.h"
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>
#include <QPoint>
#include <QFileDialog>

RenderedWindow::RenderedWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderedWindow)
{
    ui->setupUi(this);
    RenderedWindow::setWindowTitle("Rendered");

    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ShowContextMenu(const QPoint &)));

    QDir *dir = new QDir;
    m_workDir = dir->currentPath();

    QPixmap image("./basic.png");

    m_pimageScene = new QGraphicsScene();
    m_pimageScene->addPixmap(image);
    ui->graphicsView->setScene(m_pimageScene);


}

RenderedWindow::~RenderedWindow()
{
    delete ui;
}

void RenderedWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {

    }

}



void RenderedWindow::ShowContextMenu(const QPoint& pos) // this is a slot
{
    // for most widgets
    QPoint globalPos = this->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Menu Item 1");
    // ...

    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {
        // something was chosen, do stuff
    }
    else
    {
        // nothing was chosen
    }
}


void RenderedWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
        m_workDir,
        tr("Images (*.jpg)"));
}

