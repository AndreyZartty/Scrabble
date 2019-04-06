#include "pantallaespera.h"
#include "ui_pantallaespera.h"

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
#include <thread>

#define PORT 3550
#define MAXDATASIZE 1000


pantallaEspera::pantallaEspera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaEspera)
{
    ui->setupUi(this);
    //std::thread t1(pause_thread, 1);
    //t1.join();
}

pantallaEspera::~pantallaEspera()
{
    delete ui;
}

void pantallaEspera::setCode(string _code){
    code = _code;
}
string pantallaEspera::getcode(){
    return code;
}

void pantallaEspera::setLinetxt(){
    QString qcode = QString::fromStdString(code);
    ui->lineEdit->setText(qcode);
    //SendJson();
}

 int pantallaEspera::MendJson()
{
    char* str;
    int fd, numbytes, r;
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

    json_object *jstring = json_object_new_string("Esperando Jugadores...");

    json_object_object_add(jobj,"COMENZAR", jstring);

    //while(true){
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

        cout<< "Test while pantalla espera" << endl;/*
        for (;;) {
                    r = read(fd, recvBuff, MAXDATASIZE);

                    if (r == -1) {
                        perror("read");
                        return EXIT_FAILURE;
                    }
                    if (r == 0)
                        break;
                    printf("READ: %s\n", recvBuff);
        }

        if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) != 0){

             cout<< "Test while pantalla espera ifg" << endl;
            printf("Error en recv() \n");
            exit(-1);
        }
        cout<< "Test while pantalla espera 4" << endl;
        struct json_object *tempConfir;
        json_object *parsed_jsonConfir = json_tokener_parse(recvBuff);
        json_object_object_get_ex(parsed_jsonConfir, "COMENZAR", &tempConfir);
        string temp = json_object_get_string(tempConfir);
        cout<< "Test while pantalla espera 3" << endl;
        if(temp=="TRUE"){
            cout<< "NO VA A EJECUTARSE GAY " << endl;
            pantallaTablero *tab = new pantallaTablero;
            tab->setCode(getcode());
            tab->show();
            hide();
            //break;
        }

        memset(sendBuff, 0, MAXDATASIZE);
        memset(recvBuff, 0, MAXDATASIZE);

        cout<< "Test while pantalla espera 2" << endl;
    //}*/
    ::close(fd);
}

 int pantallaEspera::SendJson(){
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

     json_object *jstring = json_object_new_string("Esperando Jugadores...");

     json_object *jstring_codigo = json_object_new_string(getcode().c_str());

     json_object_object_add(jobj,"JUGARCL", jstring);

     json_object_object_add(jobj, "CODIGO", jstring_codigo);



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

         cout<<"Error en recv()"<<endl;
         exit(-1);
     }
     cout<<"kk"<<endl;


     struct json_object *tempConfir;
     json_object *parsed_jsonConfir = json_tokener_parse(recvBuff);
     json_object_object_get_ex(parsed_jsonConfir, "JUGARSRV", &tempConfir);


     if (json_object_get_string(tempConfir) != 0) {
         string temp = json_object_get_string(tempConfir);
         if(temp=="TRUE"){
             cout<< "NO VA A EJECUTARSE GAY " << endl;
             pantallaTablero *tab = new pantallaTablero;
             tab->setCode(getcode());
             tab->show();
             hide();
             //break;
         }
     }
     cout<< "TENGA UN BONITO DIA" << endl;
     ///Se limpian los Buffers
     memset(recvBuff, 0, MAXDATASIZE);
     memset(sendBuff, 0, MAXDATASIZE);

     ::close(fd);

}




