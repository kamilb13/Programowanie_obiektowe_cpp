#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->Bind(wxEVT_KEY_DOWN, &MyFrame::OnKeyDown, this);
        panel->Bind(wxEVT_KEY_UP, &MyFrame::OnKeyUp, this);
        panel->Bind(wxEVT_CHAR, &MyFrame::OnChar, this);
    }

private:
    void OnKeyDown(wxKeyEvent& event)
    {
        int keyCode = event.GetKeyCode();
        wxString keyName = wxString::Format("%c", keyCode);
        wxString message = "Key Down: " + keyName;
        wxLogMessage(message);
        event.Skip();
    }

    void OnKeyUp(wxKeyEvent& event)
    {
        int keyCode = event.GetKeyCode();
        wxString keyName = wxString::Format("%c", keyCode);
        wxString message = "Key Up: " + keyName;
        wxLogMessage(message);
        event.Skip();
    }

    void OnChar(wxKeyEvent& event)
    {
        int keyCode = event.GetKeyCode();
        wxString keyName = wxString::Format("%c", keyCode);
        wxString message = "Character Typed: " + keyName;
        wxLogMessage(message);
        event.Skip();
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame("Keyboard Events");
        frame->SetClientSize(400, 300);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
