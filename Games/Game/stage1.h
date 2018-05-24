#ifndef STAGE1_H
#define STAGE1_H

#include <QDialog>

namespace Ui {
class Stage1;
}

class Stage1 : public QDialog
{
    Q_OBJECT

public:
    explicit Stage1(QWidget *parent = 0);
    ~Stage1();

private:
    Ui::Stage1 *ui;
};

#endif // STAGE1_H
