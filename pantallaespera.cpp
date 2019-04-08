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

void pantallaEspera::setServHelp(serverHelper _sH){
    sH = _sH;
}
serverHelper pantallaEspera::getServHelp(){
    return sH;
}

void pantallaEspera::setLinetxt(){
    QString qcode = QString::fromStdString(sH.getCodigo());
    ui->lineEdit->setText(qcode);
    //SendJson();
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

     json_object *jstring_codigo = json_object_new_string(sH.getCodigo().c_str());

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
     memset(sendBuff, 0, MAXDATASIZE);
     cout<<"teeeeeest"<<endl;

     if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

         cout<<"Error en recv()"<<endl;
         exit(-1);
     }
     cout<<"kk"<<endl;


     struct json_object *tempConfir;
     json_object *parsed_jsonConfir = json_tokener_parse(recvBuff);
     json_object_object_get_ex(parsed_jsonConfir, "JUGARSRV", &tempConfir);
     memset(recvBuff, 0, MAXDATASIZE);


     if (json_object_get_string(tempConfir) != 0) {
         string temp = json_object_get_string(tempConfir);
         if(temp=="TRUE"){
             string tempJ1L = "";
             string tempJ2L = "";
             string tempJ3L = "";
             string tempJ4L = "";

             json_object *jobjJ = json_object_new_object();

             json_object *jstringJ = json_object_new_string("Obteniendo nombres...");

             json_object_object_add(jobjJ,"NOMBRES", jstring);

             json_object_object_add(jobjJ, "CODIGO", jstring_codigo);


             if (strcpy(sendBuff, json_object_to_json_string(jobjJ)) == NULL) {
                 printf("ERROR strcpy()");
                 exit(-1);
             }

             if (write(fd, sendBuff, strlen(sendBuff)) == -1)
             {
                 printf("ERROR write()");
                 exit(-1);
             }



             if ((numbytes=recv(fd,recvBuff,MAXDATASIZE,0)) < 0){

                 printf("Error en recv() \n");
                 exit(-1);
             }

             struct json_object *tempJ1;
             json_object *parsed_jsonJ1 = json_tokener_parse(recvBuff);
             json_object_object_get_ex(parsed_jsonJ1, "JUGADOR1", &tempJ1);

             struct json_object *tempJ2;
             json_object *parsed_jsonJ2 = json_tokener_parse(recvBuff);
             json_object_object_get_ex(parsed_jsonJ2, "JUGADOR2", &tempJ2);

             struct json_object *tempJ3;
             json_object *parsed_jsonJ3 = json_tokener_parse(recvBuff);
             json_object_object_get_ex(parsed_jsonJ3, "JUGADOR3", &tempJ3);

             struct json_object *tempJ4;
             json_object *parsed_jsonJ4 = json_tokener_parse(recvBuff);
             json_object_object_get_ex(parsed_jsonJ4, "JUGADOR4", &tempJ4);

             if (json_object_get_string(tempJ1) != 0 && json_object_get_string(tempJ2) != 0) {
                 tempJ1L = json_object_get_string(tempJ1);
                 tempJ2L = json_object_get_string(tempJ2);
                 if (json_object_get_string(tempJ3) != 0){
                     tempJ3L = json_object_get_string(tempJ3);
                     if (json_object_get_string(tempJ4) != 0){
                         tempJ4L = json_object_get_string(tempJ4);

                     }
                 }
             }else {
                 struct json_object *tempErr;
                 json_object *parsed_jsonErr = json_tokener_parse(recvBuff);
                 json_object_object_get_ex(parsed_jsonErr, "ERROR", &tempErr);
                 string temp = json_object_get_string(tempErr);
                 cout<<"Mensaje del Servidor: " << temp<<endl;
             }
             pantallaTablero *tab = new pantallaTablero;
             DragWidget *dr = new DragWidget(tab);

             tab->setServHelp(sH);
             tab->setLabels(tempJ1L, tempJ2L, tempJ3L, tempJ4L);
             tab->show();

             //prueba *tab2 = new prueba;
             //DragWidget *dr = new DragWidget(tab2);
             //tab2->show();

             hide();


             //break;
         }
         else {
             QMessageBox::information(this, tr("Error"), tr("Faltan jugadores por unirse"));
         }
     }
     cout<< "TENGA UN BONITO DIA" << endl;
     ///Se limpian los Buffers
     memset(recvBuff, 0, MAXDATASIZE);
     memset(sendBuff, 0, MAXDATASIZE);

     ::close(fd);

}





void pantallaEspera::on_pushButton_clicked()
{
    SendJson();
}
