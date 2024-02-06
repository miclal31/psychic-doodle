#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

enum class Lokalizacja {
    NA_MASZCIE,
    NA_DACHU_BUDYNKU,
    NA_SCIANIE_BUDYNKU,
    W_POMIESZCZENIU,
    W_PRZESTRZENI_OTWARTEJ
};


struct Antena {
    string typ;
    float dlugosc;
    float wzmocnienie;
};


struct Nadajnik {
    Antena* antena;
    Lokalizacja lokalizacja;
    float napiecieAkumulatora;
    float mocNadajnika;
    uint16_t licznikKomunikatow;
};


string LokalizacjeString[] = {
    "na maszcie",
    "na dachu budynku",
    "na œcianie budynku",
    "w pomieszczeniu",
    "w przestrzeni otwartej"
};


void wypelnijNadajnik(Nadajnik& nadajnik, Antena* antena, Lokalizacja lokalizacja, float napiecieAkumulatora, float mocNadajnika, uint16_t licznikKomunikatow) {
    nadajnik.antena = antena;
    nadajnik.lokalizacja = lokalizacja;
    nadajnik.napiecieAkumulatora = napiecieAkumulatora;
    nadajnik.mocNadajnika = mocNadajnika;
    nadajnik.licznikKomunikatow = licznikKomunikatow;
}


void wyswietlNadajnik(const Nadajnik& nadajnik) {
    cout << "Antena: " << nadajnik.antena->typ << ", Lokalizacja: " << LokalizacjeString[static_cast<int>(nadajnik.lokalizacja)] << ", Licznik komunikatow: " << nadajnik.licznikKomunikatow << endl;
}


float sredniaLiczbaKomunikatow(Nadajnik* nadajniki, int n) {
    float suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += nadajniki[i].licznikKomunikatow;
    }
    return suma / n;
}


Nadajnik& nadajnikSredniKomunikat(Nadajnik* nadajniki, int n) {
    float srednia = sredniaLiczbaKomunikatow(nadajniki, n);
    float minOdchylenie = abs(nadajniki[0].licznikKomunikatow - srednia);
    Nadajnik* najblizszyNadajnik = &nadajniki[0];

    for (int i = 1; i < n; ++i) {
        float odchylenie = abs(nadajniki[i].licznikKomunikatow - srednia);
        if (odchylenie < minOdchylenie) {
            minOdchylenie = odchylenie;
            najblizszyNadajnik = &nadajniki[i];
        }
    }

    return *najblizszyNadajnik;
}

int main() {
     setlocale(LC_CTYPE, "Polish");
   
    Antena anteny[] = {
        {"Pretowa", 1.0, 2.0},
        {"Dipol pó³falowy", 1.5, 2.5},
        {"Panelowa", 1.2, 2.2},
        {"Dipol æwieræfalowy", 1.3, 2.3},
        {"Yagi", 1.1, 2.1}
    };

    
    Nadajnik nadajniki[] = {
        {&anteny[0], Lokalizacja::NA_MASZCIE, 3.5, 0.05, 1000},
        {&anteny[1], Lokalizacja::W_POMIESZCZENIU, 3.4, 0.1, 700},
        {&anteny[2], Lokalizacja::W_PRZESTRZENI_OTWARTEJ, 3.6, 0.1, 800},
        {&anteny[3], Lokalizacja::NA_SCIANIE_BUDYNKU, 3.5, 0.08, 450},
        {&anteny[4], Lokalizacja::W_POMIESZCZENIU, 3.4, 0.09, 600}
    };

   
    for (int i = 0; i < 5; ++i) {
        wyswietlNadajnik(nadajniki[i]);
    }

   
    Nadajnik& najblizszy = nadajnikSredniKomunikat(nadajniki, 5);
    cout << "Najblizszy nadajnik: ";
    wyswietlNadajnik(najblizszy);

    return 0;
}
