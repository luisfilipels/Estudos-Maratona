//
// Created by luisf on 03/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, R;

    cin >> P >> R;

    if (P == 1) {
        if (R == 1) {
            cout << "A";
        } else {
            cout << "B";
        }
    } else {
        cout << "C";
    }

}