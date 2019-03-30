#include "pantallajuego.h"
#include "ui_pantallajuego.h"

PantallaJuego::PantallaJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}
