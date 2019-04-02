#include "pantallajuego.h"
#include "ui_pantallajuego.h"

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

PantallaJuego::PantallaJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Crear_J()));
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}

int PantallaJuego::Crear_J(){
    char* str;
    int fd, numbytes;
    struct sockaddr_in client;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    char buf[MAXDATASIZE];

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
        client.sin_addr.s_addr = inet_addr("192.168.100.13");
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (::connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    QString nick = ui->nick_line->text();
    QString cant = ui->cant_spin->text();

    json_object *jobj = json_object_new_object();

    json_object *jstring = json_object_new_string(nick.toUtf8().constData());

    json_object *jint = json_object_new_int(cant.toInt());

    json_object_object_add(jobj,"HOST", jstring);
    json_object_object_add(jobj,"CANTIDAD DE JUGADORES", jint);



    if (strcpy(buf, json_object_to_json_string(jobj)) == NULL) {
        printf("ERROR strcpy()");
        exit(-1);
    }

    if (write(fd, buf, strlen(buf)) == -1)
    {
        printf("ERROR write()");
        exit(-1);
    }

    printf("Written data\n");

    memset(buf, 0, MAXDATASIZE);

    ::close(fd);
}
