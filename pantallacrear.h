#ifndef PANTALLACREAR_H
#define PANTALLACREAR_H

#include <QWidget>
#include <pantallatablero.h>
#include <pantallaespera.h>
#include "serverHelper.h"

using namespace std;
namespace Ui {
class pantallaCrear;
}

class pantallaCrear : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaCrear(QWidget *parent = nullptr);
    ~pantallaCrear();
    string getJugador();
    string getCode();
    void setCode(string _code);
    void setJugador(string _jugador);
    string getIP();
    void setIP(string ip);
private slots:
    int Crear_J();

    void on_graf_button_clicked();

private:
    string code;
    string jugador;
    string IP;

    Ui::pantallaCrear *ui;
};

#endif // PANTALLACREAR_H
