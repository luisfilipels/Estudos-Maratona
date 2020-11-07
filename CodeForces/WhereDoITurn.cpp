//
// Created by luisf on 06/11/2020.
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

    ll ax, ay, bx, by, cx, cy;

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    ll res = (bx - ax) * (cy - by) - (by - ay) * (cx - bx);

    if (res == 0) {
        cout << "TOWARDS";
    } else if (res < 0) {
        cout << "RIGHT";
    } else {
        cout << "LEFT";
    }
}