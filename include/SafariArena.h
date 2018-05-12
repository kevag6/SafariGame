#ifndef SAFARIARENA_H
#define SAFARIARENA_H

#include <wx/grid.h>
#include "Cell.h"
#include "Lion.h"
#include "Gazelle.h"
#include "Obstacles.h"
#include "Bridge.h"
#include <wx/stattext.h>
#include "wx/timer.h"

//extern wxWindow gridPanel;
//extern wxWindowID ID_PANEL1;
extern wxGrid *gridArray[3];
extern Cell ****cellArr;
extern int ***check;

extern int numLions;
extern int numGazelles;
extern int numObstacles;


extern wxStaticText* gazText;
extern wxStaticText* lionText;
extern wxStaticText* moveText;

class SafariArena
{
    public:
        SafariArena();
        SafariArena(int, int, int);
        virtual ~SafariArena();

        void initialize(wxWindow*, wxWindowID);
        //Cell ****cellArr;
        void initCells(int, int, int);

        void displayCells();
        void displayStats();

        void setLions(int lions);
        void setGazelles(int gazelles);
        void setObstacles(int obstacles);

        int getLions();
        int getGazelles();
        int getObstacles();
        int getArenaSize();

        void run();


    protected:

    private:
        int  numRows, numCols, numPlanes, numL, numG, numObstacles, arenaSize;
        //bool ***check;
};

#endif // SAFARIARENA_H
