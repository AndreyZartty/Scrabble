#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QMainWindow>

namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit PantallaJuego(QWidget *parent = nullptr);
    ~PantallaJuego();

private:
    Ui::PantallaJuego *ui;
};

#endif // PANTALLAJUEGO_H
