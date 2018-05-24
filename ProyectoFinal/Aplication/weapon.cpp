#include "weapon.h"

Weapon::Weapon()
{

}

QRectF Weapon::boundingRect() const
{
    return QRectF(0,0,80,80);
}

void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if (condition == 0){
        pixmap.load(":/KanshouYBakuya.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 1){
        pixmap.load(":/Kanshou_y_Bakuya_Overedge.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        pixmap.load(":/Espada0.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        pixmap.load(":/Espada1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        pixmap.load(":/Espada3.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void Weapon::movimiento()
{
    if (condition == 0){
        setPos(x()+velocity,y());
    }
    if (condition == 1){
        setPos(x()+velocity,y());
    }
    if (condition == 2){
        setPos(x()-velocity,y()-velocity);
    }
    if (condition == 3){
        setPos(x()-velocity,y()-velocity);
    }
    if (condition == 4){
        setPos(x()-velocity,y());
    }

}

void Weapon::setCondition(int number)
{
    condition = number;
}

int Weapon::getCondition()
{
    return condition;
}
