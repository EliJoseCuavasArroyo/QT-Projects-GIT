#ifndef ESFERA_H
#define ESFERA_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <time.h>
#include <math.h>

#include <iostream>

using namespace std;

class Esfera: public QGraphicsItem
{
public:
    Esfera();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mover();
    void choqueX();
    void choqueY();

    void setDatos();

private:

    float radio;
    float masa;

    float Vx;
    float Vy;

    float e; // coeficioente de restitucion
    float K; // coeficiente de friccion



};

#endif // ESFERA_H
