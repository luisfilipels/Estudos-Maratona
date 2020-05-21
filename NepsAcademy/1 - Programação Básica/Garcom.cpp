//
// Created by luisf on 03/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    int quebrados = 0;

    for (int i = 0; i < N; i++) {
        int L, C;
        cin >> L >> C;
        if (L > C) {
            quebrados += C;
        }
    }
    cout << quebrados;
}