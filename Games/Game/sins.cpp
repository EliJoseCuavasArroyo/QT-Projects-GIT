#include "sins.h"

Sins::Sins()
{

}

QRectF Sins::boundingRect() const
{
    return QRectF(0,0,200,300);
}

void Sins::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (condition == 1){
        QPixmap pixmap;
        pixmap.load(":/Avaricia.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        QPixmap pixmap;
        pixmap.load(":/orgullo.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        QPixmap pixmap;
        pixmap.load(":/berserker.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        QPixmap pixmap;
        pixmap.load(":/archer.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }

}

void Sins::mover()
{
    // Movimiento
    if(movement < 5)
    {
        setPos(x()-0.5,y()+1);
        movement++;
    }
    else if ((5 <= movement)&&(movement < 10))
    {
        setPos(x()+0.5,y()-1);
        movement++;
    }

    if (movement == 10)
    {
         movement = 0;
    }
}

void Sins::setCondition(int number)
{
    condition = number;
}
