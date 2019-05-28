#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include "stud.h"
#include "Funkcijos.h"
#include <algorithm>

 using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int Default_ND=5;

void generate (int &kiekis){
string nr = std::to_string(kiekis);
int ND[Default_ND];
std::ofstream out ("studentai"+nr+".txt");
unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
std::mt19937 generuoti(seed);
std::uniform_int_distribution < int > random(1, 10);
out<<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(17);
for (size_t i = 0; i < Default_ND; i++){
out<<"ND"<<i+1<<std::setw(6);
if(Default_ND-i==1)
out<<"   "<<"Egazminas";
}
out<<endl;
for(size_t x = 0; x < kiekis; x++){
out<<"Vardas"<<x<<std::setw(20)<<"Pavarde"<<x<<std::setw(15);

for(size_t y = 0; y < Default_ND + 1; y++){

ND[y]=random(generuoti);
out<<ND[y]<<std::setw(7);
}
out<<endl;
}
out.close();

};

bool compare_m(stud & a, stud & b) {
   return a.galb() > b.galb();

};
void nuskaitymas (vector <stud> &x)
{
    string kiekis="-1";
    string tikrinama="t";
    while(tikrinama=="t"){
    stoppointoption:
    cout<<"Iveskite t raide, jei norite sugeneruoti studentus, jei ne, spauskite bet kokia kita raide: ";
    cin>>tikrinama;
    try{
        if(tikrinama!="t")
        {
            throw tikrinama;
        }

    }
    catch(string tikrinama){
        if(tikrinama!="t")
     {
      break;
    }
    }

    stoppointkiekis:
    cout<<"Iveskite studentu skaiciu"<<endl;
    cin>>kiekis;
    try
    {
        if(number(kiekis)==false||std::stoi(kiekis)<=0)
            throw kiekis;

    }
    catch(string kiekis){
        cout<<"Iveskite teigiamą sveikąjį skaičių!"<<endl;
        goto stoppointkiekis;
    }

    int kiek=std::stoi(kiekis);
    cout<<endl;
    auto start = std::chrono::high_resolution_clock::now();
generate(kiek);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start;
std::cout<< "generavimo trukme: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";


start = std::chrono::high_resolution_clock::now();
skaityti(x,kiek);
 end = std::chrono::high_resolution_clock::now();
diff = end-start;
std::cout<< "nuskaitymo trukme: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";


     start = std::chrono::high_resolution_clock::now();
  sort(x,kiek);
 end = std::chrono::high_resolution_clock::now();
 diff = end-start;
std::cout<< "atrinkimo ir isvedimo trukme: "<<std::fixed<<std::setprecision(7)<< diff.count() << " s\n";

    x.clear();

     }


    x.clear();

    string pasirinkimas="r";

while (pasirinkimas=="r")  {

stoptaskas:
 std::cout<<"Jei dar norite ivesti studento duomenis ranka, spauskite r, jei ivedete visus duomenis, spauskite bet kuri kita mygtuka"<<endl;

    cin>>pasirinkimas;
    try{
        if(pasirinkimas!="r")
        {
            throw pasirinkimas;
        }

    }
    catch(string pasirinkimas){
        if(pasirinkimas!="r")
        break;
    }

    stud laikinas;
    string vardas,pavarde;
    int kiekis;
    string kiek;
    vector <int> ND;
    int egzaminas;


    checkpoint1:
    cout<<"Iveskite studento varda"<<endl;
    cin>>vardas;
    try{
        if(number(vardas))
            throw vardas;
        }
    catch(string vardas)
    {
      cout<< "vardas negali buti tik skaiciai!"<<endl;
      goto checkpoint1;

    };
    laikinas.set_vardas(vardas);


      checkpoint2:
    cout<<"Iveskite studento pavarde"<<endl;
    cin>>pavarde;
    try{
        if(number(pavarde))
            throw pavarde;
        }
    catch(string pavarde)
    {
      cout<< "pavarde negali buti tik skaiciai"<<endl;
      goto checkpoint2;

    };
    laikinas.set_pavarde(pavarde);


    checkpoint3:
    cout<<"Iveskite studento nd kieki"<<endl;
    cin>>kiek;
    try{
        if(number(kiek)==false||std::stoi(kiek)<=0||std::stoi(kiek)>=RAND_MAX)
            throw kiek;

    }
    catch(string kiek)
    {
   cout<< "skaicius turi buti sveikasis ir teigiamas"<<endl;
      goto checkpoint3;
    }
kiekis=std::stoi(kiek);

stop:
cout<<"Jei norite automatiskai sugeneruotu namu darbu, spauskite t, jei ivedinesite duomenis ranka, spauskite bet kuri kita mygtuka "<<endl;
cin>>tikrinama;
if(tikrinama=="t"){

    std::random_device rd;
    std::mt19937 generuoti(rd());
    std::uniform_int_distribution < int > random(1, 10);

    for(size_t i = 0;i<kiekis;i++){

    ND.push_back(random(generuoti));
    }

    laikinas.set_nd(ND);
string egz;
    egzaminas1:
    cout<<"Iveskite studento egzamino rezulta"<<endl;
    cin>>egz;
     try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }
    catch(string egz)
    {
      cout<< "egzamino rezultatas turi buti teigiamas sveikasis skaicius nuo 0 iki 10!"<<endl;

      goto egzaminas1;

    };
    egzaminas=std::stoi(egz);
    laikinas.set_egzaminas(egzaminas);

    laikinas.galutinis();
    laikinas.median();

    x.push_back(laikinas);
   }

if(tikrinama!="t"){
int nd;
string namai;
for(size_t i = 0;i<kiekis;i++){
nd1:
cout<< "Įveskite nd rezultata"<<endl;
cin>>namai;

    try{
        if(number(namai)==false||std::stoi(namai)<0||std::stoi(namai)>10)
            throw namai;
        }
    catch(string namai)
    {
      cout<< "Iveskite tinkamus duomenis"<<endl;
      goto nd1;
      }
      nd=std::stoi(namai);
    ND.push_back(nd);

    }

string egz;
    egzaminas2:
    cout<<"Iveskite studento egzamino rezultatus"<<endl;
    cin>>egz;
    try{
        if(number(egz)==false||std::stoi(egz)<0||std::stoi(egz)>10)
            throw egz;
        }
    catch(string egz)
    {
      cout<< "sveikaji skaiciu nuo 1 iki 10!"<<endl;

      goto egzaminas2;

    };
    egzaminas=std::stoi(egz);

    laikinas.set_nd(ND);
    laikinas.set_egzaminas(egzaminas);
    laikinas.galutinis();
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
    auto nr= std::to_string(kiekis);
    string vardas,pavarde;
    vector <int> ND ;
    int sk;
    int egzaminas;
    std::ifstream in ("studentai"+nr+".txt");

    in.ignore(256, '\n');

    while (! in.eof()){
    in>>vardas>>std::ws>>pavarde>>std::ws;
    laikinas_stud.set_vardas(vardas);
    laikinas_stud.set_pavarde(pavarde);

    for(size_t i = 0;i<Default_ND;i++)
    {
        in>>sk;
        ND.push_back(sk);
        laikinas_stud.set_nd(ND);

   }
   in>>egzaminas;
laikinas_stud.set_egzaminas(egzaminas);
laikinas_stud.median();
laikinas_stud.galutinis();
x.push_back(laikinas_stud);
ND.clear();
}

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
void print (vector <stud> &printable, string &filename){
    std::ofstream fr (filename,std::ios::app);
    fr<<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(23)<<"Galutinis"<<std::setw(11)<<"Mediana"<<endl;
    fr<<"----------------------------------------------------------------"<<endl;
    for(size_t i=0;i<printable.size();i++)
    {
        fr<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(19);
        fr<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(12)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<endl;
    }
fr.close();
}
void print2 (vector <stud> &printable){
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"Vardas"<<std::setw(20)<<"Pavarde"<<std::setw(15)<<"Galutinis"<<"    "<<"Mediana"<<endl;
    for(size_t i=0;i<printable.size();i++)
    {
        cout<<printable[i].vardas()<<std::setw(20)<<printable[i].pavarde()<<std::setw(20);
        cout<<std::fixed<<std::setprecision(2)<<printable[i].galb()<<std::setw(7)<<std::fixed<<std::setprecision(2)<<printable[i].mediana()<<endl;
    }
}
void sort (vector <stud> &x,int &kiekis)
{
    string goodout ="Kietiakai.txt";
    string badout  ="Vargsiukai.txt";
    sort(x.begin(), x.end(), compare_m);
    vector<stud> vargsiukai, kietiakai, studentai;
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
               vargsiukai.push_back(studentai[i]);

           }
           else{
                        kietiakai.push_back(studentai[i]);
           }
    }

print(kietiakai,goodout);
print(vargsiukai,badout);

}

