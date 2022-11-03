#include "commercialzone.h"
#include "residentialzone.h"
#include "industrialzone.h"
#include "zonenode.h"

#include <vector>
#include <algorithm>

using namespace std;

commercialzone::commercialzone() : zonenode::zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'C', 0) {}

void commercialzone::increasePopulation() {
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

    if(residentialzone::getAvailableWorkers() >= 1 && industrialzone::getAvailableGoods() >= 1) {
        switch(this->getPopulation()) {
            case 0:
                if(count(tempPop.begin(), tempPop.end(), 1) >= 1) {
                    this->setPopulation(this->getPopulation() + 1);
                    residentialzone::decreaseAvailableWorkers(1);
                    industrialzone::decreaseAvailableGoods(1);
                }
                else if(isPowered) {
                    this->setPopulation(this->getPopulation() + 1);
                    residentialzone::decreaseAvailableWorkers(1);
                    industrialzone::decreaseAvailableGoods(1);
                }
                break;
            case 1:
                if(count(tempPop.begin(), tempPop.end(), 1) >= 2) {
                    this->setPopulation(this->getPopulation() + 1);
                    residentialzone::decreaseAvailableWorkers(1);
                    industrialzone::decreaseAvailableGoods(1);
                }
                break;
            default:
                    break;
        }
    }
}