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
        



for (i = 0; i < initialZone.size(); ++i) {
  x = i;
  y = i;
  zoneNode.SetYCoordinate(y);
  zoneNode.SetXCoordinate(x);
 

cout << initialZone.at(i) << endl;

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

for(i=0; i<mapNodes.size(); ++i){
cout<< mapNodes.at(i).GetXCoordinate() << mapNodes.at(i).GetYCoordinate() << endl;
cout<< mapNodes.at(i).getType() << endl;
}


rowCount.clear();
mapNodes.clear();
initialZone.clear();

csvReadIn.close();

return 0;

}