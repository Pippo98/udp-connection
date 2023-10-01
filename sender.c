#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/time.h>
#include <math.h>

#include "udp.h"

union u64 {
	uint64_t u64;
	char c[sizeof(uint64_t) + 1024 * 2 * 2];
};

static uint64_t get_timestamp_u() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * (uint64_t)1000000 + tv.tv_usec;
}

int main(void) {
	sock_t *sock = sock_new("192.168.1.10", 1234, 1235);

	if (sock_bind(sock) == -1) {
		perror("sock_bind");
		return EXIT_FAILURE;
	}

	uint64_t bytes_received = 0;
	union u64 sent, recv;

	sock_send(sock, sent.c, sizeof(sent.c));
	while (1) {

		bytes_received = sock_recv(sock, recv.c, sizeof(recv.c));
		sent.u64 = get_timestamp_u();
		sock_send(sock, sent.c, sizeof(sent.c));

		printf("Bytes received: %lu\n", bytes_received);
	}

	return EXIT_SUCCESS;
}