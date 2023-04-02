#include <iostream>
#include <set>
#include <string>

using namespace std;

class Uczen{
private:
    string imie, nazwisko;
public:
    Uczen(string imie, string nazwisko) : imie(imie), nazwisko(nazwisko){}

    friend bool operator<(const Uczen& u1, const Uczen& u2)
    {
        if (u1.nazwisko == u2.nazwisko)
        {
            return u1.imie < u2.imie;
        }
        return u1.nazwisko < u2.nazwisko;
    }

    friend ostream& operator<<(ostream& os, const Uczen& u)
    {
        os << u.nazwisko << " " << u.imie;
        return os;
    }
};

class Klasa{
private:
    set <Uczen> listaUczniow;
public:
    void dodaj(Uczen uczen)
    {
        listaUczniow.insert(uczen);
    }

    void usun(Uczen uczen)
    {
        listaUczniow.erase(uczen);
    }

    void wypisz()
    {
        cout << "Lista uczniow: ";
        for (auto it = listaUczniow.begin(); it != listaUczniow.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main()
{
    Klasa klasa;
    int wybor;
    string imie, nazwisko;
    do{
        cout << "Wybierz opcje:\n1. Dodaj ucznia\n2. Usun ucznia\n3. Wyswietl liste uczniow\n4. Koniec" << endl;
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                cout << "Podaj imie ucznia: ";
                cin >> imie;
                cout << "Podaj nazwisko ucznia: ";
                cin >> nazwisko;
                klasa.dodaj(Uczen(imie, nazwisko));
                break;
            case 2:
                cout << "Podaj imie ucznia: ";
                cin >> imie;
                cout << "Podaj nazwisko ucznia: ";
                cin >> nazwisko;
                klasa.usun(Uczen(imie, nazwisko));
                break;
            case 3:
                klasa.wypisz();
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
