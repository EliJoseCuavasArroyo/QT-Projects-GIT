#include "twoplayers.h"
#include "ui_twoplayers.h"

void TwoPlayers::setTurno(bool value)
{
    turno = value;
}

void TwoPlayers::setAnimation(bool value)
{
    animation = value;
}

void TwoPlayers::setAnimationKi(bool value)
{
    animationKi = value;
}

void TwoPlayers::setArcherInstall(bool value)
{
    ArcherInstall = value;
}

void TwoPlayers::setSaberInstall(bool value)
{
    SaberInstall = value;
}

TwoPlayers::TwoPlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoPlayers)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,841,560);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    emit aviso(9);

    // Condicionamiento del nivel

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo4")));
    heroe->setCondition(5);
    ban->setCondition(7);

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

    heroe->setArmasAndHp();
    scene->addItem(heroe);
    heroe->setPos(50, 90);


    // Pecado capital

    ban->setArmasAndHp();
    scene->addItem(ban);
    ban->setPos(600, 90);


    // Preparamos las armas

    espada->setCondition(0);
    scene->addItem(espada);
    espada->setPos(1000, 1000);

    Final_Ki->setCondition(0);
    scene->addItem(Final_Ki);
    Final_Ki->setPos(1000, 1500);

    // Condiciones iniciales

    setTurno(true);
    setAnimation(false);
    setAnimationKi(false);
    setArcherInstall(false);
    setSaberInstall(false);

    ui->label->setText("Player1 Status (Archer):");
    ui->label_4->setText("Player2 Status (Saber):");

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(BattleRoyal()));

    timer->start(100);

}

TwoPlayers::~TwoPlayers()
{
    delete ui;
    delete scene;
}
void TwoPlayers::BattleRoyal()
{

    heroe->mover();
    ban->mover();

    // Verificacion de la animacion

    if (animation == true)
    {
        timer->start(40);
        if (animationKi == true){
            Final_Ki->movimiento();
        }
        else{
            espada->movimiento();
        }
    }
    else
    {
        timer->start(70);
    }


    // En el caso de que colisione con el heroe o pecado capital

    if ((espada->collidesWithItem(heroe))&&(espada->getCondition() != 0)&&(espada->getCondition() != 1)){

        heroe->TakeDamage((espada->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

    }

    else if ((Final_Ki->collidesWithItem(heroe))&&(Final_Ki->getCondition() != 0)){

        heroe->TakeDamage((Final_Ki->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

    }

    else if ((Final_Ki->collidesWithItem(ban))&&((Final_Ki->getCondition() == 0))){

        ban->TakeDamage((Final_Ki->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

    }

    else if ((espada->collidesWithItem(ban))&&((espada->getCondition() == 0)||(espada->getCondition() == 1))){

        ban->TakeDamage((espada->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

    }

    // Actualizacion del status de los personajes

    // Primero Archer

    if ((heroe->getHP()) > 0){
         ui->label_2->setText("HP: " + QString::number((heroe->getHP())));
    }
    else
    {
        ui->label_2->setText("HP: 0");

        // Cerramos el Juego

        timer->stop();
        this->close();
    }

     ui->label_3->setText("MP: " + QString::number((heroe->getMP())));

     // Segundo Saber

     if ((ban->getHP()) > 0){
          ui->label_5->setText("HP: " + QString::number((ban->getHP())));
     }
     else
     {
         ui->label_5->setText("HP: 0");

         // Cerramos el Juego

         timer->stop();
         this->close();
     }

      ui->label_6->setText("MP: " + QString::number((ban->getMP())));

    // Tercero el turno

    if (animation == true){
        ui->label_7->setText("  Turno: ");
    }
    else if (turno == true){
        ui->label_7->setText("  Turno: Player 1");
    }
    else{
        ui->label_7->setText("  Turno: Player 2");
    }
}

// Funciones de Archer

void TwoPlayers::on_pushButton_clicked() // Kanshou y bakuya
{
    if ((turno == true)&&(animation == false)){
        espada->setCondition((heroe->getArmaP()));
        espada->setDamage();
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }
}

void TwoPlayers::on_pushButton_2_clicked() // Kanshou y bakuya overgede
{
    if ((turno == true)&&(animation == false)&&((heroe->getMP()) >= 100)){
        espada->setCondition((heroe->getArmaS()));
        espada->setDamage();
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }
}

void TwoPlayers::on_pushButton_3_clicked() // Ki
{
    if ((turno == true)&&(animation == false)&&((heroe->getMP()) >= 250)&&(ArcherInstall == true)){
        Final_Ki->setCondition((heroe->getArmaKi()));
        Final_Ki->setDamage();
        Final_Ki->setPos(160, 150);
        setAnimation(true);
        setAnimationKi(true);
        setTurno(false);
    }
}

void TwoPlayers::on_pushButton_4_clicked() // Archer install
{
    if ((turno == true)&&(animation == false)&&(ArcherInstall == false)){
        setArcherInstall(true);
        heroe->setCondition(6);
        heroe->setArmasAndHp();
        heroe->setPos(50, 90);
    }
}

void TwoPlayers::on_pushButton_5_clicked() // Pass
{
    if ((turno == true)&&(animation == false)){
        setTurno(false);
    }
}

// Funciones de Saber

void TwoPlayers::on_pushButton_6_clicked() // Basic Excalibur
{
    if ((turno == false)&&(animation == false)){
        espada->setCondition((ban->getArmaP()));
        espada->setDamage();
        espada->setPos(500, 150);
        setAnimation(true);
        setTurno(true);
    }
}

void TwoPlayers::on_pushButton_7_clicked() // Yellow Excalibur
{
    if ((turno == false)&&(animation == false)&&((ban->getMP()) >= 100)){
        espada->setCondition((ban->getArmaS()));
        espada->setDamage();
        espada->setPos(500, 150);
        setAnimation(true);
        setTurno(true);
    }
}

void TwoPlayers::on_pushButton_8_clicked() // Blue Excalibur
{
    if ((turno == false)&&(animation == false)&&((ban->getMP()) >= 250)&&(SaberInstall == true)){
        Final_Ki->setCondition((ban->getArmaKi()));
        Final_Ki->setDamage();
        Final_Ki->setPos(500, 150);
        setAnimationKi(true);
        setAnimation(true);
        setTurno(true);
    }
}

void TwoPlayers::on_pushButton_9_clicked() // Saber Install
{
    if ((turno == false)&&(animation == false)&&(SaberInstall == false)){
        setSaberInstall(true);
        ban->setCondition(8);
        ban->setArmasAndHp();
        ban->setPos(600, 90);
    }
}

void TwoPlayers::on_pushButton_10_clicked() // Pass
{
    if ((turno == false)&&(animation == false)){
        setTurno(true);
    }
}


