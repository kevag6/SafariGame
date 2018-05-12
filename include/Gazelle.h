#ifndef GAZELLE_H
#define GAZELLE_H

#include "Cell.h"
#include "Bridge.h"
#include "wx/grid.h"

extern Cell**** cellArr;
extern wxGrid *gridArray[3];

extern int numGazelles;

class Gazelle: public Cell
{
    public:
        int alreadyProcessed = 0;
        int timeToReproduce;

        void reproduce(Coordinate);

        Gazelle();
        Gazelle(int, int, int);
        Gazelle(int, int, int, int, int);
        virtual ~Gazelle();
        wxString gazelleImage = wxT("G");

        Coordinate getLocation();
        Coordinate getEmptyNeighborCell();
        Coordinate getBridgeNeighborCell();

        wxString getImage();

        Cell *cellEast();
        Cell *cellWest();
        Cell *cellNorth();
        Cell *cellSouth();

        void moveFrom(Coordinate, Coordinate);
        void process();

        int getProcessed();
        void setProcess(int);

    protected:

    private:
        Coordinate gazelleCoord;
};
#endif // GAZELLE_H
