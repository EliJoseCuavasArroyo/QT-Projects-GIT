#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include <iostream>
#include <string>
#include <fstream>
#include "enviroment.h"

using namespace std;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H

