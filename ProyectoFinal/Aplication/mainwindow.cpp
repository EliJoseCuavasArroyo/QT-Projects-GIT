#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,840,560);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    emit aviso(9);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo2")));

    // scene->setSceneRect(0,0,1800,800);

    QLine linebottom(scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());
    QLine linetop(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y());
    QLine lineder(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y());
    QLine lineizq(scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());

    scene->addLine(linetop);
    scene->addLine(linebottom);
    scene->addLine(lineder);
    scene->addLine(lineizq);

    scene->addItem(heroe);
    heroe->setPos(50, 100);

    orgullo->setCondition(2);
    scene->addItem(orgullo);
    orgullo->setPos(450, 100);

    ban->setCondition(1);
    scene->addItem(ban);
    ban->setPos(550, 100);

    ira->setCondition(3);
    scene->addItem(ira);
    ira->setPos(650, 65);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animacion()));

    timer->start(70);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animacion()
{

    heroe->mover();
    ban->mover();
    orgullo->mover();
    ira->mover();

}

void MainWindow::on_pushButton_clicked() // Jugar
{
    timer->stop();
    this->close();

    Enviroment escena;
    escena.exec();
}

void MainWindow::on_pushButton_2_clicked() // Dos jugadores
{
    timer->stop();
    this->close();

    TwoPlayers escenario;
    escenario.exec();
}
