#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

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
};

#endif