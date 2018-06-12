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
        return QRectF(20,0,100,100);
    }
    else if (condition == 3){
        return QRectF(0,0,120,120);
    }
    else if (condition == 4){
        return QRectF(0,0,80,40);
    }
    else if (condition == 5){
        return QRectF(0,0,100,80);
    }
    else if (condition == 7){
        return QRectF(0,0,200,150);
    }
    else if (condition == 8){
        return QRectF(50,0,150,150);
    }
    else if (condition == 9){
        return QRectF(0,0,120,120);
    }
    else if (condition == 10){
        return QRectF(20,30,120,50);
    }
    else if (condition == 11){
       return QRectF(20,30,120,50);
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
        pixmap.load(":/assasinsword.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        pixmap.load(":/swordberserker.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        pixmap.load(":/knife.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 5){
        pixmap.load(":/EspadasDoradas.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 6){
        pixmap.load(":/Arondight.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 7){
        pixmap.load(":/rayoDeKi.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 8){
        pixmap.load(":/isthar.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 9){
        pixmap.load(":/LanzaDorada.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 10){
        pixmap.load(":/Excalibur.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 11){
        pixmap.load(":/yellow_excalibur.png");
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
    if (condition == 10){
       setPos(x()-velocity,y());
    }
    if (condition == 11){
        setPos(x()-velocity,y());
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
        // pixmap.load(":/assasinsword.png");
        damage = 180;
    }
    if (condition == 3){
        // pixmap.load(":/swordberserker.png");
       damage = 250;
    }
    if (condition == 4){
        // pixmap.load(":/knife.png");
        damage = 80;
    }
    if (condition == 5){
        // pixmap.load(":/EspadasDoradas.png");
        damage = 130;
    }
    if (condition == 6){
        // pixmap.load(":/Arondight.png");
        damage = 140;
    }
    if (condition == 7){
        // pixmap.load(":/rayoDeKi.png");
        damage = 150;
    }
    if (condition == 8){
        // pixmap.load(":/isthar.png");
        damage = 280;
    }
    if (condition == 9){
        // pixmap.load(":/LanzaDorada.png");
        damage = 190;
    }
    if (condition == 10){
        // pixmap.load(":/Excalibur.png");
        damage = 100;
    }
    if (condition == 11){
       // pixmap.load(":/yellow_excalibur.png");
        damage = 210;
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

