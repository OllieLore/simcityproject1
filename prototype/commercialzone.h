#ifndef COMMERCIALZONE_H
#define COMMERCIALZONE_H

#include "zonenode.h"

class commercialzone : public zonenode {
    private:
    public:
        //Constructur
        commercialzone();

        //Mutator
        void increasePopulation();
};

#endif