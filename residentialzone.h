#ifndef RESIDENTIALZONE_H
#define RESIDENTIALZONE_H

#include "zonenode.h"

class residentialzone : public zonenode { // Calls from the zonenode from the zonenode.h file
    private:
        static int workers; // Keeps track of the worker amount
        //int population; // Keeps track of the population in a cell
        //int Neighbors; // Keeps track of population size of the cell's neighbors
        bool IsNearPowerline; //PopulationisGreater; // Determines if the conditions are met to increase the population size
        int futurePop; // used to increase population step by step
    public:
        residentialzone(); // Class called
        void IncreasePopulationSize(/*int population, int Neighbors*/); // Brings in the bools and int to increase the population size
        //int getPopulationSize(int population); // Gets the size of the population
        static int getWorkers(); //getter
        static void setWorkers(int workersI); //setter
        //void growWorkerCount();
        int GetFuturePop(); //getter
        void SetFuturePop(int futurePopI); //setter
        void UpdatePopAndWorkers(); //updates population with futurePop and workers accordingly
};

#endif
