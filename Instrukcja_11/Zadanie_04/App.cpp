#include <wx/wx.h>
#include <wx/gauge.h>

class MyFrame : public wxFrame
{
private:
    wxGauge* pasek;
    wxButton* startButton;
    wxButton* resetButton;

public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        pasek = new wxGauge(panel, wxID_ANY, 100, wxPoint(20, 20), wxSize(250, 25));

        pasek->SetValue(10);
        pasek->SetRange(200);
        pasek->SetForegroundColour(wxColour(0, 0, 255));
        pasek->SetBackgroundColour(wxColour(255, 255, 255));
        pasek->SetBezelFace(5);

        startButton = new wxButton(panel, wxID_ANY, "+10", wxPoint(20, 60));
        resetButton = new wxButton(panel, wxID_ANY, "Reset", wxPoint(120, 60));

        startButton->Bind(wxEVT_BUTTON, &MyFrame::OnStartButtonClick, this);
        resetButton->Bind(wxEVT_BUTTON, &MyFrame::OnResetButtonClick, this);
    }

    void OnStartButtonClick(wxCommandEvent& event){
        int wartosc_paska = pasek->GetValue();
        if (wartosc_paska < pasek->GetRange()){
            pasek->SetValue(wartosc_paska + 10);
        }
    }

    void OnResetButtonClick(wxCommandEvent& event){
        pasek->SetValue(0);
    }

};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        wxInitAllImageHandlers();
        MyFrame* frame = new MyFrame("Zadanie 04");
        frame->SetClientSize(350, 200);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
