#include "esfera.h"

Esfera::Esfera()
{

}

QRectF Esfera::boundingRect() const
{
    return QRectF(0, 0,2*radio,2*radio);
}

void Esfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void Esfera::mover()
{
 //   V = sqrt((pow(Vx, 2))+(pow(Vy, 2)));
 //   Ay = (K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vy*radio*radio*(1/masa))+9.8;
 //   Ax = (K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vx*radio*radio*(1/masa));

    if ((y() > 0.1)||(Vy > 0)){
    //    setPos(x()+Vx*(0.1), y()+(Vy)*(0.1)-(9.8)*(0.1)*(0.1)*(0.5));

                setPos(x()+((Vx)*(0.1))-((K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vx*radio*radio*(1/masa))*(0.1)*(0.1)*(0.5)), y()+((Vy)*(0.1))-(((K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vy*radio*radio*(1/masa))+9.8)*(0.1)*(0.1)*(0.5)));
      //  Vy = Vy-(9.8)*(0.1);
               Vy = Vy-((K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vy*radio*radio*(1/masa))+9.8)*(0.1);
               Vx = Vx-(K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vx*radio*radio*(1/masa))*(0.1);
    }
    else{
     //   setPos(x()+Vx*(0.1), y());
            setPos(x()+((Vx)*(0.1))-((K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vx*radio*radio*(1/masa))*(0.1)*(0.1)*(0.5)), y());
             Vx = Vx-(K*(sqrt((pow(Vx, 2))+(pow(Vy, 2))))*Vx*radio*radio*(1/masa))*(0.1);
   }

}

void Esfera::choqueX()
{
    Vx = (-1)*(e)*Vx;
}

void Esfera::choqueY()
{
    Vy = (-1)*(e)*Vy;
}

void Esfera::setDatos()
{
    srand(time(NULL));

    float num;

    num = rand()%(300);
    Vx = (num);

    num = rand()%(300);
    Vy = (num);

    num = 5+rand()%(31-5);
    radio = num;

    num = 50+rand()%(601-50);
    masa = num;

    num = 50+rand()%(101-50);
    e = (num*(0.01));

    num = rand()%(11);
    K = (num*(0.001));

    cout << "K" << K << endl;
    cout << "e" << e << endl;
}


