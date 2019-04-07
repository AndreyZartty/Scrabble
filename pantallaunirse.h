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

class pantallaUnirse : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaUnirse(QWidget *parent = nullptr);
    ~pantallaUnirse();
    string getJugador();
    string getCode();
    void setCode(string _code);
    void setJugador(string _jugador);
    string getIP();
    void setIP(string ip);

private slots:
    void on_UnirseButton_clicked();

private:
    Ui::pantallaunirse *ui;
    int SendJson();
    string code;
    string jugador;
    string IP;
};

#endif // PANTALLAUNIRSE_H
