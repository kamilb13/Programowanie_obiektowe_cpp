#include <iostream>

using namespace std;

class Zwierze{
public:
    virtual void poruszaj() = 0;
    virtual void dajGlos() = 0;
};

class Swinia : public Zwierze{
public:
    void poruszaj(){
        cout << "Swinia chodzi.\n";
    }
    void dajGlos(){
        cout << "Kwwi kwii!!!!!!!!\n";
    }
};

class Pies :public Zwierze{
public:
    void poruszaj(){
        cout << "Pies chodzi.\n";
    }
    void dajGlos(){
        cout << "hau hau\n";
    }
};

class Kot : public Zwierze{
public:
    void poruszaj(){
        cout << "Kot chodzi\n";
    }
    void dajGlos(){
        cout << "Mial mial\n";
    }
};

int main(){
    Zwierze* zwierzeta[3] = {new Swinia(), new Pies(), new Kot()};

    for (int i = 0; i < 3; i++){
        zwierzeta[i]->poruszaj();
        zwierzeta[i]->dajGlos();

    }
    delete []zwierzeta;
    return 0;
}
