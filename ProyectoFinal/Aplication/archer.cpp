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

// Atributos de Archer

bool Archer::getLife() const
{
    return life;
}

void Archer::setLife()
{
    if (HP > 0)
    {
        life = true;
    }
    else
    {
        life = false;
    }
}

int Archer::getHP()
{
    return HP;
}

int Archer::getMP() const
{
    return MP;
}

void Archer::cure()
{
    int curing = 0;
    while (HP < 2000){
        HP = HP+1;
        curing = curing+1;
        if (curing == 500) break;
    }

    MP = MP-80;
}

int Archer::getArmaP() const
{
    return armaP;
}

int Archer::getArmaS()
{
    MP = MP-120;
    return armaS;
}

void Archer::TakeDamage(int damage)
{
    HP = HP - damage;
}


int Archer::getArmaKi()
{
    MP = MP-150;
    return armaKi;
}

