#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "zonenode.h"
#include "residentialzone.h"
#include "industrialzone.h"
#include "commercialzone.h"

using namespace std;

//Global variables
vector<vector<zonenode*>> values; //Grid
int MAX_TIME_STEPS, REFRESH_RATE;
int availableworkers;

//Initialize everything
void initialize() {
    //File name input
    string filename;
    string csvfilename;
    ifstream filein;
    cin >> filename;

    //Open config file to store region csv, max time steps, and refresh rate
    filein.open(filename);
    if(filein.is_open()) {
        filein >> csvfilename;
        filein >> MAX_TIME_STEPS;
        filein >> REFRESH_RATE;

        cout << "MAX TIME STEPS: " << MAX_TIME_STEPS << endl;
        cout << "REFRESH RATE: " << REFRESH_RATE << endl;
    }
    else {
        cout << "Error opening config file" << endl;
    }
    filein.close();

    vector<zonenode*> row; //Row of grid
    string line, value; //Input helper variables

    //Initial store into vectors
    fstream file (csvfilename, ios::in);
    if(file.is_open()) {
        while(getline(file, line)) {
            row.clear();

            stringstream str(line);

            while(getline(str, value, ',')) {
                zonenode *toadd;

                //Determine what type of zone object to create
                switch(value[0]) {
                    case '-': //road
                        toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '-', 0);
                        break;
                    case 'T': //powerline
                        toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'T', 0);
                        break;
                    case '#': //intersection
                        toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '#', 0);
                        break;
                    case 'P': //powerplant
                        toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'P', 0);
                        break;
                    case 'I': //industrial
                        toadd = new industrialzone();
                        break;
                    case 'R': //residential
                        toadd = new residentialzone();
                        break;
                    case 'C': //commercial
                        toadd = new commercialzone();
                        break;
                    default:
                        break;
                }

                row.push_back(toadd);
            }  
            values.push_back(row);
        }
    }
    else {
        cout << "Error opening region file" << endl;
    }
    file.close();

    //Link all nodes
    for(int x = 0; x < values.size(); x++) {
        for(int y = 0; y < values[x].size(); y++) {
            zonenode *current = values[x][y];
            current->setID(x * 100 + y);

            //Link north
            if(x - 1 >= 0) {
                current->setNeighbor(0, values[x - 1][y]);

                //Link north west
                if(y - 1 >= 0)
                    current->setNeighbor(4, values[x - 1][y - 1]);

                //Link north east
                if(y + 1 <= values[x].size() - 1)
                    current->setNeighbor(5, values[x - 1][y + 1]);
            }

            //Link south
            if(x + 1 <= values.size() - 1) {
                current->setNeighbor(1, values[x + 1][y]);

                //Link south west
                if(y - 1 >= 0)
                    current->setNeighbor(6, values[x + 1][y - 1]);

                //Link south east
                if(y + 1 <= values[x].size() - 1)
                    current->setNeighbor(7, values[x + 1][y + 1]);
            }

            //Link west
            if(y - 1 >= 0)
                current->setNeighbor(2, values[x][y - 1]);

            //Link east
            if(y + 1 <= values[x].size() - 1)
                current->setNeighbor(3, values[x][y + 1]);
        }
    }
}

//Output every zone's neighbors for debugging purposes
void outputValues() {
    for(int x = 0; x < values.size(); x++) {
        for(int y = 0; y < values[x].size(); y++) {
            cout << "Currently looking at: " << values[x][y]->toString() << endl;

            for(int z = 0; z < 8; z++) {
                if(values[x][y]->getNeighbor(z) != nullptr)
                    cout << values[x][y]->getNeighbor(z)->toString() << endl;
            }

            cout << endl;
        }
    }
}

void spreadpollution(int p, int x, int y) {
    int centerx = x;
    int centery = y;

    int startx = x;
    int starty = y;

    for(int a = p; a > 0; a--) {
        //Spread left and right columns
        for(int b = starty; b <= starty + 2 * (p - a); b++) {
            if(b >= 0 && b <= values.size()) {
                if(centerx - (p - a) >= 0 && centerx - (p - a) <= values[x].size())
                    values[centerx - (p - a)][b]->setPollution(values[centerx - (p - a)][b]->getPollution() + a);
                if(centerx - (p - a) != centerx + p - a && centerx + p - a >= 0 && centerx + p - a <= values[x].size())
                    values[centerx + p - a][b]->setPollution(values[centerx + p - a][b]->getPollution() + a);
            }
        }

        //Spread top and bottom rows
        for(int b = startx + 1; b <= startx + 2 * (p - a) - 1; b++) {
            if(b >= 0 && b <= values[x].size()) {
                if(centery - (p - a) >= 0 && centery - (p - a) <= values.size())
                    values[b][centery - (p - a)]->setPollution(values[b][centery - (p - a)]->getPollution() + a);
                if(centery + p - a >= 0 && centery + p - a <= values.size())
                    values[b][centery + p - a]->setPollution(values[b][centery + p - a]->getPollution() + a);
            }
        }

        startx--;
        starty--;
    }
}

int main() {
    initialize();

    //Start simulation
    for(int a = 0; a < MAX_TIME_STEPS; a++) {
        //Calculate new commercial population
        for(int x = 0; x < values.size(); x++) {
            for(int y = 0; y < values[x].size(); y++) {
                if(values[x][y]->getType() == 'C') {
                    commercialzone *tempInd = (commercialzone*) values[x][y];
                    tempInd->increasePopulation();
                }
            }
        }

        //Calculate new industrial population
        for(int x = 0; x < values.size(); x++) {
            for(int y = 0; y < values[x].size(); y++) {
                if(values[x][y]->getType() == 'I') {
                    industrialzone *tempInd = (industrialzone*) values[x][y];
                    tempInd->increasePopulation();
                }
            }
        }

        //Calculate pollution
        for(int x = 0; x < values.size(); x++) {
            for(int y = 0; y < values[x].size(); y++) {
                if(values[x][y]->getType() == 'I') {
                    spreadpollution(values[x][y]->getPopulation(), x, y);
                }
            }
        }

        //Caluculate new residential population
        for(int x = 0; x < values.size(); x++) {
            for(int y = 0; y < values[x].size(); y++) {
                if(values[x][y]->getType() == 'R') {
                    residentialzone *tempRes = (residentialzone*) values[x][y];
                    tempRes->increasePopulation();
                }
            }
        }

        if(a % REFRESH_RATE == 0) {
            //Output population state
            cout << "Population state" << endl;
            for(int x = 0; x < values.size(); x++) {
                for(int y = 0; y < values[x].size(); y++) {
                    if(values[x][y]->getPopulation() == 0)
                        cout << values[x][y]->getType() << " ";
                    else
                        cout << values[x][y]->getPopulation() << " ";
                }
                cout << endl;
            }
            
            //Output pollution state
            cout << "Pollution state" << endl;
            for(int x = 0; x < values.size(); x++) {
                for(int y = 0; y < values[x].size(); y++) {
                    cout << values[x][y]->getPollution() << " ";
                }
                cout << endl;
            }
            cout << "Ending step " << a << endl;
        }
    }
    //End of simulation and program

    return 0;
}