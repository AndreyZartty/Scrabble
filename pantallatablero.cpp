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
