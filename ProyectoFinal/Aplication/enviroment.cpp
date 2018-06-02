#include "enviroment.h"
#include "ui_enviroment.h"

Enviroment::Enviroment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enviroment)
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
    orgullo->setPos(500, 100);

    ban->setCondition(1);
    scene->addItem(ban);
    ban->setPos(600, 100);

    ira->setCondition(3);
    scene->addItem(ira);
    ira->setPos(700, 100);

    espada->setCondition(0);
    scene->addItem(espada);
    espada->setPos(160, 150);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animacion()));

    timer->start(50);
}

Enviroment::~Enviroment()
{
    delete ui;
}

void Enviroment::animacion()
{
    //heroe->mover();
    //ban->mover();
    //orgullo->mover();
    //ira->mover();

    espada->movimiento();

    if (espada->collidesWithItem(ira)){
        espada->setCondition(2);
        espada->setPos(350, 500);
    }

    else if ((espada->collidesWithItem(heroe))&&(espada->getCondition() == 2 )){
        espada->setCondition(3);
        espada->setPos(500, 500);
    }

    else if ((espada->collidesWithItem(heroe))&&(espada->getCondition() == 3 )){
        espada->setCondition(1);
        espada->setPos(50, 300);
    }

    else if (espada->x() > 800){
        espada->setCondition(4);
        espada->setPos(700, 300);
    }

    else if (espada->x() < 0){
        espada->setCondition(0);
        espada->setPos(160, 150);
    }
}


void Enviroment::on_pushButton_clicked()
{
    timer->stop();
    this->close();

    Stage1 escena;
    escena.exec();
}

void Enviroment::on_pushButton_2_clicked()
{
    // ui->label->setText("fsa");
}

void Enviroment::on_pushButton_3_clicked()
{

}

void Enviroment::on_pushButton_4_clicked()
{

}

void Enviroment::on_pushButton_5_clicked()
{
    timer->stop();
    this->close();
}
