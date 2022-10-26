#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "zonenode.h"
#include <cstring>

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
       
        cout << row.size();
      
        }

rows = rowCount.size();

for (i = 0; i < initialZone.size(); ++i) {
 
zoneNode.SetXCoordinate(i);
zoneNode.SetYCoordinate(i);
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

cout<< mapNodes.at(6).GetXCoordinate() << mapNodes.at(6).GetYCoordinate() << endl;
cout<< mapNodes.at(6).getType() << endl;

csvReadIn.close();

cout << rows << endl;
//cout << mapNodes.at(6) << endl;

return 0;

}