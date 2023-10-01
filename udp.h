#ifndef __UDP_H__
#define __UDP_H__

#include <stdio.h>

typedef struct sock_t sock_t;

sock_t *sock_new(const char *ip, int sender_port, int receiver_port);
void sock_free(sock_t *sock);

int sock_bind(sock_t *sock);
ssize_t sock_recv(sock_t *sock, char *buf, int len);
ssize_t sock_send(sock_t *sock, const char *buf, int len);

#endif // __UDP_H__