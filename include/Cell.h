#ifndef CELL_H
#define CELL_H

#include "Coordinate.h"
//#include "SafariArena.h"

extern int numPlanes;
extern int numRows;
extern int numCols;
extern int ***check;

class Cell
{
    public:
        int alreadyProcessed = 0;
        Cell();
        Cell(Coordinate);
        Cell(int, int, int);
        virtual ~Cell();


        virtual Coordinate getLocation();
        virtual Coordinate getEmptyNeighborCell();
        virtual Coordinate getPreyNeighborCell();
        virtual Coordinate getNeighborBridgeCoord();
        void setLocation(Coordinate);

        virtual Cell *cellEast();
        virtual Cell *cellWest();
        virtual Cell *cellNorth();
        virtual Cell *cellSouth();

        virtual void moveFrom(Coordinate, Coordinate);
        virtual void process();

        virtual wxString getImage();

        virtual int getProcessed();
        virtual void setProcess(int);

        wxString cellImage = wxT(" ");



    protected:

    private:
        Coordinate cellCoordinate;
        int x, y, z;
};

extern Cell**** cellArr;


#endif // CELL_H
