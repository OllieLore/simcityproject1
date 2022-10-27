#ifndef RESIDENTIALZONE_H
#define RESIDENTIALZONE_H

class residentialzone :: public zonenode { // Calls from the zonenode from the zonenode.h file
    private:
        int population; // Keeps track of the population in a cell
        int Neighbors; // Keeps track of population size of the cell's neighbors
        bool IsNearPowerline, PopulationisGreater; // Determines if the conditions are met to increase the population size
    public:
        residentialzone(); // Class called
        int IncreasePopulationSize(int population, int Neighbors, bool IsNearPowerline, bool PopulationisGreater); // Brings in the bools and int to increase the population size
        int getPopulationSize(int population); // Gets the size of the population
};

#endif
