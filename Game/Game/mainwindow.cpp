#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,1800,800);

    ui->graphicsView->setScene(scene);

    emit aviso(9);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo1")));


    // scene->setSceneRect(0,0,1800,800);

    /*
    scene=new QGraphicsScene(0,0,600,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(1,-1);
    emit aviso(9);

    mover1=false;
    mover2=false;

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Tesoso_Sagrado")));
     */

    QLine linebottom(scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());
    QLine linetop(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y());
    QLine lineder(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y());
    QLine lineizq(scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());

    scene->addLine(linetop);
    scene->addLine(linebottom);
    scene->addLine(lineder);
    scene->addLine(lineizq);

    scene->addItem(heroe);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animacion()));

    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animacion()
{

}

void MainWindow::on_pushButton_clicked()
{

}
