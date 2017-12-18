#ifndef PG_STRINGPKEY_LIBRARY_H
#define PG_STRINGPKEY_LIBRARY_H

const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char *generate_token(size_t desired_str_length, int collision_sensitivity);
double likelihood_of_collision(size_t key_length_count, int record_count);
static char *gen_rand_string(char *str, size_t size);
#endif