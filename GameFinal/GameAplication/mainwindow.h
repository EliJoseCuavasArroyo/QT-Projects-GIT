#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "archer.h"
#include "sins.h"
#include "twoplayers.h"
#include "enviroment.h"
#include "weapon.h"
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void aviso(int);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene* scene;
    QTimer* timer;

    // Personajes:
    Archer *heroe = new Archer [1];
    Sins *ban = new Sins [1];
    Sins *orgullo = new Sins [1];
    Sins *ira = new Sins [1];

public slots:
    void animacion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

