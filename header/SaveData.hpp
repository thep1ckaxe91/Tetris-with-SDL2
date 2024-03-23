#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP
#include "constant.hpp"
#include "bits/stdc++.h"
#include "SDL2/SDL.h"
using namespace std;


int get_personal_best();
void set_personal_best(int score);
/**
 * @brief compress 4 bytes into 1 integer variable
 * 
 * @param c1 the most significant byte
 * @param c2 
 * @param c3 
 * @param c4 the least significant byte
 * @return int the integer the have c1 as the most significant byte to c4 is the least one
 */
int bytes_to_int(char c1,char c2,char c3,char c4);
/**
 * @brief allocate a char pointer that represent the int that passed
 * user should free the memory with delete []
 * @param x the value to cut to bytes
 * @return char* pointer to the heap allocated mem that represent the value
 */
char *int_to_bytes(int x);

#endif