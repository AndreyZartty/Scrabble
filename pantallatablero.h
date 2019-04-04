#ifndef PANTALLATABLERO_H
#define PANTALLATABLERO_H

#include <QWidget>

namespace Ui {
class pantallaTablero;
}

class pantallaTablero : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaTablero(QWidget *parent = nullptr);
    ~pantallaTablero();

private:
    Ui::pantallaTablero *ui;
};

#endif // PANTALLATABLERO_H
