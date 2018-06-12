#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    // Recibimos el usuario y contraseña ingresado

    QString Usuario = ui->lineEdit->text();
    QString Contrasena = ui->lineEdit_2->text();

    string user;
    string password;
    string line;

    user = Usuario.toStdString();
    password = Contrasena.toStdString();

    // Verificamos si en realidad existe este usuario

    ifstream file;
    file.open(user+".txt");

    if (file.fail()){
        ui->label_3->setText("This User Does Not Exist");
    }
    else
    {
        while (!file.eof()){
            getline(file, line);
            if (line == "Password:"){
                getline(file, line);
                if (line == password) // En el caso de que haya ingresado la contraseña bien
                {
                    string nombre_archivo = "Users.txt";

                    ofstream creacion_archivo(nombre_archivo);
                    creacion_archivo << user << endl;

                    creacion_archivo.close();
                    file.close();

                    this->close();

                    Enviroment escena;
                    escena.exec();

                }
                 else
                {
                     ui->label_3->setText("Incorrect Password");
                }
            }
        }
    }

    file.close();

}

void Login::on_pushButton_2_clicked() // Registrar
{
    // Prevemos los posibles errores

    bool error1 = false;
    bool error2 = false;
    bool newfile = false;

    int longitud;

    // Recibimos el usuario y contraseña ingresado

    QString Usuario = ui->lineEdit->text();
    QString Contrasena = ui->lineEdit_2->text();

    string user;
    string password;

    user = Usuario.toStdString();
    password = Contrasena.toStdString();

    // Verificamos si este usuario ya existe o no

    ifstream fileRead;
    fileRead.open(user+".txt");

    if (fileRead.fail()){
        fileRead.close();
        newfile = true; // Podemos usar este usuario
    }
    else
    {
        fileRead.close();
        ui->label_3->setText("This User Already Exists");
    }

    // En el caso de el usuario no exista

    if (newfile == true)
    {

        // Vemos si el usuario lleva espacios

        longitud = user.length();

        for (int i = 0; i<longitud; i++){
            if (user[i] == ' '){
                error1 = true;
                break;
            }
        }

        // Vemos si la contraseña lleva espacios

        longitud = password.length();

        for (int i = 0; i<longitud; i++){
            if (password[i] == ' '){
                error2 = true;
                break;
            }
        }

        if (user == ""){
            ui->label_3->setText("Invalid User");
        }
        else if (password == ""){
            ui->label_3->setText("Invalid Password");
        }
        else if (error1 == true){
            ui->label_3->setText("Invalid User");
        }
        else if (error2 == true){
            ui->label_3->setText("Invalid Password");
        }
        else
        {
            ui->label_3->setText("User And Password Saved ...");
            // Operacion para archivar al usuario

            ofstream file;

            file.open(user+".txt");

            // Ponemos sus datos

            file << "User:" << endl;
            file << user << endl;
            file << "Password:" << endl;
            file << password << endl;
            file << "Level:" << endl;
            file << "1" << endl;
            file << "Score:" << endl;
            file << "0" << endl;

            file.close();

        }
    }


}
