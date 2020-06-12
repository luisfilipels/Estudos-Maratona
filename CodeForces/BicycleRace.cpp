//
// Created by luisf on 11/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

enum Direction {
    NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3
};

int main() {
    Fast;

    int n; // Secoes retas
    cin >> n;

    int count = 0;

    Direction current = NORTH;
    int prevX, prevY;

    cin >> prevX >> prevY;

    for (int i = 1; i < n + 1; i++) {
        int x, y;
        cin >> x >> y;
        int vertical = y - prevY;
        int horizontal = x - prevX;
        prevX = x;
        prevY = y;
        Direction prev = current;
        if (vertical > 0) {
            current = NORTH;
        } else if (vertical < 0) {
            current = SOUTH;
        } else if (horizontal > 0) {
            current = EAST;
        } else {
            current = WEST;
        }
        if ((prev == EAST && current == NORTH) || (prev == NORTH && current == WEST) || (prev == WEST && current == SOUTH) || (prev == SOUTH && current == EAST)) {
            count++;
        }
    }

    cout << count;

}