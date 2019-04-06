#include "pantallacrear.h"
#include "ui_pantallacrear.h"

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

#define PORT 3550
#define MAXDATASIZE 1000

using namespace std;

pantallaCrear::pantallaCrear(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaCrear)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Crear_J()));

}

pantallaCrear::~pantallaCrear()
{
    delete ui;
}

int pantallaCrear::Crear_J(){
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

    //QString nick = ui->nick_line->text();
    QString cant = ui->cant_spin->text();

    json_object *jobj = json_object_new_object();

    json_object *jstring = json_object_new_string(getJugador().c_str());

    json_object *jint = json_object_new_int(cant.toInt());

    json_object_object_add(jobj,"JUGADOR", jstring);
    json_object_object_add(jobj,"JUGADORES PERMITIDOS", jint);



    if (strcpy(sendBuff, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }

    if (write(fd, sendBuff, strlen(sendBuff)) == -1)
    {
        printf("ERROR write()");
        exit(-1);
    }

    printf("Written data\n");

    if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

        printf("Error en recv() \n");
        exit(-1);
    }



    struct json_object *tempCodigo;
    json_object *parsed_jsonCodigo = json_tokener_parse(recvBuff);
    json_object_object_get_ex(parsed_jsonCodigo, "CODIGO", &tempCodigo);
    code = json_object_get_string(tempCodigo);
    cout<<"Mensaje del Servidor: " << code <<"\n"<<endl;




    memset(sendBuff, 0, MAXDATASIZE);

    ::close(fd);

    pantallaEspera *tab = new pantallaEspera;
    tab->setCode(code);
    //tab->show();
    //hide();
}

void pantallaCrear::on_graf_button_clicked()
{
    pantallaTablero *tab = new pantallaTablero;
    tab->show();
    hide();
}

string pantallaCrear::getJugador(){
    return jugador;
}
string pantallaCrear::getCode(){
    return code;
}
void pantallaCrear::setCode(string _code){
    code = _code;
}
void pantallaCrear::setJugador(string _jugador){
    jugador = _jugador;
}
