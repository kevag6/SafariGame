#include "Obstacles.h"


Obstacles::Obstacles(){
    //ctor
}

Obstacles::~Obstacles()
{
    //dtor
}

Obstacles::Obstacles(int x, int y, int z) {
    Coordinate obstacles(x, y, z);
    obstacleCoord = obstacles;
}

wxString Obstacles::getImage()
{
    return obstacleImage;
}

void Obstacles::process()
{
    return;
}

void Obstacles::moveFrom(Coordinate fromCoord, Coordinate toCoord)
{
    return;
}
