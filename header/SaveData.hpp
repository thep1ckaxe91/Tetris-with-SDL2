#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP
#include "constant.hpp"
#include "bits/stdc++.h"
using namespace std;

const int score_offset_byte = 9284;
const int total_byte = score_offset_byte+283;

int get_personal_best();
void set_personal_best(int score);


#endif