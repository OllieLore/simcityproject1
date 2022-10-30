#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

class industrialzone : public zonenode  {
    private:
	int availableGoods;
	int workerCount;
	int population;
	int temp;
	bool powerOrPopulation;
	
    public:
        industrialzone();
	int GetPopulation();
	void SetPopulation(int population);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	int IncreasePopulation(bool powerOrPopulation, int workerCount, int population);

};

#endif