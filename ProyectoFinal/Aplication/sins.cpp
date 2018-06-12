#include "sins.h"

Sins::Sins()
{

}

QRectF Sins::boundingRect() const
{
    if (condition == 4){
        return QRectF(0,0,200,250);
    }
    else if (condition == 3){
        return QRectF(0,0,180,230);
    }
    else if (condition == 5){
        // pixmap.load(":/EmiyaArcher_NewSprite2.png");
        return QRectF(40,0,120,180);
    }
    else if (condition == 6){
        // pixmap.load(":/EmiyaArcher_NewSprite3.png");
        return QRectF(0,0,180,180);
    }
    else if (condition == 7){
        // pixmap.load(":/Mhxsprite1.png");
        return QRectF(0,0,170,170);
    }
    else if (condition == 8){
        // pixmap.load(":/Mhxsprite3.png");
         return QRectF(0,0,200,170);
    }
    else{
        return QRectF(0,0,100,150);
    }

}

void Sins::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if (condition == 1){
        pixmap.load(":/assasins.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 2){
        pixmap.load(":/orgullo.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 3){
        pixmap.load(":/BerserkerV.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 4){
        pixmap.load(":/Lujuria.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 5){
        pixmap.load(":/EmiyaArcher_NewSprite2.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 6){
        pixmap.load(":/EmiyaArcher_NewSprite3.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 7){
        pixmap.load(":/Mhxsprite1.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    if (condition == 8){
        pixmap.load(":/Mhxsprite3.png");
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
    if (condition == 5){
        // pixmap.load(":/EmiyaArcher_NewSprite2.png");

        HP = 2000;

        armaP = 0;
        armaS = 1;
        armaKi = 0;

    }
    if (condition == 6){
        // pixmap.load(":/EmiyaArcher_NewSprite3.png");

        HP = 4000;
        MP = 1000;

        armaP = 0;
        armaS = 1;
        armaKi = 0;

    }
    if (condition == 7){
        // pixmap.load(":/Mhxsprite1.png");

        HP = 2000;

        armaP = 10;
        armaS = 11;
        armaKi = 5;

    }
    if (condition == 8){
        // pixmap.load(":/Mhxsprite3.png");

        HP = 4000;
        MP = 1000;

        armaP = 10;
        armaS = 11;
        armaKi = 5;

    }
}
