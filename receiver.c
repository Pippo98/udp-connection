#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <math.h>
#include <sys/time.h>

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

	const int tests = 1e5;
	uint64_t tests_times[tests];
	union u64 sent, recv;

	sock_recv(sock, recv.c, sizeof(recv.c));
	for (int i = 0; i < tests; i++) {
		sent.u64 = get_timestamp_u();
		sock_send(sock, sent.c, sizeof(sent.c));
		sock_recv(sock, recv.c, sizeof(recv.c));

		tests_times[i] = recv.u64 - sent.u64;
		usleep(5);
	}
	// caluculate average and std deviation
	uint64_t sum = 0;
	for (int i = 0; i < tests; i++) {
		sum += tests_times[i];
	}
	double avg = sum / tests;
	double std_dev = 0;
	for (int i = 0; i < tests; i++) {
		std_dev += (tests_times[i] - avg) * (tests_times[i] - avg);
	}
	std_dev = sqrt(std_dev / tests);

	printf("Average: %f microseconds\n", avg);
	printf("Std Dev: %f microseconds\n", std_dev);

	return EXIT_SUCCESS;
}