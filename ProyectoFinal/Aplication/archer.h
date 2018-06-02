#ifndef ARCHER_H
#define ARCHER_H

#include <QGraphicsItem>
#include <QPainter>

class Archer: public QGraphicsItem
{
private:

    int movement = 0;

    // Aqui ponemos los atributos de archer como la vida, el nombre, ataque, si esta vivo o no.


    bool life = true;

    int HP = 2000;
    int MP = 500;

    int armaP = 0;
    int armaS = 1;
    int armaKi;
    int Heal;


public:
    Archer();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();

// Falta poner las funciones de archer que afectan sus atributos directos.

    bool getLife() const;
    void setLife();

    int getHP();
    int getMP() const;

    void cure(); // Cura usando Ki

    int getArmaP() const;
    int getArmaS();
    int getArmaKi();

    void TakeDamage(int damage);


};

#endif // ARCHER_H
