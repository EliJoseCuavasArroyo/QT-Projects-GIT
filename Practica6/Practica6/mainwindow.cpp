#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(0,0,1000,500);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    emit aviso(9);

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(animacion()));
    timer->start(10);

    l1=new QGraphicsLineItem(0,0,1000,0);
    l2=new QGraphicsLineItem(0,0,0,500);
    l3=new QGraphicsLineItem(1000,0,1000,500);
    l4=new QGraphicsLineItem(0,500,1000,500);

    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animacion()
{
    for(int i=0; i<esferas.length();i++)
    {
        if((esferas.at(i)->collidesWithItem(l2))||(esferas.at(i)->collidesWithItem(l3)))
        {
            collideX = true;
        }
        else{
            collideX = false;
        }

        if((esferas.at(i)->collidesWithItem(l1))||(esferas.at(i)->collidesWithItem(l4)))
        {
            collideY = true;
        }
        else{
            collideY = false;
        }

        esferas.at(i)->mover();

        if(((esferas.at(i)->collidesWithItem(l2))||(esferas.at(i)->collidesWithItem(l3)))&&(collideX == false))
        {
            esferas.at(i)->choqueX();
        }
        if(((esferas.at(i)->collidesWithItem(l1))||(esferas.at(i)->collidesWithItem(l4)))&&(collideY == false))
        {
            esferas.at(i)->choqueY();
        }

    }
}

void MainWindow::on_pushButton_clicked()
{
    esferas.append(new Esfera());
    esferas.last()->setDatos();

    srand(time(NULL));

    float num;
    float Px;
    float Py;

    num = 10+rand()%(951-10);
    Px = num;

    num = 50+rand()%(451-50);
    Py = num;

    scene->addItem(esferas.last());
    esferas.last()->setPos(Px, Py);
}
