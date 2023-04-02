#include <iostream>
#include <vector>

using namespace std;

class Osoba{
protected:
    string imie;
    string nazwisko;
    string kolor_wlosow;
    int wiek;
public:
    Osoba(string imie, string nazwisko, string kolor_wlosow, int wiek){
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->kolor_wlosow=kolor_wlosow;
        this->wiek=wiek;
    }

    string getImie(){
        return imie;
    }

    string getNazwisko(){
        return nazwisko;
    }

    string getKolorWlosow(){
        return kolor_wlosow;
    }

    int getWiek(){
        return wiek;
    }

    void setImie(string imie) {
        this->imie = imie;
    }

    void setNazwisko(string nazwisko) {
        this->nazwisko = nazwisko;
    }

    void setKolorWlosow(string kolor_wlosow) {
        this->kolor_wlosow = kolor_wlosow;
    }

    void setWiek(int wiek) {
        this->wiek = wiek;
    }

    void info(){
        cout << "Imie: " << imie << endl;
        cout << "Naywisko: " << nazwisko << endl;
        cout << "KOlor wlosow: " << kolor_wlosow << endl;
        cout << "Wiek: " << wiek << endl;
    }

    void przedstawSie(){
        cout << "Czesc mam na imie " << imie << "." << endl;
    }

    void biega(){
        cout << imie << " " << nazwisko << " biega." << endl;
    }
};

int main(){
    Osoba osoba("Kamil", "Brzoza", "Blond", 20);
    Osoba osoba1("Jan", "Kowalski", "Czarne", 29);
    vector<Osoba> vector;
    vector.push_back(osoba);
    vector.push_back(osoba1);
    for(auto osoba : vector){
        cout << osoba.getImie();
        cout << endl;
    }
    return 0;
}
