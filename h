#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //zadanie1
    srand(time(NULL));
    int tab[10] = {};
    int n;
    int proby = 2;
    cout << "Podaj liczbe naturalna n, nie wieksza niz 5: " << endl;
    cin >> n;
    while (n > 5 || n < 0)
    {
        cout << "Podaj liczbe naturalna n, nie wieksza niz 5: " << endl;
        cin >> n;

    }
    for (int i = 0; i < n; i++)
    {
        cout << "Podaj liczbe parzysta, naturalna i mniejsza od 100: " << endl;
        cin >> tab[i];
        while (tab[i] > 100 || tab[i] % 2 != 0 || tab[i] < 0)
        {
            proby--;
            cout << "Liczba pozostalych prob wynosi: " << proby + 1 << endl;
            cout << "Podaj liczbe parzysta, naturalna i mniejsza od 100: " << endl;
            cin >> tab[i];
            if (proby == 0)
            {
                proby = 2;
                cout << "Przekroczono liczbe prob dla danego elementu!" << endl;
                tab[i] = 0;
                continue;
            }
        }
    }

    for (int i = 0; i < sizeof(tab); i++)
    {
        cout << tab[i] << ",";
    }
    cout << endl;
    //zadanie2
    cout << endl;
    for (int i = 0; i < sizeof(tab); i++)
    {
        if (tab[i] == 0)
        {
            tab[i] = rand() % 100 + 1;
            while (tab[i] % 2 != 0)
            {
                tab[i] = rand() % 100 + 1;
            }
        }
        cout<< tab[i]<<",";
    }
    cout << endl;
    cout << endl;

    //zadanie3

      int*  start = &tab[0];
      int*  koniec = &tab[9];

      while (start < koniec)
      {
          int temp = *start;
          *start = *koniec;
          *koniec = temp;
          start++;
          koniec--;
      }

    for (int i = 0; i < sizeof(tab); i++)
    {
        cout << tab[i] << ",";
    }

}
