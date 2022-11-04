#include "commercialzone.h"
#include "zonenode.h"
#include <iostream>

//Constructor
commercialzone::commercialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'C', 0) 
{
    futurePop = 0;
}

int commercialzone::GetFuturePop()
{
    return futurePop;
}

void commercialzone::SetFuturePop(int futurePopI)
{
    futurePop = futurePopI;
}

//checks if enough neighbors have the required population
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

//main function for commercial timestep.
void commercialzone::ComercialTimeStep(int &availableWorker, int availableGood)
{
    switch(population)
    {
    case 0: //when pop is 0
        if (isPowered && availableWorker >= 1 && availableGood  >= 1)
        {
            futurePop = 1;
            availableWorker--;
            availableGood--;

        }
        else if (NeighborPopulationCheck(1, 1) && availableWorker >= 1 && availableGood  >= 1)
        {
            futurePop = 1;
            availableWorker--;
            availableGood--;
        }
        break;

    case 1: //when pop is 1
        if (NeighborPopulationCheck(1, 2) && availableWorker >= 1 && availableGood  >= 1)
        {
            futurePop = 2;
            availableWorker--;
            availableGood--;
        }
        break;
    }
}

//updates population
void commercialzone::UpdatePop()
{
    population = GetFuturePop();
}