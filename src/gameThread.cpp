#include "gameThread.h"

gameThread::gameThread()
{
    //ctor
}

gameThread::~gameThread()
{
    //dtor
}

void *gameThread::Entry()
{
    wxMessageBox(wxT("In entry of gameThread"));
    safari->run();

    delete safari;
    return NULL;
}
