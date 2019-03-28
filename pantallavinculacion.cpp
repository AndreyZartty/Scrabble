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
    ui->label->setText(x);

}
