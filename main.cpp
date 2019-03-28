#include "pantallavinculacion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PantallaVinculacion w;
    w.show();

    return a.exec();
}
