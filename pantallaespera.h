#ifndef PANTALLAESPERA_H
#define PANTALLAESPERA_H

#include <QWidget>
#include "pantallatablero.h"
#include "serverHelper.h"
#include <QMessageBox>

using namespace std;
namespace Ui {
class pantallaEspera;
}

class pantallaEspera : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaEspera(QWidget *parent = nullptr);
    ~pantallaEspera();
    void setServHelp(serverHelper _sH);
    serverHelper getServHelp();
    void setLinetxt();
    int SendJson();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pantallaEspera *ui;
    serverHelper sH;
};

#endif // PANTALLAESPERA_H
