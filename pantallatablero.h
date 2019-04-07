#ifndef PANTALLATABLERO_H
#define PANTALLATABLERO_H

#include <QWidget>
#include "serverHelper.h"
#include <thread>

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
    int sendJsonPasar();
    int checkTurno();
private slots:
    void on_pushButton_2_clicked();

    //void on_lbl_Turno_linkActivated(const QString &link);

    void on_label_linkHovered(const QString &link);

private:
    Ui::pantallaTablero *ui;
    serverHelper sH;
    std::thread t1;

};

#endif // PANTALLATABLERO_H
