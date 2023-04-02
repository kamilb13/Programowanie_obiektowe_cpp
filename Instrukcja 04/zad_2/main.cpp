#include <iostream>

using namespace std;

class Zwierze{
public:
    Zwierze(){}
    void jedz() {
        cout << "Zwierze je" << endl;
    }
};

class Ptak : public Zwierze{
public:
    Ptak(){}
    void lec(){
        cout << "Ptak lata" << endl;
    }
};

class Ryba : public Zwierze{
public:
    Ryba(){}
    void plyn(){
        cout << "Ryba plywa" << endl;
    }
};

int main(){
    Ptak* ptak = new Ptak();
    Zwierze* zwierze = ptak;
    zwierze->jedz();

    Ryba ryba;
    ((Zwierze&)ryba).jedz();
    //ryba.jedz();

    delete ptak;
    return 0;
}




