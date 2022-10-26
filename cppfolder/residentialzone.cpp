#include "residentialzone.h"
#include "zonenode.h"

//Constructor
residentialzone::residentialzone()
{
    int population = 0; // Population starts at 0
    int Neighbors = 0; // Neighbors starts at 0
    bool IsNearPowerline = false; // Set to false by default
    bool PopulationisGreater = false; // Set to false by default
};

int residentialzone::getPopulationSize(int population)
{
    return population;
    // WILL NEED TO UTILIZE RECURSION TO FIND OUT IF THE POPULATION ZONE IS NEAR A POWERLINE AND NEAR A NODE WITH A HIGHER POPULATION
    // KEEP POPULATION AT LIMIT OF 5, UNLESS TA SAYS OTHERWISE
};

int residentialzone::IncreasePopulationSize(int population, int Neighbors, bool IsNearPowerline, bool PopulationisGreater)
{
    if(IsNearPowerline == true && PopulationisGreater == true)
    {
        // TRY AND KEEP POPULATION LIMITED TO 5
        // POTENTIALLY HAVE RECURSION IN A LOOP THAT STOPS WHEN POP REACHES 5
        population+1;
    }
};
