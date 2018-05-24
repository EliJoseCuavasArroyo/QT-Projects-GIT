#include "archer.h"

Archer::Archer()
{

}

QRectF Archer::boundingRect() const
{
     return QRectF(0,0,150,150);
}

void Archer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/archer.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

void Archer::mover()
{
    // Movimiento.
    if(movement < 5)
    {
        setPos(x()+0.5,y()+1);
        movement++;
    }
    else if ((5 <= movement)&&(movement < 10))
    {
        setPos(x()-0.5,y()-1);
        movement++;
    }

    if (movement == 10)
    {
         movement = 0;
    }
}
