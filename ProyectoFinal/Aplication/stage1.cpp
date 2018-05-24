#include "stage1.h"
#include "ui_stage1.h"

#include <iostream>

using namespace std;

bool Stage1::getTurno() const
{
    return turno;
}

void Stage1::setTurno(bool value)
{
    turno = value;
}

bool Stage1::getAnimation() const
{
    return animation;
}

void Stage1::setAnimation(bool value)
{
    animation = value;
}

Stage1::Stage1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stage1)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,841,560);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    emit aviso(9);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo4")));

    // scene->setSceneRect(0,0,1800,800);

    QLine linebottom(scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());
    QLine linetop(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y());
    QLine lineder(scene->sceneRect().bottomLeft().x(),scene->sceneRect().bottomLeft().y(),scene->sceneRect().topLeft().x(),scene->sceneRect().topLeft().y());
    QLine lineizq(scene->sceneRect().bottomRight().x(),scene->sceneRect().bottomRight().y(),scene->sceneRect().topRight().x(),scene->sceneRect().topRight().y());

    scene->addLine(linetop);
    scene->addLine(linebottom);
    scene->addLine(lineder);
    scene->addLine(lineizq);

    // Heroe en Escena
    scene->addItem(heroe);
    heroe->setPos(50, 100);

    // Pecado capital
    ban->setCondition(1);
    scene->addItem(ban);
    ban->setPos(600, 100);

    espada->setCondition(0);
    scene->addItem(espada);
    espada->setPos(500, 500);

    setTurno(true);
    setAnimation(false);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(BattleRoyal()));

    timer->start(100);
}

Stage1::~Stage1()
{
    delete ui;
}

void Stage1::BattleRoyal()
{
    heroe->mover();
    ban->mover();

    if (animation == true){
        timer->start(50);
        espada->movimiento();

    }

    else{
        timer->start(100);
    }

    if ((turno == false)&&(animation == false)){
        espada->setCondition(2);
        espada->setPos(350, 500);
        setAnimation(true);
        setTurno(true);
    }

    if ((espada->collidesWithItem(heroe))&&(espada->getCondition() == 2)){
        setAnimation(false);
        espada->setPos(1000, 1000);
    }
    else if ((espada->collidesWithItem(ban))&&(((espada->getCondition() == 0))||(espada->getCondition() == 1))){
        setAnimation(false);
        espada->setPos(1000, 1000);
    }


}

void Stage1::on_pushButton_clicked() // Kanshou y bakuya
{
    if ((turno == true)&&(animation == false)){
        espada->setCondition(0);
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }

}

void Stage1::on_pushButton_2_clicked() // Kanshou y bakuya overgede
{
    if ((turno == true)&&(animation == false)){
        espada->setCondition(1);
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }
}

void Stage1::on_pushButton_3_clicked() // Ki
{

}

void Stage1::on_pushButton_4_clicked() // Pasar turno
{
    if ((turno == true)&&(animation == false)){
        setTurno(false);
    }
}

