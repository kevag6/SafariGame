#include "Lion.h"


Lion::Lion()
{
    //ctor
}

Lion::~Lion()
{
    //dtor
}

Lion::Lion(int x, int y, int z)
{
//    Coordinate *lionLocation = new Coordinate(x,y,z);
//    lionCoord = *lionLocation;
    lionCoord.setX(x);
    lionCoord.setY(y);
    lionCoord.setZ(z);
    timeToFeed = 7;
    timeToReproduce = 8;
    alreadyProcessed = 0;
}

Lion::Lion(int x, int y, int z, int feedTime, int reproduceTime, int processed)
{
//    Coordinate *lionLocation = new Coordinate(x,y,z);
//    lionCoord = *lionLocation;

    lionCoord.setX(x);
    lionCoord.setY(y);
    lionCoord.setZ(z);

    timeToFeed = feedTime;
    timeToReproduce = reproduceTime;
    //Check if this lion has already been processed.
    alreadyProcessed = processed;
}

wxString Lion::getImage()
{
    return wxT("L");
}

Coordinate Lion::getLocation()
{
    return lionCoord;
}

void Lion::reproduce(Coordinate babyCoord)
{
    delete cellArr[babyCoord.getX()][babyCoord.getY()][babyCoord.getZ()];
    cellArr[babyCoord.getX()][babyCoord.getY()][babyCoord.getZ()] = NULL;

    cellArr[babyCoord.getX()][babyCoord.getY()][babyCoord.getZ()] = new Lion(babyCoord.getX(),babyCoord.getY(),babyCoord.getZ(),7, 8, 1);//*cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()];



    //gridArray[babyCoord.getZ()]->SetCellValue(babyCoord.getX(), babyCoord.getY(), cellArr[babyCoord.getX()][babyCoord.getY()][babyCoord.getZ()]->getImage());

    return;
}

Coordinate Lion::getBridgeNeighborCell()
{
    Coordinate newCoord = this->getLocation();
    if(this->cellEast() != NULL && this->cellEast()->getImage().IsSameAs(wxT("B")) ) {
        newCoord.setY(newCoord.getY() + 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO EAST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellWest() != NULL && this->cellWest()->getImage().IsSameAs(wxT("B"))) {
        newCoord.setY(newCoord.getY() - 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO WEST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellNorth() != NULL && this->cellNorth()->getImage().IsSameAs(wxT("B"))) {
        newCoord.setX(newCoord.getX() - 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellSouth() != NULL && this->cellSouth()->getImage().IsSameAs(wxT("B"))) {
        newCoord.setX(newCoord.getX() + 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    //wxMessageBox(wxT("In getPreyNeighbor No prey was found returning original coordinate location of lion"));
    return newCoord;
}

Coordinate Lion::getPreyNeighborCell()
{
    //srand(time(NULL));
    Coordinate newCoord = this->getLocation();
    if(this->cellEast() != NULL && this->cellEast()->getImage().IsSameAs(wxT("G")) ) {
        newCoord.setY(newCoord.getY() + 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO EAST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellWest() != NULL && this->cellWest()->getImage().IsSameAs(wxT("G"))) {
        newCoord.setY(newCoord.getY() - 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO WEST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellNorth() != NULL && this->cellNorth()->getImage().IsSameAs(wxT("G"))) {
        newCoord.setX(newCoord.getX() - 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    if(this->cellSouth() != NULL && this->cellSouth()->getImage().IsSameAs(wxT("G"))) {
        newCoord.setX(newCoord.getX() + 1);
        wxString temp;
        temp.Printf(wxT("FOUND PREY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
        //wxMessageBox(temp);
        //done = true;
        return newCoord;
    }
    //wxMessageBox(wxT("In getPreyNeighbor No prey was found returning original coordinate location of lion"));
    return newCoord;
}

Coordinate Lion::getEmptyNeighborCell()
{



    Coordinate newCoord = this->getLocation();
    //wxMessageBox(wxT("set newCoord to THIS Coordinate"));
    bool done = false;
    int vE = 0, vW = 0, vS = 0, vN = 0;
    wxString temp;
    while(done == false || !(vE && vW && vS && vN)) {
        temp.Printf(wxT("In while vE %d vW %d vN %d vS %d !vW %d"), vE, vW, vS, vN, !vW);
        //wxMessageBox(temp);
        if((vE && vW && vS && vN)){
            done = true;
        }
        switch((rand() % 4) + 1) {
        case 1:
            vE++;
            if(this->cellEast() != NULL && this->cellEast()->getImage().IsSameAs(wxT(" "))) {
                newCoord.setY(newCoord.getY() + 1);
                wxString temp;
                temp.Printf(wxT("FOUND EMPTY CELL TO EAST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
                //wxMessageBox(temp);
                done = true;

                return newCoord;
            }
            break;
        case 2:
            vW++;
            if(this->cellWest() != NULL && this->cellWest()->getImage().IsSameAs(wxT(" "))) {
                newCoord.setY(newCoord.getY() - 1);
                wxString temp;
                temp.Printf(wxT("FOUND EMPTY CELL TO WEST coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
                //wxMessageBox(temp);
                done = true;

                return newCoord;
            }
            break;
        case 3:
            vN++;
            if(this->cellNorth() != NULL && this->cellNorth()->getImage().IsSameAs(wxT(" "))) {
                newCoord.setX(newCoord.getX() - 1);
                wxString temp;
                temp.Printf(wxT("FOUND EMPTY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
                //wxMessageBox(temp);
                done = true;

                return newCoord;
            }
            break;
        case 4:
            vS++;
            if(this->cellSouth() != NULL && this->cellSouth()->getImage().IsSameAs(wxT(" "))) {
                newCoord.setX(newCoord.getX() + 1);
                wxString temp;
                temp.Printf(wxT("FOUND EMPTY CELL TO NORTH coordinate is %d, %d, %d"), newCoord.getX(), newCoord.getY(), newCoord.getZ());
                //wxMessageBox(temp);
                done = true;

                return newCoord;
            }
            break;
        }

    }
    //If lion couldn't find an empty neighbor cell return it's own coordinate of where lion is located.
    //sleep(1);
    //wxMessageBox(wxT("Sending same coord"));
    return newCoord;
}

Cell* Lion::cellEast()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getY() == numCols - 1){
        return NULL;

    }

    return cellArr[thisCoord.getX()][thisCoord.getY() + 1][thisCoord.getZ()];
}

Cell* Lion::cellWest()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getY() == 0){
        return NULL;
    }

    return cellArr[thisCoord.getX()][thisCoord.getY() - 1][thisCoord.getZ()];
}

Cell* Lion::cellSouth()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getX() == numRows - 1){
        return NULL;
    }

    return cellArr[thisCoord.getX() + 1][thisCoord.getY()][thisCoord.getZ()];
}

Cell* Lion::cellNorth()
{
    Coordinate thisCoord = this->getLocation();

    if(thisCoord.getX() == 0){
        return NULL;
    }

    return cellArr[thisCoord.getX() - 1][thisCoord.getY()][thisCoord.getZ()];
}

void Lion::process()
{
    Coordinate emptyCoord;
    Coordinate bridgeCoord;

    --this->timeToReproduce;
    --this->timeToFeed;


    if(this->timeToFeed == 0){

        --numLions;

        Coordinate deletedLion = this->getLocation();

        delete cellArr[deletedLion.getX()][deletedLion.getY()][deletedLion.getZ()];
        cellArr[deletedLion.getX()][deletedLion.getY()][deletedLion.getZ()] = NULL;


        cellArr[deletedLion.getX()][deletedLion.getY()][deletedLion.getZ()] = new Cell(deletedLion.getX(), deletedLion.getY(), deletedLion.getZ());

        //gridArray[deletedLion.getZ()]->SetCellValue(deletedLion.getX(), deletedLion.getY(), cellArr[deletedLion.getX()][deletedLion.getY()][deletedLion.getZ()]->getImage());

        return;

    }
    if(this->timeToReproduce == 0){
        emptyCoord = getEmptyNeighborCell();
        this->timeToReproduce = 8;
        if(!(this->getLocation().getX() == emptyCoord.getX() && this->getLocation().getY() == emptyCoord.getY() && this->getLocation().getZ() == emptyCoord.getZ())){
            this->reproduce(emptyCoord);
            ++numLions;
        }
        //wxMessageBox(wxT("No empty neighbor found no reproduction"));
        //return;

    }
    Coordinate preyCoord = this->getPreyNeighborCell();
    if(!(this->getLocation().getX() == preyCoord.getX() && this->getLocation().getY() == preyCoord.getY() && this->getLocation().getZ() == preyCoord.getZ())){
        --numGazelles;

        this->timeToFeed = 7;
        moveFrom(this->getLocation(), preyCoord);
        return;

    }


    bool done = false;
    int vB = 0, vE = 0;

    while(done == false || !(vB && vE)){

        if((vB && vE)){
            done = true;
        }
        switch((rand() % 2) + 1) {
        case 1:
            vB++;
            bridgeCoord = this->getBridgeNeighborCell();
            if(!(this->getLocation().getX() == bridgeCoord.getX() && this->getLocation().getY() == bridgeCoord.getY() && this->getLocation().getZ() == bridgeCoord.getZ())){
                Coordinate toCoord = cellArr[bridgeCoord.getX()][bridgeCoord.getY()][bridgeCoord.getZ()]->getNeighborBridgeCoord();

                if(cellArr[toCoord.getX()][toCoord.getY()][toCoord.getZ()]->getImage().IsSameAs(wxT(" "))){
                    moveFrom(this->getLocation(), toCoord);
                    done = true;
                    return;
                }

            }
            break;
        case 2:
            vE++;
            emptyCoord = getEmptyNeighborCell();

            if(!(this->getLocation().getX() == emptyCoord.getX() && this->getLocation().getY() == emptyCoord.getY() && this->getLocation().getZ() == emptyCoord.getZ())){
                //wxMessageBox(wxT("Empty cord found moving to this empty cell"));
                moveFrom(this->getLocation(), emptyCoord);
                done = true;
                return;

            }

            break;

        }

    }
    //wxMessageBox(wxT("Did not break in process."));
//    temp.Printf(wxT("oldCoord X %d Y %d Z %d"), this->getLocation().getX(), this->getLocation().getY(),this->getLocation().getZ());
//    wxMessageBox(temp);
    //moveFrom(this->getLocation(), this->getLocation());
    return;
}

void Lion::moveFrom(Coordinate fromCoord, Coordinate toCoord)
{
    wxString temp;
    temp.Printf(wxT("in moveFrom fromCoord is X %d Y %d Z %d\n toCoord is X %d Y %d Z %d"),
                fromCoord.getX(), fromCoord.getY(),fromCoord.getZ(),
                toCoord.getX(),toCoord.getY(),toCoord.getZ());
    //wxMessageBox(temp);

    //wxMessageBox( cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()]->getImage());

    if(!(toCoord.getX() == fromCoord.getX() && toCoord.getY() == fromCoord.getY() && toCoord.getZ() == fromCoord.getZ())){

        delete cellArr[toCoord.getX()][toCoord.getY()][toCoord.getZ()];
        cellArr[toCoord.getX()][toCoord.getY()][toCoord.getZ()] = NULL;

        cellArr[toCoord.getX()][toCoord.getY()][toCoord.getZ()] = new Lion(toCoord.getX(),toCoord.getY(),toCoord.getZ(), timeToFeed, timeToReproduce, 1);//*cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()];


        delete cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()];
        cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()] = NULL;

        cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()] = new Cell(fromCoord.getX(), fromCoord.getY(), fromCoord.getZ());

        //wxMessageBox( cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()]->getImage());

        //gridArray[toCoord.getZ()]->SetCellValue(toCoord.getX(), toCoord.getY(), cellArr[toCoord.getX()][toCoord.getY()][toCoord.getZ()]->getImage());
        //gridArray[fromCoord.getZ()]->SetCellValue(fromCoord.getX(), fromCoord.getY(), cellArr[fromCoord.getX()][fromCoord.getY()][fromCoord.getZ()]->getImage());
    }

    return;
}

int Lion::getProcessed()
{
    return alreadyProcessed;
}

void Lion::setProcess(int setProcess)
{
    alreadyProcessed = setProcess;
}

