#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxComboBox* comboBox = new wxComboBox(panel, wxID_ANY, "", wxPoint(20, 20), wxDefaultSize, wxArrayString(), wxCB_DROPDOWN | wxCB_SORT);
        comboBox->Append("wxComboBox 1");
        comboBox->Append("wxComboBox 2");
        comboBox->Append("wxComboBox 3");
        comboBox->SetSelection(0);

        wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(20, 70), wxSize(150, 100), wxArrayString(), wxLB_SINGLE);
        listBox->Append("wxListBox 1");
        listBox->Append("wxListBox 2");
        listBox->Append("wxListBox 3");

        wxCheckListBox* checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(20, 190), wxSize(150, 200), wxArrayString(), wxLB_SINGLE);
        checkListBox->Append("wxCheckListBox 1");
        checkListBox->Append("wxCheckListBox 2");
        checkListBox->Append("wxCheckListBox 3");

        wxString choices[] = { "wxRadioBox 1", "wxRadioBox 2", "wxRadioBox 3" };
        wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Wybierz jedn¹ opcjê", wxPoint(200, 20), wxDefaultSize, WXSIZEOF(choices), choices, 1, wxRA_SPECIFY_COLS);

        wxRadioButton* radioButton1 = new wxRadioButton(panel, wxID_ANY, "wxRadioButton 1", wxPoint(200, 200));
        wxRadioButton* radioButton2 = new wxRadioButton(panel, wxID_ANY, "wxRadioButton 2", wxPoint(200, 240));
        wxRadioButton* radioButton3 = new wxRadioButton(panel, wxID_ANY, "wxRadioButton 3", wxPoint(200, 280));

    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame("Zadanie 02");
        frame->SetClientSize(600, 800);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
