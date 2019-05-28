#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include "stud.h"

void generate(int &kiekis);
void nuskaitymas(vector <stud> &x);
void skaityti (vector <stud> &x,int &kiekis);
void sort(vector <stud> &x,int &kiekis);
void print2(vector <stud> &printable);
bool number(string const &c);
