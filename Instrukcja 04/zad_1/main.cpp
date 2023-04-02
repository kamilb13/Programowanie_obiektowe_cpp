#include <iostream>
//1 3 4 5
class Roslina{
public:
    Roslina(){ }
    void fotosyntezuj( ){
        for( int i=0; i<3; ++i )
        std::cout << "Fotosyntezuje\n";
    }

    void produkujTlen( ){
        for( int i=0; i<2; ++i )
        std::cout << "Zamieniam zle powietrze w dobre\n";
    }
};

class Drzewo : public Roslina{
public:
    Drzewo(){ }
    void powiewaj(){
        std::cout << "moje liscie powiewaja!...\n";
    }
    void opadajaLiscie(){
        std::cout << "Moje liscie mi spadaja...\n";
    }
};

int main(){
    Drzewo brzoza;
    brzoza.fotosyntezuj();
    brzoza.produkujTlen();
    brzoza.opadajaLiscie();
    brzoza.produkujTlen();
    brzoza.powiewaj();
    return 0;
}
