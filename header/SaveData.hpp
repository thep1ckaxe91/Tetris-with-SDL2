#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP
#include "constant.hpp"
using namespace std;


int get_personal_best();
void set_personal_best(int score);

int bytes_to_int(const char *c);
char *int_to_bytes(int x);

#endif