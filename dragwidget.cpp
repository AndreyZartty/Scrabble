#include <QtWidgets>
#include <QTableView>
#include <iostream>
#include <QPushButton>
#include <QObject>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <json-c/json.h>
#include <json-c/debug.h>
#include <json-c/json_object.h>
#include <QMessageBox>
#include <thread>
#include "serverHelper.h"

#define PORT 3550
#define MAXDATASIZE 1000

#include "dragwidget.h"

using namespace std;

//! [0]
DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    setMinimumWidth(1400);
    setMinimumHeight(1000);
    setMaximumWidth(1400);
    setMaximumHeight(1000);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QTableWidget *cuadricula = new QTableWidget(this);
    cuadricula->setColumnCount(15);
    cuadricula->setRowCount(15);
    for(int i=0;i<15;i++){
        cuadricula->setRowHeight(i,25);
    }
    for(int i=0;i<15;i++){
        cuadricula->setColumnWidth(i,55);
    }
    cuadricula->horizontalHeader()->setVisible(false);
    cuadricula->verticalHeader()->setVisible(false);
    cuadricula->setMinimumWidth(857);
    cuadricula->setMinimumHeight(378);
    cuadricula->setMaximumWidth(857);
    cuadricula->setMaximumHeight(378);
    cuadricula->move(20,30);
    this->matriz = cuadricula;

    QPushButton *ret = new QPushButton(this);
    ret->move(75,500);
    ret->setText("Return");
    QObject::connect(ret, SIGNAL (clicked()),this, SLOT( on_ret_clicked()));


    QLabel *houseIcon = new QLabel(this);
    houseIcon->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon->move(75, 450);
    houseIcon->show();
    houseIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon2 = new QLabel(this);
    houseIcon2->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon2->move(135, 450);
    houseIcon2->show();
    houseIcon2->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon3 = new QLabel(this);
    houseIcon3->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon3->move(195, 450);
    houseIcon3->show();
    houseIcon3->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon4 = new QLabel(this);
    houseIcon4->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon4->move(255, 450);
    houseIcon4->show();
    houseIcon4->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon5 = new QLabel(this);
    houseIcon5->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon5->move(315, 450);
    houseIcon5->show();
    houseIcon5->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon6 = new QLabel(this);
    houseIcon6->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon6->move(375, 450);
    houseIcon6->show();
    houseIcon6->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon7 = new QLabel(this);
    houseIcon7->setPixmap(QPixmap("/home/cucho16/Documentos/Proyectos C++/Scrabble/ImScrabble/Ñ.png"));
    houseIcon7->move(435, 450);
    houseIcon7->show();
    houseIcon7->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *lbl_J1 = new QLabel(this);
    lbl_J1->move(1000,40);
    lbl_J1->setMinimumWidth(30);
    lbl_J1->setMinimumHeight(30);
    lbl_J1->show();
    this->lbl_J1 = lbl_J1;

    QLabel *lbl_J2 = new QLabel(this);
    lbl_J2->move(1000,60);
    lbl_J2->setMinimumWidth(30);
    lbl_J2->setMinimumHeight(30);
    lbl_J2->show();

    this->lbl_J2 = lbl_J2;

    QLabel *lbl_J3 = new QLabel(this);
    lbl_J3->move(1000,80);
    lbl_J3->show();
    this->lbl_J3 = lbl_J3;

    QLabel *lbl_J4 = new QLabel(this);
    lbl_J4->move(1000,100);
    lbl_J4->show();
    this->lbl_J4 = lbl_J4;

    QLabel *lbl_p1 = new QLabel(this);
    lbl_p1->move(1100,40);
    lbl_p1->setMinimumWidth(30);
    lbl_p1->setMinimumHeight(30);
    lbl_p1->show();
    this->lbl_p1 = lbl_p1;

    QLabel *lbl_p2 = new QLabel(this);
    lbl_p2->move(1100,60);
    lbl_p2->setMinimumWidth(30);
    lbl_p2->setMinimumHeight(30);
    lbl_p2->show();
    lbl_p2->adjustSize();
    this->lbl_p2 = lbl_p2;

    QLabel *lbl_p3 = new QLabel(this);
    lbl_p3->move(1100,80);
    lbl_p3->show();
    this->lbl_p3 = lbl_p3;

    QLabel *lbl_p4 = new QLabel(this);
    lbl_p4->move(1100,100);
    lbl_p4->show();
    this->lbl_p4 = lbl_p4;

    QLabel *label = new QLabel(this);
    label->move(1050,130);
    label->show();
    label->setMinimumWidth(30);
    label->setMinimumHeight(30);
    this->label = label;

    QPushButton *pushButton = new QPushButton(this);
    pushButton->setText("Scrabble");
    pushButton->move(1000,660);
    pushButton->show();
    this->pushButton = pushButton;
    QObject::connect(pushButton, SIGNAL (clicked()),this, SLOT( on_pushButton_clicked()));

    QPushButton *pushButton_2 = new QPushButton(this);
    pushButton_2->setText("Pasar");
    pushButton_2->move(860,660);
    pushButton_2->show();
    this->pushButton_2 = pushButton_2;
    QObject::connect(pushButton_2, SIGNAL (clicked()),this, SLOT( on_pushButton_2_clicked()));

}
//! [0]
void DragWidget::setServHelp(serverHelper _sH){
    this->sH = _sH;
}
serverHelper DragWidget::getServHelp(){
    return sH;
}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        int cC= 0;
        int cR= 0;
        int Dx = 75;
        int dx = 20;
        int Dy = 55;
        int dy = 30;
        while(cC<15){
            if(dx< newIcon->x() + 28 and newIcon->x() + 28 < Dx){
                while(cR<15){
                    if(dy< newIcon->y() + 13 and newIcon->y() + 13 < Dy){
                        this->Row = cR;
                        this->Col = cC;
                        this->ficha = newIcon;
                        this->matriz->setCellWidget(cR,cC,newIcon);
                        newIcon->show();
                        newIcon->setAttribute(Qt::WA_DeleteOnClose);
                        cR=16;
                        cC=16;
                    }
                    else {
                        cR++;
                        dy += 25;
                        Dy += 25;
                    }
                }
                cC=17;

            }
            else{
                cC++;
                dx += 55;
                Dx += 55;
            }
        }
        if(cC==15 or cR== 15){
            newIcon->move(75,450);
            newIcon->show();
            newIcon->setAttribute(Qt::WA_DeleteOnClose);
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//! [1]
void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

void DragWidget::on_ret_clicked(){
    QLabel *current = this->ficha;
    this->matriz->removeCellWidget(this->ficha->x(),this->ficha->y());
    current->move(0, 0);
    current->show();
    current->setAttribute(Qt::WA_DeleteOnClose);
    cout << "xd" << endl;
}
void DragWidget::setLabels(string _j1, string _j2, string _j3, string _j4){
    this->lbl_J1->setText(QString::fromUtf8(_j1.c_str()));
    this->lbl_J2->setText(QString::fromUtf8(_j2.c_str()));
    this->lbl_J3->setText(QString::fromUtf8(_j3.c_str()));
    this->lbl_J4->setText(QString::fromUtf8(_j4.c_str()));

    this->lbl_p1->setText("0");
    this->lbl_p2->setText("0");

    if(_j3 != ""){
        this->lbl_p3->setText("0");
        if(_j4 != ""){
            this->lbl_p4->setText("0");
        }
    }

    this->label->setText("TEST");

}
void DragWidget::on_pushButton_2_clicked()
{
    this->pushButton_2->setEnabled(false);
    this->label->setText("Esperando Turno...");
    std::thread t1 (&DragWidget::sendJsonPasar, this);
    t1.join();
    //sendJsonPasar();
}
int DragWidget::sendJsonPasar(){
    char* str;
    int fd, numbytes;
    struct sockaddr_in client;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    char sendBuff[MAXDATASIZE];
    char recvBuff[MAXDATASIZE];

    struct hostent *he;

    if (fd < 0)
    {
        printf("Error : Could not create socket\n");
        return 1;
    }
    else
    {
        client.sin_family = AF_INET;
        client.sin_port = htons(PORT);
        client.sin_addr.s_addr = inet_addr("192.168.100.17");
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (::connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    json_object *jobj = json_object_new_object();

    json_object *jstring = json_object_new_string((sH.getJugador()+" ha terminado el turno!").c_str());

    json_object *jstring2 = json_object_new_string(sH.getCodigo().c_str());

    json_object_object_add(jobj,"PASAR", jstring);
    json_object_object_add(jobj,"CODIGO", jstring2);

    if (strcpy(sendBuff, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }

    if (write(fd, sendBuff, strlen(sendBuff)) == -1)
    {
        printf("ERROR write()");
        exit(-1);
    }

    cout<<"Written data"<<endl;

    if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

        printf("Error en recv() \n");
        exit(-1);
    }
    printf("READ: %s\n", recvBuff);




    struct json_object *tempJugadorPasar;
    json_object *parsed_jsonJugadorPasar = json_tokener_parse(recvBuff);
    json_object_object_get_ex(parsed_jsonJugadorPasar, "PASAR", &tempJugadorPasar);

    if (json_object_get_string(tempJugadorPasar) != 0) {
        string temp = json_object_get_string(tempJugadorPasar);

        if (json_object_get_string(tempJugadorPasar) != 0) {
            string tempStrJugadorPasar = json_object_get_string(tempJugadorPasar);
            ///Se tiene el nombre del jugador en turno
            cout << "INICIO CHECK TURNO" << endl;

            this->label->setText("Esperando Turno...");

            ///Se limpian los Buffers
            memset(recvBuff, 0, MAXDATASIZE);
            memset(sendBuff, 0, MAXDATASIZE);

            ::close(fd);
            //t1.detach();

            checkTurno();
            //std::thread t1 (&pantallaTablero::checkTurno, this);
            //t1.join();

        } else {
            struct json_object *tempErr;
            json_object *parsed_jsonErr = json_tokener_parse(recvBuff);
            json_object_object_get_ex(parsed_jsonErr, "ERROR", &tempErr);
            string temp = json_object_get_string(tempErr);
            cout<<"Mensaje del Servidor: " << temp<<endl;
        }

    }


    ///Se limpian los Buffers
    memset(recvBuff, 0, MAXDATASIZE);
    memset(sendBuff, 0, MAXDATASIZE);

    ::close(fd);


}

int DragWidget::checkTurno(){
    cout << "CHECKING TURNO" << endl;

    this->label->setText("Esperando Turno...");

    char* str;
    int fd, numbytes;
    struct sockaddr_in client;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    char sendBuff[MAXDATASIZE];
    char recvBuff[MAXDATASIZE];

    struct hostent *he;

    if (fd < 0)
    {
        printf("Error : Could not create socket\n");
        return 1;
    }
    else
    {
        client.sin_family = AF_INET;
        client.sin_port = htons(PORT);
        client.sin_addr.s_addr = inet_addr("192.168.100.17");
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (::connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    json_object *jobj = json_object_new_object();

    json_object *jstringTurno = json_object_new_string("Verificando turno actual.");

    json_object *jstringCodigo = json_object_new_string(sH.getCodigo().c_str());

    json_object_object_add(jobj,"TURNO", jstringTurno);
    json_object_object_add(jobj,"CODIGO", jstringCodigo);

    if (strcpy(sendBuff, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }

    if (write(fd, sendBuff, strlen(sendBuff)) == -1)
    {
        printf("ERROR write()");
        exit(-1);
    }

    cout<<"Written data"<<endl;

    if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

        printf("Error en recv() \n");
        exit(-1);
    }
    printf("READ: %s\n", recvBuff);


    struct json_object *tempTurno;
    json_object *parsed_jsonTurno = json_tokener_parse(recvBuff);
    json_object_object_get_ex(parsed_jsonTurno, "TURNO", &tempTurno);

    if (json_object_get_string(tempTurno) != 0) {
        string temp = json_object_get_string(tempTurno);

        if (temp == getServHelp().getJugador()) {
            cout << "En Turno" << endl;
            this->label->setText("En Turno");
            this->pushButton_2->setEnabled(true);

        } else {
            cout << "Esperando Turno..." << endl;

            this->label->setText("Esperando Turno...");

            ///Se limpian los Buffers
            memset(recvBuff, 0, MAXDATASIZE);
            memset(sendBuff, 0, MAXDATASIZE);

            ::close(fd);

            checkTurno();
        }


    } else {
        struct json_object *tempErr;
        json_object *parsed_jsonErr = json_tokener_parse(recvBuff);
        json_object_object_get_ex(parsed_jsonErr, "ERROR", &tempErr);
        string temp = json_object_get_string(tempErr);
        cout<<"Mensaje del Servidor: " << temp<<endl;
     }


     ///Se limpian los Buffers
     memset(recvBuff, 0, MAXDATASIZE);
     memset(sendBuff, 0, MAXDATASIZE);

     ::close(fd);
}

void DragWidget::on_label_linkHovered(const QString &link)
{
    cout << "TEST LABEL" << endl;
}

int DragWidget::sendJsonScrabble(){
    char* str;
    int fd, numbytes;
    struct sockaddr_in client;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    char sendBuff[MAXDATASIZE];
    char recvBuff[MAXDATASIZE];

    struct hostent *he;

    if (fd < 0)
    {
        printf("Error : Could not create socket\n");
        return 1;
    }
    else
    {
        client.sin_family = AF_INET;
        client.sin_port = htons(PORT);
        client.sin_addr.s_addr = inet_addr("192.168.100.17");
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (::connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    json_object *jobj = json_object_new_object();

    json_object *jstring = json_object_new_string(sH.getCodigo().c_str());

    json_object_object_add(jobj,"CODIGO", jstring);

    /*json_object *jF1L = json_object_new_string(ui->F1Llbl->text().toUtf8());
    json_object *jF2L = json_object_new_string(ui->F2Llbl->text().toUtf8());
    json_object *jF3L = json_object_new_string(ui->F3Llbl->text().toUtf8());
    json_object *jF4L = json_object_new_string(ui->F4Llbl->text().toUtf8());
    json_object *jF5L = json_object_new_string(ui->F5Llbl->text().toUtf8());
    json_object *jF6L = json_object_new_string(ui->F6Llbl->text().toUtf8());
    json_object *jF7L = json_object_new_string(ui->F7Llbl->text().toUtf8());
    json_object *jF1P = json_object_new_string();
    json_object *jF2P = json_object_new_string(ui->F2Plbl->text().toUtf8());
    json_object *jF3P = json_object_new_string(ui->F3Plbl->text().toUtf8());
    json_object *jF4P = json_object_new_string(ui->F4Plbl->text().toUtf8());
    json_object *jF5P = json_object_new_string(ui->F5Plbl->text().toUtf8());
    json_object *jF6P = json_object_new_string(ui->F6Plbl->text().toUtf8());
    json_object *jF7P = json_object_new_string(ui->F7Plbl->text().toUtf8());

    //json_object_object_add(jobj,"CODIGO", jstring);
    json_object_object_add(jobj,"F1L", jF1L);
    json_object_object_add(jobj,"F2L", jF2L);
    json_object_object_add(jobj,"F3L", jF3L);
    json_object_object_add(jobj,"F4L", jF4L);
    json_object_object_add(jobj,"F5L", jF5L);
    json_object_object_add(jobj,"F6L", jF6L);
    json_object_object_add(jobj,"F7L", jF7L);
    json_object_object_add(jobj,"F1P", jF1P);
    json_object_object_add(jobj,"F2P", jF2P);
    json_object_object_add(jobj,"F3P", jF3P);
    json_object_object_add(jobj,"F4P", jF4P);
    json_object_object_add(jobj,"F5P", jF5P);
    json_object_object_add(jobj,"F6P", jF6P);
    json_object_object_add(jobj,"F7P", jF7P);*/


    if (strcpy(sendBuff, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }

    if (write(fd, sendBuff, strlen(sendBuff)) == -1)
    {
        printf("ERROR write()");
        exit(-1);
    }

    cout<<"Written data SCRABBLE"<<endl;

    if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

        printf("Error en recv() \n");
        exit(-1);
    }
    printf("READ SCRABBLE : %s\n", recvBuff);




    struct json_object *tempVerif;
    json_object *parsed_jsonVerif = json_tokener_parse(recvBuff);
    json_object_object_get_ex(parsed_jsonVerif, "VERIFICACION", &tempVerif);

    if (json_object_get_string(tempVerif) != 0) {
        string temp = json_object_get_string(tempVerif);

        if (temp == "false"){
            //False, devolver fichas a lista jugador, permite volver a ponerlas, vuelve a empezar el turno
            cout<<temp<<endl;
            memset(recvBuff, 0, MAXDATASIZE);
            memset(sendBuff, 0, MAXDATASIZE);

            ::close(fd);
        }else {
            cout<<"puntos"<<endl;
        }

    }


    ///Se limpian los Buffers
    memset(recvBuff, 0, MAXDATASIZE);
    memset(sendBuff, 0, MAXDATASIZE);

    ::close(fd);
}

void DragWidget::on_pushButton_clicked()
{
    sendJsonScrabble();
    this->pushButton_2->setEnabled(false);
    this->label->setText("Esperando Turno...");
    std::thread t1 (&DragWidget::sendJsonPasar, this);
    t1.join();
}
