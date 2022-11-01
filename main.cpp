#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "zonenode.h" // ***Reminder: change .cpp for VS code and to .h before uplaod
#include "commercialzone.h"

using namespace std;

int main()
{
    //-------------------------- Global Variables --------------------------
    string valueRead, inputFile; // variable for node character (stored as string to use getline function)
    bool headNode = false;
    int intRead;

    vector<vector<zonenode*>> regionMap;

    ifstream inputStream, in_s; // file reader input 


    //-------------------------- Reading in Config file --------------------------

    /*cout << "Input config file:";
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
        */

        //-------------------------- Reading in Region file --------------------------
    inputStream.open("CityData.txt"/*inputFile*/);
    if (inputStream.is_open()) // saftey check for open file
    {
        while (getline(inputStream, valueRead, ',')) // start reading file until the end
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

            zonenode* tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, valueRead[0], 0); // creates node
            regionMap.at(regionMap.size() - 1).push_back(tempNode); // adds tempNode to its row vector


            /*
            switch (valueRead.at(0))
            {
                case 'R':
                    // residentialnode* tempNodeR =
                    break;

                case 'I':
                    break;

            case 'C':
                commercialzone * tempNodeC = new commercialzone();
                tempNodeC->setType('c');
                regionMap.at(regionMap.size() - 1).push_back(tempNodeC); // adds tempNode to its row vector
                break;

                case '-':
                    break;

                case 'T':
                    break;

                case '#':
                    break;

                case 'P':
                    break;

            default:
                zonenode* tempNode = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, valueRead[0], 0); // creates node
                regionMap.at(regionMap.size() - 1).push_back(tempNode); // adds tempNode to its row vector
                break;
            }*/
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
/*}
else {
    cout << "Error opening config file" << endl;
}*/


//Link all nodes
    for (int x = 0; x < regionMap.size(); x++) {
        for (int y = 0; y < regionMap[x].size(); y++) {
            zonenode* current = regionMap[x][y];

            //Link north
            if (x - 1 >= 0) {
                current->setNeighbor(0, regionMap[x - 1][y]);

                //Link north west
                if (y - 1 >= 0)
                    current->setNeighbor(4, regionMap[x - 1][y - 1]);

                //Link north east
                if (y + 1 <= regionMap[x].size() - 1)
                    current->setNeighbor(5, regionMap[x - 1][y + 1]);
            }

            //Link south
            if (x + 1 <= regionMap.size() - 1) {
                current->setNeighbor(1, regionMap[x + 1][y]);

                //Link south west
                if (y - 1 >= 0)
                    current->setNeighbor(6, regionMap[x + 1][y - 1]);

                //Link south east
                if (y + 1 <= regionMap[x].size() - 1)
                {
                    current->setNeighbor(7, regionMap[x + 1][y + 1]);
                }

            }

            //Link west
            if (y - 1 >= 0)
                current->setNeighbor(2, regionMap[x][y - 1]);

            //Link east

            if (y + 1 <= regionMap[x].size() - 1)
                current->setNeighbor(3, regionMap[x][y + 1]);
        }
    }

    // Setting ID, IsPowered
    for (long unsigned int i = 0; i < regionMap.size(); i++)
    {
        if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0)->getType() != ' ')
        {
            for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
            {
                regionMap.at(i).at(j)->setID(i * 100 + j);
                regionMap.at(i).at(j)->CheckForPower();
            }
        }
    }



    //--------------------Comercial Zone Testing--------------------------

    for (int k = 0; k < 5; k++)
    {
        // Tells comercial nodes to run comercial timestep
        for (long unsigned int i = 0; i < regionMap.size(); i++)
        {
            if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0)->getType() != ' ')
            {
                for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
                {
                    if (regionMap.at(i).at(j)->getType() == 'C')
                    {
                        regionMap.at(i).at(j)->ComercialTimeStep();
                    }
                }
                cout << endl;
            }
        }

        // Outputs region with populations to show changes
        for (long unsigned int i = 0; i < regionMap.size(); i++)
        {
            if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0)->getType() != ' ')
            {
                for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
                {
                    cout << regionMap.at(i).at(j)->getType() << " ";
                    cout << regionMap.at(i).at(j)->getPopulation() << " ";
                }
                cout << endl;
            }
        }
    }



    return 0;
}