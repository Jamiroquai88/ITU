#ifndef OBJECTS_H
#define OBJECTS_H
#include <string>
#include <QtGui>
#include <QtCore>
#include <fstream>
#include <cstdio>
#include <QPoint>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QtMath>
#include <QList>
#include <typeinfo>

namespace Ui {
class MainWindow;
}

enum cols {Black, Red, Green, Blue};

using namespace std;

class Object : public QGraphicsItem {
protected:
    Ui::MainWindow *m_ui;
    int m_size;
    QPoint m_center;
    int m_refl, m_gamma , m_z;
    QColor m_color;
    QPen m_pen;
    QString m_name;
public:
    Object();
    void setValues(int nsize, QPoint nm_center,  Ui::MainWindow *ui, string name);
    void changeColour(QColor new_color);
    void setSize(int val);
    void setName(QString name);
    void setGamma(int val);
    void setRefl(int val);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};


class Cube : public Object {
private:
    QPoint m_points[8];
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

class Sphere : public Object {
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

class Plain: public Object {
private:
    QPoint m_points[4];
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

class Light : public Object {
private:
    int lightPower;
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPower(int val);
    QRectF boundingRect() const;
};

#endif // OBJECTS_H
