#include "commercialzone.h"
#include "zonenode.h"
#include <iostream>

//Constructor
commercialzone::commercialzone() {}

bool commercialzone::NeighborPopulationCheck(int popMin, int neighborAmount)
{
    int qualified = 0;
    for (int i = 0; i < 8; i++)
    {
        switch (id)
        {
        default:
            break;
        }
        if (getNeighbor(i)->getPopulation() <= popMin)
        {
            qualified++;
        }
    }

    if (qualified >= neighborAmount)
        return true;
    else
        return false;
}

void commercialzone::ComercialTimeStep()
{
    switch(population)
    {
    case 0:
        if (isPowered /*&& availableWorker && availableGood*/)
        {
            population = 1;
        }
        else if (NeighborPopulationCheck(1, 1)/*&& availableWorker && availableGood*/)
        {
            population = 1;
        }
        break;

    case 1:
        if (NeighborPopulationCheck(1, 2)/*&& availableWorker && availableGood*/)
        {
            population = 2;
        }
        break;
    }
}
commercialzone.cpp
Displaying zonenode.h.