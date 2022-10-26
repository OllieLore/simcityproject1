#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

class industrialzone {
    private:
	int availableGoods; 
	int workerCount;
	int population; //zone population
	int temp;
	bool power;  //Is the zone near a powerline
	int onePopulationZones; //for adjacent zone calculation
	int twoPopulationZones; //for adjacent zone calculation
    public:
        industrialzone();  //constructor
	int GetPopulation();
	void SetPopulation(int population);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	int IncreasePopulation(bool power, int workerCount); //Grow zone population
	

};

#endif