#include "pantallaespera.h"
#include "ui_pantallaespera.h"
#include <iostream>


pantallaEspera::pantallaEspera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaEspera)
{
    ui->setupUi(this);
}

pantallaEspera::~pantallaEspera()
{
    delete ui;
}

void pantallaEspera::setCode(string _code){
    code = _code;
}
string pantallaEspera::getcode(){
    return code;
}

void pantallaEspera::setLinetxt(){
    cout << "TEST CODIGO EN LINEEDIT" << endl;
    cout << "TEST CODE: " << code << endl;
    QString qcode = QString::fromStdString(code);
    ui->lineEdit->setText(qcode);
    ui->lineEdit->update();
    cout << "TEST 2 CODIGO EN LINEEDIT" << endl;
}
