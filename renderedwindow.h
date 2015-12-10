#ifndef RENDEREDWINDOW_H
#define RENDEREDWINDOW_H

#include <QWidget>

namespace Ui {
class RenderedWindow;
}

class RenderedWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenderedWindow(QWidget *parent = 0);
    ~RenderedWindow();

    inline void SetImage(QImage image) const;

private:
    Ui::RenderedWindow *ui;
};

#endif // RENDEREDWINDOW_H
