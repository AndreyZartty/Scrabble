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
    QString nick = ui->line_nick->text();
    pantallaCrear *tab = new pantallaCrear;
    tab->setJugador(nick.toUtf8().constData());
    tab->show();
    hide();
}

void PantallaJuego::on_pushButton_2_clicked()
{
    QString nick = ui->line_nick->text();
    pantallaunirse *tab = new pantallaunirse;
    tab->setJugador(nick.toUtf8().constData());
    tab->show();
    hide();
}

string PantallaJuego::getJugador(){
    return jugador;
}
void PantallaJuego::setJugador(string _jugador){
    jugador = _jugador;
}


