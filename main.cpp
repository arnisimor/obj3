#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include "stud.h"
#include "Funkcijos.h"


using std::cin;
using std::cout;
using std::string;
using std::vector;


int main()
{
vector <stud> x;
nuskaitymas(x);
if(x.size()==0){
return 0;
}
/*else
    {
    print2(x);
    }*/
}
