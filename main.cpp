#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "zonenode.h" // ***Reminder: change .cpp for VS code and to .h before uplaod
#include "residentialzone.h"

using namespace std;

//-------------------------- Global Variables --------------------------
vector<vector<zonenode*>> regionMap;
int population = 0, pollution = 0;

void analyze(int a, int A, int b, int B)
{
    if (a <= regionMap[0].size() && a >= 0 && A <= regionMap.size() && A >= 0 && b <= regionMap[0].size() && b >= 0 && B <= regionMap.size() && B >= 0)
    {
        // Output population state
        cout << "Population state:" << endl;
        for (int x = A; x < B; x++)
        {
            for (int y = a; y < b; y++)
            {
                if (regionMap[x][y]->getPopulation() == 0)
                    cout << regionMap[x][y]->getType() << " ";
                else
                    cout << regionMap[x][y]->getPopulation() << " ";
                population += regionMap[x][y]->getPopulation();
            }
            cout << endl;
        }

        // Output pollution state
        cout << "Pollution state:" << endl;
        for (int x = A; x < B; x++)
        {
            for (int y = a; y < b; y++)
            {
                cout << regionMap[x][y]->getPollution() << " ";
                pollution += regionMap[x][y]->getPollution();
            }
            cout << endl;
        }

        cout << "Total population is: " << population << endl;
        population = 0;
        cout << "Total pollution is: " << pollution << endl
             << endl;
        pollution = 0;
    }
}

void customanalyze() {
    char choice;
            cout << "Would you like to analyze a region [y/n]?" << endl;
            do {
                cin >> choice;
                if(choice == 'y')
                {
                    int choicex, choicey, choicex2, choicey2;
                    do {
                        //Input region to analyze
                        cout << "Enter top left x coordinate (0 indexed)" << endl;
                        cin >> choicex;
                        cout << "Enter top left y coordinate (0 indexed)" << endl;
                        cin >> choicey;
                        cout << "Enter bottom right x coordinate (0 indexed)" << endl;
                        cin >> choicex2;
                        cout << "Enter bottom right y coordinate (0 indexed)" << endl;
                        cin >> choicey2;

                        if(choicex <= values[0].size() && choicex >= 0 && choicey <= values.size() && choicey >= 0 && choicex2 <= values[0].size() && choicex2 >= 0 && choicey2 <= values.size() && choicey2 >= 0) {
                            //Do analyze
                            analyze(choicex, choicey, choicex2, choicey2);
                            break;
                        }
                        else {
                            cout << "Did not enter valid coordinates. Try again." << endl;
                        }
                    }
                    while(!(choicex <= values[0].size() && choicex >= 0 && choicey <= values.size() && choicey >= 0 && choicex2 <= values[0].size() && choicex2 >= 0 && choicey2 <= values.size() && choicey2 >= 0));
                    break;
                }
                else if(choice == 'n') {
                    break;
                }
                else {
                    cout << "Did not enter a valid choice. Try again." << endl;
                }
            }
            while(choice != 'y' && choice != 'n');
}

int main()
{
    //-------------------------- Variables --------------------------
    string valueRead, inputFile; // variable for node character (stored as string to use getline function)
    bool headNode = false;
    int intRead;

    ifstream inputStream, in_s; // file reader input 


    //-------------------------- Reading in Config file --------------------------
    
    cout << "Input config file:";
    cin >> inputFile; // Read in the config file's name

    in_s.open(inputFile);
    if (in_s.is_open())
    {
        in_s >> inputFile; // Read in the region map file's name

        in_s >> intRead; // Read in the max time steps
        const int MAX_TIME_STEPS = intRead; // Store max time steps
        cout << "Max Time Steps: " << MAX_TIME_STEPS << endl;

        in_s >> intRead; // Read in the refresh rate of time steps
        const int REFRESH_RATE = intRead; //  Store refresh rate of time steps
        cout << "Refresh Rate: " << REFRESH_RATE << endl;

        //-------------------------- Reading in Region file --------------------------
        inputStream.open(inputFile);
        if (inputStream.is_open()) // saftey check for open file
        {
            while(getline(inputStream, valueRead, ',')) // start reading file until the end
            {                
                if (regionMap.empty()) // checks if there is no rows
                {
                    headNode = true; // mark for new row vector
                }

                for (int i = 0; i < valueRead.size(); i++) // checking for new lines
                {
                    if (valueRead.at(i) == '\n')
                    {
                        if (i == 0)
                        {
                            headNode = true; // set marker so that later can be turned into head of new linked list
                            valueRead = valueRead.at(1); // removes the newline characeter
                        }
                        else 
                        {
                            headNode = true; // set marker so that later can be turned into head of new linked list
                            valueRead = valueRead.at(valueRead.size() - 1); // removes the newline characeter
                        }
                    }
                }
                
                if (headNode) // adds new row vector
                {
                    vector<zonenode*> tempZoneVect;
                    regionMap.push_back(tempZoneVect);
                    headNode = false;
                }

                

                zonenode *tempNode;

                switch(valueRead[0]) {
                    case '-': //road
                        tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '-', 0);
                        break;
                    case 'T': //powerline
                        tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'T', 0);
                        break;
                    case '#': //intersection
                        tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '#', 0);
                        break;
                    case 'P': //powerplant
                        tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'P', 0);
                        break;
                    case 'I': //industrial
                        break;
                    case 'R': //residential
                        tempNode = new residentialzone();
                        break;
                    case 'C': //commercial
                        break;
                    default:
                        break;
                }

                regionMap.at(regionMap.size() - 1).push_back(tempNode); // adds tempNode to its row vector
            }

            // outputs regionMap
            for (long unsigned int i = 0; i < regionMap.size(); i++)
            {
                if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0)->getType() != ' ')
                {
                    for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
                    {
                        cout << regionMap.at(i).at(j)->getType() << " ";
                    }
                    cout << endl;
                }
            }

            inputStream.close(); // close file
        }
        else {
            cout << "Error opening region map file" << endl;
        }

        in_s.close(); // close config file
    }
    else {
        cout << "Error opening config file" << endl;
    }

    //Link all nodes
    for(int x = 0; x < regionMap.size(); x++) {
        for(int y = 0; y < regionMap[x].size(); y++) {
            zonenode *current = regionMap[x][y];

            //Link north
            if(x - 1 >= 0) {
                current->setNeighbor(0, regionMap[x - 1][y]);

                //Link north west
                if(y - 1 >= 0)
                    current->setNeighbor(4, regionMap[x - 1][y - 1]);

                //Link north east
                if(y + 1 <= regionMap[x].size() - 1)
                    current->setNeighbor(5, regionMap[x - 1][y + 1]);
            }

            //Link south
            if(x + 1 <= regionMap.size() - 1) {
                current->setNeighbor(1, regionMap[x + 1][y]);

                //Link south west
                if(y - 1 >= 0)
                    current->setNeighbor(6, regionMap[x + 1][y - 1]);

                //Link south east
                if(y + 1 <= regionMap[x].size() - 1)
                    current->setNeighbor(7, regionMap[x + 1][y + 1]);
            }

            //Link west
            if(y - 1 >= 0)
                current->setNeighbor(2, regionMap[x][y - 1]);

            //Link east
            if(y + 1 <= regionMap[x].size() - 1)
                current->setNeighbor(3, regionMap[x][y + 1]);
        }
    }

    return 0;
}