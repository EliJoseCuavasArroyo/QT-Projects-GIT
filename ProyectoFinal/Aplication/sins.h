#ifndef SINS_H
#define SINS_H

#include <QGraphicsItem>
#include <QPainter>

class Sins: public QGraphicsItem
{
private:

    int condition;
    int movement = 0;
 // Aqui ponemos los atributos de archer como la vida, el nombre, ataque, si esta vivo o no.

public:
    Sins();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void setCondition(int number);

// Falta poner las funciones de archer que afectan sus atributos directos.
};

#endif // SINS_H
