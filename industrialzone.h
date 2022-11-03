#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H
#include "zonenode.h"
#include <string>
#include "residentialzone.h"

using namespace std;

class industrialzone : public zonenode {
    public:

	int availableGoods;
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
	int GetPopulation();
	void SetPopulation(int industrialPopulation);
	int GetAvailableGoods();
	void SetAvailableGoods(int availableGoods);
	int GetWorkerCount();
	void SetWorkerCount(int workerCount);
	void CheckPower();
	void CheckWorkerCount();
	int IncreasePopulation(bool power, bool pop, bool workers);
	bool CheckNeighborPopulation();
	int IncreaseGoods(bool power, bool pop, bool workers);


};

#endif