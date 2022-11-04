#ifndef RESIDENTIALZONE_H
#define RESIDENTIALZONE_H

#include "zonenode.h"

class residentialzone : public zonenode {
    private:
        static int availableWorkers;
    public:
        //Constructor
        residentialzone();

        //Mutator
        void increasePopulation();

        static void decreaseAvailableWorkers(int n);

        //Accessor
        static int getAvailableWorkers();
};

#endif