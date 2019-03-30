//
// Created by jose on 27/03/19.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <iostream>


#define PORT 3550


#define MAXDATASIZE 1000

int main (){
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
        client.sin_addr.s_addr = htonl(INADDR_ANY);
        memset(client.sin_zero, '\0', sizeof(client.sin_zero));
    }

    if (connect(fd, (const struct sockaddr *)&client, sizeof(client)) < 0)
    {
        printf("ERROR connecting to server\n");
        return 1;
    }

    if ((numbytes=recv(fd,buf,MAXDATASIZE,0)) < 0){

        printf("Error en recv() \n");
        exit(-1);
    }



    printf("Mensaje del Servidor: %s\n",buf);

    memset(buf, 0, MAXDATASIZE);

    close(fd);
}