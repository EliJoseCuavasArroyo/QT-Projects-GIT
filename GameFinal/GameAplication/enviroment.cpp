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
    orgullo->setPos(450, 100);

    ban->setCondition(1);
    scene->addItem(ban);
    ban->setPos(550, 100);

    ira->setCondition(3);
    scene->addItem(ira);
    ira->setPos(650, 65);

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
    delete scene;
}

void Enviroment::animacion()
{

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

    string line;

    ifstream fileRead;
    fileRead.open("Users.txt");
    getline(fileRead, line);
    fileRead.close();

    ifstream fileReadUser;
    fileReadUser.open(line+".txt");

    string line2;
    char word;

    while (!fileReadUser.eof()){
        getline(fileReadUser, line2);
        if (line2 == "Level:"){
            getline(fileReadUser, line2);
            word = line2[0];
            fileReadUser.close();
            break;
        }
    }

    char contenido_archivo = '1';

    if (word >= contenido_archivo) // Verificacion de que ha pasado el nivel
    {
        string nombre_archivo = "playing.txt";

        ofstream creacion_archivo(nombre_archivo.c_str());
        creacion_archivo << contenido_archivo << endl;
        creacion_archivo.close();

        timer->stop();
        this->close();

        Stage escena;
        escena.exec();
    }

}

void Enviroment::on_pushButton_2_clicked()
{

    string line;

    ifstream fileRead;
    fileRead.open("Users.txt");
    getline(fileRead, line);
    fileRead.close();

    ifstream fileReadUser;
    fileReadUser.open(line+".txt");

    string line2;
    char word;

    while (!fileReadUser.eof()){
        getline(fileReadUser, line2);
        if (line2 == "Level:"){
            getline(fileReadUser, line2);
            word = line2[0];
            fileReadUser.close();
            break;
        }
    }

    char contenido_archivo = '2';

    if (word >= contenido_archivo) // Verificacion de que ha pasado el nivel
    {
        string nombre_archivo = "playing.txt";

        ofstream creacion_archivo(nombre_archivo.c_str());
        creacion_archivo << contenido_archivo << endl;
        creacion_archivo.close();

        timer->stop();
        this->close();

        Stage escena;
        escena.exec();
    }
}

void Enviroment::on_pushButton_3_clicked()
{

    string line;

    ifstream fileRead;
    fileRead.open("Users.txt");
    getline(fileRead, line);
    fileRead.close();

    ifstream fileReadUser;
    fileReadUser.open(line+".txt");

    string line2;
    char word;

    while (!fileReadUser.eof()){
        getline(fileReadUser, line2);
        if (line2 == "Level:"){
            getline(fileReadUser, line2);
            word = line2[0];
            fileReadUser.close();
            break;
        }
    }

    char contenido_archivo = '3';

    if (word >= contenido_archivo) // Verificacion de que ha pasado el nivel
    {
        string nombre_archivo = "playing.txt";

        ofstream creacion_archivo(nombre_archivo.c_str());
        creacion_archivo << contenido_archivo << endl;
        creacion_archivo.close();

        timer->stop();
        this->close();

        Stage escena;
        escena.exec();
    }
}

void Enviroment::on_pushButton_4_clicked()
{

    string line;

    ifstream fileRead;
    fileRead.open("Users.txt");
    getline(fileRead, line);
    fileRead.close();

    ifstream fileReadUser;
    fileReadUser.open(line+".txt");

    string line2;
    char word;

    while (!fileReadUser.eof()){
        getline(fileReadUser, line2);
        if (line2 == "Level:"){
            getline(fileReadUser, line2);
            word = line2[0];
            fileReadUser.close();
            break;
        }
    }

    char contenido_archivo = '4';

    if (word >= contenido_archivo) // Verificacion de que ha pasado el nivel
    {
        string nombre_archivo = "playing.txt";

        ofstream creacion_archivo(nombre_archivo.c_str());
        creacion_archivo << contenido_archivo << endl;
        creacion_archivo.close();

        timer->stop();
        this->close();

        Stage escena;
        escena.exec();
    }
}

void Enviroment::on_pushButton_5_clicked()
{
    timer->stop();
    this->close();
}
