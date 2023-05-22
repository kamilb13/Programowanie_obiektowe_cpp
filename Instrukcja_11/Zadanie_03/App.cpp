#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>

class MyFrame : public wxFrame
{
private:
    wxTextCtrl* imie;
    wxTextCtrl* nazwisko;
    wxSpinCtrl* wiek;
    wxChoice* rokStudiow;
    wxComboBox* grupaDziekanska;
    wxTextCtrl* indeks;

public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxStaticText* imieLabel = new wxStaticText(panel, wxID_ANY, "Imiê:", wxPoint(20, 20));
        wxStaticText* nazwiskoLabel = new wxStaticText(panel, wxID_ANY, "Nazwisko:", wxPoint(20, 60));
        wxStaticText* wiekLabel = new wxStaticText(panel, wxID_ANY, "Wiek:", wxPoint(20, 100));
        wxStaticText* rokStudiowLabel = new wxStaticText(panel, wxID_ANY, "Rok studiów:", wxPoint(20, 140));
        wxStaticText* grupaDziekanskaLabel = new wxStaticText(panel, wxID_ANY, "Grupa dziekañska:", wxPoint(20, 180));
        wxStaticText* indeksLabel = new wxStaticText(panel, wxID_ANY, "Nr indeksu:", wxPoint(20, 220));

        imie = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 20), wxSize(200, -1));
        nazwisko = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 60), wxSize(200, -1));
        wiek = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(170, 100), wxSize(70, -1), wxSP_ARROW_KEYS, 0, 100, 0);
        wxString yearChoices[] = { "1", "2", "3", "4", "5" };
        rokStudiow = new wxChoice(panel, wxID_ANY, wxPoint(170, 140), wxSize(70, -1), WXSIZEOF(yearChoices), yearChoices);

        wxArrayString groupChoices;
        groupChoices.Add("1ID11A");
        groupChoices.Add("1ID11B");
        groupChoices.Add("1ID12A");
        groupChoices.Add("1ID12B");
        grupaDziekanska = new wxComboBox(panel, wxID_ANY, "", wxPoint(170, 180), wxSize(150, -1), groupChoices, wxCB_DROPDOWN);

        indeks = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(170, 220), wxSize(150, -1));

        wxButton* saveButton = new wxButton(panel, wxID_ANY, "Zapisz", wxPoint(170, 260));

        saveButton->Bind(wxEVT_BUTTON, &MyFrame::OnSaveButtonClick, this);

    }

private:
    void OnSaveButtonClick(wxCommandEvent& event)
    {
        // Kod obs³uguj¹cy zdarzenie klikniêcia przycisku "Zapisz"
        wxString name = imie->GetValue();
        wxString surname = nazwisko->GetValue();
        int age = wiek->GetValue();
        wxString year = rokStudiow->GetStringSelection();
        wxString group = grupaDziekanska->GetValue();
        wxString index = indeks->GetValue();

        // Przetwarzanie wprowadzonych danych...

        wxMessageBox("Dane zosta³y zapisane.", "Informacja", wxOK | wxICON_INFORMATION);
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        wxInitAllImageHandlers();
        MyFrame* frame = new MyFrame("Zadanie 03");
        frame->SetClientSize(600, 800);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
