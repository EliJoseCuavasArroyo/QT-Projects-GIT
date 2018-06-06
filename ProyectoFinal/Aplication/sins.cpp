#include "sins.h"

Sins::Sins()
{

}

QRectF Sins::boundingRect() const
{
    if (condition == 4){
        return QRectF(0,0,200,250);
    }
    else{
        return QRectF(0,0,100,150);
    }

}

void Sins::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if (condition == 1){
        pixmap.load(":/Avaricia.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        pixmap.load(":/orgullo.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        pixmap.load(":/berserker.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        pixmap.load(":/Lujuria.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }

}

int Sins::getHP() const
{
    return HP;
}

int Sins::getArmaP() const
{
    return armaP;
}

int Sins::getArmaS()
{
    MP = MP-100;
    return armaS;
}

int Sins::getArmaKi()
{
    MP = MP-250;
    return armaKi;
}

int Sins::getMP() const
{
    return MP;
}

void Sins::TakeDamage(int damage)
{
    HP = HP - damage;
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

void Sins::setArmasAndHp()
{
    if (condition == 1){

        // Ban ready
        HP = 3000;
        armaP = 4;
        armaS = 2;
        armaKi = 1;

    }
    if (condition == 2){

        // Orgullo
        HP = 3500;
        armaP = 5;
        armaS = 9;
        armaKi = 3;

    }
    if (condition == 3){

        // Ira
        HP = 4000;
        armaP = 6;
        armaS = 3;
        armaKi = 2;

    }
    if (condition == 4){

        // Lujuria
        HP = 3000;
        armaP = 7;
        armaS = 8;
        armaKi = 4;

    }
}
