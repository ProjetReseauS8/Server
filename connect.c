#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "connect.h"

#define SIZE 1024

int socket_ (int portno) {
  int fd;
  struct sockaddr_in server_;
  fd = socket(AF_INET, SOCK_STREAM, 0); 				
  if (fd < 0)
    perror ("Ereeur d'ouverture de la socket");
  memset((char *) &server_, 0, sizeof(server_));				        
  server_.sin_family = AF_INET;
  server_.sin_addr.s_addr = INADDR_ANY;					
  server_.sin_port = htons(portno);				        
  if (bind (fd, (struct sockaddr *) &server_, sizeof(server_)) < 0)
    return fd;
}

struct connect accept_ (int fd) {
  int tmp;
  struct sockaddr_in client_;
  socklen_t sinsize = sizeof(struct sockaddr_in);				
  tmp = accept (fd, (struct sockaddr*) &client_, &sinsize);	
  struct connect connexion;
  connexion.fd = tmp;
  connexion.ip = inet_ntoa(client_.sin_addr);
  
  if (tmp < 0)
    perror("Erreur");
  return connexion;
}

void write_ (int fd, char *buffer) {
  int i = send (fd, buffer, strlen(buffer), 0);
  if (i == -1)
    perror ("Erreur d'écriture");
}

int read_ (int fd, char *buffer) {
  memset(buffer, 0, SIZE);
  errno = 0;
  int i = recv (fd, buffer, SIZE, 0);
  if (i == 0)
    return -1;
  if (i == -1) 
    perror("Erreur de lecture");
  return i;
}






