#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "zonenode.h"
#include "residentialzone.h"
#include "commercialzone.h"
#include "industrialzone.h"


using namespace std;

//-------------------------- Global Variables --------------------------
vector<vector<zonenode*>> regionMap;
int population = 0, pollution = 0;
int MAX_TIME_STEPS, REFRESH_RATE;

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

                        if(choicex <= regionMap[0].size() && choicex >= 0 && choicey <= regionMap.size() && choicey >= 0 && choicex2 <= regionMap[0].size() && choicex2 >= 0 && choicey2 <= regionMap.size() && choicey2 >= 0) {
                            //Do analyze
                            analyze(choicex, choicey, choicex2, choicey2);
                            break;
                        }
                        else {
                            cout << "Did not enter valid coordinates. Try again." << endl;
                        }
                    }
                    while(!(choicex <= regionMap[0].size() && choicex >= 0 && choicey <= regionMap.size() && choicey >= 0 && choicex2 <= regionMap[0].size() && choicex2 >= 0 && choicey2 <= regionMap.size() && choicey2 >= 0));
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

//Function to spread pollution
void spreadpollution(int p, int x, int y)
{
    int centerx = x;
    int centery = y;

    int startx = x;
    int starty = y;

    for (int a = p; a > 0; a--)
    {
        // Spread left and right columns
        for (int b = starty; b <= starty + 2 * (p - a); b++)
        {
            if (b >= 0 && b <= regionMap.size())
            {
                if (centerx - (p - a) >= 0 && centerx - (p - a) <= regionMap[x].size() && a > regionMap[centerx - (p - a)][b]->getPollution())
                    regionMap[centerx - (p - a)][b]->setPollution(a);
                if (centerx - (p - a) != centerx + p - a && centerx + p - a >= 0 && centerx + p - a <= regionMap[x].size() && a > regionMap[centerx + p - a][b]->getPollution())
                    regionMap[centerx + p - a][b]->setPollution(a);
            }
        }

        // Spread top and bottom rows
        for (int b = startx + 1; b <= startx + 2 * (p - a) - 1; b++)
        {
            if (b >= 0 && b <= regionMap[x].size())
            {
                if (centery - (p - a) >= 0 && centery - (p - a) <= regionMap.size() && a > regionMap[b][centery - (p - a)]->getPollution())
                    regionMap[b][centery - (p - a)]->setPollution(a);
                if (centery + p - a >= 0 && centery + p - a <= regionMap.size() && a > regionMap[b][centery + p - a]->getPollution())
                    regionMap[b][centery + p - a]->setPollution(a);
            }
        }

        startx--;
        starty--;
    }
}

int main()
{
    //-------------------------- Variables --------------------------
    string valueRead, inputFile; // variable for node character (stored as string to use getline function)
    bool headNode = false;
    int intRead;

    ifstream inputStream, in_s; // file reader input 


    //-------------------------- Reading in Config file --------------------------
    
    cout << "Input config file: ";
    cin >> inputFile; // Read in the config file's name

    in_s.open(inputFile);
    if (in_s.is_open())
    {
        in_s >> inputFile; // Read in the region map file's name

        in_s >> intRead; // Read in the max time steps
        MAX_TIME_STEPS = intRead; // Store max time steps
        cout << "Max Time Steps: " << MAX_TIME_STEPS << endl;

        in_s >> intRead; // Read in the refresh rate of time steps
        REFRESH_RATE = intRead; //  Store refresh rate of time steps
        cout << "Refresh Rate: " << REFRESH_RATE << endl;

        //-------------------------- Reading in Region file --------------------------
        inputStream.open(inputFile);
        if (inputStream.is_open()) // saftey check for open file
        {
            if (regionMap.empty()) // checks if there is no rows
            {
                headNode = true; // mark for new row vector
            } 

            for (int i = 0; i < valueRead.size(); i++) // checking for new lines
            {
                if (inputStream.eof()) //if end of file is found dont add this value.
                    break;
                    
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
            
            //sets the correct typer of node to be added
            zonenode* tempNode;
            switch (valueRead.at(0))
            {
            case 'R':
                tempNode = new residentialzone();
                break;

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
                        tempNode = new industrialzone();
                        break;
                    case 'R': //residential
                        tempNode = new residentialzone();
                        break;
                    case 'C': //commercial
                        tempNode = new commercialzone();
                        break;
                    default:
                        break;
                }

            case 'C':
                tempNode = new commercialzone();
                break;

            inputStream.close(); // close file
        }


        in_s.close(); // close config file
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

    //do simulation
    for (int a = 0; a < MAX_TIME_STEPS; a++)
    {
        cout << "----------Step " << a << "----------" << endl;

        // Calculate new commercial population
        for (int x = 0; x < regionMap.size(); x++)
        {
            for (int y = 0; y < regionMap[x].size(); y++)
            {
                if (regionMap[x][y]->getType() == 'C')
                {
                    commercialzone *tempInd = (commercialzone *)regionMap[x][y];
                    tempInd->increasePopulation();
                }
            }
        }

        // Calculate new industrial population
        for (int x = 0; x < regionMap.size(); x++)
        {
            for (int y = 0; y < regionMap[x].size(); y++)
            {
                if (regionMap[x][y]->getType() == 'I')
                {
                    industrialzone *tempInd = (industrialzone *)regionMap[x][y];
                    tempInd->increasePopulation();
                }
            }
        }

        // Calculate pollution
        for (int x = 0; x < regionMap.size(); x++)
        {
            for (int y = 0; y < regionMap[x].size(); y++)
            {
                if (regionMap[x][y]->getType() == 'I')
                {
                    spreadpollution(regionMap[x][y]->getPopulation(), x, y);
                }
            }
        }

        // Caluculate new residential population
        for (int x = 0; x < regionMap.size(); x++)
        {
            for (int y = 0; y < regionMap[x].size(); y++)
            {
                if (regionMap[x][y]->getType() == 'R')
                {
                    residentialzone *tempRes = (residentialzone *)regionMap[x][y];
                    tempRes->increasePopulation();
                }
            }
        }

        if (a % REFRESH_RATE == 0)
        {
            //Output entire city
            analyze(0, 0, regionMap[0].size(), regionMap.size());

            //Custom analyze
            customanalyze();
        }
    }


    return 0;
}