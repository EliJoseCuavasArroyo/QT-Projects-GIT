#include "weapon.h"

Weapon::Weapon()
{

}

QRectF Weapon::boundingRect() const
{
    if ( condition == 6){
        return QRectF(0,0,120,50);
    }
    else if (condition == 2){
        return QRectF(0,0,100,100);
    }
    else if (condition == 3){
        return QRectF(0,0,120,120);
    }
    else if (condition == 4){
        return QRectF(0,0,100,100);
    }
    else if (condition == 5){
        return QRectF(0,0,100,30);
    }
    else if (condition == 7){
        return QRectF(0,0,100,100);
    }
    else if (condition == 9){
        return QRectF(0,0,120,120);
    }
    else{
        return QRectF(0,0,80,80);
    }
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
    if (condition == 5){
        pixmap.load(":/ArmaDorada.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 6){
        pixmap.load(":/Berserker_espada1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 7){
        pixmap.load(":/flecha_guerra.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 8){
        pixmap.load(":/FlechaDorada.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 9){
        pixmap.load(":/LanzaDorada.png");
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
    if (condition == 5){
        setPos(x()-velocity,y());
    }
    if (condition == 6){
       setPos(x()-velocity,y());
    }
    if (condition == 7){
        setPos(x()-velocity,y());
    }
    if (condition == 8){
       setPos(x()-velocity,y()-velocity);
    }
    if (condition == 9){
        setPos(x()-velocity,y()-velocity);
    }

}

int Weapon::getDamage()
{
    return damage;
}

void Weapon::setDamage()
{
    if (condition == 0){
        // pixmap.load(":/KanshouYBakuya.png");
        damage = 100;
    }
    if (condition == 1){
        // pixmap.load(":/Kanshou_y_Bakuya_Overedge.png");
        damage = 210;
    }
    if (condition == 2){
        // pixmap.load(":/Espada0.png");
        damage = 120;
    }
    if (condition == 3){
        // pixmap.load(":/Espada1.png");
       damage = 250;
    }
    if (condition == 4){
        // pixmap.load(":/Espada3.png");
        damage = 80;
    }
    if (condition == 5){
        // pixmap.load(":/ArmaDorada.png");
        damage = 80;
    }
    if (condition == 6){
        // pixmap.load(":/Berserker_espada1.png");
        damage = 80;
    }
    if (condition == 7){
        // pixmap.load(":/flecha_guerra.png");
        damage = 80;
    }
    if (condition == 8){
        // pixmap.load(":/FlechaDorada.png");
        damage = 80;
    }
    if (condition == 9){
        // pixmap.load(":/LanzaDorada.png");
        damage = 80;
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
