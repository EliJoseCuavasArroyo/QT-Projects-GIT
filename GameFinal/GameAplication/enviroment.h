#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <QDialog>

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include <string>
#include <fstream>
#include "archer.h"
#include "sins.h"
#include "stage.h"
#include "weapon.h"

using namespace std;

namespace Ui {
class Enviroment;
}

class Enviroment : public QDialog
{
    Q_OBJECT

signals:
    void aviso(int);

public:
    explicit Enviroment(QWidget *parent = 0);
    ~Enviroment();

    QGraphicsScene* scene;
    QTimer* timer;

    // Personajes:
    Archer *heroe = new Archer [1];
    Sins *ban = new Sins [1];
    Sins *orgullo = new Sins [1];
    Sins *ira = new Sins [1];

    // Armas:
    Weapon *espada = new Weapon [1];

public slots:
    void animacion();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Enviroment *ui;
};

#endif // ENVIROMENT_H






