#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

class industrialzone {
    private:
	int availableGoods;
	int workerCount;
	int population;
	int temp;
	bool power;
	int onePopulationCells;
	int twoPopulationCells;
    public:
        industrialzone();
	int GetPopulation();
	void SetPopulation(int population);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	
	

};

#endif