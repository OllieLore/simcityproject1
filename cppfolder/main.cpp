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
    vector<zonenode*> listHeads; // stores head of the linked list {setup for Linked List implimentation}
    zonenode* tempNodePtr = NULL;
    bool headNode = false;
    int numberOfNodes = 0;
    int intRead;

    vector<vector<char>> regionMap;

    ifstream inputStream; // file reader input 


    //-------------------------- Reading in Config file --------------------------
    /*
    cin >> inputFile; // Read in the region file's name

    cin >> intRead; // Read in the max time steps
    const int MAX_TIME_STEPS  = intRead; // Store max time steps

    cin >> intRead; // Read in the refresh rate of time steps
    const int REFRESH_RATE  = intRead; //  Store refresh rate of time steps
    */

    //-------------------------- Reading in Region file --------------------------
    inputStream.open(/*inputFile*/ "CityCSV.txt");
    if (inputStream.is_open()) // saftey check for open file
    {

        while (!inputStream.eof()) // start reading file until the end
        {
            getline(inputStream, valueRead, ','); // read until next comma and store it in valueRead
            

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
                vector<char> tempCarVect;
                regionMap.push_back(tempCarVect);
                headNode = false;
            }
            
            regionMap.at(regionMap.size() - 1).push_back(valueRead.at(0)); // adds valueRead to its row vector
        }

        for (long unsigned int i = 0; i < regionMap.size(); i++) // outputs regionMap 
        {
            if (regionMap.at(i).size() != 1 && regionMap.at(i).at(0) != ' ')
            for (long unsigned int j = 0; j < regionMap.at(i).size(); j++)
            {
                cout << regionMap.at(i).at(j) << ",";
            }
            cout << endl;
        }

        cout << "DONE" << endl; //DEBUG: make sure script is fully run

        inputStream.close(); // close file
    }

    return 0;
}