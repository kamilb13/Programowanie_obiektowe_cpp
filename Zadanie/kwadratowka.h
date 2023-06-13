#include <wx/wx.h>

class Kwadratowka : public wxFrame{

private:
    wxTextCtrl* poleA;
    wxTextCtrl* poleB;
    wxTextCtrl* poleC;
    wxTextCtrl* wynikText;

public:
    Kwadratowka() : wxFrame(NULL, wxID_ANY, "Wyznaczanie pierwiastków");
    void wyznaczPierwiastki(wxCommandEvent& event);
}
