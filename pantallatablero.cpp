#include "pantallatablero.h"
#include "ui_pantallatablero.h"

pantallaTablero::pantallaTablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaTablero)
{
    ui->setupUi(this);
}

pantallaTablero::~pantallaTablero()
{
    delete ui;
}

string pantallaTablero::getCode(){
    return code;
}
void pantallaTablero::setCode(string _code){
    code = _code;
}

void pantallaTablero::setLabels(string _j1, string _j2, string _j3, string _j4){
    ui->lbl_J1->setText(QString::fromUtf8(_j1.c_str()));
    ui->lbl_J2->setText(QString::fromUtf8(_j2.c_str()));
    ui->lbl_J3->setText(QString::fromUtf8(_j3.c_str()));
    ui->lbl_J4->setText(QString::fromUtf8(_j4.c_str()));
}
