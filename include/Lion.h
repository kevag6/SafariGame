#ifndef LION_H
#define LION_H

#include "Cell.h"
#include "Bridge.h"
#include "wx/grid.h"


extern Cell**** cellArr;
extern wxGrid *gridArray[3];

extern int numLions;
extern int numGazelles;

class Lion: public Cell
{
    public:
        int timeToFeed;
        int timeToReproduce;
        int alreadyProcessed = 0;

        Lion();
        Lion(int, int, int);
        Lion(int, int, int, int, int, int);
        virtual ~Lion();

        wxString getImage();

        Coordinate getLocation();

        void reproduce(Coordinate);

        wxString lionImage = wxT("L");

        Coordinate getEmptyNeighborCell();
        Coordinate getPreyNeighborCell();
        Coordinate getBridgeNeighborCell();

        Cell *cellEast();
        Cell *cellWest();
        Cell *cellNorth();
        Cell *cellSouth();

        int getProcessed();
        void setProcess(int);


        void moveFrom(Coordinate, Coordinate);
        void process();

    protected:

    private:
        Coordinate lionCoord;
};

#endif // LION_H
