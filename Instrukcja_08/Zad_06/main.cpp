#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
    int hour, minute, second;

    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
};

int main() {
    // Pobranie aktualnego czasu systemowego
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Utworzenie obiektu klasy Time z aktualnym czasem
    Time currentTime(ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

    // Przypisanie wartoœci pól sk³adowych obiektu do zmiennych
    int hour = currentTime.hour;
    int minute = currentTime.minute;
    int second = currentTime.second;

    // Wyœwietlenie informacji o czasie
    cout << "Aktualny czas: " << hour << ":" << minute << ":" << second << endl;

    return 0;
}
