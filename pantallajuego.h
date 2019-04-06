#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QMainWindow>
#include <pantallacrear.h>
#include <pantallaunirse.h>


using namespace std;

namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit PantallaJuego(QWidget *parent = nullptr);
    ~PantallaJuego();
    string getJugador();
    void setJugador(string _jugador);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PantallaJuego *ui;
    string jugador;
};

#endif // PANTALLAJUEGO_H
