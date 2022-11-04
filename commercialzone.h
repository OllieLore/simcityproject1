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

        // What to do when a time step is called
        void ComercialTimeStep(int &availableWorker, int availableGood);

        //updates population with futurePop
        void UpdatePop();
};

#endif