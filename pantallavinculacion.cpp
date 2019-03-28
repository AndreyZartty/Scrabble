#include "pantallavinculacion.h"
#include "ui_pantallavinculacion.h"

PantallaVinculacion::PantallaVinculacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PantallaVinculacion)
{
    ui->setupUi(this);
}

PantallaVinculacion::~PantallaVinculacion()
{
    delete ui;
}

void PantallaVinculacion::on_UnirseButton_clicked()
{
    QString x = ui->lineEdit->text();
    if(x=="Inserte el código de invitación"){
        x= "Inserte un código válido";
    }
    else {
        x= "Gracias!!";
    }
    ui->label->setText(x);

}
