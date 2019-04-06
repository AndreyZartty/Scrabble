#ifndef PANTALLACREAR_H
#define PANTALLACREAR_H

#include <QWidget>
#include <pantallatablero.h>

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
private slots:
    int Crear_J();

    void on_graf_button_clicked();

private:
    string code;
    string jugador;

    Ui::pantallaCrear *ui;
};

#endif // PANTALLACREAR_H
