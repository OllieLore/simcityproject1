#ifndef INDUSTRIALZONE_H
#define INDUSTRIALZONE_H

#include "zonenode.h"

using namespace std;

class industrialzone : public zonenode {
	private:
		//Stores all avaiable goods, used by commercial class
		static int availableGoods;
    public:


	//int availableGoods;
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

	void increasePopulation(); //Increase population of cell
	static void decreaseAvailableGoods(int n); //Decrease available goods when used by commercial class
 	static int getAvailableGoods(); //Accessor

};

#endif