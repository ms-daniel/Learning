// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OpenFile(wxCommandEvent& event);
};

enum
{
    ID_Hello = 1,
    ID_FILE = 2
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Aprendendo WxWidgets")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Olá...\tCtrl-H",
        "Aqui vou so mostrar um dialog box");
    menuFile->Append(ID_FILE, "Abrir arquivo", "abre ai vai");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, "&Click me..\tCtrl-C", "Essa foi minha primeira tentativa de mudança");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Arquivo");
    menuBar->Append(menuHelp, "&Ajuda");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Bem-vindo a tela de aprendizagem WxWidgets");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OpenFile, this, ID_FILE);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Esse era apenas um exemplo de hello world, mas vou mexer muito",
        "Tentando de novo", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Dialog box do wxwidgets");
}

void MyFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog* OpenDialog = new wxFileDialog(
        this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
        _("Text files (*.txt)|*.txt|C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx| C Source files(*.c) | *.c | C header files(*.h) | *.h"),
            wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
  
    }
}