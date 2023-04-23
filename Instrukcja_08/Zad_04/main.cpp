#include <iostream>
#include <locale.h>

using namespace std;

class Wektor {
  public:
    double x, y, z;

    bool operator==(const Wektor& w) const {
        return (x == w.x && y == w.y && z == w.z);
    }

    bool operator!=(const Wektor& w) const {
        return !(*this == w);
    }
};

int main() {
    setlocale(LC_CTYPE, "Polish");

    Wektor w1, w2;

    cout << "Podaj sk�adowe pierwszego wektora (x y z): ";
    cin >> w1.x >> w1.y >> w1.z;

    cout << "Podaj sk�adowe drugiego wektora (x y z): ";
    cin >> w2.x >> w2.y >> w2.z;

    if (w1 == w2) {
        cout << "Wektory s� r�wne." << endl;
    } else {
        cout << "Wektory nie s� r�wne." << endl;
    }

    if (w1 != w2) {
        cout << "Wektory s� r�ne." << endl;
    } else {
        cout << "Wektory nie s� r�ne." << endl;
    }

    return 0;
}
