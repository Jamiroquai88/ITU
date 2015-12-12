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
protected:
    int size;
    QPoint center;
    int refl, gamma ,z;
    QColor color;
public:
    Object();
    void setValues(int nsize, QPoint ncenter);
    void changeColour(QColor new_color);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


class Cube : public Object {
private:
    QPoint points[8];
public:
   // Cube(int size, QPoint center);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};



#endif // OBJECTS_H
