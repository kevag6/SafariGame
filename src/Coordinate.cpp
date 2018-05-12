#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, int z)
{
    //ctor
    this->x = x;
    this->y = y;
    this->z = z;

}

Coordinate::Coordinate(){}

Coordinate::~Coordinate()
{
    //dtor
}

int Coordinate::getX()
{
    return this->x;
}

void Coordinate::setX(int x)
{
    this->x = x;
}

int Coordinate::getY()
{
    return this->y;
}

void Coordinate::setY(int y)
{
    this->y = y;
}

int Coordinate::getZ()
{
    return z;
}

void Coordinate::setZ(int z)
{
    this->z = z;
}

void Coordinate::printCoordinate(Coordinate printCoord)
{

}
