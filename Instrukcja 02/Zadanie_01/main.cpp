#include <iostream>
#include <string>

using namespace std;

class Samochod{
protected:
    string marka;
    string model;
    string kolor;
    int rocznik;
    int pojemnosc_silnika;
public:
    Samochod(string marka, string model, string kolor, int rocznik, int pojemnosc_silnika){
        this->marka=marka;
        this->model=model;
        this->kolor=kolor;
        this->rocznik=rocznik;
        this->pojemnosc_silnika=pojemnosc_silnika;
    }

    string getMarka(){
        return marka;
    }

    string getModel(){
        return model;
    }

    string getKolor(){
        return kolor;
    }

    int getRocznik(){
        return rocznik;
    }

    int getPojemnoscSilnika(){
        return pojemnosc_silnika;
    }

    void setMarka(string marka) {
        this->marka = marka;
    }

    void setModel(string model) {
        this->model = model;
    }

    void setKolor(string kolor) {
        this->kolor = kolor;
    }

    void setRocznik(int rocznik) {
        this->rocznik = rocznik;
    }

    void setPojemnoscSilnika(int pojemnosc_silnika) {
        this->pojemnosc_silnika = pojemnosc_silnika;
    }

    void info(){
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Kolor: " << kolor << endl;
        cout << "Rocznik: " << rocznik << endl;
        cout << "Pojemnosc silnika: " << pojemnosc_silnika << " cm3" << endl;
    }

    void start(){
        cout << "Samochod " << marka << " " << model << " zostal uruchomiony." << endl;
    }

    void stop(){
        cout << "Samochod " << marka << " " << model << " zostal zatrzymany." << endl;
    }

    void przyspiesz(int predkosc){
        cout << "Samochod " << marka << " " << model << " przyspiesza do prdekosci " << predkosc << " km/h." << endl;
    }

    void hamuj(){
        cout << "Samochod " << marka << " " << model << " hamuje." << endl;
    }
};

class Telefon{
protected:
    string marka;
    string model;
    string kolor;
    float przekatna_ekranu;
public:
    Telefon(string marka, string model, string kolor, float przekatna_ekranu){
        this-> marka=marka;
        this->model=model;
        this->kolor=kolor;
        this->przekatna_ekranu=przekatna_ekranu;
    }

    string getMarka(){
        return marka;
    }

    string getModel(){
        return model;
    }

    string getKolor(){
        return kolor;
    }

    float getPrzekatnaEkranu(){
        return przekatna_ekranu;
    }

    void setMarka(string marka) {
        this->marka = marka;
    }

    void setModel(string model) {
        this->model = model;
    }

    void setKolor(string kolor){
        this->kolor = kolor;
    }

    void setPrzekatnaEkranu(float przekatna_ekranu){
        this->przekatna_ekranu = przekatna_ekranu;
    }

    void info(){
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Kolor: " << kolor << endl;
        cout << "Przekatna ekranu: " << przekatna_ekranu << " cali" << endl;
    }

    void dzwoni(string numer){
        cout << "Telefon " << marka << " " << model << " dzwoni do " << numer << "." << endl;
    }

    void wyslijSMS(string numer, string tresc){
        cout << "Telefon " << marka << " " << model << " wysyla smsa o tresci " << tresc << " na numer " << numer << "." << endl;
    }

    void odbierzPolaczenie(string numer){
        cout << "Telefon " << marka << " " << model << " odbiera polaczenie od numeru " << numer << "." << endl;
    }
};


class Samolot{
protected:
    string marka;
    string model;
    string kolor;
    int pojemnosc_silnika;
    int liczba_miejsc;
public:
    Samolot(string marka, string model, string kolor, int pojemnosc_silnika, int liczba_miejsc){
        this->marka=marka;
        this->model=model;
        this->kolor=kolor;
        this->pojemnosc_silnika=pojemnosc_silnika;
        this->liczba_miejsc=liczba_miejsc;
    }

    string getMarka(){
        return marka;
    }

    string getModel(){
        return model;
    }

    string getKolor(){
        return kolor;
    }

    int getPojemnoscSilnika(){
        return pojemnosc_silnika;
    }

    int getLiczbaMiejsc(){
        return liczba_miejsc;
    }

    void setMarka(string marka){
        this->marka = marka;
    }

    void setModel(string model){
        this->model = model;
    }

    void setKolor(string kolor){
        this->kolor = kolor;
    }

    void setPojemnoscSilnika(int pojemnosc_silnika) {
        this->pojemnosc_silnika = pojemnosc_silnika;
    }

    void setLiczbaMiejsc(int liczba_miejsc) {
        this->liczba_miejsc = liczba_miejsc;
    }

    void info(){
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Kolor: " << kolor << endl;
        cout << "Pojemnosc silnika: " << pojemnosc_silnika << " cm^3" << endl;
        cout << "Liczba miejsc: " << liczba_miejsc << endl;
    }

    void start(){
        cout << "Samolot " << marka << " " << model << " zostal uruchomiony" << endl;
    }

    void stop(){
        cout << "Samolot " << marka << " " << model << " zostal zatrzymany" << endl;
    }

    void wznoszenie(int wysokosc){
        cout << "Samolot " << marka << " " << model << " wznosi sie na wysokosc " << wysokosc << " metrow" << endl;
    }

    void ladowanie(){
        cout << "Samolot " << marka << " " << model << " laduje" << endl;
    }
};




int main(){
    Samochod samochod("Volvo", "S40", "Czarny", 2006, 1.6);
    Telefon telefon("Samsung", "S10", "Czarny", 6.0);
    Samolot samolot("Boeing", "Boeing 3773", "Bialy", 1000, 535);
    samochod.info();
    cout << endl;
    samochod.hamuj();
    cout << endl;
    telefon.info();
    telefon.dzwoni("123456789");
    cout << endl;
    cout << telefon.getKolor();
    cout << endl;
    samolot.wznoszenie(1000);

    return 0;
}
