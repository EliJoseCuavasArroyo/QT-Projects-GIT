#include "stage.h"
#include "ui_stage.h"

void Stage::setTurno(bool value)
{
    turno = value;
}

void Stage::setAnimation(bool value)
{
    animation = value;
}

void Stage::setAnimationKi(bool value)
{
    animationKi = value;
}

Stage::Stage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stage)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,841,560);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->scale(1,-1);

    emit aviso(9);

    ifstream ifs;

    ifs.open("playing.txt");

    char c = 0;

    ifs.get(c);

    ifs.close();


    // Condicionamiento del nivel

    if (c == '1')
    {
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo3")));
        ban->setCondition(1);
    }
    else if (c == '2')
    {
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo4")));
        ban->setCondition(2);
    }
    else if (c == '3')
    {
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo2")));
        ban->setCondition(3);
    }
    else
    {
         ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Fondo4")));
         ban->setCondition(4);
    }

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
    if (c == '1')
    {
        heroe->setPos(50, 70);
    }
    else
    {
        heroe->setPos(50, 90);
    }

    // Pecado capital

    ban->setArmasAndHp();
    scene->addItem(ban);

    if (c == '1')
    {
        ban->setPos(600, 70);
    }
    else if (c == '3')
    {
        ban->setPos(600, 65);
    }
    else
    {
        ban->setPos(600, 90);
    }

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

    ui->progressBar->setValue(valueHP);
    ui->progressBar_2->setValue(valueMP);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(BattleRoyal()));

    timer->start(100);

}

Stage::~Stage()
{
    delete ui;
    delete scene;
}

void Stage::BattleRoyal()
{
    srand(time(NULL));

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

    // Turno del pecado capital

    if ((turno == false)&&(animation == false)){
        int num;
        if ((ban->getMP()) >= 250){
            num = rand()%(3);
            if (num == 0)
            {
                espada->setCondition((ban->getArmaP()));
                espada->setDamage();
                espada->setPos(500, 150);
            }
            else if (num == 1)
            {
                espada->setCondition((ban->getArmaS()));
                espada->setDamage();
                espada->setPos(400, 500);
            }
            else // num = 2
            {
                Final_Ki->setCondition((ban->getArmaKi()));
                Final_Ki->setDamage();
                Final_Ki->setPos(500, 150);
                setAnimationKi(true);
            }

        }
        else if ((ban->getMP()) >= 100){
            num = rand()%(2);
            if (num == 0){
                espada->setCondition((ban->getArmaP()));
                espada->setDamage();
                espada->setPos(500, 150);
            }
            else // num = 1
            {
                espada->setCondition((ban->getArmaS()));
                espada->setDamage();
                espada->setPos(400, 500);
            }
        }
        else
        {
            espada->setCondition((ban->getArmaP()));
            espada->setDamage();
            espada->setPos(500, 150);
        }

        setAnimation(true);
        setTurno(true);
    }

    // En el caso de que colisione con el heroe o pecado capital

    if ((espada->collidesWithItem(heroe))&&(espada->getCondition() != 0)&&(espada->getCondition() != 1)){

        heroe->TakeDamage((espada->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

        Score = Score + (espada->getDamage());
    }

    else if ((Final_Ki->collidesWithItem(heroe))&&(Final_Ki->getCondition() != 0)){

        heroe->TakeDamage((Final_Ki->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

        Score = Score + (Final_Ki->getDamage());
    }

    else if ((Final_Ki->collidesWithItem(ban))&&((Final_Ki->getCondition() == 0))){

        ban->TakeDamage((Final_Ki->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

        Score = Score + (Final_Ki->getDamage());
    }

    else if ((espada->collidesWithItem(ban))&&((espada->getCondition() == 0)||(espada->getCondition() == 1))){

        ban->TakeDamage((espada->getDamage()));
        setAnimation(false);
        setAnimationKi(false);
        espada->setPos(1000, 1000);
        Final_Ki->setPos(1000, 1500);

        Score = Score + (espada->getDamage());
    }

    // Actualizacion de las barras de HP y MP

    if (valueHP > (((heroe->getHP())*100)/2500)){
        valueHP = valueHP-1;
    }
    else if (valueHP < (((heroe->getHP())*100)/2500)){
        valueHP = valueHP+1;
    }

    if (valueMP > (((heroe->getMP())*100)/1200)){
        valueMP = valueMP-1;
    }
    else if (valueMP < (((heroe->getMP())*100)/1200)){
        valueMP = valueMP+1;
    }

    ui->progressBar->setValue(valueHP);
    ui->progressBar_2->setValue(valueMP);

    ui->label_2->setText("MP: " + QString::number((heroe->getMP())));
    ui->label_6->setText("MP: " + QString::number((ban->getMP())));

    // Actualizacion de los Puntos

    ui->label_3->setText("Archer Status:                                                                                                                        Score: "+QString::number(Score));

    // Verificacion de muerte

    if (valueHP > 0){
        ui->label->setText("HP: " + QString::number((heroe->getHP())));
    }
    else
    {
        ui->label->setText("HP: 0");

        // Volvemos a abrir eviroment

        timer->stop();
        this->close();

        Enviroment escena;
        escena.exec();
    }

    if ((ban->getHP()) > 0){
         ui->label_5->setText("HP: " + QString::number((ban->getHP())));
    }
    else
    {
        ui->label_5->setText("HP: 0");

        // Actualizamos al usuario, ya que fue el ganador

        string line;

        ifstream fileRead;
        fileRead.open("Users.txt");
        getline(fileRead, line);
        fileRead.close();

        ifstream fileReadUser;
        fileReadUser.open(line+".txt");

        string line2;

        string user;
        string password;
        string level;
        string puntaje;

        getline(fileReadUser, line2); // Usuario
        getline(fileReadUser, user);
        getline(fileReadUser, line2); // Contraseña
        getline(fileReadUser, password);
        getline(fileReadUser, line2); // Nivel
        getline(fileReadUser, level);
        getline(fileReadUser, line2); // Puntaje
        getline(fileReadUser, puntaje);

        fileReadUser.close();

        // Actualizamos el nivel

        ifstream fs;

        fs.open("playing.txt");

        char p = 0;
        char nivel = level[0];

        fs.get(p);

        fs.close();

        // Respecto a su condicionamiento del nivel

        if (nivel == p){
            if (p == '1'){
                level = "2";
            }
            if (p == '2'){
                level = "3";
            }
            if (p == '3'){
                level = "4";
            }
            if (p == '4'){
                level = "5";
            }
        }

        // Actualizamos el puntaje acumulado

        Score = Score + (atoi(puntaje.c_str()));

        // Actualizacion total

        ofstream file;

        file.open(user+".txt");

        // Ponemos sus datos

        file << "User:" << endl;
        file << user << endl;
        file << "Password:" << endl;
        file << password << endl;
        file << "Level:" << endl;
        file << level << endl;
        file << "Score:" << endl;
        file << Score << endl;

        file.close();

         // Volvemos a abrir eviroment

        timer->stop();
        this->close();

        Enviroment escena;
        escena.exec();
    }

}

void Stage::on_pushButton_clicked() // Kanshou y bakuya
{
    if ((turno == true)&&(animation == false)){
        espada->setCondition((heroe->getArmaP()));
        espada->setDamage();
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }
}

void Stage::on_pushButton_2_clicked() // Kanshou y bakuya overgede
{
    if ((turno == true)&&(animation == false)&&((heroe->getMP()) >= 80)){
        espada->setCondition((heroe->getArmaS()));
        espada->setDamage();
        espada->setPos(160, 150);
        setAnimation(true);
        setTurno(false);
    }
}

void Stage::on_pushButton_3_clicked() // Ki
{
    if ((turno == true)&&(animation == false)&&((heroe->getMP()) >= 150)){
        Final_Ki->setCondition((heroe->getArmaKi()));
        Final_Ki->setDamage();
        Final_Ki->setPos(160, 150);
        setAnimation(true);
        setAnimationKi(true);
        setTurno(false);
    }
}

void Stage::on_pushButton_4_clicked() // Heal
{
    if ((turno == true)&&(animation == false)&&(heroe->getMP() >= 50)){
        heroe->cure();
        setTurno(false);
    }
}

void Stage::on_pushButton_5_clicked() // Pass
{
    if ((turno == true)&&(animation == false)){
        setTurno(false);
    }
}
