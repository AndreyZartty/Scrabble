#ifndef PANTALLAESPERA_H
#define PANTALLAESPERA_H

#include <QWidget>
#include "pantallatablero.h"

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
    void setCode(string _code);
    string getcode();
    void setLinetxt();
    int SendJson();
    int MendJson();


private:
    Ui::pantallaEspera *ui;
    string code;
};

#endif // PANTALLAESPERA_H
