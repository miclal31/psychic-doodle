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

    cout << "Wybierz jedn� z opcji a, b lub c:\n";
    cout << "a. Wype�nianie rosn�co\n";
    cout << "b. Wype�nianie malej�co\n";
    cout << "c. Wype�nianie losowe\n";

    for (i = 0; i < 3; i++) {
        cin >> choice;
        if (choice == 'a' || choice == 'b' || choice == 'c') {
            valid_choice = true;
            break;
        }
        else {
            cout << "Nieprawid�owy wyb�r. Spr�buj ponownie.\n";
        }
    }

    if (!valid_choice) {
        cout << "Nieprawid�owy wyb�r. Wybrano opcj� c.\n";
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
        cout << "Podaj doln� granic� przedzia�u: ";
        cin >> lower;
        cout << "Podaj g�rn� granic� przedzia�u: ";
        cin >> upper;
        while (upper - lower < 1) {
            cout << "R�nica mi�dzy granicami musi by� niemniejsza ni� 1. Podaj doln� granic� przedzia�u: ";
            cin >> lower;
            cout << "Podaj g�rn� granic� przedzia�u: ";
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
    cout << "\n�rednia: " << fixed << setprecision(2) << avg << endl;

    cout << "Liczba w tablicy r�ni�ca si� w najmniejszym stopniu od wyznaczonej �redniej: " << arr[index] << endl;

    cout << "Widok tablicy z zerami zamiast pozosta�ych element�w:\n";
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
