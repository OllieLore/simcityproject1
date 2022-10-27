#include "residentialzone.h"
#include "zonenode.h"

//Constructor
residentialzone::residentialzone()
{
    population = 0; // Population starts at 0
    Neighbors = 0; // Neighbors starts at 0
    PopulationisGreater = false; // Set to false by default
};

int residentialzone::getPopulationSize(int population)
{
    return population;
};

int residentialzone::IncreasePopulationSize(int population, int Neighbors)
{
    vector<int> tempPop; // Looks at the neighbors of the cell
    IsNearPowerline = false; // Set to false by default

    for(int x = 0; x < 8; x++) // Initializes and defines its neighbors
    {
        zonenode *temp = getNeighbor(x);

        switch (temp->getType())
        {
            case 'T':
                IsNearPowerline = true;
                break;
            case '#':
                IsNearPowerline = true;
                break;
            case 'I':
                tempPop.push_back(temp->getPopulation());
                break;
            case 'C':
                tempPop.push_back(temp->getPopulation());
                break;
            case 'R':
                tempPop.push_back(temp->getPopulation());
                break;
        }
    }
    if (IsNearPowerline) // If the cell is confirmed to be near a powerline
    {
        population+=1; // Increases population by one
    }
        switch (population) // Checks neighboring cells for if the population is greater
        {
        case 0:
            if(count(tempPop.begin(), tempPop.end(), 1) >= 1)
            {
                population++;
            }
            break;
        case 1:
            if(count(tempPop.begin(), tempPop.end(), 1) >= 2)
            {
                population++;
            }
            break;
        case 2:
            if(count(tempPop.begin(), tempPop.end(), 2) >= 4)
            {
                population++;
            }
            break;
        case 3:
            if(count(tempPop.begin(), tempPop.end(), 3) >= 6)
            {
                population++;
            }
            break;
        case 4:
            if(count(tempPop.begin(), tempPop.end(), 4) >= 8)
            {
                population++;
            }
            break;
        }
};
