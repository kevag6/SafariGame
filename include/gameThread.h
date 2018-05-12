#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <wx/thread.h>
#include "SafariArena.h"
#include "../projectMain.h"

extern SafariArena* safari;


class gameThread : public wxThread
{
    public:
        gameThread();
        virtual ~gameThread();
        virtual void *Entry();

    protected:

    private:
};

#endif // GAMETHREAD_H
