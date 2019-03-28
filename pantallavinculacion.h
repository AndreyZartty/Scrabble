#ifndef PANTALLAVINCULACION_H
#define PANTALLAVINCULACION_H

#include <QMainWindow>

namespace Ui {
class PantallaVinculacion;
}

class PantallaVinculacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit PantallaVinculacion(QWidget *parent = nullptr);
    ~PantallaVinculacion();

private:
    Ui::PantallaVinculacion *ui;
};

#endif // PANTALLAVINCULACION_H
