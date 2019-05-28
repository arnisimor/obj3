#include "stud.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int Defaultnd=5;

bool compare_m(stud & a, stud & b) {
   return a.galb() > b.galb();

};


void generate (int &kiekis){

string nr = std::tostring(kiekis);
int ND[Defaultnd];
std::ofstream out ("kursiokai"+nr+".txt");
std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution < int > random(1, 10);
out<<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(17);
for (size_t i = 0; i < Defaultnd; i++){
out<<"ND"<<i+1<<std::setw(6);
if(Defaultnd-i==1)
out<<"   "<<"Egazminas";
}
out<<std::endl;
for(size_t x = 0; x < kiekis; x++){
out<<"Vardas"<<x<<std::setw(20)<<"Pavarde"<<x<<std::setw(15);

for(size_t y = 0; y < Defaultnd + 1; y++){

ND[y]=random(generuoti);
out<<ND[y]<<std::setw(7);
}
out<<std::endl;
}
out.close();

};

void ivedimas (vector <stud> &a)
{
    string kiekis="-1";
    string option="1";


    while(option=="1"){

    stoppointoption:
    cout<<std::endl;
    cout<<"Jei norite generuoti studentus įrašykite - 1, jei ne - 2 "<<std::endl;
    cin>>option;

    try{
        if(option!="1")
        {
            throw option;
        }

    }
    catch(string option){
        if(option=="2")
     {
      break;
    }
    else
    {
        cout<< "Iveskite tinkamus duomenis "<<std::endl;
        goto stoppointoption;
    }
    }

    stoppointkiekis:
    cout<<"Iveskite generuojamu studentu kiekį"<<std::endl;
    cin>>kiekis;
    try
    {
        if(number(kiekis)==false||std::stoi(kiekis)<=0||std::stoi(kiekis)>=RAND_MAX)
            throw kiekis;

    }
    catch(string kiekis){
        cout<<"Iveskite tinkamus kiekio duomenis"<<std::endl;
        goto stoppointkiekis;
    }

    int kiek=std::stoi(kiekis);
    cout<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
generate(kiek);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start;
std::cout<<kiekis<< " studentu GENERAVIMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";


start = std::chrono::high_resolution_clock::now();
skaityti(x,kiek);
 end = std::chrono::high_resolution_clock::now();
diff = end-start;
std::cout<<kiekis<< " studentu NUSKAITYMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";


     start = std::chrono::high_resolution_clock::now();
  sort(x,kiek);
 end = std::chrono::high_resolution_clock::now();
 diff = end-start;
std::cout<<kiekis<< " studentu RUSIAVIMAS IR SPAUSDINIMAS uztruko: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";

    x.clear();

     }


    x.clear();

    string optionas="1";

while (optionas=="1")  {

stoptaskas:
 std::cout<<"Jei norite įvesti studento duomenis ranka įrašykite - 1, jei ne - 2 "<<std::endl;

    cin>>optionas;
    try{
        if(optionas!="1")
        {
            throw optionas;
        }

    }
    catch(string optionas){
        if(optionas=="2")
        break;
        else
        {
        cout<< "Iveskite tinkamus duomenis"<<std::endl;
        goto stoptaskas;

        }
    }

    studentas laikinas;
    string vardas,pavarde;
    int kiekis;
    string kiek;
    vector <int> ND;
    int egzaminas;


    checkpoint1:
    cout<<"Iveskite studento varda"<<std::endl;
    cin>>vardas;
    try{
        if(number(vardas))
            throw vardas;
        }
    catch(string vardas)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint1;

    };
    laikinas.set_vardas(vardas);


      checkpoint2:
    cout<<"Iveskite studento pavarde"<<std::endl;
    cin>>pavarde;
    try{
        if(number(pavarde))
            throw pavarde;
        }
    catch(string pavarde)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint2;

    };
    laikinas.set_pavarde(pavarde);


    checkpoint3:
    cout<<"Iveskite studento nd kieki"<<std::endl;
    cin>>kiek;
    try{
        if(number(kiek)==false||std::stoi(kiek)<=0||std::stoi(kiek)>=RAND_MAX)
            throw kiek;

    }
    catch(string kiek)
    {
   cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto checkpoint3;
    }
kiekis=std::stoi(kiek);

string variantas="1";
stop:
cout<<"Iveskite 1 - generuoti atsitiktinai nd, iveskite  bet ką - jei norite ivesti nd ranka "<<std::endl;
cin>>variantas;
if(variantas=="1"){

    std::random_device rd;
    std::mt19937 generuoti(rd());
    std::uniform_int_distribution < int > random(1, 10);

    for(size_t i = 0;i<kiekis;i++){

    ND.push_back(random(generuoti));
    }

    laikinas.set_nd(ND);
string egz;
    egzaminas1:
    cout<<"Iveskite studento egzamino rezultatus"<<std::endl;
    cin>>egz;
     try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }
    catch(string egz)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;

      goto egzaminas1;

    };
    egzaminas=std::stoi(egz);
    laikinas.set_egzaminas(egzaminas);

    laikinas.finalinis();
    laikinas.median();

    x.push_back(laikinas);
   }

if(variantas!="1"){
int nd;
string namai;
for(size_t i = 0;i<kiekis;i++){
nd1:
cout<< "Įveskite nd rezultatą"<<std::endl;
cin>>namai;

    try{
        if(number(namai)==false||std::stoi(namai)<0||std::stoi(namai)>10)
            throw namai;
        }
    catch(string namai)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;
      goto nd1;
      }
      nd=std::stoi(namai);
    ND.push_back(nd);

    }

string egz;
    egzaminas2:
    cout<<"Iveskite studento egzamino rezultatus"<<std::endl;
    cin>>egz;
    try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }
    catch(string egz)
    {
      cout<< "Iveskite tinkamus duomenis"<<std::endl;

      goto egzaminas2;

    };
    egzaminas=std::stoi(egz);

    laikinas.set_nd(ND);
    laikinas.set_egzaminas(egzaminas);
    laikinas.finalinis();
    laikinas.median();

    x.push_back(laikinas);
}
    ND.clear();
    kiekis=-1;
    egzaminas=-1;

};

}

void skaityti (vector <stud> &x,int &kiekis)
{
    stud laikinas_stud;
    auto nr= std::tostring(kiekis);
    string vardas,pavarde;
    vector <int> ND ;
    int sk;
    int egzaminas;
    std::ifstream in ("kursiokai"+nr+".txt");

    in.ignore(256, '\n');

    while (! in.eof()){
    in>>vardas>>std::ws>>pavarde>>std::ws;
    laikinas_stud.set_vardas(vardas);
    laikinas_stud.set_pavarde(pavarde);

    for(size_t i = 0;i<Defaultnd;i++)
    {
        in>>sk;
        ND.push_back(sk);
        laikinas_stud.set_nd(ND);

   }
   in>>egzaminas;
laikinas_stud.set_egzaminas(egzaminas);
laikinas_stud.median();
laikinas_stud.finalinis();
x.push_back(laikinas_stud);
ND.clear();
}

}
void print (vector <stud> &printable, string &filename){
    std::ofstream out (filename,std::ios::app);
    for(size_t i=0;i<printable.size();i++)
    {
        out<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(20);
        out<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(5)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<std::endl;
    }
out.close();
}
void print2 (vector <stud> &printable){
    cout<<"-------------------------------------------------------------------------------"<<std::endl;
    cout<<"vardas"<<std::setw(20)<<"pavarde"<<std::setw(15)<<"galutinis"<<"    "<<"mediana"<<std::endl;
    for(size_t i=0;i<printable.size();i++)
    {
        cout<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(20);
        cout<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(7)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<std::endl;
    }
}
void sort (vector <stud> &x,int &kiekis)
{
    string goodout ="kietiakai.txt";
    string badout  ="vargsiukai.txt";
    sort(x.begin(), x.end(), compare_m);
    vector<stud> nenaudeliai, geriukai, studentai;
    stud laikinas;
    string vardas,pavarde;
    double galb,median;
    for(size_t i=0;i<kiekis;i++){
    vardas=x[i].vardas();
    pavarde=x[i].pavarde();
    galb=x[i].galb();
    median=x[i].mediana();
    laikinas.set_vardas(vardas);
    laikinas.set_pavarde(pavarde);
    laikinas.set_galb(galb);
    laikinas.set_mediana(median);
    studentai.push_back(laikinas);
    }
       for(size_t i=0;i<kiekis;i++){
           if(studentai[i].galb()<5.0)
           {
               nenaudeliai.push_back(studentai[i]);

           }
           else{
                        geriukai.push_back(studentai[i]);
           }
    }

print(geriukai,goodout);
print(nenaudeliai,badout);

}

bool number(const std::string &c)
{
    if (c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos)
    {
        return true;
    }

    return false;
}
