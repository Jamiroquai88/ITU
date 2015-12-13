#include "objects.h"

void Object::setValues(int nsize, QPoint ncenter)
{
    m_size = nsize;
    m_center = ncenter;
}

Object::Object()
{
        setFlag(ItemIsMovable);
        setFlag(ItemIsSelectable);
        m_pen.setCosmetic(true);
}



void Object::changeColour(QColor new_color)
{
    m_color = new_color;
    return;
}

void Object::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);

    // Check the bounds of scene.
    /*if (x() < 0) {
        setPos(0, y());
    }
    else if (x() + boundingRect().right() > scene()->width()) {
        setPos(scene()->width() - boundingRect().width(), y());
    }

    if (y() < 0) {
        setPos(x(), 0);
    }
    else if ( y()+ boundingRect().bottom() > scene()->height()) {
        setPos(x(), scene()->height() - boundingRect().height());
    }*/
}

void Object::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->isSelected()) {
        this->setSelected(false);
        m_color.setNamedColor("#000"); // Unselected -> black color.
    }
    else {
        this->setSelected(true);
        m_color.setNamedColor("#FF0"); // Selected -> yellow color.
    }

    update();

    QGraphicsItem::mousePressEvent(event);
}


void Cube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPoint p;

    int halfSize = m_size / 2;

    // Point A.
    p.setX(m_center.x() + m_size);
    p.setY(m_center.y() - m_size);
    m_points[0] = p;

    // Point B.
    p.setX(m_center.x() - m_size);
    p.setY(m_center.y() - m_size);
    m_points[1] = p;

    // Point C.
    p.setX(m_center.x() - (m_size * 1.5));
    p.setY(m_center.y() - halfSize);
    m_points[2] = p;

    // Point D.
    p.setX(m_center.x() + halfSize);
    p.setY(m_center.y() - halfSize);
    m_points[3] = p;

    // Point E.
    p.setX(m_center.x() + m_size);
    p.setY(m_center.y() + m_size);
    m_points[4] = p;

    // Point F.
    p.setX(m_center.x() - m_size);
    p.setY(m_center.y() + m_size);
    m_points[5] = p;

    // Point G.
    p.setX(m_center.x() - (m_size * 1.5));
    p.setY(m_center.y() + (m_size * 1.5));
    m_points[6] = p;

    // Point H.
    p.setX(m_center.x() + halfSize);
    p.setY(m_center.y() + (m_size * 1.5));
    m_points[7] = p;

    m_pen.setColor(m_color);
    painter->setPen(m_pen);

    painter->drawLine(m_points[0], m_points[1]);
    painter->drawLine(m_points[0], m_points[3]);
    painter->drawLine(m_points[0], m_points[4]);
    painter->drawLine(m_points[1], m_points[2]);
    painter->drawLine(m_points[1], m_points[5]);
    painter->drawLine(m_points[2], m_points[3]);
    painter->drawLine(m_points[2], m_points[6]);
    painter->drawLine(m_points[3], m_points[7]);
    painter->drawLine(m_points[4], m_points[5]);
    painter->drawLine(m_points[4], m_points[7]);
    painter->drawLine(m_points[5], m_points[6]);
    painter->drawLine(m_points[6], m_points[7]);
    //setScale(0.0);
}

QRectF Cube::boundingRect() const
{
    return QRectF(m_center.x() - m_size*1.5,m_center.y() - m_size, m_size*2.5, m_size*2.5);
}

void Sphere::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    m_pen.setColor(m_color);
    painter->setPen(m_pen);

    int minorAxis = m_size / 3;

    painter->drawEllipse(m_center.x() - m_size, m_center.y() - m_size, m_size * 2, m_size * 2);
    painter->drawEllipse(m_center.x() - m_size, m_center.y() - (minorAxis / 2) , m_size * 2, minorAxis);
    painter->drawEllipse(m_center.x() - (minorAxis), m_center.y() - m_size , minorAxis * 2, m_size * 2);
}

QRectF Sphere::boundingRect() const
{
    return QRectF(m_center.x() - m_size,m_center.y() - m_size, m_size*2, m_size*2);
}

void Plain::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPoint p;

    // Point A.
    p.setX(m_center.x() - (m_size * 3));
    p.setY(m_center.y() + m_size);
    m_points[0] = p;

    // Point B.
    p.setX(m_center.x() + m_size);
    p.setY(m_center.y() + m_size);
    m_points[1] = p;

    // Point C.
    p.setX(m_center.x() + (m_size * 3));
    p.setY(m_center.y() - m_size);
    m_points[2] = p;

    // Point D.
    p.setX(m_center.x() - m_size);
    p.setY(m_center.y() - m_size);
    m_points[3] = p;

    m_pen.setColor(m_color);
    painter->setPen(m_pen);

    painter->drawLine(m_points[0], m_points[1]);
    painter->drawLine(m_points[0], m_points[3]);;
    painter->drawLine(m_points[1], m_points[2]);
    painter->drawLine(m_points[2], m_points[3]);
}

QRectF Plain::boundingRect() const
{
    return QRectF(m_center.x() - (m_size * 3),m_center.y() - m_size, m_size*6, m_size*2);
}
