#include "stage1.h"
#include "ui_stage1.h"

Stage1::Stage1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stage1)
{
    ui->setupUi(this);
}

Stage1::~Stage1()
{
    delete ui;
}
