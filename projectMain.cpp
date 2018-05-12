/***************************************************************
 * Name:      projectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Kevin Grifo ()
 * Created:   2018-03-29
 * Copyright: Kevin Grifo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "projectMain.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include "Cell.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "SafariArena.h"
#include "wx/thread.h"
#include "gameThread.h"

int ***check;
int numRows;
int numCols;
int numPlanes;
int numLions;
int numGazelles;
int numObstacles;
Cell ****cellArr;

wxStaticText* gazText;
wxStaticText* lionText;
wxStaticText* moveText;



//(*InternalHeaders(projectFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(projectFrame)
const long projectFrame::ID_PANEL2 = wxNewId();
const long projectFrame::ID_STATICTEXT1 = wxNewId();
const long projectFrame::ID_SPINCTRL1 = wxNewId();
const long projectFrame::ID_STATICTEXT2 = wxNewId();
const long projectFrame::ID_SPINCTRL2 = wxNewId();
const long projectFrame::ID_STATICTEXT3 = wxNewId();
const long projectFrame::ID_SPINCTRL3 = wxNewId();
const long projectFrame::ID_STATICTEXT4 = wxNewId();
const long projectFrame::ID_SPINCTRL4 = wxNewId();
const long projectFrame::ID_STATICTEXT5 = wxNewId();
const long projectFrame::ID_SPINCTRL5 = wxNewId();
const long projectFrame::ID_STATICTEXT6 = wxNewId();
const long projectFrame::ID_SPINCTRL6 = wxNewId();
const long projectFrame::ID_BUTTON1 = wxNewId();
const long projectFrame::ID_STATICTEXT7 = wxNewId();
const long projectFrame::ID_STATICTEXT10 = wxNewId();
const long projectFrame::ID_STATICTEXT8 = wxNewId();
const long projectFrame::ID_STATICTEXT11 = wxNewId();
const long projectFrame::ID_STATICTEXT9 = wxNewId();
const long projectFrame::ID_STATICTEXT12 = wxNewId();
const long projectFrame::ID_PANEL1 = wxNewId();
const long projectFrame::idMenuQuit = wxNewId();
const long projectFrame::idMenuAbout = wxNewId();
const long projectFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(projectFrame,wxFrame)
    //(*EventTable(projectFrame)
    // EVT_TIMER(TIMER_ID, projectFrame::OnTimer)
    //*)


END_EVENT_TABLE()

projectFrame::projectFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(projectFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer9;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxBoxSizer* BoxSizer12;
    wxMenu* Menu2;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1050,800));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(416,152), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    gridPanel = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(700,800), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    gridPanel->SetMinSize(wxSize(700,800));
    gridPanel->SetMaxSize(wxSize(700,800));
    BoxSizer14->Add(gridPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Planes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    arenaPlanes = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 1, 3, 0, _T("ID_SPINCTRL1"));
    arenaPlanes->SetValue(_T("0"));
    BoxSizer4->Add(arenaPlanes, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Height"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    arenaHeight = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 5, 13, 0, _T("ID_SPINCTRL2"));
    arenaHeight->SetValue(_T("0"));
    BoxSizer5->Add(arenaHeight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Width"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer6->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    arenaWidth = new wxSpinCtrl(Panel1, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 5, 35, 0, _T("ID_SPINCTRL3"));
    arenaWidth->SetValue(_T("0"));
    BoxSizer6->Add(arenaWidth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Obstacles"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer7->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    numOfObstacles = new wxSpinCtrl(Panel1, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL4"));
    numOfObstacles->SetValue(_T("0"));
    BoxSizer7->Add(numOfObstacles, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Gazelles"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer8->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    numOfGazelles = new wxSpinCtrl(Panel1, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL5"));
    numOfGazelles->SetValue(_T("0"));
    BoxSizer8->Add(numOfGazelles, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    Lions = new wxStaticText(Panel1, ID_STATICTEXT6, _("Lions"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer9->Add(Lions, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    numOfLions = new wxSpinCtrl(Panel1, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL6"));
    numOfLions->SetValue(_T("0"));
    BoxSizer9->Add(numOfLions, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    StartButton = new wxButton(Panel1, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(StartButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Gazelle Count:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer11->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    gazStat = new wxStaticText(Panel1, ID_STATICTEXT10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer11->Add(gazStat, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Lion Count:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    BoxSizer12->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lionStat = new wxStaticText(Panel1, ID_STATICTEXT11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer12->Add(lionStat, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT9, _("# of Moves:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer13->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    timeStat = new wxStaticText(Panel1, ID_STATICTEXT12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer13->Add(timeStat, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);


    Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&projectFrame::OnSpinCtrl2Change);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projectFrame::OnStartButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projectFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projectFrame::OnAbout);
    //*)

    gazText = gazStat;
    lionText = lionStat;
    moveText = timeStat;

}

//projectFrame::projectFrame()
//: m_timer(this, TIMER_ID)
//{
//// 1 second interval
//m_timer.Start(1000);
//}



projectFrame::~projectFrame()
{
    //(*Destroy(projectFrame)
    //*)
}


void projectFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void projectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void projectFrame::OnSpinCtrl2Change(wxSpinEvent& event)
{
}

void projectFrame::OnButton3Click(wxCommandEvent& event)
{
}

void projectFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void projectFrame::OnTimer(wxTimerEvent& event)
{
// Do whatever you want to do every second here
    wxMessageBox(wxT("In onTimer"));
}

wxGrid *grid;
wxGrid *gridArray[3];

SafariArena* safari;

void projectFrame::OnStartButtonClick(wxCommandEvent& event)
{
    srand(time(NULL));


    //wxMessageBox(wxT(""))

    safari = new SafariArena(arenaWidth->GetValue(), arenaHeight->GetValue(), arenaPlanes->GetValue());

    numCols = arenaWidth->GetValue();
    numRows = arenaHeight->GetValue();
    numPlanes = arenaPlanes->GetValue();

    numLions = numOfLions->GetValue();
    numGazelles = numOfGazelles->GetValue();
    numObstacles = numOfObstacles->GetValue();

    int totalPlayers = numLions + numGazelles + numObstacles;
    int totalCells = numCols*numRows*numPlanes;

    if(totalPlayers > totalCells){
        wxMessageBox(wxT("There are more players than there are cells"));
        return;
    }
    //get the number of lions, gazelles, and obstacles for the game.
    safari->initCells(numOfLions->GetValue(), numOfGazelles->GetValue(), numOfObstacles->GetValue());

    safari->initialize(gridPanel, ID_PANEL1);



//    gameThread *safariThread = new gameThread();
//    wxMessageBox(wxT("new Thread in heap"));
//    if(safariThread->Create() != wxTHREAD_NO_ERROR){
//        wxMessageBox(wxT("Error creating thread"));
//    }
//    else{
//        wxMessageBox(wxT("Thread properly created"));
//        //safariThread->Run();
//        if ( safariThread->Run() != wxTHREAD_NO_ERROR )
//        {
//            wxMessageBox(wxT("Can't create the thread!"));
//            delete safariThread;
//            safariThread = NULL;
//        }
//    }



    safari->run();

    delete safari;


}

void projectFrame::OnIdle(wxIdleEvent& event)
{
    event.Skip();
}
