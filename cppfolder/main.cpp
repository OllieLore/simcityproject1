#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "zonenode.h" // ***Reminder: change .cpp to .h before uplaod
//#include "comercialzone.h"
//#include "residential.h"
//#include "industrial.h"
//#include "LinkedList.h"

using namespace std;

int main()
{
    //-------------------------- Global Variables --------------------------
    string valueRead, inputFile; // variable for node character (stored as string to use getline function)
    bool headNode = false;
    int intRead;

    vector<vector<zonenode>> regionMap;

    ifstream inputStream, in_s; // file reader input 


    //-------------------------- Reading in Config file --------------------------
    
    cout << "Input config file:";
    cin >> inputFile; // Read in the config file's name

    in_s.open(inputFile);
    if (in_s.is_open())
    {
        in_s >> inputFile; // Read in the region map file's name

        in_s >> intRead; // Read in the max time steps
        const int MAX_TIME_STEPS  = intRead; // Store max time steps
        cout << "Max Time Steps: " << MAX_TIME_STEPS << endl;

        in_s >> intRead; // Read in the refresh rate of time steps
        const int REFRESH_RATE  = intRead; //  Store refresh rate of time steps
        cout << "Refresh Rate: " << REFRESH_RATE << endl;

        //-------------------------- Reading in Region file --------------------------
        inputStream.open(inputFile);
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
                            valueRead = valueRead.at(0); // removes the newline characeter
                        }
                    }
                }

                

                if (headNode) // adds new row vector
                {
                    vector<zonenode> tempZoneVect;
                    regionMap.push_back(tempZoneVect);
                    headNode = false;
                }

                zonenode tempNode;
                tempNode.setType(valueRead.at(0));
                regionMap.at(regionMap.size() - 1).push_back(tempNode); // adds valueRead to its row vector
            }
                
            for (long unsigned int i = 0; i < regionMap.size(); i++) // outputs regionMap 
            {
                if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0).getType() != ' ')
                for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
                {
                    cout << regionMap.at(i).at(j).getType() << ",";
                }
                cout << endl;
            }

            inputStream.close(); // close file
        }
        else
        {
            cout << "NO" << endl;
        }

        in_s.close();
    }
    

    return 0;
}