#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <cmath>

int wartosci[7];
int wartosci_cech[7];
int Poczytalnosc, Magia, Wytrzymalosc, Ruch;

using namespace std;

void losowanie_cech()
{
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
            wartosci[i] = 5 * (rand() % 16 + 3);
        else
            wartosci[i] = 5 * (rand() % 13 + 8);
    }
}
void wypis()
{
    cout << "wartosci:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << wartosci[i] << "    ";
    }
    cout << endl;
}
void przerzut()
{
    char wybor;

    cout << endl
         << "wybierz jedna wartosc do przerzucenia: " << endl;
    wybor = getch();
    switch (wybor)
    {
    case '1':
        wartosci[0] = 5 * (rand() % 16 + 3);
        break;

    case '2':
        wartosci[1] = 5 * (rand() % 16 + 3);
        break;

    case '3':
        wartosci[2] = 5 * (rand() % 16 + 3);
        break;
    case '4':
        wartosci[3] = 5 * (rand() % 16 + 3);
        break;
    case '5':
        wartosci[4] = 5 * (rand() % 16 + 3);
        break;

    default:
        cout << "Nie ma takiej opcji w menu!";
    }
}
void przydzial()
{
    char wybor;

    cout << "1. Sila" << endl;
    cout << "2. Kondycja" << endl;
    cout << "3. Wyglad" << endl;
    cout << "4. Moc" << endl;
    cout << "5. Zrecznosc" << endl
         << endl;

    cout << "wartosci:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << wartosci[i] << "    ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl
             << "wybierz ceche ktora ma przyjac " << i + 1 << " wartosc: " << endl;
        wybor = getch();
        switch (wybor)
        {
        case '1':
            wartosci_cech[0] = wartosci[i];
            cout << "twoja sila ma wartosc: " << wartosci[i];
            break;

        case '2':
            wartosci_cech[1] = wartosci[i];
            cout << "twoja kondycja ma wartosc: " << wartosci[i];
            break;

        case '3':
            wartosci_cech[2] = wartosci[i];
            cout << "twoj wyglad ma wartosc: " << wartosci[i];
            break;
        case '4':
            wartosci_cech[3] = wartosci[i];
            cout << "twoja moc ma wartosc: " << wartosci[i];
            break;
        case '5':
            wartosci_cech[4] = wartosci[i];
            cout << "twoja zrecznosc ma wartosc: " << wartosci[i];
            break;

        default:
            cout << "Nie ma takiej opcji w menu!";
        }
        cout << endl;
    }
}
int main()
{
    losowanie_cech();
    wypis();
    cout << "czy chcesz przerzucic jakas wartosc? jesli tak wybierz 1: ";
    char zmiana = getch();
    if (zmiana = 1)
    {
        przerzut();
    }
    else
    {
    }
    przydzial();
    cout << endl;
    cout << endl;

    system("pause");
    return 0;
}