#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "zonenode.h"
#include "residentialzone.h"
#include "commercialzone.h"
#include "industrialzone.h"

using namespace std;

//-------------------------- Global Variables --------------------------
vector<vector<zonenode *>> regionMap;
int population = 0, pollution = 0;
int MAX_TIME_STEPS, REFRESH_RATE;

//General output
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

//Function to allow custom analyzing of a specific region
void customanalyze()
{
    char choice;
    cout << "Would you like to analyze a region [y/n]?" << endl;
    do
    {
        cin >> choice;
        if (choice == 'y')
        {
            int choicex, choicey, choicex2, choicey2;
            do
            {
                // Input region to analyze
                cout << "Enter top left x coordinate (0 indexed)" << endl;
                cin >> choicex;
                cout << "Enter top left y coordinate (0 indexed)" << endl;
                cin >> choicey;
                cout << "Enter bottom right x coordinate (0 indexed)" << endl;
                cin >> choicex2;
                cout << "Enter bottom right y coordinate (0 indexed)" << endl;
                cin >> choicey2;

                if (choicex <= regionMap[0].size() && choicex >= 0 && choicey <= regionMap.size() && choicey >= 0 && choicex2 <= regionMap[0].size() && choicex2 >= 0 && choicey2 <= regionMap.size() && choicey2 >= 0)
                {
                    // Do analyze
                    analyze(choicex, choicey, choicex2, choicey2);
                    break;
                }
                else
                {
                    cout << "Did not enter valid coordinates. Try again." << endl;
                }
            } while (!(choicex <= regionMap[0].size() && choicex >= 0 && choicey <= regionMap.size() && choicey >= 0 && choicex2 <= regionMap[0].size() && choicex2 >= 0 && choicey2 <= regionMap.size() && choicey2 >= 0));
            break;
        }
        else if (choice == 'n')
        {
            break;
        }
        else
        {
            cout << "Did not enter a valid choice. Try again." << endl;
        }
    } while (choice != 'y' && choice != 'n');
}

// Function to spread pollution
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
    // File name input
    string filename;
    string csvfilename;
    ifstream filein;
    cin >> filename;

    // Open config file to store region csv, max time steps, and refresh rate
    filein.open(filename);
    if (filein.is_open())
    {
        filein >> csvfilename;
        filein >> MAX_TIME_STEPS;
        filein >> REFRESH_RATE;

        cout << "MAX TIME STEPS: " << MAX_TIME_STEPS << endl;
        cout << "REFRESH RATE: " << REFRESH_RATE << endl;
    }
    else
    {
        cout << "Error opening config file" << endl;
    }
    filein.close();

    vector<zonenode *> row; // Row of grid
    string line, value;     // Input helper variables

    // Initial store into vectors
    fstream file(csvfilename, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, value, ','))
            {
                zonenode *toadd;

                // Determine what type of zone object to create
                switch (value[0])
                {
                case '-': // road
                    toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '-', 0);
                    break;
                case 'T': // powerline
                    toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'T', 0);
                    break;
                case '#': // intersection
                    toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, '#', 0);
                    break;
                case 'P': // powerplant
                    toadd = new zonenode(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 'P', 0);
                    break;
                case 'I': // industrial
                    toadd = new industrialzone();
                    break;
                case 'R': // residential
                    toadd = new residentialzone();
                    break;
                case 'C': // commercial
                    toadd = new commercialzone();
                    break;
                default:
                    break;
                }

                row.push_back(toadd);
            }
            regionMap.push_back(row);
        }
    }
    else
    {
        cout << "Error opening region file" << endl;
    }
    file.close();

    // Link all nodes
    for (int x = 0; x < regionMap.size(); x++)
    {
        for (int y = 0; y < regionMap[x].size(); y++)
        {
            zonenode *current = regionMap[x][y];
            current->setID(x * 100 + y);

            // Link north
            if (x - 1 >= 0)
            {
                current->setNeighbor(0, regionMap[x - 1][y]);

                // Link north west
                if (y - 1 >= 0)
                    current->setNeighbor(4, regionMap[x - 1][y - 1]);

                // Link north east
                if (y + 1 <= regionMap[x].size() - 1)
                    current->setNeighbor(5, regionMap[x - 1][y + 1]);
            }

            // Link south
            if (x + 1 <= regionMap.size() - 1)
            {
                current->setNeighbor(1, regionMap[x + 1][y]);

                // Link south west
                if (y - 1 >= 0)
                    current->setNeighbor(6, regionMap[x + 1][y - 1]);

                // Link south east
                if (y + 1 <= regionMap[x].size() - 1)
                    current->setNeighbor(7, regionMap[x + 1][y + 1]);
            }

            // Link west
            if (y - 1 >= 0)
                current->setNeighbor(2, regionMap[x][y - 1]);

            // Link east
            if (y + 1 <= regionMap[x].size() - 1)
                current->setNeighbor(3, regionMap[x][y + 1]);
        }
    }
    // do simulation
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
            // Output entire city
            analyze(0, 0, regionMap[0].size(), regionMap.size());

            // Custom analyze
            customanalyze();
        }
    }

    return 0;
}