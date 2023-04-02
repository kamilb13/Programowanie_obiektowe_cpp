#include <iostream>

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

class Krzak : public Roslina{
public:
    Krzak(){ }
    void powiewaj(){
        std::cout << "moje liscie powiewaja jestem krakiem!...\n";
    }
    void kluje(){
        std::cout << "kluje bo jestem krzakiem...\n";
    }
};

class Wodorosty : public Roslina{
public:
    Wodorosty(){ }
    void plywaj(){
        std::cout << "jestem wodorostem i plywam!...\n";
    }
};

int main(){
    Drzewo brzoza;
    Krzak agrest;
    Wodorosty lilia_wodna;

    Roslina tablica[] = { brzoza, agrest, lilia_wodna };
    for (int i = 0; i < 2; i++) {
        tablica[i].fotosyntezuj();
        tablica[i].produkujTlen();
    }
    return 0;
}
