#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Obs³uga zdarzeñ", wxDefaultPosition, wxSize(400, 300))
    {
        panel = new wxPanel(this);

        wxString choices[] = { "Opcja 1", "Opcja 2", "Opcja 3" };

        button = new wxButton(panel, wxID_ANY, "Kliknij mnie", wxPoint(20, 20));
        combo_box = new wxComboBox(panel, wxID_ANY, "", wxPoint(20, 60), wxDefaultSize, 3, choices, wxCB_DROPDOWN);
        list_box = new wxListBox(panel, wxID_ANY, wxPoint(20, 100), wxSize(150, 100), 3, choices, wxLB_SINGLE);
        radio_button = new wxRadioButton(panel, wxID_ANY, "Wybierz mnie", wxPoint(20, 220));

        button->Bind(wxEVT_BUTTON, &MyFrame::on_button_click, this);
        combo_box->Bind(wxEVT_COMBOBOX, &MyFrame::on_combo_box_select, this);
        list_box->Bind(wxEVT_LISTBOX, &MyFrame::on_list_box_select, this);
        radio_button->Bind(wxEVT_RADIOBUTTON, &MyFrame::on_radio_button_select, this);
    }

    void on_button_click(wxCommandEvent& event)
    {
        wxMessageBox("Przycisk zosta³ klikniêty!");
        event.Skip();
    }

    void on_combo_box_select(wxCommandEvent& event)
    {
        wxString selection = combo_box->GetStringSelection();
        wxString message = "Wybrano: " + selection;
        wxMessageBox(message);
        event.Skip();
    }

    void on_list_box_select(wxCommandEvent& event)
    {
        int selectionIndex = list_box->GetSelection();
        wxString selection = list_box->GetString(selectionIndex);
        wxString message = "Wybrano: " + selection;
        wxMessageBox(message);
        event.Skip();
    }

    void on_radio_button_select(wxCommandEvent& event)
    {
        wxMessageBox("Radio button zosta³ zaznaczony!");
        event.Skip();
    }

private:
    wxPanel* panel;
    wxButton* button;
    wxComboBox* combo_box;
    wxListBox* list_box;
    wxRadioButton* radio_button;
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
