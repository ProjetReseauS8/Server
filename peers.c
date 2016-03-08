#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peers.h"

struct file *file_init () {
  struct file *f = malloc (sizeof (struct file));
  f->name_ = malloc(_STR_SIZE);
  f->size_ = malloc(_STR_SIZE);
  f->key_ = malloc(_STR_SIZE);
  f->state_ = 0;
  return f;
}

struct file *create_file (char *name_, char *size_, char *block_size_, char *key_, int state_) {
  struct file *f = init_file ();
  strcpy(f->name_, name_);
  strcpy(f->size_, size_);
  strcpy(f->key_, key_);
  f->state_= state_;
  return f;
}

struct peers_list *create_peers_list () {
  struct peers_list *l = malloc (sizeof (struct peers_list));
  l->peers_list_ = NULL;
  l->nb_ = 0;
  return l;
}

struct peer *peer_init_ () {
  struct peer *peer_ = malloc (sizeof (struct peer));
  peer_->ip_ = malloc(_SIZE_IP);
  peer_->port_ = malloc(_SIZE_PORT);
  peer_->file_list_ = NULL;
  peer_->nb_ = 0;
  return peer_;
}

struct peer *create_peer (char *ip, char *port) {
  struct peer *p = init_peer ();
  strcpy(p->ip_, ip);
  strcpy(p->port_, port);
  return p;
}

struct peer* find_peer (struct peer *s) {
  if (peers== NULL) return 0;
  int i;
  struct peer *p;
  for (i=0; i<peers->nb_; i++) {
    p = peers->peers_list_[i];
    if (strcmp(p->ip_, s->ip_) == 0 && strcmp(p->port_, s->port_) == 0)
      return p;
  }
  return NULL;
}

struct peer * find_peer_ip (struct connect ip_socket) {
  int i;
  struct peer * p;
  for (i=0; i<peers->nb_; i++) {
    p = peers->peers_list_[i];
    if (equal (p->ip_, ip_socket.ip))
      return p;
  }																														       	      	retureturn  NULL;
}

struct file * find_file (char * key) {
  int i, j;
  struct peer * peer_;
  struct file * file_;
  for (i=0; i<peers->nb_; i++) {
    peer_ = peers->peers_list_[i];
    if (peer_->file_list_ != NULL) {
      for (j=0; j<peers->nb_; j++) {
	file_ = peer_->file_list_[j];
	if (equal (file_->key_, key)) 
	  return file_;
      }
    }
  }
  return NULL;
}

void add_file (struct peer *peer_,struct file *file_) {
  peer_->file_list_ = realloc (peer_->file_list_, sizeof(struct file*) * (peer_->nb_ + 1));
  peer_->file_list_[peers->nb_] = file_;
  peer_->nb_+=1;
}

void add_peer (struct peer *peer_) {
  peers->peers_list_ = realloc (peers->peers_list_, sizeof(struct peer*) * (peers->nb_ + 1));
  peers->peers_list_[peers->nb_] = peer_;
  peers->nb_+=1;
}


