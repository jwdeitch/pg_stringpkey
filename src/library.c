#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "postgres.h"
#include "executor/spi.h"
#include "library.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

int
main() {
	srand(time(NULL) * getpid());
	SPI_connect();
	generate_token(10, 10);
	return 0;
}

char *
generate_token(size_t desired_str_length, int collision_sensitivity) {

	while (collision_sensitivity--) {
		char *test = malloc(sizeof(char) * desired_str_length);
		rand_string(test, desired_str_length);
		printf("trying -- %s \r\n", test);
		ret = SPI_exec(command, cnt);
	}

	return "123123123";
}

//bool collision_detected(char *str) {

//}

// https://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
// should be further optimized
static char *
rand_string(char *str, size_t size) {
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK0123456789";
	if (size) {
		--size;
		for (size_t n = 0; n < size; n++) {
			int key = rand() % (int) (sizeof charset - 1);
			str[n] = charset[key];
		}
		str[size] = '\0';
	}
	return str;
}