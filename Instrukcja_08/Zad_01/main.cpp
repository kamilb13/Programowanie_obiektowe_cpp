#include <iostream>

using namespace std;

class Vector {
  public:
    int x, y;

    Vector operator+( Vector& v) {
        Vector wyn;
        wyn.x = x + v.x;
        wyn.y = y + v.y;
        return wyn;
    }

    Vector operator-( Vector& v) {
        Vector wyn;
        wyn.x = x - v.x;
        wyn.y = y - v.y;
        return wyn;
    }
};

int main() {
    Vector vector1, vector2, suma, roznica;

    cout << "Podaj wspolrzedne pierwszego wektora: ";
    cin >> vector1.x >> vector1.y;
    cout << "Podaj wspolrzedne drugiego wektora: ";
    cin >> vector2.x >> vector2.y;

    suma = vector1 + vector2;
    roznica = vector1 - vector2;

    cout << "Suma wektora: (" << suma.x << ", " << suma.y << ")" << endl;
    cout << "Roznica wektora: (" << roznica.x << ", " << roznica.y << ")" << endl;

    return 0;
}
