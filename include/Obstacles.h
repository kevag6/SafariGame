#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "Cell.h"

class Obstacles: public Cell
{
    public:
        Obstacles();
        Obstacles(int, int, int);
        virtual ~Obstacles();
        wxString obstacleImage = wxT("O");

        wxString getImage();

        void process();
        void moveFrom(Coordinate, Coordinate);

    protected:

    private:

        Coordinate obstacleCoord;
};

#endif // OBSTACLES_H
