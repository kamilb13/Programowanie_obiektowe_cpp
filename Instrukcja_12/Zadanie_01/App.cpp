#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Informacje o myszy", wxDefaultPosition, wxSize(400, 300))
    {
        panel = new wxPanel(this);
        status_bar = CreateStatusBar();

        panel->Bind(wxEVT_MOTION, &MyFrame::on_mouse_move, this);
        panel->Bind(wxEVT_LEFT_DOWN, &MyFrame::on_left_down, this);
        panel->Bind(wxEVT_LEFT_UP, &MyFrame::on_left_up, this);
        panel->Bind(wxEVT_LEFT_DCLICK, &MyFrame::on_left_double_click, this);
        panel->Bind(wxEVT_MOUSEWHEEL, &MyFrame::on_mouse_scroll, this);
    }

    void on_mouse_move(wxMouseEvent& event)
    {
        status_bar->SetStatusText(wxString::Format("polozenie kursora: %d, %d", event.GetX(), event.GetY()));
        //event.Skip();
    }

    void on_left_down(wxMouseEvent& event)
    {
        status_bar->SetStatusText("LP klik");
        //event.Skip();
    }

    void on_left_up(wxMouseEvent& event)
    {
        status_bar->SetStatusText("LP podniesiony");
        //event.Skip();
    }

    void on_left_double_click(wxMouseEvent& event)
    {
        status_bar->SetStatusText("LP podwojnie");
        //event.Skip();
    }

    void on_mouse_scroll(wxMouseEvent& event)
    {
        int rotation = event.GetWheelRotation();
        status_bar->SetStatusText(wxString::Format("Przewijanie: %d", rotation));
        //event.Skip();
    }

private:
    wxPanel* panel;
    wxStatusBar* status_bar;
};

class MyApp : public wxApp
{
public:
    bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->SetClientSize(400, 400);
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
