#include <wx/wx.h>
#include <sstream>

class CalculatorFrame : public wxFrame
{
public:
    CalculatorFrame() : wxFrame(NULL, wxID_ANY, "Kalkulator", wxDefaultPosition, wxSize(300, 400))
    {
        panel = new wxPanel(this);

        text_ctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 20), wxSize(250, 40), wxTE_READONLY | wxTE_RIGHT);

        wxGridSizer* grid_sizer = new wxGridSizer(4, 4, 5, 5);
        for (int i = 0; i < 10; i++)
        {
            wxButton* button = new wxButton(panel, wxID_ANY, wxString::Format("%d", i));
            button->Bind(wxEVT_BUTTON, &CalculatorFrame::on_number_button_click, this);
            grid_sizer->Add(button, 0, wxEXPAND);
        }
        wxButton* addButton = new wxButton(panel, ID_ADD, "+");
        addButton->Bind(wxEVT_BUTTON, &CalculatorFrame::on_operator_button_click, this);
        grid_sizer->Add(addButton, 0, wxEXPAND);
        wxButton* subtractButton = new wxButton(panel, ID_SUBTRACT, "-");
        subtractButton->Bind(wxEVT_BUTTON, &CalculatorFrame::on_operator_button_click, this);
        grid_sizer->Add(subtractButton, 0, wxEXPAND);
        wxButton* multiplyButton = new wxButton(panel, ID_MULTIPLY, "*");
        multiplyButton->Bind(wxEVT_BUTTON, &CalculatorFrame::on_operator_button_click, this);
        grid_sizer->Add(multiplyButton, 0, wxEXPAND);
        wxButton* divideButton = new wxButton(panel, ID_DIVIDE, "/");
        divideButton->Bind(wxEVT_BUTTON, &CalculatorFrame::on_operator_button_click, this);
        grid_sizer->Add(divideButton, 0, wxEXPAND);
        wxButton* equalsButton = new wxButton(panel, ID_EQUALS, "=");
        equalsButton->Bind(wxEVT_BUTTON, &CalculatorFrame::on_equals_button_click, this);
        grid_sizer->Add(equalsButton, 0, wxEXPAND);

        wxBoxSizer* box_sizer = new wxBoxSizer(wxVERTICAL);
        box_sizer->Add(text_ctrl, 0, wxEXPAND | wxBOTTOM, 10);
        box_sizer->Add(grid_sizer, 1, wxEXPAND);

        panel->SetSizer(box_sizer);
    }

    void on_number_button_click(wxCommandEvent& event)
    {
        wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
        wxString buttonText = button->GetLabel();

        wxString currentText = text_ctrl->GetValue();
        currentText += buttonText;

        text_ctrl->SetValue(currentText);
    }

    void on_operator_button_click(wxCommandEvent& event)
    {
        wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
        wxString buttonText = button->GetLabel();

        wxString currentText = text_ctrl->GetValue();
        currentText += " " + buttonText + " ";

        text_ctrl->SetValue(currentText);
    }

    void on_equals_button_click(wxCommandEvent& event)
    {
        wxString currentText = text_ctrl->GetValue();

        double result = 0;

        std::istringstream input(currentText.ToStdString());
        std::string token;
        std::string op;

        input >> result;

        while (input >> op)
        {
            double operand;
            input >> operand;

            if (op == "+")
                result += operand;
            else if (op == "-")
                result -= operand;
            else if (op == "*")
                result *= operand;
            else if (op == "/")
                result /= operand;
        }

        text_ctrl->SetValue(wxString::Format("%g", result));
    }

private:
    enum
    {
        ID_ADD = 1000,
        ID_SUBTRACT,
        ID_MULTIPLY,
        ID_DIVIDE,
        ID_EQUALS
    };

    wxPanel* panel;
    wxTextCtrl* text_ctrl;
};

class MyApp : public wxApp
{
public:
    bool OnInit() override
    {
        CalculatorFrame* frame = new CalculatorFrame();
        frame->SetClientSize(400, 400);
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
