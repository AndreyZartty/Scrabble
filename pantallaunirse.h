#ifndef PANTALLAUNIRSE_H
#define PANTALLAUNIRSE_H

#include <QWidget>
#include <pantallaespera.h>
#include <pantallatablero.h>
#include "serverHelper.h"


using namespace std;
namespace Ui {
class pantallaunirse;
}

class pantallaunirse : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaunirse(QWidget *parent = nullptr);
    ~pantallaunirse();
    string getJugador();
    string getCode();
    void setCode(string _code);
    void setJugador(string _jugador);

private slots:
    void on_UnirseButton_clicked();

private:
    Ui::pantallaunirse *ui;
    int SendJson();
    string code;
    string jugador;
};

#endif // PANTALLAUNIRSE_H
