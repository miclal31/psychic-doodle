#include <iostream>
#include <cstring>

using namespace std;

using Tekst = char[50];

enum Kategoria { Beletrystyka, Poradnik, Podrecznik, Lektura };

struct Autor {
    Tekst imie;
    Tekst nazwisko;
};

struct Ksiazka {
    Tekst tytul;
    Autor* autor;
    Kategoria kategoria;
    uint16_t liczbaStron;
};

const char* kategorie[] = { "Beletrystyka", "Poradnik", "Podrecznik", "Lektura" };

void wypelnijKsiazke(Ksiazka* ksiazka, Tekst tytul, Autor* autor, Kategoria kategoria, uint16_t liczbaStron)
{
    strcpy_s(ksiazka->tytul, 50, tytul);
    ksiazka->autor = autor;
    ksiazka->kategoria = kategoria;
    ksiazka->liczbaStron = liczbaStron;
}

void wyswietlKsiazke(Ksiazka ksiazka)
{
    cout << "Tytul: " << ksiazka.tytul << endl;
    cout << "Autor: " << ksiazka.autor->imie << " " << ksiazka.autor->nazwisko << endl;
    cout << "Kategoria: " << kategorie[ksiazka.kategoria] << endl;
    cout << "Liczba stron: " << ksiazka.liczbaStron << endl;
}

void autorMaksLiczbaStron(Ksiazka* ksiazki, uint16_t n, Tekst* najlepszyAutor)
{
    uint16_t maksLiczbaStron = 0;
    for (uint16_t i = 0; i < n; i++)
    {
        if (ksiazki[i].liczbaStron > maksLiczbaStron)
        {
            maksLiczbaStron = ksiazki[i].liczbaStron;
            assert(ksiazki[i].autor != nullptr);
            strcpy_s(najlepszyAutor, 50, ksiazki[i].autor->nazwisko);
        }
    }
    if (maksLiczbaStron == 0)
    {
        throw std::invalid_argument("Nie znaleziono ksiazki z autorem");
    }
}

int main()
{
    setlocale(LC_ALL, "");
    Autor autor1 = { "Remigiusz", "Mróz" };
    Autor autor2 = { "James", "Clear" };
    Autor autor3 = { "Robert", "Martin" };
    Autor autor4 = { "Krzysztof", "Krocz" };
    Autor autor5 = { "W³adys³aw", "Reymont" };
    Autor autor6 = { "Raymond", "Mears" };

    Ksiazka ksiazki[] = {
        {"Operacja Mir", &autor1, Beletrystyka, 464},
        {"Atomowe nawyki", &autor2, Poradnik, 272},
        {"Czysty Kod", &autor3, Poradnik, 424},
        {"Java.Podrêcznik na start", &autor4, Podrecznik, 280},
        {"Ch³opi", &autor5, Lektura, 710},
        {"Podrêcznik sztuki przetrwania", &autor6, Podrecznik, 240},
        {"Bez autora", nullptr, Beletrystyka, 100}
    };

    Tekst najlepszyAutor;
    try
    {
        autorMaksLiczbaStron(ksiazki, 7, najlepszyAutor);
        cout << "Autor z najwieksza liczba stron: " << najlepszyAutor << endl;
    }
    catch (const std::invalid_argument & e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
