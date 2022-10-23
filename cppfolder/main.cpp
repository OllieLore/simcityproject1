#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "zonenode.cpp"
//#include "LinkedList.h"

using namespace std;

int main()
{
    string valueRead, inputFile; // variable for node character (stored as string to use getline function)
    vector<zonenode*> listHeads; // stores head of the linked list {setup for Linked List implimentation}
    //vector<string> valuesList; // temporary storage for nodes
    zonenode* tempNodePtr = NULL;
    bool headNode;
    int numberOfNodes = 0;

    ifstream inputStream; // file reader input

    //cin >> inputFile;

    inputStream.open(/*inputFile*/"CityData.txt");
    if (inputStream.is_open()) // saftey check for open file
    {

        while (!inputStream.eof()) // start reading file until the end
        {
            getline(inputStream, valueRead, ','); // read until next comma and store it in valueRead
            zonenode* newNode = new zonenode(); // Make empty node
            
            if (listHeads.empty())
            {
                headNode = true;
            }

            if (valueRead.at(0) == '\n' && !inputStream.eof()) // if there is a new line 
            {
                valueRead = valueRead.at(1); // removes the newline characeter
                headNode = true; // set marker so that later can be turned into head of new linked list
            }

            newNode->setType(valueRead.at(0)); // sets value read to be stored into the empty node
            numberOfNodes++; // increase node count

            newNode->setNeighbor(2, tempNodePtr); // sets previous node pointer

            if (tempNodePtr != NULL) 
            {
                tempNodePtr->setNeighbor(3, newNode); //sets next node value
            }
            

            tempNodePtr = newNode;

            if (headNode)
            {
                listHeads.push_back(newNode);
                headNode = false;
            }
        }
        tempNodePtr->setNeighbor(3, NULL); // sets tails node to NULL

        for (long unsigned int j = 0; j < listHeads.size(); j++) // read out the head values
        {
            cout << "head: " << listHeads.at(j)->getType() << ", ";
        }

        cout << endl;

        zonenode* curNode = listHeads.at(0);
        cout << curNode->getType() << ", ";
        for (long unsigned int j = 0; j < /*numberOfNodes - 1*/ 25; j++) // read out all nodes
        {
            
            if (curNode->getNeighbor(3) != NULL)
            {
                //cout << j << ": ";
                curNode = curNode->getNeighbor(3);
                cout << curNode->getType() << ", ";
            }
            
        }

    
        cout << "DONE" << endl; //DEBUG: make sure script is fully run

        inputStream.close(); // close file
    }
    
    return 0;
}