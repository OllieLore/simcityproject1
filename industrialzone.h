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
	
  
        industrialzone();
	int GetPopulation();
	void SetPopulation(int industrialPopulation);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	bool CheckPower(bool powerOrPopulation);
	int CheckWorkerCount(int workerCount);
	int IncreasePopulation(int industrialPopulation);
	

};

#endif