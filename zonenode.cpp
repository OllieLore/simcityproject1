#include <string>

#include "zonenode.h"

// Constructor
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

zonenode::zonenode()
{

}

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

// Set zone type function
void zonenode::setType(char t)
{
    type = t;
}

// Set population function
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
        break;
    case 1:
        return south;
        break;
    case 2:
        return west;
        break;
    case 3:
        return east;
        break;
    case 4:
        return nwest;
        break;
    case 5:
        return neast;
        break;
    case 6:
        return swest;
        break;
    case 7:
        return seast;
        break;
    default:
        return NULL;
        break;
    }
    return NULL;

}

// Get zone type function
char zonenode::getType()
{
    return type;
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