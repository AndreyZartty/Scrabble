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
