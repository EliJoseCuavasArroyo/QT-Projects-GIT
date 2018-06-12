#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsItem>
#include <QPainter>

class Weapon: public QGraphicsItem
{
private:

    int condition;
    float velocity = 10;
    int damage;
    // Flata poner los atributos directos del arma.

public:
    Weapon();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void movimiento();
    void setCondition(int number);
    int getCondition();

    // Falta poner los atributos de Weapon que afectan a sus atributos propios.
    int getDamage();
    void setDamage();
};

#endif // WEAPON_H
