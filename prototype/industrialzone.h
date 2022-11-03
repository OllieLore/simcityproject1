#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

#include "zonenode.h"

class industrialzone : public zonenode {
    private:
        static int availableGoods;
    public:
        //Constructor
        industrialzone();

        //Mutator
        void increasePopulation();

        static void decreaseAvailableGoods(int n);

        //Accessor
        static int getAvailableGoods();
};

#endif