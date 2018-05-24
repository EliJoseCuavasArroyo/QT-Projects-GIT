#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,1600,1000);

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
    heroe->setPos(50, 150);

    orgullo->setCondition(2);
    scene->addItem(orgullo);
    orgullo->setPos(900, 150);

    ban->setCondition(1);
    scene->addItem(ban);
    ban->setPos(1100, 150);

    ira->setCondition(3);
    scene->addItem(ira);
    ira->setPos(1300, 150);

    espada->setCondition(0);
    scene->addItem(espada);
    espada->setPos(350, 250);


    //espada1->setCondition(1);
    //scene->addItem(espada1);
    //espada1->setPos(-50, 550);


    //espada2->setCondition(2);
    //scene->addItem(espada2);
    //espada2->setPos(800, 1000);


    //espada3->setCondition(3);
    //scene->addItem(espada3);
    //espada3->setPos(600, 1000);

    //espada4->setCondition(4);
    //scene->addItem(espada4);
    //espada4->setPos(850, 550);


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

    heroe->mover();

    //ban->mover();
    //orgullo->mover();
    ira->mover();

    espada->movimiento();

    //espada1->movimiento();

    //espada2->movimiento();

    //espada3->movimiento();

   // espada4->movimiento();

    if (espada->collidesWithItem(ira)){
        espada->setCondition(1);
      espada->setPos(51, 550);
    }

    if (espada->x() > 1500){
        espada->setCondition(2);
       espada->setPos(800, 800);
    }


    if (espada->collidesWithItem(heroe)){
       espada->setCondition(4);
       espada->setPos(850, 550);
    }


   // if (espada->collidesWithItem(heroe)){
     //   espada->setPos(600, 1000);
    //}

    if (espada->x() < 50){
        espada->setCondition(0);
          espada->setPos(350, 250);

    }

}

void MainWindow::on_pushButton_clicked()
{
    timer->stop();
    this->close();

    Enviroment escena;
    escena.exec();
}
