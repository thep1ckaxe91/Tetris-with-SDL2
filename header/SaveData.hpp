#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP
#include "constant.hpp"
using namespace std;


int get_personal_best();
void set_personal_best(int score);

int bytes_to_int(const char *c);
char *int_to_bytes(int x);

float get_sfx_volume();
float get_music_volume();
void set_sfx_volume(float value);
void set_music_volume(float value);

#endif