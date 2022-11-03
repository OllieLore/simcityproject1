#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H
#include "zonenode.h"
#include <string>
#include "residentialzone.h"

using namespace std;

class industrialzone : public zonenode {
    public:

	static int availableWorkers;
	static int availableGoods;
	int workerCount;
	int industrialPopulation;
	zonenode *temp;
	bool power;
	bool pop;
	bool workers;
	int neighborPopCount1;
	int neighborPopCount2;
	residentialzone *tempR;
	
  
        industrialzone();
	void SetPopulation(int industrialPopulation);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	void CheckPower();
	void CheckWorkerCount();
	void IncreasePopulation(bool power, bool pop, bool workers);
	void CheckNeighborPopulation();
	int IncreaseGoods(bool power, bool pop, bool workers);
	bool GetPower();
	bool GetPop();
	bool GetWorkers();

};

#endif