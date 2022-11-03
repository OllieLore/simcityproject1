#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H
#include "zonenode.h"
#include <string>
#include "residentialzone.h"

using namespace std;

class industrialzone : public zonenode {
    public:

	static int availableWorkers; //static variable for available workers between classes
	static int availableGoods; //static variable for available goods between classes
	int workerCount;
	int industrialPopulation;
	zonenode *temp;
	bool power;
	bool pop;
	bool workers;
	int neighborPopCount1;
	int neighborPopCount2;
	residentialzone *tempR;
	
  
        industrialzone(); //constructor
	void SetPopulation(int industrialPopulation);
	int GetAvailableGoods(); //get good #
	void SetAvailableGoods(int availableGoods); //set good #
	int GetWorkerCount(); 
	void SetWorkerCount(int workerCount);
	void CheckPower(); //check if cell powered
	void CheckWorkerCount(); //check if workers available
	void IncreasePopulation(bool power, bool pop, bool workers); //increase population of zone
	void CheckNeighborPopulation(); //check population growth criteria
	int IncreaseGoods(bool power, bool pop, bool workers); //increase goods
	bool GetPower();
	bool GetPop();
	bool GetWorkers();

};

#endif