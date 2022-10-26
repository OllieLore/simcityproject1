#include "residentialzone.h"
#include "zonenode.h"

//Constructor
residentialzone::residentialzone()
{

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
