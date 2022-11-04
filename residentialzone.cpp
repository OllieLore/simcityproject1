#include "residentialzone.h"
#include <iostream>

#include <vector>
#include <algorithm>

//Constructor
int residentialzone::workers = 0;
residentialzone::residentialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'R', 0)
{
    //workers = 0; // Worker amount starts at 0
    //population = 0; // Population starts at 0
    //Neighbors = 0; // Neighbors starts at 0
    //PopulationisGreater = false; // Set to false by default
    futurePop = 0;
};

/*int residentialzone::getPopulationSize(int population)
{
    return population;
};*/

int residentialzone::getWorkers() {
    return workers;
}

void residentialzone::setWorkers(int workersI) {
    workers = workersI;
}

void residentialzone::IncreasePopulationSize(/*int population, int Neighbors*/)
{
    std::vector<int> tempPop; // Looks at the neighbors of the cell
    IsNearPowerline = false; // Set to false by default

    for(int x = 0; x < 8; x++) // Initializes and defines its neighbors
    {
        if (getNeighbor(x) != nullptr)
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
    }
    if (IsNearPowerline && population == 0) // If the cell is confirmed to be near a powerline
    {
        futurePop++; // Increases population by one
    }
    else
    {
        switch (population) // Checks neighboring cells for if the population is greater
        {
        case 0:
            if(std::count(tempPop.begin(), tempPop.end(), 1) >= 1)
            {
                futurePop++;
            }
            break;
        case 1:
            if(count(tempPop.begin(), tempPop.end(), 1) >= 2)
            {
                futurePop++;
            }
            break;
        case 2:
            if(count(tempPop.begin(), tempPop.end(), 2) >= 4)
            {
                futurePop++;
            }
            break;
        case 3:
            if(count(tempPop.begin(), tempPop.end(), 3) >= 6)
            {
                futurePop++;
            }
            break;
        case 4:
            if(count(tempPop.begin(), tempPop.end(), 4) >= 8)
            {
                futurePop++;
            }
            break;
        }
    }
}

int residentialzone::GetFuturePop()
{
    return futurePop;
}

void residentialzone::SetFuturePop(int futurePopI)
{
    futurePop = futurePopI;
}

void residentialzone::UpdatePopAndWorkers()
{
    workers+= futurePop - population;
    population = futurePop;
}
