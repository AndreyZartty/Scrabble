#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "window.h"

#include "Juego.h"


static Juego* juego;

/**
 *
 */
void inicio() {
    //Instancia el objeto Juego
    juego = new Juego("codigo", 4);

    //Creacion de las fichas
    //Asignacion de poolFichas y cantFichas
    juego->crearFichas();

}



int main(int argc, char **argv)
{
 QApplication app (argc, argv);


 MainWindow window;

 QPushButton *button = new QPushButton("Iniciar el programa");
 QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
 button->show();

 window.show();


/*
 QPushButton *button = new QPushButton("Iniciar el programa");
 QObject::connect(button, SIGNAL(clicked()), &app, SLOT(main::inicio()));
 button->show();
 */

 return app.exec();
}
