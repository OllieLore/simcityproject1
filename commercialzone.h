#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

class commercialzone : public zonenode {
    private:
        bool isPowered;
    public:
        commercialzone();
        GetIsPowered();
        SetIsPowered(bool powerI);
        CheckForPower();
        ComercialTimeStep();
};

#endif