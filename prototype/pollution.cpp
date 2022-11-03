#include <iostream>

using namespace std;

int map[20][20] = {0};

//Spread of pollution horizontally, helper function for spreadComplete
void spreadHorizontal(int p, int x, int y) {
    int temp = p - 1;
    for(int i = 1; i < p; i++) {
        //Check bounds, then spread right horizontal
        if(x + i >= 0 && x + i <= 19)
            map[y][x + i] += temp;

        //Check bounds, then spread left horizontal
        if(x - i >= 0 && x - i <= 19)
            map[y][x - i] += temp;
        temp--;
    }
}

//Spread of pollution completely
void spreadComplete(int p, int x, int y) {
    //Plot pollution origin
    map[y][x] += p;
    
    //Spread middle horizontal first
    spreadHorizontal(p, x, y);

    //Spread everywhere else
    int temp = p - 1;
    for(int i = 1; i < p; i++) {
        //Check bounds, then spread lower horizontal
        if(y + i >= 0 && y + i <= 19) {
            map[y + i][x] += temp;
            spreadHorizontal(temp, x, y + i);
        }

        //Check bounds, then spread upper horizontal
        if(y - i >= 0 && y - i <= 19) {
            map[y - i][x] += temp;
            spreadHorizontal(temp, x, y - i);
        }

        temp--;
    }
}

int main() {
    //Choose pollution origin and value
    int pollution, xCoordinate, yCoordinate;
    cout << "Enter X Y coordinates\n";
    cin >> xCoordinate >> yCoordinate;
    cout << "Enter pollution value\n";
    cin >> pollution;

    //Do spreading
    spreadComplete(pollution, xCoordinate, yCoordinate);

    //Output map
    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 20; y++) {
            cout << map[x][y] << " ";
        }
        cout << "\n";
    }

    return 0;
}