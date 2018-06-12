#include "ki.h"

Ki::Ki()
{

}

QRectF Ki::boundingRect() const
{
    if (condition == 5){
        return QRectF(20,30,120,50);
    }
    else{
        return QRectF(0,0,140,120);
    }

}

void Ki::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if (condition == 0){
        pixmap.load(":/Ki_prota.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 1){
        pixmap.load(":/Ki_azul.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        pixmap.load(":/Ki_ira.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        pixmap.load(":/Ki_orgullo.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        pixmap.load(":/Ki_lujuria.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 5){
        pixmap.load(":/Blue_excalibur.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void Ki::movimiento()
{
    if (condition == 0){
        setPos(x() + v_x, y() + (v_y*0.8) + ((-9.8*0.01)/2));
        v_y += (-9.8*0.1);
    }
    if (condition == 1){
        setPos(x() - v_x, y() + (v_y*0.8) + ((-9.8*0.01)/2));
        v_y += (-9.8*0.1);
    }
    if (condition == 2){
        setPos(x() - v_x, y() + (v_y*0.8) + ((-9.8*0.01)/2));
        v_y += (-9.8*0.1);
    }
    if (condition == 3){
        setPos(x() - v_x, y() + (v_y*0.8) + ((-9.8*0.01)/2));
        v_y += (-9.8*0.1);
    }
    if (condition == 4){
        setPos(x() - v_x, y() + (v_y*0.8) + ((-9.8*0.01)/2));
        v_y += (-9.8*0.1);
    }
    if (condition == 5){
        setPos(x()-10,y());
    }
}

void Ki::setCondition(int number)
{
    condition = number;
}

int Ki::getCondition()
{
    return condition;
}

int Ki::getDamage()
{
    return damage;
}

void Ki::setDamage()
{
    v_y = 25;
    v_x = 8;

    if (condition == 0){
        // pixmap.load(":/Ki_prota.png");
        damage = 500;
    }
    if (condition == 1){
        // pixmap.load(":/Ki_azul.png");
        damage = 300;
    }
    if (condition == 2){
        // pixmap.load(":/Ki_ira.png");
        damage = 500;
    }
    if (condition == 3){
        // pixmap.load(":/Ki_orgullo.png");
        damage = 450;
    }
    if (condition == 4){
        // pixmap.load(":/Ki_lujuria.png");
        damage = 600;
    }
    if (condition == 5){
        // pixmap.load(":/Blue_excalibur.png");
        damage = 500;
    }
}

