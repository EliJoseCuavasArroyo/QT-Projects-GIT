#ifndef SINS_H
#define SINS_H

#include <QGraphicsItem>
#include <QPainter>

class Sins: public QGraphicsItem
{
private:

    int condition;
    int movement = 0;

    int HP;
    int MP = 1000;

    int armaP;
    int armaS;
    int armaKi;

 // Aqui ponemos los atributos de archer como la vida, el nombre, ataque, si esta vivo o no.

public:
    Sins();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void setCondition(int number);

// Falta poner las funciones de archer que afectan sus atributos directos.
    void setArmasAndHp();

    int getHP() const;
    int getMP() const;

    int getArmaP() const;
    int getArmaS();
    int getArmaKi();

    void TakeDamage(int damage);
};

#endif // SINS_H
