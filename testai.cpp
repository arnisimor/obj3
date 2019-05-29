#define CATCH_CONFIG_MAIN
#include"vector"
#include"stud.h"
#include"catch.hpp"

using std::vector;
using std::string;
TEST_CASE("Medianos patikrinimas")
{
    stud testas;
    vector<int> nd = {4,5,8,9};
    testas.set_nd(nd);
    testas.median();

    REQUIRE(testas.mediana()==6.5);
}


TEST_CASE("Galutinio balo patikrinimas")
{
    stud testas;
    vector<int> nd = {3,8,7,5,9};
    int egz=5;
    testas.set_egzaminas(egz);
    testas.set_nd(nd);
    testas.galutinis();

    REQUIRE(testas.galb()==5.56);
}

TEST_CASE("Vardo patikrinimas")
{
    stud testas;
    string vardas="Vardas01";
    testas.set_vardas(vardas);
     REQUIRE(testas.vardas()=="Vardas01");

}
TEST_CASE("Pavardes patikrinimas")
{
    stud testas;
    string pavarde="Pavarde01";
    testas.set_pavarde(pavarde);
     REQUIRE(testas.pavarde()=="Pavarde01");

}
