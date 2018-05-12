#include "Cell.h"


Cell::Cell()
{

}

Cell::Cell(Coordinate aCoord)
{
    //ctor
    cellCoordinate = aCoord;

}

Cell::Cell(int xCoord, int yCoord, int zCoord)
{
//    Coordinate *cellCoord = new Coordinate(xCoord,yCoord,zCoord);
//    cellCoordinate = *cellCoord;

    cellCoordinate.setX(xCoord);
    cellCoordinate.setY(yCoord);
    cellCoordinate.setZ(zCoord);
}

Cell::~Cell()
{
    //dtor
}

void Cell::setLocation(Coordinate newCoord)
{
    this->cellCoordinate = newCoord;
}

Coordinate Cell::getLocation()
{
    return cellCoordinate;
}



wxString Cell::getImage()
{
    return cellImage;
}

Coordinate Cell::getNeighborBridgeCoord()
{
    return this->getLocation();
}

Coordinate Cell::getPreyNeighborCell()
{
    return this->getLocation();
}

Coordinate Cell::getEmptyNeighborCell()
{
    Coordinate newCoord = this->getLocation();

    return newCoord;
}

Cell* Cell::cellEast()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getY() == numCols - 1){
        return NULL;

    }

    return cellArr[thisCoord.getX()][thisCoord.getY() + 1][thisCoord.getZ()];
}

Cell* Cell::cellWest()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getY() == 0){
        return NULL; //cellArr[thisCoord.getX()][thisCoord.getY()][thisCoord.getZ()];
    }

    return cellArr[thisCoord.getX()][thisCoord.getY() - 1][thisCoord.getZ()];
}

Cell* Cell::cellSouth()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getX() == numRows - 1){
        return NULL; //cellArr[thisCoord.getX()][thisCoord.getY()][thisCoord.getZ()];
    }

    return cellArr[thisCoord.getX() + 1][thisCoord.getY()][thisCoord.getZ()];
}

Cell* Cell::cellNorth()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getX() == 0){
        return NULL;
    }

    return cellArr[thisCoord.getX() - 1][thisCoord.getY()][thisCoord.getZ()];
}

void Cell::moveFrom(Coordinate fromCoord, Coordinate toCoord){return;}

void Cell::process()
{
    //wxMessageBox(wxT("In Cell Process"));
    return;
}

int Cell::getProcessed()
{
    return alreadyProcessed;
}

void Cell::setProcess(int setProcess)
{
    alreadyProcessed = setProcess;
}
