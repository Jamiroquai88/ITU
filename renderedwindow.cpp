#include "renderedwindow.h"
#include "ui_renderedwindow.h"

RenderedWindow::RenderedWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderedWindow)
{
    ui->setupUi(this);
    RenderedWindow::setWindowTitle("Rendered");
}

RenderedWindow::~RenderedWindow()
{
    delete ui;
}
