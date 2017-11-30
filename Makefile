build:
	cc src/*.c -I`pg_config --includedir-server` -lm -g -Wall -Werror -o pg_stringpkey

release:
	cc src/*.c -I`pg_config --includedir-server` -lm -g -Wall -Werror -o pg_stringpkey -O3