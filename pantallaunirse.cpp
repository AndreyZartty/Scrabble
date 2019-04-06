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

    json_object *jobj = json_object_new_object();

    QString txt = ui->lineEdit->text();
    QString txt2 = ui->lineEdit_2->text();
    json_object *jstring = json_object_new_string(txt.toUtf8());
    json_object *jstring2 = json_object_new_string(txt2.toUtf8());

    json_object_object_add(jobj,"Nombre", jstring2);
    json_object_object_add(jobj,"CODIGO", jstring);



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

void pantallaunirse::on_UnirseButton_clicked()
{
    SendJson();
}
