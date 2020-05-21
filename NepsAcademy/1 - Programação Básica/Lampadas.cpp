//
// Created by luisf on 03/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool i1 = false, i2 = false;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int lido;
        cin >> lido;
        if (lido == 1) {
            i1 = !i1;
        } else {
            i1 = !i1;
            i2 = !i2;
        }
    }
    cout << (i1 ? 1 : 0) << "\n";
    cout << (i2 ? 1 : 0) << "\n";
}