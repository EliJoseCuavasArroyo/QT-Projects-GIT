#include "archer.h"

Archer::Archer()
{

}

QRectF Archer::boundingRect() const
{
     return QRectF(0,0,100,100);
}

void Archer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/archer.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

void Archer::mover()
{
    setPos(x()+1,y()+1);
}
