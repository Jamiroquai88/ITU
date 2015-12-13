#ifndef OBJECTS_H
#define OBJECTS_H
#include <string>
#include <fstream>
#include <cstdio>
#include <QPoint>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QtMath>

using namespace std;

class Object : public QGraphicsItem {
protected:
    int m_size;
    QPoint m_center;
    int m_refl, m_gamma , m_z;
    QColor m_color;
    QPen m_pen;
public:
    Object();
    void setValues(int nsize, QPoint nm_center);
    void changeColour(QColor new_color);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};


class Cube : public Object {
private:
    QPoint m_points[8];
public:
   // Cube(int size, QPoint m_center);
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



#endif // OBJECTS_H
