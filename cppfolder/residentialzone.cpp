#include "residentialzone.h"
#include "zonenode.h"

//Constructor
residentialzone::residentialzone()
{
    int population; // Keeps track of the population in a cell
    int Neighbors; // Keeps track of population size of the cell's neighbors
    bool IsNearPowerline, PopulationisGreater; // Determines if the conditions are met to increase the population size
};

int residentialzone::getPopulationSize(int population)
{
    return population;
};

int residentialzone::IncreasePopulationSize(int population, int Neighbors, bool IsNearPowerline, bool PopulationisGreater)
{
    if(IsNearPowerline == true && PopulationisGreater == true)
    {
        population+1;
    }
};
