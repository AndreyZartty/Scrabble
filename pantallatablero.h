#ifndef PANTALLATABLERO_H
#define PANTALLATABLERO_H

#include <QWidget>

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
    void setCode(string _code);
    string getCode();
    void setLabels(string _j1, string _j2, string _j3, string _j4);
private:
    Ui::pantallaTablero *ui;
    string code;

};

#endif // PANTALLATABLERO_H
