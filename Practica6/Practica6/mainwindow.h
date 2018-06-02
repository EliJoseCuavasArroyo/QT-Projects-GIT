#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "esfera.h"

#include <time.h>

#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animacion();

private slots:
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;

    QList<Esfera*> esferas;

    QTimer *timer;

    bool collideX;
    bool collideY;


};

#endif // MAINWINDOW_H
