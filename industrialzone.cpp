#include "industrialzone.h"
#include "zonenode.h"
#include <string>

using namespace std;

//Constructor
industrialzone::industrialzone() {
industrialPopulation = 0;
availableGoods = 0;
workerCount = 0;
temp* = NULL;
powerOrPopulation = true;
}

int industrialzone::GetPopulation(){
    return industrialPopulation;
}
	
void industrialzone::SetPopulation(int industrialPopulation){
    industrialPopulation = industrialPopulation;
}
	
int industrialzone::GetAvailableGoods(){
        return availableGoods; 
    }
	
void industrialzone::SetAvailableGoods(int availableGoods){
    this->availableGoods = availableGoods;
}
	
int industrialzone:: GetWorkerCount(){
    return workerCount;
}
	
void industrialzone::SetWorkerCount(int workerCount){
    this->workerCount = workerCount;
}
	

//Grow zone population
int industrialzone::IncreasePopulation(int industrialPopulation){ 
    industrialPopulation = industrialPopulation + 1;
        return industrialPopulation;
}
       
        
bool industrialzone::CheckPower(char type){
    
    if(type == '#' || type == "T" || type == "P"){
        return powerOrPopulation = true;
    }

    else{
        return powerOrPopulation = false;
    }
    }
    
bool industrialzone::CheckNeighborPopulation(int population){
    if(industrialPopulation == 0){


    }

}
     
