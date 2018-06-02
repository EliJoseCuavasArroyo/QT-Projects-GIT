#ifndef STAGE1_H
#define STAGE1_H

#include <QDialog>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "archer.h"
#include "sins.h"
#include "enviroment.h"
#include "stage1.h"
#include "weapon.h"

namespace Ui {
class Stage1;
}

class Stage1 : public QDialog
{
    Q_OBJECT
private:

    bool turno; // Turno del Heroe (1) ; Turno del Pecado (0)
    bool animation; // Se esta animando una accion (1) ; De lo contrario (0)

    int valueHP = 100;
    int valueMP = 100;

signals:
    void aviso(int);

public:
    explicit Stage1(QWidget *parent = 0);
    ~Stage1();

    QGraphicsScene* scene;
    QTimer* timer;

    // Personajes:
    Archer *heroe = new Archer [1];
    Sins *ban = new Sins [1];
   // Sins *orgullo = new Sins [1];
   // Sins *ira = new Sins [1];

    // Armas:
    Weapon *espada = new Weapon [1];

    bool getTurno() const;
    void setTurno(bool value);

    bool getAnimation() const;
    void setAnimation(bool value);

public slots:
    void BattleRoyal();

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Stage1 *ui;
};

#endif // STAGE1_H

