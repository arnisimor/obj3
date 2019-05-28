#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class stud
{
private:
string vardas_;
string pavarde_;
vector <int> nd_;
int egzaminas_;
double mediana_;
double galb_;

public:
string vardas() const {return vardas_;}
string pavarde() const {return pavarde_;}
vector<int> nd() const {return nd_;}
double mediana() const {return mediana_;}
double galb() const {return galb_;}
void set_vardas(string vardas) {vardas_ = vardas;}
void set_pavarde(string pavarde) {pavarde_ = pavarde;}
void set_nd(vector<int> nd) {nd_ = nd;}
void set_egzaminas(int egzaminas) {egzaminas_ = egzaminas;}
void set_mediana(double mediana) {mediana_ = mediana;}
void set_galb(double galb) {galb_ = galb;}
void median();
void galutinis();

};

#endif
