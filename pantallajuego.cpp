#include "pantallajuego.h"
#include "ui_pantallajuego.h"

#define PORT 3550
#define MAXDATASIZE 1000

using namespace std;

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

void PantallaJuego::on_pushButton_clicked()
{
    pantallaCrear *tab = new pantallaCrear;
    tab->show();
    hide();
}

void PantallaJuego::on_pushButton_2_clicked()
{
    pantallaunirse *tab = new pantallaunirse;
    tab->show();
    hide();
}
