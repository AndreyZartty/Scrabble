#include "serverHelper.h"

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

serverHelper::serverHelper()
{

}

int serverHelper::send(string instruccion) {
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
        client.sin_addr.s_addr = inet_addr("192.168.100.17");
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (::connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    ///Crea un objeto JSON para enviar
    json_object *jobj = json_object_new_object();

    ///Codigo del juego
    json_object *jstringCodigo = json_object_new_string(getCodigo().c_str());
    ///Instruccion por ejecutar en servidor
    json_object *jstring = json_object_new_string(instruccion.c_str());

    ///Ingresa al JSON el codigo y la instruccion
    json_object_object_add(jobj,"CODIGO", jstringCodigo);
    json_object_object_add(jobj,"INSTRUCCION", jstring);



    if (strcpy(buf, json_object_to_json_string(jobj)) == nullptr) {
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
