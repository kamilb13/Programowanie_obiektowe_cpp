#include <iostream>
#include <list>

using namespace std;

class Stos{
private:
    list <int> listaStosu;
public:
    void dodaj(int wartosc){
        listaStosu.push_back(wartosc);
    }

    void usun(){
        if (!listaStosu.empty()){
            listaStosu.pop_back();
        }
    }

    void wypisz(){
        cout << "Zawartosc stosu: ";
        for (auto it = listaStosu.rbegin(); it != listaStosu.rend(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main(){
    Stos stos;
    int wybor, wartosc;
    do{
        cout << "Wybierz opcje: \n1. Dodaj element \n2. Usun element \n3. Wyswietl zawartosc stosu \n4. Koniec" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1:
                cout << "Podaj wartosc do dodania: ";
                cin >> wartosc;
                stos.dodaj(wartosc);
                break;
            case 2:
                stos.usun();
                break;
            case 3:
                stos.wypisz();
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
