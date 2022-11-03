#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[20][20] = {0};

void spreadpollution(int p, int x, int y) {
    int centerx = x;
    int centery = y;

    int startx = x;
    int starty = y;

    for(int a = p; a > 0; a--) {
        //Spread left and right columns
        for(int b = starty; b <= starty + 2 * (p - a); b++) {
            if(b >= 0 && b <= 19) {
                if(centerx - (p - a) >= 0 && centerx - (p - a) <= 19)
                    map[centerx - (p - a)][b] += a;
                if(centerx - (p - a) != centerx + p - a && centerx + p - a >= 0 && centerx + p - a <= 19)
                    map[centerx + p - a][b] += a;
            }
        }

        //Spread top and bottom rows
        for(int b = startx + 1; b <= startx + 2 * (p - a) - 1; b++) {
            if(b >= 0 && b <= 19) {
                if(centery - (p - a) >= 0 && centery - (p - a) <= 19)
                    map[b][centery - (p - a)] += a;
                if(centery + p - a >= 0 && centery + p - a <= 19)
                    map[b][centery + p - a] += a;
            }
        }

        startx--;
        starty--;
    }
}

int main() {
    //Choose pollution origin and value
    int pollution, xCoordinate, yCoordinate;
    cout << "Enter X Y coordinates\n";
    cin >> xCoordinate >> yCoordinate;
    cout << "Enter pollution value\n";
    cin >> pollution;

    spreadpollution(pollution, xCoordinate, yCoordinate);
    spreadpollution(pollution, xCoordinate - 1, yCoordinate - 1);

    //Output map
    for(int y = 0; y < 20; y++) {
        for(int x = 0; x < 20; x++) {
            cout << map[x][y] << " ";
        }
        cout << "\n";
    }

    return 0;
}