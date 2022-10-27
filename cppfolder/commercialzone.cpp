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
        if (getNeighbor(i).getType == 'T')
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
            else if (/*&& availableWorker && availableGood*/)
            {

            }
            break;

        case 1:

            break;

        
    }
}