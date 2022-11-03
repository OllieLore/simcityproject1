#include "commercialzone.h"
#include "zonenode.h"
#include <iostream>

//Constructor
commercialzone::commercialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'C', 0) {}

bool commercialzone::NeighborPopulationCheck(int popMin, int neighborAmount)
{
    int qualified = 0;
    for (int i = 0; i < 8; i++)
    {
        if (getNeighbor(i) != nullptr)
        {
            if (getNeighbor(i)->getPopulation() >= popMin)
            {
                qualified++;
            }
        }
    }

    if (qualified >= neighborAmount)
        return true;
    else
        return false;
}

void commercialzone::ComercialTimeStep(int availableWorker, int availableGood)
{
    switch(population)
    {
    case 0:
        if (isPowered && availableWorker >= 1 && availableGood  >= 1)
        {
            population = 1;
        }
        else if (NeighborPopulationCheck(1, 1) && availableWorker >= 1 && availableGood  >= 1)
        {
            population = 1;
        }
        break;

    case 1:
        if (NeighborPopulationCheck(1, 2) && availableWorker >= 1 && availableGood  >= 1)
        {
            population = 2;
        }
        break;
    }
}