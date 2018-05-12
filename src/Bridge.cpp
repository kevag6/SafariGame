#include "Bridge.h"

Bridge::Bridge()
{
    //ctor
}


Bridge::Bridge(int x, int y, int z)
{
    alreadyProcessed = 1;

    Coordinate *bridgeLocation = new Coordinate(x,y,z);
    bridgeCoord = *bridgeLocation;
    if(bridgeCoord.getZ() == 0){
        neighborBridgeCoord.setX(1);
        neighborBridgeCoord.setY(numCols - 1);
        neighborBridgeCoord.setZ(1);
    }
    if(bridgeCoord.getZ() == 1){
        if(bridgeCoord.getX() == 0){
            neighborBridgeCoord.setX(numRows - 2);
            neighborBridgeCoord.setY(numCols - 1);
            neighborBridgeCoord.setZ(0);
        }
        else{
            neighborBridgeCoord.setX(1);
            neighborBridgeCoord.setY(numCols - 1);
            neighborBridgeCoord.setZ(2);
        }
    }
    if(bridgeCoord.getZ() == 2){
        neighborBridgeCoord.setX(numRows - 2);
        neighborBridgeCoord.setY(numCols - 1);
        neighborBridgeCoord.setZ(1);
    }
}



Bridge::~Bridge()
{
    //dtor
}

Coordinate Bridge::getNeighborBridgeCoord()
{
    return neighborBridgeCoord;
}

wxString Bridge::getImage()
{
    return brigeImage;
}

Coordinate Bridge::getLocation()
{
    return bridgeCoord;
}

void Bridge::process()
{
    return;
}
