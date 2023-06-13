#include <wx/wx.h>
#include <kwadratowka.h>

Kwadratowka::Kwadratowka() : wxFrame(NULL, wxID_ANY, "Wyznaczanie pierwiastków"){
        wxPanel* panel = new wxPanel(this);
        panel->SetBackgroundColour(wxColour(* wxWHITE));

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText* labelA = new wxStaticText(panel, wxID_ANY, "Wspó³czynnik a:");
        poleA = new wxTextCtrl(panel, wxID_ANY);
        sizer->Add(labelA, 0, wxALL, 6);
        sizer->Add(poleA, 0, wxALL, 6);

        wxStaticText* labelB = new wxStaticText(panel, wxID_ANY, "Wspó³czynnik b:");
        poleB = new wxTextCtrl(panel, wxID_ANY);
        sizer->Add(labelB, 0, wxALL, 6);
        sizer->Add(poleB, 0, wxALL, 6);

        wxStaticText* labelC = new wxStaticText(panel, wxID_ANY, "Wspó³czynnik c:");
        poleC = new wxTextCtrl(panel, wxID_ANY);
        sizer->Add(labelC, 0, wxALL, 6);
        sizer->Add(poleC, 0, wxALL, 6);

        wxButton* wyznaczBtn = new wxButton(panel, wxID_ANY, "Wyznacz");
        sizer->Add(wyznaczBtn, 0, wxALL, 6);

        wxStaticText* wynikLabel = new wxStaticText(panel, wxID_ANY, "Pierwiastki:");
        wynikText = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(-1, -1), wxSize(400, -1));
        sizer->Add(wynikLabel, 0, wxALL, 6);
        sizer->Add(wynikText, 0, wxALL, 6);

        mainSizer->AddStretchSpacer();
        mainSizer->Add(sizer, 0, wxALIGN_CENTER);
        mainSizer->AddStretchSpacer();

        panel->SetSizer(mainSizer);

        wyznaczBtn->Bind(wxEVT_BUTTON, &Kwadratowka::wyznaczPierwiastki, this);
    }

    Kwadratowka::wyznaczPierwiastki(wxCommandEvent& event){
        double a, b, c;

        poleA->GetValue().ToDouble(&a);
        poleB->GetValue().ToDouble(&b);
        poleC->GetValue().ToDouble(&c);

        double delta = (b*b)-(4*a*c);
        wxString wynik;
        double sqrtDelta = sqrt(delta);

        if(a == 0){
            wynik << "To jest funkcja liniowa, a nie kwadratowa";
        }else{
            if (delta > 0){
                double x1 = (-b+sqrtDelta)/(2*a);
                double x2 = (-b-sqrtDelta)/(2*a);
                wynik << "x1 = " << x1 << ", x2 = " << x2;
            }
            else if (delta == 0){
                double x = -b / (2 * a);
                wynik << "x = " << x;
            }
            else{
                wynik << "Brak pierwaistkow";
            }
        }

        wynikText->SetValue(wynik);
    }
