#include "stud.h"
#include <algorithm>

void stud::median(){
    size_t size = nd_.size();
    if (size != 0)
    {
        sort(nd_.begin(), nd_.end());
        if (size % 2 == 0)
        {
            mediana_ = (double)((nd_[size / 2 - 1] + nd_[size / 2]) * 0.5);
        }
        else
        {
            mediana_ = nd_[size / 2];
        }
    }
}
void stud::galutinis(){
    int kiekis = nd_.size();
    int suma = 0;
    if (kiekis != 0)
    {
        for (int x = 0; x < kiekis; x++)
        {
            suma += nd_[x];
        }
        galb_ = 0.4 * suma / kiekis + 0.6 * egzaminas_;
    }
    else
        galb_ = 0.6 * egzaminas_;
}

