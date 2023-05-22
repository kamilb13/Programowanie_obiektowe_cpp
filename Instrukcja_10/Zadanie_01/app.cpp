#include <wx/wx.h>
#include "kalkulator.h"

enum{
    ID1,
    ID2,
    ID3,
    ID4
};

float kalkulator::suma(){
    return x+y;
}
float kalkulator::odejmowanie(){
    return x-y;
}
float kalkulator::iloczyn(){
    return x*y;
}
float kalkulator::iloraz(){
    if(y) return x/y;
}

class MyApp : public wxApp{
public:
    bool OnInit();
};

class MyFrame : public wxFrame{
public:
    MyFrame();
private:
    wxTextCtrl *liczba1;
    wxTextCtrl *liczba2;
    wxTextCtrl *wynik;
    kalkulator *Kalkulator = new kalkulator();
    void plusBtn(wxCommandEvent& event){
        wynik->SetValue("");
        Kalkulator->zwrocxy(atof(liczba1->GetValue()), atof(liczba2->GetValue()));
        *wynik << Kalkulator->suma();
    }

    void minusBtn(wxCommandEvent& event){
        wynik->SetValue("");
        Kalkulator->zwrocxy(atof(liczba1->GetValue()), atof(liczba2->GetValue()));
        *wynik << Kalkulator->odejmowanie();
    }

    void mulBtn(wxCommandEvent& event){
        wynik->SetValue("");
        Kalkulator->zwrocxy(atof(liczba1->GetValue()), atof(liczba2->GetValue()));
        *wynik << Kalkulator->iloczyn();
    }

    void divBtn(wxCommandEvent& event){
        wynik->SetValue("");
        if(atof(liczba2->GetValue())){
            Kalkulator->zwrocxy(atof(liczba1->GetValue()), atof(liczba2->GetValue()));
            *wynik << Kalkulator->iloraz();
        }
        else{
            *wynik << "Dzielisz przez zero";
        }
    }
};

bool MyApp::OnInit(){
    MyFrame *frame = new MyFrame();
    frame->SetClientSize(wxSize(400, 400));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Kalkulator"){
    liczba1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(100, 50));
    liczba2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(150, 10), wxSize(100, 50));
    wxButton *plusBtn = new wxButton(this, ID1, "+", wxPoint(20, 120), wxSize(50, 50));
    wxButton *minusBtn = new wxButton(this, ID2, "-", wxPoint(20, 180), wxSize(50, 50));
    wxButton *mnozenieBtn = new wxButton(this, ID3, "*", wxPoint(20, 240), wxSize(50, 50));
    wxButton *dzielenieBtn = new wxButton(this, ID4, "/", wxPoint(20, 300), wxSize(50, 50));
    wynik = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 150), wxSize(150, 50));

    Bind(wxEVT_BUTTON, &MyFrame::plusBtn, this, ID1);
    Bind(wxEVT_BUTTON, &MyFrame::minusBtn, this, ID2);
    Bind(wxEVT_BUTTON, &MyFrame::mulBtn, this, ID3);
    Bind(wxEVT_BUTTON, &MyFrame::divBtn, this, ID4);
}


wxIMPLEMENT_APP(MyApp);
