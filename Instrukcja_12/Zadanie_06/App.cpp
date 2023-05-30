#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <fstream>
#include <sstream>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 10), wxSize(400, 300), wxTE_MULTILINE);

        wxButton* saveButton = new wxButton(panel, wxID_ANY, "Save", wxPoint(10, 320));
        wxButton* loadButton = new wxButton(panel, wxID_ANY, "Load", wxPoint(90, 320));
        wxButton* clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(170, 320));

        saveButton->Bind(wxEVT_BUTTON, &MyFrame::OnSaveButtonClick, this);
        loadButton->Bind(wxEVT_BUTTON, &MyFrame::OnLoadButtonClick, this);
        clearButton->Bind(wxEVT_BUTTON, &MyFrame::OnClearButtonClick, this);
    }

private:
    wxTextCtrl* textCtrl;

    void OnSaveButtonClick(wxCommandEvent& event)
    {
        wxString filePath = wxFileSelector("Save File", "", "", "", "Text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT, this);

        if (!filePath.empty())
        {
            std::ofstream file(filePath.ToStdString());
            if (file.is_open())
            {
                file << textCtrl->GetValue();
                file.close();
                wxMessageBox("File saved.");
            }
            else
            {
                wxMessageBox("Failed to save file.", "Error", wxOK | wxICON_ERROR);
            }
        }
    }

    void OnLoadButtonClick(wxCommandEvent& event)
    {
        wxString filePath = wxFileSelector("Load File", "", "", "", "Text files (*.txt)|*.txt", wxFD_OPEN, this);

        if (!filePath.empty())
        {
            std::ifstream file(filePath.ToStdString());
            if (file.is_open())
            {
                std::stringstream buffer;
                buffer << file.rdbuf();
                textCtrl->SetValue(buffer.str());
                file.close();
                wxMessageBox("File loaded.");
            }
            else
            {
                wxMessageBox("Failed to load file.", "Error", wxOK | wxICON_ERROR);
            }
        }
    }

    void OnClearButtonClick(wxCommandEvent& event)
    {
        textCtrl->Clear();
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame("Text Editor");
        frame->SetClientSize(420, 380);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
