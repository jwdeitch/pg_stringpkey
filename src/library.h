#ifndef PG_STRINGPKEY_LIBRARY_H
#define PG_STRINGPKEY_LIBRARY_H
char *generate_token(int collision_sensitivity, size_t desired_str_length);
static char *rand_string(char *str, size_t size);
bool collision_detected(char *str);
#endif