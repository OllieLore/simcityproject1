#ifndef ZONENODE_H
#define ZONENODE_H

#include <string>

class zonenode
{
protected:
    // Zone type
    char type;

    // Misc. values
    int population, pollution, id /*id is 00x00y*/;

    // Stores powere status of node
    bool isPowered;

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
    zonenode(zonenode *n, zonenode *s, zonenode *w, zonenode *e, zonenode *nw, zonenode *ne, zonenode *sw, zonenode *se, char t, int i);

    zonenode();

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
    void setNeighbor(int l, zonenode *n);

    // Set zone type function
    void setType(char t);

    // Set population function
    void setPopulation(int p);

    // Set pollution function
    void setPollution(int p);

    // Set id function
    void setID(int i);
    // Get neighbor function
    zonenode *getNeighbor(int l);

    // Get zone type function
    char getType();

    // Get population function
    int getPopulation();

    // Get pollution function
    int getPollution();

    // Get id function
    int getID();

    // Get isPowered function
    bool GetIsPowered();

    // Set isPowered function
    void SetIsPowered(bool powerI);

    // Checks if there is a neighbor that provides power
    void CheckForPower();

    // toString function
    std::string toString();


    //--------------------Comercial Zone Testing--------------------------

    // Checks neighbor poulation to see if they meet requirements
    bool NeighborPopulationCheck(int popMin, int neighborAmount);

    // What to do when a time step is called
    void ComercialTimeStep();
};

#endif