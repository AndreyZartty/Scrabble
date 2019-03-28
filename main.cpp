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


#define PORT 3550


#define MAXDATASIZE 1000


int main(int argc, char *argv[])
{
    int fd, numbytes;


    char buf[MAXDATASIZE];


    struct hostent *he;


    struct sockaddr_in server;


    if (argc !=2) {

        printf("Uso: %s <Dirección IP>\n",argv[0]);
        exit(-1);
    }

    if ((he=gethostbyname(argv[1]))==NULL){
        printf("gethostbyname() error\n");
        exit(-1);
    }

    if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
        printf("socket() error\n");
        exit(-1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    server.sin_addr = *((struct in_addr *)he->h_addr);

    bzero(&(server.sin_zero),8);

    if(connect(fd, (struct sockaddr *)&server,
               sizeof(struct sockaddr))==-1){

        printf("connect() error\n");
        exit(-1);
    }

    if ((numbytes=recv(fd,buf,MAXDATASIZE,0)) == -1){

        printf("Error en recv() \n");
        exit(-1);
    }

    buf[numbytes]='\0';

    printf("Mensaje del Servidor: %s\n",buf);


    close(fd);

}