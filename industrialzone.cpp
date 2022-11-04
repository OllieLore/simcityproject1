#include "industrialzone.h"
#include "residentialzone.h"
#include "zonenode.h"

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Initialize availableGoods
int industrialzone::availableGoods = 0;

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
    
void industrialzone::increasePopulation() {
    vector<int> tempPop;
    bool isPowered = false;

    //Gets information on neighbors' population and whether current residential zone is powered
    for(int x = 0; x < 8; x++) {
        zonenode *temp = getNeighbor(x);

        if(temp != nullptr)
            switch(temp->getType()) {
                case 'T':
                    isPowered = true;
                    break;
                case '#':
                    isPowered = true;
                    break;
                case 'I':
                    tempPop.push_back(temp->getPopulation());
                    break;
                case 'C':
                    tempPop.push_back(temp->getPopulation());
                    break;
                case 'R':
                    tempPop.push_back(temp->getPopulation());
                    break;
                default:
                    break;
            }
    }

    //Do all the incrementing
    if(residentialzone::getAvailableWorkers() >= 2) {
        switch(this->getPopulation()) {
            case 0:
                if(count(tempPop.begin(), tempPop.end(), 1) >= 1) {
                    this->setPopulation(this->getPopulation() + 1);
                    availableGoods++;
                    residentialzone::decreaseAvailableWorkers(2);
                }
                else if(isPowered) {
                    this->setPopulation(this->getPopulation() + 1);
                    availableGoods++;
                    residentialzone::decreaseAvailableWorkers(2);
                }
                break;
            case 1:
                if(count(tempPop.begin(), tempPop.end(), 1) >= 2) {
                    this->setPopulation(this->getPopulation() + 1);
                    availableGoods++;
                    residentialzone::decreaseAvailableWorkers(2);
                }
                break;
            case 2:
                if(count(tempPop.begin(), tempPop.end(), 2) >= 4) {
                    this->setPopulation(this->getPopulation() + 1);
                    availableGoods++;
                    residentialzone::decreaseAvailableWorkers(2);
                }
                break;
            default:
                    break;
        }  
    }
}

void industrialzone::decreaseAvailableGoods(int n) {
    availableGoods -= n;
}

int industrialzone::getAvailableGoods() {
    return availableGoods;
}