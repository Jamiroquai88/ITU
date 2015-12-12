#ifndef OBJECTS_H
#define OBJECTS_H
#include <string>
#include <fstream>
#include <cstdio>
#include <QPoint>
#include <QColor>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

using namespace std;

class Object : public QGraphicsItem {
private:
    int size;
    QPoint center;
    int refl, gamma ,z;
    QColor color;
public:
    Object();
    QRectF boundingRect() const;
    void set_values(int nsize, QPoint ncenter);
    void change_colour(QColor new_color);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


class Cube : public Object {
private:
    QPoint points[8];
public:
   // Cube(int size, QPoint center);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};



#endif // OBJECTS_H
