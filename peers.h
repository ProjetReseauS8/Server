#ifndef PEERS_H
#define PEERS_H
#define MAX_PEERS 100
#define MAX_FILE 100
#define SENDING 3
#define COMPLET 1
#define DOWNLOADING 2
#define INIT 0
#define ERROR -1
#define _STR_SIZE 50
#define _SIZE_IP 16
#define _SIZE_PORT 6

#include <pthread.h>
#include "connect.h"

struct peers_list *peers; 


struct file{
  char *name_; 
  char *size_; 
  char *key_; 
  int state_; 
};

struct peer{
  char *ip_; 
  char *port_; 
  struct file ** file_list_; 
  int nb_; 
};

struct peers_list{
  struct peer ** peers_list_; 
  int nb_; 
}; 


struct peers_list *creat_list(); 
struct peer  *p_init_(); 
struct file *creat_file(); 
struct peer *find_peer(struct peer *p); 
struct file *find_file(char *key); 

void add_peer( struct peer *p); 
void add_file(struct peer *p, struct file *f);
void remove_peer(struct peers_list *l, struct peer *p); 

void display_peers(struct peers_list *l); 

#endif  
