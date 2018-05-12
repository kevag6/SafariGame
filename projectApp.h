/***************************************************************
 * Name:      projectApp.h
 * Purpose:   Defines Application Class
 * Author:    Kevin Grifo ()
 * Created:   2018-03-29
 * Copyright: Kevin Grifo ()
 * License:
 **************************************************************/

#ifndef PROJECTAPP_H
#define PROJECTAPP_H

#include <wx/app.h>

class projectApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // PROJECTAPP_H
