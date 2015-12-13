#include "objects.h"
#include "mainwindow.h"

void Object::setValues(int nsize, QPoint ncenter,  Ui::MainWindow *ui, string name)
{
    m_size = nsize;
    m_center = ncenter;
    m_ui = ui;
    m_name = QString::fromStdString(name);;
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
}

QColor Object::getColor()
{
    return m_color;
}

void Object::setSize(int val)
{
    m_size = val;
}

void Object::setName(QString name)
{
    m_name = name;
}

void Object::setGamma(int val)
{
    m_gamma = val;
}

void Object::setRefl(int val)
{
    m_refl = val;
}

void Object::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);

    // Check the bounds of scene.
    /*if (x() < -(scene()->width())) {
        setPos(0, y() - scene()->height());
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
    QList<QGraphicsItem *> items(scene()->selectedItems());
    QList<QGraphicsItem *>::iterator it;
    Object *object;

    for(it = items.begin(); it != items.end(); ++it) {
       object = static_cast<Object *>(*it);
       object->changeColour(object->getColor());
    }
    scene()->clearSelection();

    this->setSelected(true);
    m_ui->objectParams->show();
    m_ui->nameEdit->setText(m_name);
    if(m_color.name()=="#000000") m_ui->colorBox->setCurrentIndex(0);
    else if(m_color.name()=="#FF0000") m_ui->colorBox->setCurrentIndex(1);
    else if(m_color.name()=="#00FF00") m_ui->colorBox->setCurrentIndex(2);
    else if(m_color.name()=="#0000FF") m_ui->colorBox->setCurrentIndex(3);
    if(typeid(*this)==typeid(Light))
    {
        m_ui->sizeSlider->setValue(m_size);
        m_ui->sizeLabel->setText("Light Power");
        m_ui->sizeSlider->setValue(m_size);
        m_ui->gammaLabel->hide();
        m_ui->gammaSlider->hide();
        m_ui->reflLabel->hide();
        m_ui->reflSlider->hide();
    }
    else
    {
        m_ui->sizeLabel->setText("Size");
        m_ui->sizeSlider->setValue(m_size);
        m_ui->gammaSlider->setValue(m_gamma);
        m_ui->reflSlider->setValue(m_refl);
        m_ui->gammaLabel->show();
        m_ui->gammaSlider->show();
        m_ui->reflLabel->show();
        m_ui->reflSlider->show();
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

    if(this->isSelected()) {
        m_pen.setColor(QColor("yellow"));
    }
    else {
        m_pen.setColor(m_color);
    }
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
    if(this->isSelected()) {
        m_pen.setColor(QColor("yellow"));
    }
    else {
        m_pen.setColor(m_color);
    }
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

    if(this->isSelected()) {
        m_pen.setColor(QColor("yellow"));
    }
    else {
        m_pen.setColor(m_color);
    }
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

void Light::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isSelected()) {
        m_pen.setColor(QColor("yellow"));
    }
    else {
        m_pen.setColor(m_color);
    }
    painter->setPen(m_pen);

    int size = m_size / 6;
    int halfSize = size / qSqrt(2);
    halfSize *= 1.6;

    painter->drawEllipse(m_center.x() - size, m_center.y() - size, size * 2, size * 2);
    painter->drawLine(m_center.x() - (size * 1.5), m_center.y(), m_center.x() - (size * 2.5), m_center.y());
    painter->drawLine(m_center.x() + (size * 1.5), m_center.y(), m_center.x() + (size * 2.5), m_center.y());
    painter->drawLine(m_center.x(), m_center.y() + (size * 1.5), m_center.x(), m_center.y() + (size * 2.5));
    painter->drawLine(m_center.x(), m_center.y() - (size * 1.5), m_center.x(), m_center.y() - (size * 2.5));
    painter->drawLine(m_center.x() - size, m_center.y() + halfSize, m_center.x() - (size * 2), m_center.y() + (size * 2));
    painter->drawLine(m_center.x() - size, m_center.y() - halfSize, m_center.x() - (size * 2), m_center.y() - (size * 2));
    painter->drawLine(m_center.x() + size, m_center.y() - halfSize, m_center.x() + (size * 2), m_center.y() - (size * 2));
    painter->drawLine(m_center.x() + size, m_center.y() + halfSize, m_center.x() + (size * 2), m_center.y() + (size * 2));
}

void Light::setPower(int val)
{
    m_lightPower = val;
}

QRectF Light::boundingRect() const
{
    int size = m_size / 6;
    return QRectF(m_center.x() - size,m_center.y() - size, size*2, size*2);
}
