#include "industrialzone.h"
#include "residentialzone.h"
#include "zonenode.h"

#include <vector>
#include <algorithm>

using namespace std;

int industrialzone::availableGoods = 0;

industrialzone::industrialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'I', 0) {}

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