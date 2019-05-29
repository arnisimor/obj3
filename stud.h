#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class zmogus
{
protected:
string vardas_;
string pavarde_;
public:
    string vardas() const {return vardas_;}
    string pavarde() const {return pavarde_;}
    virtual void set_vardas(string vardas) {vardas_ = vardas;}
    virtual void set_pavarde(string pavarde) {pavarde_ = pavarde;}
};
class stud:public zmogus
{
private:
vector <int> nd_;
int egzaminas_;
double mediana_;
double galb_;

public:
stud(){};
~stud(){};
stud(const stud &studis)
    {
        vardas_ = studis.vardas_;
        pavarde_ = studis.pavarde_;
        nd_ = studis.nd_;
        egzaminas_=studis.egzaminas_;
        mediana_ = studis.mediana_;
        galb_ = studis.galb_;
    }
stud operator=(stud other)
    {
        std::swap(vardas_, other.vardas_);
        std::swap(pavarde_, other.pavarde_);
        std::swap(nd_, other.nd_);
        std::swap(egzaminas_, other.egzaminas_);
        std::swap(mediana_, other.mediana_);
        std::swap(galb_, other.galb_);
    }
vector<int> nd() const {return nd_;}
double mediana() const {return mediana_;}
double galb() const {return galb_;}
void set_nd(vector<int> nd) {nd_ = nd;}
void set_egzaminas(int egzaminas) {egzaminas_ = egzaminas;}
void set_mediana(double mediana) {mediana_ = mediana;}
void set_galb(double galb) {galb_ = galb;}
void median();
void galutinis();
friend std::ostream& operator<<(std::ostream& out, const stud &studis)
    {
        out << studis.vardas_ << " " << studis.pavarde_ << " " << studis.galb_ << "\n";
        return out;
    };
    friend std::istream& operator>>(std::istream& in, stud &studis)
    {
        in >> studis.vardas_ >> studis.pavarde_ >> studis.galb_;
    }
friend bool operator!=(stud a, stud b)
    {
        return !(a == b);
    }
friend bool operator==(stud a,stud b)
    {
        return a == b;
    }

};

#endif
