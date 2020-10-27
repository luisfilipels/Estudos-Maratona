//
// Created by Luis Filipe on 10/26/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int main() {
    Fast;

    string from, to;
    cin >> from >> to;

    int startRow = from[1] - '1';
    int startCol = from[0] - 'a';

    int endRow = to[1] - '1';
    int endCol = to[0] - 'a';

    /*
     * a8 -> h1
     * startRow = 7 (fileira de cima)    startCol = 0 (primeira coluna)
     * endRow = 0   (fileira de baixo)   endCol = 7   (ultima coluna)
     */

    bool goingDown = startRow > endRow ? true : false;
    bool goingRight = startCol < endCol ? true : false;

    int countDiags = min(abs(startCol - endCol), abs(startRow - endRow));
    int countVertiHori = max(abs(startCol - endCol), abs(startRow - endRow)) - countDiags;

    cout << countDiags + countVertiHori << endl;

    string diagMovement;
    int difRow;
    int difCol;
    if (goingDown) {
        if (goingRight) {
            diagMovement = "RD";
            difRow = -1;
            difCol = 1;
        } else {
            diagMovement = "LD";
            difRow = -1;
            difCol = -1;
        }
    } else {
        if (goingRight) {
            diagMovement = "RU";
            difRow = 1;
            difCol = 1;
        } else {
            diagMovement = "LU";
            difRow = 1;
            difCol = -1;
        }
    }
    for (int i = 0; i < countDiags; i++) {
        cout << diagMovement << endl;
    }
    startRow += (countDiags * difRow);
    startCol += (countDiags * difCol);

    string movement;

    if (startRow == endRow) {
        if (goingRight) {
            movement = "R";
        } else {
            movement = "L";
        }
    } else {
        if (goingDown) {
            movement = "D";
        } else {
            movement = "U";
        }
    }
    for (int i = 0; i < countVertiHori; i++) {
        cout << movement << endl;
    }

}