#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/msgdlg.h>
#include <fstream>

class MyFrame : public wxFrame
{
public:
    MyFrame( wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(*wxWHITE));

        wxStaticText* imieLabel = new wxStaticText(panel, wxID_ANY, "Imie:", wxPoint(20, 20));
        wxStaticText* nazwiskoLabel = new wxStaticText(panel, wxID_ANY, "Nazwisko:", wxPoint(20, 60));
        wxStaticText* wiekLabel = new wxStaticText(panel, wxID_ANY, "Wiek:", wxPoint(20, 100));
        wxStaticText* rokStudiowLabel = new wxStaticText(panel, wxID_ANY, "Rok studiow:", wxPoint(20, 140));
        wxStaticText* grupaDziekanskaLabel = new wxStaticText(panel, wxID_ANY, "Grupa dziekanska:", wxPoint(20, 180));
        wxStaticText* indeksLabel = new wxStaticText(panel, wxID_ANY, "Nr indeksu:", wxPoint(20, 220));

        imie = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 20), wxSize(200, -1));
        nazwisko = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 60), wxSize(200, -1));
        wiek = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(170, 100), wxSize(70, -1), wxSP_ARROW_KEYS, 0, 100, 0);
        wxArrayString yearChoices;
        yearChoices.Add("1");
        yearChoices.Add("2");
        yearChoices.Add("3");
        yearChoices.Add("4");
        yearChoices.Add("5");

        rokStudiow = new wxChoice(panel, wxID_ANY, wxPoint(170, 140), wxSize(70, -1), yearChoices);

        wxArrayString groupChoices;
        groupChoices.Add("1ID11A");
        groupChoices.Add("1ID11B");
        groupChoices.Add("1ID12A");
        groupChoices.Add("1ID12B");
        groupChoices.Add("1ID15A");
        groupChoices.Add("1ID15B");

        grupaDziekanska = new wxComboBox(panel, wxID_ANY, "", wxPoint(170, 180), wxSize(150, -1), groupChoices);

        indeks = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 220), wxSize(150, -1));

        wxButton* zapisz_btn = new wxButton(panel, wxID_ANY, "Zapisz", wxPoint(170, 260));
        wxButton* czysc_btn = new wxButton(panel, wxID_ANY, "Czyœæ", wxPoint(260, 260));

        zapisz_btn->Bind(wxEVT_BUTTON, &MyFrame::OnSaveButtonClick, this);
        czysc_btn->Bind(wxEVT_BUTTON, &MyFrame::OnClearButtonClick, this);
    }

private:
    wxTextCtrl* imie;
    wxTextCtrl* nazwisko;
    wxSpinCtrl* wiek;
    wxChoice* rokStudiow;
    wxComboBox* grupaDziekanska;
    wxTextCtrl* indeks;

    void OnSaveButtonClick(wxCommandEvent& event)
    {
        wxString name = imie->GetValue();
        wxString surname = nazwisko->GetValue();
        int age = wiek->GetValue();
        wxString year = rokStudiow->GetStringSelection();
        wxString group = grupaDziekanska->GetValue();
        wxString index = indeks->GetValue();

        if (age < 0)
        {
            wxMessageBox("Wiek nie mo¿e byæ ujemny!", "B³¹d", wxOK | wxICON_ERROR);
            return;
        }

        std::ofstream zapis("dane.txt", std::ios_base::app);

        zapis << name << " " << surname << ", " << age << " lat, " << year << " rok studiów, grupa dziekañska " << group << ", numer indeksu " << index << std::endl;

        zapis.close();

        wxMessageBox("Dane zapisane.", "Sukces", wxOK | wxICON_INFORMATION);
    }

    void OnClearButtonClick(wxCommandEvent& event)
    {
        imie->Clear();
        nazwisko->Clear();
        wiek->SetValue(0);
        rokStudiow->SetSelection(-1);
        grupaDziekanska->SetValue("");
        indeks->Clear();
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame("Zadanie 04");
        frame->SetClientSize(400, 350);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
