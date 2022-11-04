#include "industrialzone.h"
#include "zonenode.h"
#include <string>

using namespace std;

//Constructor
industrialzone::industrialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'I', 0) {
industrialPopulation = 0;
availableGoods = 0;
workerCount = 0;
temp = NULL;
powerOrPopulation = true;
neighborPopCount1 = 0;
neighborPopCount2 = 0;
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
       
        
void industrialzone::CheckPower(){
    for(int i = 0; i < 8; i++){

        *temp = *zonenode::getNeighbor(i);

    if(temp->getType() == '#' || temp->getType() == 'T' || temp->getType() == 'P'){
         powerOrPopulation = true;
    }

    else{
        powerOrPopulation = false;
    }
    }
}

bool industrialzone::CheckNeighborPopulation(){
    for(int i = 0; i < 8; i++){

        *temp = *zonenode::getNeighbor(i);
            
    if(temp->getPopulation() >= 1){
        neighborPopCount1++;

    }
    if(temp->getPopulation() >= 2){
        neighborPopCount2++;
    }
    }


     if(industrialPopulation == 0 && neighborPopCount1 >=1){
        return powerOrPopulation = true;
     }
     if(industrialPopulation == 0 && neighborPopCount1 >=2){
        return powerOrPopulation = true;
     }
     if(industrialPopulation == 0 && neighborPopCount2 >=4){
        return powerOrPopulation = true;
     }
     else{
        return powerOrPopulation = false;
     }
}
    
