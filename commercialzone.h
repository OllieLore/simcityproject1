#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

#include "zonenode.h"

class commercialzone : public zonenode {
    private:
        bool isPowered;
    public:
        commercialzone();
        bool GetIsPowered();
        void SetIsPowered(bool powerI);
        void CheckForPower();
        bool NeighborPopulationCheck(int popMin, int neighborAmount);
        void ComercialTimeStep();

        void increasePopulation();
};

#endif