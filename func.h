#pragma once
#include<iostream>
#include "Planeta.h"
Planeta** read_db(Planeta** arr, char* filename);
int amount(char* filename);
int write_file(char* filename, int& N);
int read_file(char* filename, Planeta** arr, int& N);
int write_new_file(Planeta** arr, int& a);
int sort_puserek(char* filename, Planeta** arr, int& n);
int edit(char* filename, Planeta** arr);
