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
    vector <string> initialZone;
    string line;
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

    cout << "Opening file." << endl;
   csvReadIn.open("zone.csv");
   
   if (!csvReadIn.is_open()) {
      cout << "Could not open file." << endl;
      return 1;
   }

getline(csvReadIn, row, '\n');
for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 

        comma++;
        }
}

cout << comma << endl;

  while (!csvReadIn.fail()) {
    getline(csvReadIn, line, ',');

    initialZone.push_back(line);

    getline(csvReadIn, row, '\n');
         rowCount.push_back(row);

     for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 
        
        count++;
  zoneNode.SetXCoordinate(count);
    }

    }
    

    }
        



for (i = 0; i < initialZone.size(); ++i) {
    rows = rowCount.size();
  x = i%comma;
  y = comma%i;
  mapNodes.at(i).SetYCoordinate(i%comma);
 

cout << initialZone.at(i) << endl;

temp = initialZone.at(i);

 if(temp == "-"){
mapNodes.at(i).setType('-');
}
 
if(temp == "P"){
mapNodes.at(i).setType('P');
}

if(temp == "T"){
mapNodes.at(i).setType('T');
}

if(temp == "I"){
mapNodes.at(i).setType('I');
}

if(temp == "R"){
mapNodes.at(i).setType('R');
}
if(temp == "C"){
mapNodes.at(i).setType('C');
}

if(temp == "#"){
mapNodes.at(i).setType('#');
}

}

for(i=0; i<mapNodes.size(); ++i){
cout<< mapNodes.at(i).GetXCoordinate() << mapNodes.at(i).GetYCoordinate() << endl;
cout<< mapNodes.at(i).getType() << endl;
}

csvReadIn.close();
initialZone.clear();
mapNodes.clear();
rowCount.clear();

return 0;

}