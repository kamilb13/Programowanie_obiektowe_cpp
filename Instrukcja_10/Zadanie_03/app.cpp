#include <wx/wx.h>
#include "person.h"

enum{
    ID1,
    ID2
};

class MyApp : public wxApp{
public:
    bool OnInit();
};

class MyFrame : public wxFrame{
public:
    MyFrame();
private:
    wxTextCtrl *textCtrl1;
    wxTextCtrl *textCtrl2;
    wxTextCtrl *textCtrl3;
    wxTextCtrl *textCtrl5;
    wxTextCtrl *textCtrl6;

    void Dodaj(wxCommandEvent& event){
        textCtrl6->SetValue("");
        wektor.push_back(osoba(textCtrl1->GetValue(), textCtrl2->GetValue(), atoi(textCtrl3->GetValue())));
        for(int i=0; i<wektor.size(); i++)
            *textCtrl6 << i+1 << ". " << wektor[i].wypiszDaneOsoby();
    }

    void Usun(wxCommandEvent& event){
        textCtrl6->SetValue("");
        int x = atoi(textCtrl5->GetValue());
        it = wektor.begin()+(x-1);
        if(x && wektor.size()>=x)
            wektor.erase(it);
        for(int i = 0 ; i<wektor.size(); i++)
            *textCtrl6 << i+1 << ". " << wektor[i].wypiszDaneOsoby();
    }
};

bool MyApp::OnInit(){
    MyFrame *frame = new MyFrame();
    frame->SetClientSize(wxSize(450, 350));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Zad 3"){
    textCtrl1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(110, 30));
    textCtrl2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(130, 10), wxSize(110, 30));
    textCtrl3 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(250, 10), wxSize(110, 30));
    wxButton *button1 = new wxButton(this, ID1, "Dodaj", wxPoint(10, 80), wxSize(50, 30));
    wxStaticText* text = new wxStaticText(this, wxID_ANY, "Wpisz jaki numer indeksu chcesz uszunac: ", wxPoint(10, 120));
    textCtrl5 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(70, 150), wxSize(30, 30));
    wxButton *button2 = new wxButton(this, ID2, "Usun", wxPoint(110, 150), wxSize(50, 30));
    textCtrl6 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 200), wxSize(420, 200), wxTE_MULTILINE);

    Bind(wxEVT_BUTTON, &MyFrame::Dodaj, this, ID1);
    Bind(wxEVT_BUTTON, &MyFrame::Usun, this, ID2);
}


wxIMPLEMENT_APP(MyApp);
