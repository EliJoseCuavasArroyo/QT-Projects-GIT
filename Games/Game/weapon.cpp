#include "weapon.h"

Weapon::Weapon()
{

}

QRectF Weapon::boundingRect() const
{
    return QRectF(0,0,150,150);
}

void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (condition == 0){
        QPixmap pixmap;
        pixmap.load(":/KanshouYBakuya.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 1){
        QPixmap pixmap;
        pixmap.load(":/Kanshou_y_Bakuya_Overedge.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        QPixmap pixmap;
        pixmap.load(":/Espada0.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        QPixmap pixmap;
        pixmap.load(":/Espada1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        QPixmap pixmap;
        pixmap.load(":/Espada3.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void Weapon::movimiento()
{
    if (condition == 0){
        setPos(x()+velocity*(0.1),y());
    }
    if (condition == 1){
        setPos(x()+velocity*(0.1)+(10)*(0.1)*(0.1)*(1/2),y());
    }
    if (condition == 2){
        setPos(x()-velocity*(0.1)-(10)*(0.1)*(0.1)*(1/2),y()-velocity*(0.1)-(10)*(0.1)*(0.1)*(1/2));
    }
    if (condition == 3){
        setPos(x()-velocity*(0.1)-(10)*(0.1)*(0.1)*(1/2),y()-velocity*(0.1)-(10)*(0.1)*(0.1)*(1/2));
    }
    if (condition == 4){
        setPos(x()-velocity*(0.1)-(10)*(0.1)*(0.1)*(1/2),y());
    }

    // velocity = velocity + (10)*(0.1);

    if (velocity > 900){
        velocity = 40;
    }

}

void Weapon::setCondition(int number)
{
    condition = number;
}
