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

private slots:
    void on_UnirseButton_clicked();

private:
    Ui::PantallaVinculacion *ui;
    int SendJson();
};

#endif // PANTALLAVINCULACION_H
