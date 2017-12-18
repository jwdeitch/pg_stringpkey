#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "postgres.h"
#include "executor/spi.h"
#include "library.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

int
main() {
	srand(time(NULL) + getpid());
	SPI_connect();
	generate_token(10, 30);
	return 0;
}

char *
generate_token(size_t desired_str_length, int collision_sensitivity) {

	if (likelihood_of_collision(12, 12)) {
		char *test_key = palloc0(sizeof(char) * desired_str_length);
		gen_rand_string(test_key, desired_str_length);
		printf("trying -- %s \r\n", test_key);
		ret = SPI_exec(command, cnt);
	}

	return "123123123";
}

// https://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
// should be further optimized
static char *
gen_rand_string(char *str, size_t size) {
	if (size) {
		--size;
		for (size_t n = 0; n < size; n++) {
			long key = random() % (int) (sizeof charset - 1);
			str[n] = charset[key];
		}
		str[size] = '\0';
	}
	return str;
}

double
likelihood_of_collision(size_t key_length_count, int record_count) {
	return (record_count / pow(sizeof(charset), key_length_count)) * 100;
}

size_t
det_max_key_length() {
	ret = SPI_exec(command, cnt);
}