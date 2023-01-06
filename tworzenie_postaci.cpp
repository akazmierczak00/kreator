#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <cmath>

using namespace std;
string imie, nazwisko;
int rzut1p, rzut2p, rzut3p, Wiek, Poczytalnosc, Magia, Wytrzymalosc, Ruch = 0;
int cechy_glowne[6], cechy_glowne2[3];
string cechy_glowne_nazwy[6], cechy_glowne2_nazwy[3];
int wybor, xd;
char ktore;

void cechy()
{
    cout << "Twoje cechy to: " << endl;
    for (int i = 0; i <= 5; i++)
    {
        cout << cechy_glowne_nazwy[i] << ": " << cechy_glowne[i] << endl;
    }
    for (int i = 0; i <= 2; i++)
    {
        cout << cechy_glowne2_nazwy[i] << ": " << cechy_glowne2[i] << endl;
    }
    cout << "Twoje punkty poczytlanosci wynosza: " << Poczytalnosc << endl;
    cout << "Twoje punkty magii wynosza: " << Magia << endl;
    cout << "Twoja wytrzymalosc wynosi: " << Wytrzymalosc << endl;
    cout << "Twoj zakres ruchu wynosi: " << Ruch << endl;
}
void patryk(int wiek)
{
    int pkt = pow(2, (wiek / 10) - 3) * 2.5;
    int pkt2 = (wiek / 10 - 3) * 5;
    int pktr = (wiek / 10 - 3);
    int testy = (wiek / 10 - 2);
    if (testy > 4)
    {
        testy = 4;
    }

    cout << endl
         << "Odejmij " << pkt << " punktow sposrod S, KON i ZR (podziel te punkty miedzy jedna, dwie lub trzy cechy)" << endl; // odejmowanie sily, budowy ciala lub kondycji z racji wieku
    cout << "1. Sila" << endl;
    cout << "2. Kondycja" << endl;
    cout << "3. Zrecznosc" << endl;
    while (xd < pkt)
    {
        cout << "Wybierz numer cechy od ktorej chcesz odjac: ";
        ktore = getch();
        cout << endl
             << "Ile punktow chcesz odjac: ";
        cin >> wybor;
        if ((wybor >= 0) && (wybor <= pkt))
        {
            xd = xd + wybor;

            switch (ktore)
            {
            case '1':
                cechy_glowne[0] = cechy_glowne[0] - wybor;
                cout << "ilosc punkt odietych od sily to: " << wybor << endl;
                cout << "Pozostale punkty do odjecia: " << pkt - xd << endl;
                break;

            case '2':
                cechy_glowne[1] = cechy_glowne[1] - wybor;
                cout << "ilosc punkt odietych od kondycji to: " << wybor << endl;
                cout << "Pozostale punkty do odjecia: " << pkt - xd << endl;
                break;

            case '3':
                cechy_glowne[5] = cechy_glowne[5] - wybor;
                cout << "ilosc punkt odietych od zrecznosci to: " << wybor << endl;
                cout << "Pozostale punkty do odjecia: " << pkt - xd << endl;
                break;

            default:
                cout << "Nie ma takiej opcji!";
            }
        }
        else
        {
            cout << "wpisales wartosc ze zlego przedzialu" << endl;
            system("pause");
            return;
        }
    }

    cechy_glowne[2] = cechy_glowne[2] - pkt2; // zmniejszanie wygladu z racji wieku
    for (int i = 0; i < testy; i++)
    {
        cechy_glowne2[2] += ((rand() % 9) + 1);
    }
    Ruch = Ruch - pktr; //odejmowanie zakresu ruchu z uwagi na wiek\

}

int main()
{
    cout << "Witaj w kreatorze postaci do gry Zew Cthulhu!" << endl;
    cout << "Podaj imie swojej postaci: ";
    cin >> imie;
    cout << "Podaj nazwisko swojej postaci: ";
    cin >> nazwisko;
    cout << "Podaj wiek swojej postaci (minimalna wartosc to 15, maksymalna to 90): ";
    cin >> Wiek;

    cechy_glowne_nazwy[0] = "Sila";
    cechy_glowne_nazwy[1] = "Kondycja";
    cechy_glowne_nazwy[2] = "Wyglad";
    cechy_glowne_nazwy[3] = "Moc";
    cechy_glowne_nazwy[4] = "Szczescie";
    cechy_glowne_nazwy[5] = "Zrecznosc";
    cechy_glowne2_nazwy[0] = "Budowa ciala";
    cechy_glowne2_nazwy[1] = "Inteligencja";
    cechy_glowne2_nazwy[2] = "Wyksztalcenie";
    srand(time(NULL));

    // generacja pierwszych cech glownych
    for (int i = 0; i <= 5; i++)
    {
        rzut1p = (rand() % 5) + 1;
        rzut2p = (rand() % 5) + 1;
        rzut3p = (rand() % 5) + 1;
        cechy_glowne[i] = (rzut1p + rzut2p + rzut3p) * 5;
    }
    // generacja kolejnych cech glownych
    for (int i = 0; i <= 2; i++)
    {
        rzut1p = (rand() % 5) + 1;
        rzut2p = (rand() % 5) + 1;
        cechy_glowne2[i] = ((rzut1p + rzut2p) + 6) * 5;
    }

    Poczytalnosc = cechy_glowne[3]; // poczytalnosc
    Magia = cechy_glowne[3] / 5;    // punkty magii

    cout << endl;
    cechy();

    if ((Wiek >= 15) && (Wiek <= 19))
    {
        cout << endl
             << "Odejmij 5 punktow sposrod Sily i Budowy Ciala (podziel te punkty miedzy jedna lub dwie cechy) (jesli odejmiesz 0 od sily to automatycznie odejmiesz 5 od budowy ciala" << endl;
        cout << "Ile punktow chcesz odjac od sily?: ";
        cin >> wybor;
        if ((wybor >= 0) && (wybor <= 5)) // odejmowanie sily lub budowy ciala z racji wieku
        {
            cechy_glowne[0] = cechy_glowne[0] - wybor;
            cechy_glowne2[0] = cechy_glowne2[0] - (5 - wybor);
        }
        else
        {
            cout << "wpisales wartosc ze zlego przedzialu xdd" << endl;
            system("pause");
            return 0;
        }
        cechy_glowne2[2] = cechy_glowne2[2] - 5; // odejmowanie wyksztalcenia z racji wieku

        rzut1p = (rand() % 5) + 1; // dodawanie szczescia z racji wieku (dwa rzuty wybieramy ten wiekszy)
        rzut2p = (rand() % 5) + 1;
        if (rzut1p > rzut2p)
        {
            cechy_glowne[4] = cechy_glowne[4] + rzut1p;
        }
        else if (rzut1p > rzut2p)
        {
            cechy_glowne[4] = cechy_glowne[4] + rzut2p;
        }
        else
        {
            cechy_glowne[4] = cechy_glowne[4] + rzut1p;
        }
    }
    else if ((Wiek >= 20) && (Wiek <= 39))
    {
        cechy_glowne2[2] = cechy_glowne2[2] + ((rand() % 9) + 1); // zwiekszenie wyksztalcenia z racji wieku
    }
    else if ((Wiek >= 40) && (Wiek <= 90))
    {
        patryk(Wiek);
    }
    else
    {
        cout << "Wiek musi znajdowac sie w przedziale od 15 do 90 lat!" << endl;
        return 0;
    }

    Wytrzymalosc = (cechy_glowne2[0] + cechy_glowne[1]) / 10; // wytrzymalosc

    if ((cechy_glowne[0] < cechy_glowne2[0]) && (cechy_glowne[5] < cechy_glowne2[0])) // zakres ruchu
    {
        Ruch = Ruch + 7;
    }
    else if ((cechy_glowne[0] > cechy_glowne2[0]) && (cechy_glowne[5] > cechy_glowne2[0]))
    {
        Ruch = Ruch + 9;
    }
    else if ((cechy_glowne[0] <= cechy_glowne2[0]) || (cechy_glowne[5] <= cechy_glowne2[0]))
    {
        Ruch = Ruch + 8;
    }

    system("pause");
    system("cls");
    cout << endl;
    cechy();
    cout << endl;

    // do notatnika
    // fstream plik;
    // plik.open("postac1.txt",ios::out);

    // plik<<"Imie: "<<imie<<endl;
    // plik<<"Nazwisko: "<<nazwisko<<endl;

    // plik.close();

    system("pause");
    return 0;
}