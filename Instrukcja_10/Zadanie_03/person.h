#include <wx/wx.h>
#include <vector>

using namespace std;

class osoba{
private:
        wxString imie;
        wxString nazwisko;
        unsigned int wiek;
        unsigned int wzrost;
public:
        osoba(wxString imie, wxString nazwisko, unsigned int wiek){
            this->imie=imie;
            this->nazwisko=nazwisko;
            this->wiek=wiek;
        }
        wxString wypiszDaneOsoby(){
            return ("imie: " + imie + " nazwisko: " + nazwisko + " wiek: " + to_string(wiek) + "\n");
        }
};

vector<osoba> wektor;
vector<osoba>::iterator it;
