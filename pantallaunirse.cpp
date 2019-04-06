#include "pantallaunirse.h"
#include "ui_pantallaunirse.h"

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

pantallaunirse::pantallaunirse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaunirse)
{
    ui->setupUi(this);
}

pantallaunirse::~pantallaunirse()
{
    delete ui;
}

int pantallaunirse::SendJson()
{
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

    QString txt = ui->lineEdit->text();
    json_object *jstring = json_object_new_string(getJugador().c_str());
    json_object *jstring2 = json_object_new_string(txt.toUtf8());

    json_object_object_add(jobj,"JUGADOR", jstring);
    json_object_object_add(jobj,"CODIGO", jstring2);


    if (strcpy(sendBuff, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }
    cout<<"FUNKA MRDA2\n"<<endl;


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

    cout<<"Mensaje del Servidor: " << recvBuff <<"\n"<<endl;

    memset(sendBuff, 0, MAXDATASIZE);


    ::close(fd);
}

void pantallaunirse::on_UnirseButton_clicked()
{
    SendJson();
    pantallaEspera *tab = new pantallaEspera();
    tab->setCode(code);
    tab->setLinetxt();
    tab->show();
    hide();
}

string pantallaunirse::getJugador(){
    return jugador;
}
string pantallaunirse::getCode(){
    return code;
}
void pantallaunirse::setCode(string _code){
    code = _code;
}
void pantallaunirse::setJugador(string _jugador){
    jugador = _jugador;
}
