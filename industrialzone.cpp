#include "industrialzone.h"
#include "zonenode.h"
#include <string>
#include "residentialzone.h"
#include "industrialzone.h"
#include <iostream>

using namespace std;
int industrialzone::availableGoods = 0;

//Constructor
industrialzone::industrialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'I', 0) {
industrialPopulation = 0;
availableGoods = 0;
workerCount = 0;
temp = nullptr;
power = true;
pop = true;
workers = true;
neighborPopCount1 = 0;
neighborPopCount2 = 0;
tempR = nullptr;
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

    bool industrialzone::GetPower(){
    return power;
}
	bool industrialzone::GetPop(){
        return pop;
    }
	bool industrialzone::GetWorkers(){
        return workers;
    }	

//Grow zone population
void industrialzone::IncreasePopulation(bool power, bool pop, bool workers){ 
    if(power == true && workers == true || pop == true && workers == true){
            cout << "true" << endl;
    population = population + 1;
    
        
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


        if(getNeighbor(i) != nullptr){

        if(getNeighbor(i)->getType() == '#'){
            power= true;
            break;
        } 
        if(getNeighbor(i)->getType() == 'T'){
            cout << "hello";
            power= true;
            break;
        }
        if(getNeighbor(i)->getType() == 'P'){
         power= true;
         break;

    }

    else{
        power = false;
    }

        }
    
    }
}

void industrialzone::CheckNeighborPopulation(){
    pop = false;

    for(int i = 0; i < 8; i++){

        
    if(getNeighbor(i) != nullptr){        
    if(getNeighbor(i)->getPopulation() >= 1){
        neighborPopCount1++;

    }
    if(getNeighbor(i)->getPopulation() >= 2){
        neighborPopCount2++;
    }
    }


     if(industrialPopulation == 0 && neighborPopCount1 >=1){
        pop = true;
     }
     if(industrialPopulation == 0 && neighborPopCount1 >=2){
        pop = true;
     }
     if(industrialPopulation == 0 && neighborPopCount2 >=4){
        pop = true;
     }
    }
}

void industrialzone::CheckWorkerCount(){

    //tempR* = *zonenode::getWorkers();
    if(residentialzone::getWorkers() >= 2){
        workers = true;
        residentialzone::setWorkers(residentialzone::getWorkers()-2);
        }
    else{
        workers = false;
    }


}
    
