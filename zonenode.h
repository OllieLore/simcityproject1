#ifndef ZONENODE_H
#define ZONENODE_H

#include <string>

class zonenode
{
private:
    // Zone type
    char type;

    // Misc. values
    int population, pollution, id /*id is 00x00y*/;

    // Neighbors
    zonenode *north;
    zonenode *south;
    zonenode *west;
    zonenode *east;
    zonenode *nwest;
    zonenode *neast;
    zonenode *swest;
    zonenode *seast;

public:
    // Constructor
    zonenode(zonenode *n, zonenode *s, zonenode *w, zonenode *e, zonenode *nw, zonenode *ne, zonenode *sw, zonenode *se, char t, int i) {}

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
    void setNeighbor(int l, zonenode *n) {}

    // Set zone type function
    void setType(char t) {}

    // Set population function
    void setPopulation(int p) {}

    // Set pollution function
    void setPollution(int p) {}

    // Set id function
    void setID(int i) {}

    // Get neighbor function
    zonenode *getNeighbor(int l) {}

    // Get zone type function
    char getType() {}

    // Get population function
    int getPopulation() {}

    // Get pollution function
    int getPollution() {}

    // Get id function
    int getID() {}

    // toString function
    std::string toString() {}
};

#endif