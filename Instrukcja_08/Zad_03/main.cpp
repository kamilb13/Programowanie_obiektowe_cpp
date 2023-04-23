#include <iostream>

using namespace std;

class Ulamek {
  public:
    int licznik, mianownik;

    friend Ulamek operator*(Ulamek& u1, Ulamek& u2) {
        Ulamek result;
        result.licznik = u1.licznik * u2.licznik;
        result.mianownik = u1.mianownik * u2.mianownik;
        return result;
    }
};

int main() {
    Ulamek u1, u2, iloczyn;

    cout << "Podaj licznik i mianownik pierwszego ulamka: ";
    cin >> u1.licznik >> u1.mianownik;

    cout << "Podaj licznik i mianownik drugiego ulamka: ";
    cin >> u2.licznik >> u2.mianownik;

    iloczyn = u1 * u2;

    cout << "Iloczyn wynosi: " << iloczyn.licznik << "/" << iloczyn.mianownik << endl;

    return 0;
}
