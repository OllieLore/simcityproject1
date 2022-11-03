#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H
#include "zonenode.h"
#include <string>

using namespace std;

class industrialzone : public zonenode {
    public:

	int availableGoods;
	int workerCount;
	int industrialPopulation;
	zonenode *temp;
	bool powerOrPopulation;
	int neighborPopCount1;
	int neighborPopCount2;
	
  
        industrialzone();
	int GetPopulation();
	void SetPopulation(int industrialPopulation);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	void CheckPower();
	int CheckWorkerCount(int workerCount);
	int IncreasePopulation(int industrialPopulation);
	bool CheckNeighborPopulation();

};

#endif