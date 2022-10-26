#include <string>

#include "zonenode.h"

// Constructor
zonenode::zonenode(){
    x = 0;
    y = 0;
    type = '-';

}
/*
zonenode::zonenode(zonenode *n, zonenode *s, zonenode *w, zonenode *e, zonenode *nw, zonenode *ne, zonenode *sw, zonenode *se, char t, int i)
{
    north = n;
    south = s;
    west = w;
    east = e;
    nwest = nw;
    neast = ne;
    swest = sw;
    seast = se;

    type = t;

    population = 0;
    pollution = 0;

    id = i;
}
*/

/*
    Set neighbor function, int l is the number equivalent of neighbor location
    0 - north
    1 - south
    2 - west
    3 - east
    4 - north west
    5 - north east
    6 - south west
    7 - south east
*/
/*
void zonenode::setNeighbor(int l, zonenode *n)
{
    switch (l)
    {
    case 0:
        north = n;
        break;
    case 1:
        south = n;
        break;
    case 2:
        west = n;
        break;
    case 3:
        east = n;
        break;
    case 4:
        nwest = n;
        break;
    case 5:
        neast = n;
        break;
    case 6:
        swest = n;
        break;
    case 7:
        seast = n;
        break;
    default:
        break;
    }
}
*/
// Set zone type function
void zonenode::setType(char t)
{
    type = t;
}

// Get zone type function
char zonenode::getType()
{
    return type;
}

// Set population function
/*
void zonenode::setPopulation(int p)
{
    population = p;
}

// Set pollution function
void zonenode::setPollution(int p)
{
    pollution = p;
}

// Set id function
void zonenode::setID(int i)
{
    id = i;
}

// Get neighbor function
zonenode *zonenode::getNeighbor(int l)
{
    switch (l)
    {
    case 0:
        return north;
    case 1:
        return south;
    case 2:
        return west;
    case 3:
        return east;
    case 4:
        return nwest;
    case 5:
        return neast;
    case 6:
        return swest;
    case 7:
        return seast;
    default:
        return nullptr;
        break;
    }

    return nullptr;
}



// Get population function
int zonenode::getPopulation()
{
    return population;
}

// Get pollution function
int zonenode::getPollution()
{
    return pollution;
}

// Get id function
int zonenode::getID()
{
    return id;
}

// toString function
std::string zonenode::toString()
{
    return this->getID() + "\t" + this->getType();
}
*/
void zonenode::SetXCoordinate(int x){
    this->x = x;
}

int zonenode::GetXCoordinate(){
    return x;
}

void zonenode::SetYCoordinate(int y){
    this->y = y;
}

int zonenode::GetYCoordinate(){
    return y;
}

