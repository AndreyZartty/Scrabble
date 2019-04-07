#ifndef PANTALLATABLERO_H
#define PANTALLATABLERO_H

#include <QWidget>
#include "serverHelper.h"

using namespace std;
namespace Ui {
class pantallaTablero;
}

class pantallaTablero : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaTablero(QWidget *parent = nullptr);
    ~pantallaTablero();
    void setServHelp(serverHelper _sH);
    serverHelper getServHelp();
    void setLabels(string _j1, string _j2, string _j3, string _j4);
    void sendJsonPasar();
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::pantallaTablero *ui;
    serverHelper sH;

};

#endif // PANTALLATABLERO_H
