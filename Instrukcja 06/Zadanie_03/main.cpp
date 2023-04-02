#include <iostream>
#include <map>
#include <string>

using namespace std;

class Slownik
{
private:
    map <string, string> angielskoPolski;
public:
    void dodaj(string angielskie, string polskie)
    {
        angielskoPolski[angielskie] = polskie;
    }

    void szukaj(string angielskie)
    {
        auto it = angielskoPolski.find(angielskie);
        if(it!=angielskoPolski.end())
        {
            cout << "Angielskie: " << it->first << ", polskie: " << it->second << endl;
        }
        else
        {
            cout << "Nie znaleziono tlumaczenia." << endl;
        }
    }

    void wypisz()
    {
        cout << "S³ownik angielsko-polski:" << endl;
        for (auto it = angielskoPolski.begin(); it != angielskoPolski.end(); ++it)
        {
            cout << it->first << " - " << it->second << endl;
        }
    }
};

int main() {
    Slownik slownik;
    int wybor;
    string angielskie, polskie;
    do
    {
        cout << "Wybierz opcje:\n1. Dodaj slowo\n2. Wyszukaj slowo\n3. Wyswietl caly slownik\n4. Koniec" << endl;
        cin >> wybor;
        switch (wybor)
        {
            case 1:
                cout << "Podaj slowo angielskie: ";
                cin >> angielskie;
                cout << "Podaj tlumaczenie polskie: ";
                cin >> polskie;
                slownik.dodaj(angielskie, polskie);
                break;
            case 2:
                cout << "Podaj slowo angielskie: ";
                cin >> angielskie;
                slownik.szukaj(angielskie);
                break;
            case 3:
                slownik.wypisz();
                break;
            case 4:
                cout << "Koniec programu" << endl;
                break;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                break;
        }
    }while(!(wybor==4));
    return 0;
}
