#ifndef ARCHER_H
#define ARCHER_H

#include <QGraphicsItem>
#include <QPainter>

class Archer: public QGraphicsItem
{
private:

 // Aqui ponemos los atributos de archer como la vida, el nombre, ataque, si esta vivo o no.

public:
    Archer();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();

// Falta poner las funciones de archer que afectan sus atributos directos.

};

#endif // ARCHER_H
