#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class stud
{
private:
string vardasp;
string pavardep;
vector <int> ndp;
int egzp;
double medp;
double galbp;

public:
string vardas() const {return vardasp;}
string pavarde() const {return pavardep;}
vector<int> nd() const {return ndp;}
double med() const {return medp;}
double galb() const {return galbp;}
void set_vardas(string vardas) {vardasp = vardas;}
void set_pavarde(string pavarde) {pavardep = pavarde;}
void set_nd(vector<int> nd) {ndp = nd;}
void set_egz(int egz) {egzp = egz;}
void set_med(double med) {medp = med;}
void set_galb(double galb) {galbp = galb;}

void median();
void galutinis();

};

void generate(int &kiekis);
void skaityti (vector <stud> &x,int &kiekis);
void sort(vector <stud> &x,int &kiekis);
void print2(vector <stud> &printable);
bool number(string const &c);

#endif
