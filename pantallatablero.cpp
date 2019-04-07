#include "pantallatablero.h"
#include "ui_pantallatablero.h"

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
#include <iostream>
#include <json-c/json.h>
#include <json-c/debug.h>
#include <json-c/json_object.h>
#include <QMessageBox>

#define PORT 3550
#define MAXDATASIZE 1000

pantallaTablero::pantallaTablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaTablero)
{
    ui->setupUi(this);
}

pantallaTablero::~pantallaTablero()
{
    delete ui;
}

void pantallaTablero::setServHelp(serverHelper _sH){
    sH = _sH;
}
serverHelper pantallaTablero::getServHelp(){
    return sH;
}

void pantallaTablero::setLabels(string _j1, string _j2, string _j3, string _j4){
    ui->lbl_J1->setText(QString::fromUtf8(_j1.c_str()));
    ui->lbl_J2->setText(QString::fromUtf8(_j2.c_str()));
    ui->lbl_J3->setText(QString::fromUtf8(_j3.c_str()));
    ui->lbl_J4->setText(QString::fromUtf8(_j4.c_str()));

}

void pantallaTablero::on_pushButton_2_clicked()
{
    sendJsonPasar();
}

int pantallaTablero::sendJsonPasar(){
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

            ///Se limpian los Buffers
            memset(recvBuff, 0, MAXDATASIZE);
            memset(sendBuff, 0, MAXDATASIZE);

            ::close(fd);

            checkTurno();

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

int pantallaTablero::checkTurno(){
    cout << "CHECKING TURNO" << endl;
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
            ui->label->setText("En Turno");

        } else {
            cout << "Esperando Turno..." << endl;

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


void pantallaTablero::on_label_linkHovered(const QString &link)
{
    cout << "TEST LABEL" << endl;
}
