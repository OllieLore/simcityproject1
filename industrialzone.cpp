#include "industrialzone.h"
#include "zonenode.h"

//Constructor
industrialzone::industrialzone() {

}

int industrialzone::GetPopulation(){
    return population;
}
	
void SetPopulation(int population){
    this->population = population;
}
	
int GetAvailableGoods(){
        return availableGoods;
    }
	
void SetAvailableGoods(int availableGoods){
    this->availableGoods;
}
	
int GetWorkerCount(){
    return workerCount;
}
	
void SetWorkerCount(int workerCount){
    this->workerCount;
}
	

//Grow zone population
int IncreasePopulation(bool powerOrPopulation, int workerCount, int population){ 
    if(powerOrPopulation == true && workerCount >= 2){
        population = population + 1;

    }

    else {
        return population;
    }

}