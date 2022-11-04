#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

#include "zonenode.h"

class commercialzone : public zonenode {
    private:
        int futurePop;
    public:
        // Constructor
        commercialzone();

        //getters and setters
        int GetFuturePop();

        void SetFuturePop(int futurePopI);

        // Checks neighbor poulation to see if they meet requirements
        bool NeighborPopulationCheck(int popMin, int neighborAmount);
        void ComercialTimeStep();

        void increasePopulation();
};

#endif