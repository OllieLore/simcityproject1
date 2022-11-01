#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

#include "zonenode.h"

class commercialzone : public zonenode {
    public:
        // Constructor
        commercialzone();

        // Checks neighbor poulation to see if they meet requirements
        bool NeighborPopulationCheck(int popMin, int neighborAmount);

        // What to do when a time step is called
        void ComercialTimeStep();
};

#endif