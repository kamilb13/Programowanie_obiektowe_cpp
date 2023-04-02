#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Zwierze {
public:
    Zwierze(string i, string g) : imie(i), gatunek(g) {}

    string getImie(){
        return imie;
    }
    string getGatunek(){
        return gatunek;
    }
    virtual void poruszaj() = 0;
    virtual void dajGlos() = 0;

private:
    string imie;
    string gatunek;
};

class Ptak : public Zwierze {
public:
    Ptak(string i) : Zwierze(i, "ptak") {}
    void poruszaj() {
        cout << "Ptak " << getImie() << " lata.\n";
    }
    void dajGlos() {
        cout << "Ptak " << getImie() << " odzywa sie fruu\n";
    }
};

class Pies : public Zwierze{
public:
    Pies(string i) : Zwierze(i, "pies") {}
    void poruszaj() {
        cout << "Pies " << getImie() << " biegnie\n";
    }
    void dajGlos() {
        cout << "Pies " << getImie() << " szczeka hau hua!\n";
    }
};

class Kot : public Zwierze{
public:
    Kot(string i) : Zwierze(i, "kot") {}
    void poruszaj() {
        cout << "Kot " << getImie() << " chodzi\n";
    }
    void dajGlos() {
        cout << "Kot " << getImie() << " miauczy miau miauuu!\n";
    }
};

int main(){
    vector<Zwierze*> zwierzeta;
    int wybor;
    string imie;

    while(true) {
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Dodaj kota" << endl;
        cout << "2. Dodaj psa" << endl;
        cout << "3. Dodaj ptaka" << endl;
        cout << "4. Wyswietl wszystkie zwierzeta" << endl;
        cout << "5. Wszyscy daja glos" << endl;
        cout << "6. Wszyscy sie poruszaja" << endl;
        cout << "7. Usun zwierze" << endl;
        cout << "8. Wyjdz" << endl;
        cin >> wybor;

        switch(wybor){
            case 1:
                cout << "Podaj imie kota: ";
                cin >> imie;
                zwierzeta.push_back(new Kot(imie));
                break;
            case 2:
                cout << "Podaj imie psa: ";
                cin >> imie;
                zwierzeta.push_back(new Pies(imie));
                break;
            case 3:
                cout << "Podaj imie ptaka: ";
                cin >> imie;
                zwierzeta.push_back(new Ptak(imie));
                break;
            case 4:
                for(auto el:zwierzeta){
                    el->dajGlos();
                    el->poruszaj();
                }
                break;
            case 5:
                for(auto el:zwierzeta){
                    el->dajGlos();
                }
                break;
            case 6:
                for(auto el:zwierzeta){
                    el->poruszaj();
                }
                break;
            case 7:
                cout << "Podaj indeks zwierzecia do usuniecia: ";
                int index;
                cin >> index;
                if (index < 0 || index >= zwierzeta.size()) {
                cout << "Nieprawidlowy indeks" << endl;
                } else {
                delete zwierzeta[index];
                zwierzeta.erase(zwierzeta.begin() + index);
                cout << "Zwierze usuniete" << endl;
                }
                break;
            case 8:
                cout << "Koniec programu" << endl;
                return 0;
            default:
                cout << "Nieprawidlowy wybor" << endl;
        }
    }
}
