#include "industrialzone.h"
#include "zonenode.h"
#include <string>
#include "residentialzone.h"

using namespace std;

//Constructor
industrialzone::industrialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'I', 0) {
industrialPopulation = 0;
availableGoods = 0;
workerCount = 0;
temp = NULL;
power = true;
pop = true;
workers = true;
neighborPopCount1 = 0;
neighborPopCount2 = 0;
tempR = NULL;
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
int industrialzone::IncreasePopulation(bool power, bool pop, bool workers){ 
    if(power == true && pop == true && workers == true){

    industrialPopulation = industrialPopulation + 1;
    
        return industrialPopulation;
    }
    else{
        return industrialPopulation;
    } 

  

}

//Increase commercial goods
int industrialzone::IncreaseGoods(bool power, bool pop, bool workers){
    if(power == true && pop == true && workers == true){
    availableGoods = availableGoods +1;
    return availableGoods;
    }
    else{
        return availableGoods;
    }
}
        
void industrialzone::CheckPower(){
    for(int i = 0; i < 8; i++){

        *temp = *zonenode::getNeighbor(i);

    if(temp->getType() == '#' || temp->getType() == 'T' || temp->getType() == 'P'){
         power= true;
    }

    else{
        power = false;
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
        return pop = true;
     }
     if(industrialPopulation == 0 && neighborPopCount1 >=2){
        return pop = true;
     }
     if(industrialPopulation == 0 && neighborPopCount2 >=4){
        return pop = true;
     }
     else{
        return pop = false;
     }
}

void industrialzone::CheckWorkerCount(){

    *tempR = *residentialzone::getWorkers();
    if(tempR->getWorkers() >= 2){
        workers = true;
        tempR->setWorkers(tempR->getWorkers()-2);
        }
    else{
        workers = false;
    }
}
    
