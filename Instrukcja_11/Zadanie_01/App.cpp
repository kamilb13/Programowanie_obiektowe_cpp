#include <wx/wx.h>
#include <wx/button.h>
#include <wx/sizer.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

        wxButton* addButton = new wxButton(panel, wxID_ADD, "");
        wxButton* applyButton = new wxButton(panel, wxID_APPLY, "");
        wxButton* boldButton = new wxButton(panel, wxID_BOLD, "");
        wxButton* cancelButton = new wxButton(panel, wxID_CANCEL, "");
        wxButton* clearButton = new wxButton(panel, wxID_CLEAR, "");
        wxButton* closeButton = new wxButton(panel, wxID_CLOSE, "");
        wxButton* copyButton = new wxButton(panel, wxID_COPY, "");
        wxButton* cutButton = new wxButton(panel, wxID_CUT, "");
        wxButton* deleteButton = new wxButton(panel, wxID_DELETE, "");
        wxButton* findButton = new wxButton(panel, wxID_FIND, "");
        wxButton* replaceButton = new wxButton(panel, wxID_REPLACE, "");

        buttonSizer->Add(addButton, 0, wxALL, 10);
        buttonSizer->Add(applyButton, 0, wxALL, 10);
        buttonSizer->Add(boldButton, 0, wxALL, 10);
        buttonSizer->Add(cancelButton, 0, wxALL, 10);
        buttonSizer->Add(clearButton, 0, wxALL, 10);
        buttonSizer->Add(closeButton, 0, wxALL, 10);
        buttonSizer->Add(copyButton, 0, wxALL, 10);
        buttonSizer->Add(cutButton, 0, wxALL, 10);
        buttonSizer->Add(deleteButton, 0, wxALL, 10);
        buttonSizer->Add(findButton, 0, wxALL, 10);
        buttonSizer->Add(replaceButton, 0, wxALL, 10);

        mainSizer->AddStretchSpacer();
        mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER);
        mainSizer->AddStretchSpacer();

        panel->SetSizer(mainSizer);
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame("Zadanie 01");
        frame->SetClientSize(400, 500);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
