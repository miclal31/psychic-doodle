#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Polish");
    float arr[12] = { 0 };
    char choice;
    float lower, upper, step = 0.01, sum = 0, avg;
    int i, index = 0;
    bool valid_choice = false;

    cout << "Wybierz jedn¹ z opcji a, b lub c:\n";
    cout << "a. Wype³nianie rosn¹co\n";
    cout << "b. Wype³nianie malej¹co\n";
    cout << "c. Wype³nianie losowe\n";

    for (i = 0; i < 3; i++) {
        cin >> choice;
        if (choice == 'a' || choice == 'b' || choice == 'c') {
            valid_choice = true;
            break;
        }
        else {
            cout << "Nieprawid³owy wybór. Spróbuj ponownie.\n";
        }
    }

    if (!valid_choice) {
        cout << "Nieprawid³owy wybór. Wybrano opcjê c.\n";
        choice = 'c';
    }

    switch (choice) {
    case 'a':
        for (i = 0; i < 12; i++) {
            arr[i] = i * step + 0.11;
        }
        break;
    case 'b':
        for (i = 0; i < 12; i++) {
            arr[i] = 1.98 - i * 0.02;
        }
        break;
    case 'c':
        cout << "Podaj doln¹ granicê przedzia³u: ";
        cin >> lower;
        cout << "Podaj górn¹ granicê przedzia³u: ";
        cin >> upper;
        while (upper - lower < 1) {
            cout << "Ró¿nica miêdzy granicami musi byæ niemniejsza ni¿ 1. Podaj doln¹ granicê przedzia³u: ";
            cin >> lower;
            cout << "Podaj górn¹ granicê przedzia³u: ";
            cin >> upper;
        }
        srand(time(NULL));
        for (i = 0; i < 12; i++) {
            arr[i] = lower + (upper - lower) * rand() / RAND_MAX;
        }
        break;
    }

    for (i = 0; i < 12; i++) {
        sum += arr[i];
    }

    avg = sum / 12;

    cout << "Tablica:\n";
    for (i = 0; i < 12; i++) {
        cout << fixed << setprecision(2) << arr[i] << "\t";
        if (abs(arr[i] - avg) < abs(arr[index] - avg)) {
            index = i;
        }
    }
    cout << "\nŒrednia: " << fixed << setprecision(2) << avg << endl;

    cout << "Liczba w tablicy ró¿ni¹ca siê w najmniejszym stopniu od wyznaczonej œredniej: " << arr[index] << endl;

    cout << "Widok tablicy z zerami zamiast pozosta³ych elementów:\n";
    for (i = 0; i < 12; i++) {
        if (i == index) {
            cout << fixed << setprecision(2) << arr[i] << "\t";
        }
        else {
            cout << "0.00\t";
        }
    }
    cout << endl;

    return 0;
}
