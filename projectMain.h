/***************************************************************
 * Name:      projectMain.h
 * Purpose:   Defines Application Frame
 * Author:    Kevin Grifo ()
 * Created:   2018-03-29
 * Copyright: Kevin Grifo ()
 * License:
 **************************************************************/

#ifndef PROJECTMAIN_H
#define PROJECTMAIN_H

#include "Cell.h"
#include "wx/timer.h"

#define TIMER_ID 1000


//(*Headers(projectFrame)
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)




class projectFrame: public wxFrame
{
    public:

        void OnIdle(wxIdleEvent& event);

        projectFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~projectFrame();



        void OnTimer(wxTimerEvent& event);


        wxStaticText* lionStat;
        wxStaticText* timeStat;
        wxStaticText* gazStat;


    private:
        wxTimer m_timer;



        //(*Handlers(projectFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSpinCtrl2Change(wxSpinEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);

        //*)

        //(*Identifiers(projectFrame)
        static const long ID_PANEL2;
        static const long ID_STATICTEXT1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_SPINCTRL4;
        static const long ID_STATICTEXT5;
        static const long ID_SPINCTRL5;
        static const long ID_STATICTEXT6;
        static const long ID_SPINCTRL6;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT12;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //Declarations(projectFrame)

        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxSpinCtrl* arenaHeight;
        wxSpinCtrl* numOfLions;
        wxButton* Button2;
        wxSpinCtrl* numOfObstacles;
        wxStaticText* StaticText1;
        wxButton* StartButton;
        wxStaticText* StaticText3;
        wxSpinCtrl* numOfGazelles;

        wxStaticText* StaticText8;
        wxSpinCtrl* arenaWidth;
        wxStaticText* StaticText7;
        wxPanel* gridPanel;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;

        wxStaticText* StaticText6;
        wxSpinCtrl* arenaPlanes;
        wxStaticText* Lions;
        wxButton* Reset;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJECTMAIN_H
