#ifndef BRIDGE_H
#define BRIDGE_H

#include "Cell.h"


class Bridge : public Cell
{
    public:
        int alreadyProcessed;

        Bridge();
        virtual ~Bridge();

        wxString getImage();

        Bridge(int, int, int);

        wxString brigeImage = wxT("B");

        void process();

        Coordinate getLocation();

        Coordinate getNeighborBridgeCoord();

        Coordinate neighborBridgeCoord;

    protected:

    private:
        Coordinate bridgeCoord;

};

#endif // BRIDGE_H
