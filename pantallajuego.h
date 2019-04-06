#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QMainWindow>
#include <pantallacrear.h>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::PantallaJuego *ui;
};

#endif // PANTALLAJUEGO_H
