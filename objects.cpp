#include "objects.h"

void Object::setValues(int nsize, QPoint ncenter)
{
    size = nsize;
    center = ncenter;
}

Object::Object()
{
        setFlag(ItemIsMovable);
}



void Object::changeColour(QColor new_color)
{
    color = new_color;
    return;
}

/*void Object::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setScale(-0.2);
    update();
    QGraphicsItem::mousePressEvent(event);
}*/


void Cube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPoint p;

    // Point A.
    p.setX(center.x() + size);
    p.setY(center.y() - size);
    points[0] = p;

    // Point B.
    p.setX(center.x() - size);
    p.setY(center.y() - size);
    points[1] = p;

    // Point C.
    p.setX(center.x() - (size * 1.5));
    p.setY(center.y() - (size / 2));
    points[2] = p;

    // Point D.
    p.setX(center.x() + (size / 2));
    p.setY(center.y() - (size / 2));
    points[3] = p;

    // Point E.
    p.setX(center.x() + size);
    p.setY(center.y() + size);
    points[4] = p;

    // Point F.
    p.setX(center.x() - size);
    p.setY(center.y() + size);
    points[5] = p;

    // Point G.
    p.setX(center.x() - (size * 1.5));
    p.setY(center.y() + (size * 1.5));
    points[6] = p;

    // Point H.
    p.setX(center.x() + (size / 2));
    p.setY(center.y() + (size * 1.5));
    points[7] = p;

    painter->drawLine(points[0], points[1]);
    painter->drawLine(points[0], points[3]);
    painter->drawLine(points[0], points[4]);
    painter->drawLine(points[1], points[2]);
    painter->drawLine(points[1], points[5]);
    painter->drawLine(points[2], points[3]);
    painter->drawLine(points[2], points[6]);
    painter->drawLine(points[3], points[7]);
    painter->drawLine(points[4], points[5]);
    painter->drawLine(points[4], points[7]);
    painter->drawLine(points[5], points[6]);
    painter->drawLine(points[6], points[7]);
    //setScale(0.0);
}

QRectF Cube::boundingRect() const
{
    return QRectF(center.x() - size*1.5,center.y() - size, size*2.5, size*2.5);
}
