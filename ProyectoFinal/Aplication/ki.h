#ifndef KI_H
#define KI_H

#include <QGraphicsItem>
#include <QPainter>


#include <iostream>

using namespace std;

class Ki: public QGraphicsItem
{
private:

    int condition;
    float v_y = 25;
    float v_x = 8;
    int damage;
    // Flata poner los atributos directos del arma.

public:
    Ki();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void movimiento();
    void setCondition(int number);
    int getCondition();

    // Falta poner los atributos de Ki que afectan a sus atributos propios.
    int getDamage();
    void setDamage();

};

#endif // KI_H
