#ifndef CONNECT_H
#define CONNECT_H

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

struct connect{
  char *ip; 
  int fd; 
}; 


int socket_ (int );
struct connect accept_(int );
void write_ (int , char *);
int read_ (int , char *);
#endif
