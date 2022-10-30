#include "commercialzone.h"
#include "zonenode.h"

//Constructor
commercialzone::commercialzone() {}

bool commercialzone::GetIsPowered()
{
    return isPowered;
}

void commercialzone::SetIsPowered(bool powerI)
{
    isPowered = powerI;
}

void commercialzone::CheckForPower()
{
    for (int i = 0; i < 8; i++)
    {
        if (getNeighbor(i).getType == 'T' /*|| getNeighbor(i).getIsPowered()*/)
        {
            SetIsPowered(true);
        }
    }
}

bool commercialzone::NeighborPopulationCheck(int popMin, int neighborAmount)
{
    int qualified = 0;
    for (int i = 0; i < 8; i++)
    {
        if (getNeighbor(i).getPopulation <= popMin)
        {
            qualified++;
        }
    }

    if (qualified >= neighborAmount)
        return true;
    else
        return false;
}

commercialzone::ComercialTimeStep()
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