#ifndef TWOPLAYERS_H
#define TWOPLAYERS_H

#include <QDialog>

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include <time.h>
#include <string>
#include <fstream>
#include "archer.h"
#include "sins.h"
#include "enviroment.h"
#include "stage1.h"
#include "weapon.h"
#include "ki.h"

namespace Ui {
class TwoPlayers;
}

class TwoPlayers : public QDialog
{
    Q_OBJECT

private:

    Ui::TwoPlayers *ui;

    bool turno; // Turno del Heroe (1) ; Turno del Pecado (0)
    bool animation; // Se esta animando una accion (1) ; De lo contrario (0)
    bool animationKi; // En el caso de que se animando un ataque con KI puro (1) ; De lo contrario (0)

    bool ArcherInstall;
    bool SaberInstall;

signals:
    void aviso(int);

public:
    explicit TwoPlayers(QWidget *parent = 0);
    ~TwoPlayers();
    QGraphicsScene* scene;
    QTimer* timer;

    // Personajes:
    Sins *heroe = new Sins [1];
    Sins *ban = new Sins [1];

    // Armas:
    Weapon *espada = new Weapon [1];
    Ki *Final_Ki = new Ki [1];

    void setTurno(bool value);

    void setAnimation(bool value);

    void setAnimationKi(bool value);

    void setArcherInstall(bool value);

    void setSaberInstall(bool value);

public slots:

    void BattleRoyal();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
};

#endif // TWOPLAYERS_H
