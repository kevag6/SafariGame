/***************************************************************
 * Name:      projectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Kevin Grifo ()
 * Created:   2018-03-29
 * Copyright: Kevin Grifo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "projectApp.h"

//(*AppHeaders
#include "projectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(projectApp);

bool projectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	projectFrame* Frame = new projectFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    wxMessageBox(wxT("Select Number of Lions, Gazelles, and Obstacles by using the appropriate spin control. Also select how large the playing field will be and then press start to begin the simulation. Have Fun!"));
    return wxsOK;

}
