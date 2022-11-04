#ifndef RESIDENTIALZONE_H
#define RESIDENTIALZONE_H

#include "zonenode.h"

class residentialzone : public zonenode { // Calls from the zonenode from the zonenode.h file
    private:
        static int workers; // Keeps track of the worker amount
        //int population; // Keeps track of the population in a cell
        //int Neighbors; // Keeps track of population size of the cell's neighbors
        bool IsNearPowerline; //PopulationisGreater; // Determines if the conditions are met to increase the population size
        int futurePop;
    public:
        residentialzone(); // Class called
        void IncreasePopulationSize(/*int population, int Neighbors*/); // Brings in the bools and int to increase the population size
        //int getPopulationSize(int population); // Gets the size of the population
        static int getWorkers();
        static void setWorkers(int workersI);
        //void growWorkerCount();
        int GetFuturePop();
        void SetFuturePop(int futurePopI);
        void UpdatePopAndWorkers();
};

#endif
