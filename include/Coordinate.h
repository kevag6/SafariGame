#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
    public:
        Coordinate(int, int, int);
        Coordinate();
        void printCoordinate(Coordinate);

        int getX();
        void setX(int);

        int getY();
        void setY(int);

        int getZ();
        void setZ(int);

        virtual ~Coordinate();

    protected:

    private:
        int x, y, z;
};

#endif // COORDINATE_H
