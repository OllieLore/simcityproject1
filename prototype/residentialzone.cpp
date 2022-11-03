#include "residentialzone.h"
#include "zonenode.h"

#include <vector>
#include <algorithm>

using namespace std;

int residentialzone::availableWorkers = 0;

residentialzone::residentialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'R', 0) {}

void residentialzone::increasePopulation() {
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
    switch(this->getPopulation()) {
        case 0:
            if(count(tempPop.begin(), tempPop.end(), 1) >= 1) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            else if(isPowered) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            break;
        case 1:
            if(count(tempPop.begin(), tempPop.end(), 1) >= 2) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            break;
        case 2:
            if(count(tempPop.begin(), tempPop.end(), 2) >= 4) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            break;
        case 3:
            if(count(tempPop.begin(), tempPop.end(), 3) >= 6) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            break;
        case 4:
            if(count(tempPop.begin(), tempPop.end(), 4) >= 8) {
                this->setPopulation(this->getPopulation() + 1);
                availableWorkers++;
            }
            break;
        default:
                break;
    }
}

void residentialzone::decreaseAvailableWorkers(int n) {
    availableWorkers -= n;
}

int residentialzone::getAvailableWorkers() {
    return availableWorkers;
}