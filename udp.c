#include "udp.h"

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sock_t {
	int sender_fd, receiver_fd;
	struct sockaddr_in sender, receiver;
} sock_t;

// Cross platform socket implementation
sock_t *sock_new(const char *ip, int sender_port, int receiver_port) {
	sock_t *sock = malloc(sizeof(sock_t));

	sock->sender_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	sock->sender.sin_family = AF_INET;
	sock->sender.sin_port = htons(sender_port);
	sock->sender.sin_addr.s_addr = inet_addr(ip);

	sock->receiver_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	sock->receiver.sin_family = AF_INET;
	sock->receiver.sin_port = htons(receiver_port);
	sock->receiver.sin_addr.s_addr = inet_addr(ip);

	if (sock->sender_fd < 0) {
		perror("sender socket");
	}
	if (sock->receiver_fd < 0) {
		perror("receiver socket");
	}
	printf("sender_fd: %d\n", sock->sender_fd);
	printf("receiver_fd: %d\n", sock->receiver_fd);

	return sock;
}
void sock_free(sock_t *sock) { free(sock); }
int sock_bind(sock_t *sock) {
	// reuse address
	// int opt = 1;
	// setsockopt(sock->receiver_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	int ret = bind(sock->receiver_fd, (struct sockaddr *)&sock->receiver, sizeof(sock->receiver));
	// If binding fails due to address already in use, flip sender and receiver ports and try again
	if (ret < 0) {
		printf("Binding failed, trying again with flipped ports\n");
		int temp = sock->sender.sin_port;
		sock->sender.sin_port = sock->receiver.sin_port;
		sock->receiver.sin_port = temp;
		return bind(sock->receiver_fd, (struct sockaddr *)&sock->receiver, sizeof(sock->receiver));
	}
	return ret;
}
ssize_t sock_recv(sock_t *sock, char *buf, int len) {
	// struct sockaddr_in temp;
	socklen_t addr_len = sizeof(sock->receiver);
	return recvfrom(sock->receiver_fd, buf, len, 0, (struct sockaddr *)&sock->receiver, &addr_len);
}

ssize_t sock_send(sock_t *sock, const char *buf, int len) {
	return sendto(sock->sender_fd, buf, len, 0, (struct sockaddr *)&sock->sender, sizeof(sock->sender));
}