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
    

    cout << "Opening file." << endl;
   csvReadIn.open("zone.csv");
   
   if (!csvReadIn.is_open()) {
      cout << "Could not open file." << endl;
      return 1;
   }


  while (!csvReadIn.fail()) {

    getline(csvReadIn, line, ',');

    initialZone.push_back(line);

    getline(csvReadIn, row, '\n');

         rowCount.push_back(row);
     for (int i = 0; i < row.size(); i++){
    if (row[i] == ',') { 
        
        count++;
  rows = rowCount.size();
  zoneNode.SetXCoordinate(count);
  zoneNode.SetYCoordinate(rows);
  mapNodes.push_back(zoneNode);

    }
    
}
    }
        



for (i = 0; i < initialZone.size(); ++i) {
 

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


return 0;

}