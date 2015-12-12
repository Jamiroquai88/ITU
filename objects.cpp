#include "objects.h"

void Object::set_values(int nsize, QPoint ncenter)
{
    size = nsize;
    center = ncenter;
}

Object::Object()
{
        setFlag(ItemIsMovable);
}

QRectF Object::boundingRect() const
{
    return QRectF(center.x(),center.y(),size*2,size*2);
}



void Object::change_colour(QColor new_color)
{
    color = new_color;
    return;
}

void Object::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setScale(-1);
    update();
    QGraphicsItem::mousePressEvent(event);
}


void Cube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    painter->drawRect(rec);
    //setScale(0.0);
}
