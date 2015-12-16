#ifndef RENDEREDWINDOW_H
#define RENDEREDWINDOW_H

#include <QWidget>
#include <QGraphicsScene>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::RenderedWindow *ui;
    QGraphicsScene *m_pimageScene;

    void mousePressEvent(QMouseEvent *event);
    void ShowContextMenu(const QPoint& pos);
    void onCustomContextMenu(const QPoint &point);
    QString m_workDir;
};

#endif // RENDEREDWINDOW_H
