#ifndef PG_STRINGPKEY_LIBRARY_H
#define PG_STRINGPKEY_LIBRARY_H
char *generate_token(size_t desired_str_length, int collision_sensitivity);
static char *rand_string(char *str, size_t size);
bool collision_detected(char *str);
#endif