#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "zonenode.h"
#include <cstring>
#include <algorithm>

using namespace std;


int main(){
    ifstream csvReadIn;  //input file stream
    ifstream csvRow;
    ifstream csvRows;
    ifstream inputFile;
    string rowss;
    vector <string> initialZone;
    string line;
    string configLine;
    int i;
    zonenode zoneNode;
    vector <zonenode> mapNodes;
    string temp;
    int count = 0;
    string row;
    vector <string> rowCount;
    int rows;
    int comma;
    int x;
    int y;
    int timesteps; //max timesteps
    int refresh;   //refresh rate
    string regionFile;



cout << "Input config file:";
    cin >> configLine; // Read in the config file's name

 inputFile.open(configLine);
 if(!inputFile.is_open()) {
    cout << "Could not open config file." << endl;
      return 1;
 }

 inputFile >> regionFile;
 inputFile >> timesteps;
 inputFile >> refresh;


    cout << "Opening file." << endl;
   csvReadIn.open(regionFile);
   
   if (!csvReadIn.is_open()) {
      cout << "Could not open file." << endl;
      return 1;
   }

/*getline(csvReadIn, row, '\n');
for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 

        comma++;
        }
}

cout << comma << endl;
*/
  while (!csvReadIn.fail()) {
    getline(csvReadIn, line, ',');

    initialZone.push_back(line);

    //getline(csvReadIn, row, '\n');
     //    rowCount.push_back(row);
    //rows = rowCount.size();
     /*for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 
        
        count++;
  
    }

    }
    */

    }
    csvReadIn.close();    

csvRow.open("zone.csv");

    getline(csvRow, row, '\n');
for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 

        comma++;
        }
}
csvRow.close(); 

csvRows.open("zone.csv");

while (!csvRows.fail()) {
getline(csvRows, rowss, '\n');
    rowCount.push_back(rowss);
    rows = rowCount.size();
}
csvRows.close(); 


for (i = 0; i < initialZone.size(); ++i) {
  x = i/comma;
  y = i/rows;
  //zoneNode.SetYCoordinate(y);
 // zoneNode.SetXCoordinate(x);
 
//cout << "X: " << x << endl;
//cout << "Y: " << y << endl;
cout << initialZone.at(i);

temp = initialZone.at(i);

 if(temp == "-"){
  zoneNode.setType('-');
}
 
if(temp == "P"){
 zoneNode.setType('P');
}

if(temp == "T"){
 zoneNode.setType('T');
}

if(temp == "I"){
 zoneNode.setType('I');
}

if(temp == "R"){
 zoneNode.setType('R');
}
if(temp == "C"){
 zoneNode.setType('C');
}

if(temp == "#"){
 zoneNode.setType('#');
}
mapNodes.push_back(zoneNode);
}

/*for(i=0; i<mapNodes.size(); ++i){
//cout<< mapNodes.at(i).GetXCoordinate() << mapNodes.at(i).GetYCoordinate() << endl;
cout<< mapNodes.at(i).getType();
}
*/
cout << "Timestamp: " << timesteps << endl;
cout << "Refresh rate: " << refresh << endl;

rowCount.clear();
mapNodes.clear();
initialZone.clear();



return 0;

}