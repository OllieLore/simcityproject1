#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "zonenode.cpp" // ***Reminder: change .cpp to .h before uplaod
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
    bool headNode;
    int numberOfNodes = 0;
    int intRead;

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
    inputStream.open(/*inputFile*/ "CityData.txt" );
    if (inputStream.is_open()) // saftey check for open file
    {

        while (!inputStream.eof()) // start reading file until the end
        {
            getline(inputStream, valueRead, ','); // read until next comma and store it in valueRead
            zonenode* newNode = new zonenode(); // Make empty node

            while (valueRead.at(0) == '\n' && !inputStream.eof())
            {
                
                valueRead = valueRead.at(1); // removes the newline characeter
                headNode = true; // set marker so that later can be turned into head of new linked list
                
            }

            switch (valueRead.at(0)) // use input to add the correct node
            {
            case 'R':
                /* code */
                break;
            
            case 'I':
                /* code */
                break;
            
            case 'C':
                /* code */
                break;
            
            case 'T':
                /* code */
                break;
            case '#':
                /* code */
                break;
            
            case '-':
                /* code */
                break;
            
            case 'P':
                /* code */
                break;
            
            default:
                break;
            }
            
            if (listHeads.empty())
            {
                headNode = true;
            }

            newNode->setType(valueRead.at(0)); // sets value read to be stored into the empty node
            numberOfNodes++; // increase node count

            newNode->setNeighbor(2, tempNodePtr); // sets previous node pointer

            if (tempNodePtr != NULL) 
            {
                tempNodePtr->setNeighbor(3, newNode); //sets next node value
            }
            

            tempNodePtr = newNode;

            if (headNode) // adds marked nodes to head vector
            {
                listHeads.push_back(newNode);
                headNode = false;
            }
        }
        tempNodePtr->setNeighbor(3, NULL); // sets tails node to NULL

        for (long unsigned int i = 1; i < listHeads.size(); i++) // cuts the list into seperate list 
        {
            tempNodePtr = listHeads.at(i)->getNeighbor(2);
            tempNodePtr->setNeighbor(3, NULL);
            listHeads.at(i)->setNeighbor(2, NULL);
        }


        zonenode* curNode;
        for (long unsigned int i = 0; i < listHeads.size(); i++) // keeps track of row
        {
            curNode = listHeads.at(i);
            for (long unsigned int j = 0; curNode != NULL; j++) // keeps track of collumn
            {
                if (j > 0)
                {
                    std::cout << curNode->getType() << ", ";
                    curNode = curNode->getNeighbor(3);
                }
                
            }
            std::cout << endl;
        }

        std::cout << "DONE" << endl; //DEBUG: make sure script is fully run

        inputStream.close(); // close file
    }
    
    return 0;
}