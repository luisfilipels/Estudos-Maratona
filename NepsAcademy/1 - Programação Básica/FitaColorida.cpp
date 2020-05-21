//
// Created by luisf on 04/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    int fita[N];

    int esqDir[N];
    int dirEsq[N];

    for (int i = 0; i < N; i++) {
        cin >> fita[i];
    }

    for (int i = 0; i < N; i++) {
        esqDir[i] = INT_MAX;
        dirEsq[i] = INT_MAX;
    }

    bool firstZero = false;
    for (int i = 0; i < N; i++) {
        if (fita[i] == 0) {
            esqDir[i] = 0;
            firstZero = true;
        } else {
            if (firstZero && fita[i] != 0) {
                esqDir[i] = esqDir[i-1] + 1;
            }
        }
    }

    firstZero = false;
    for (int i = N-1; i >= 0; i--) {
        if (fita[i] == 0) {
            dirEsq[i] = 0;
            firstZero = true;
        } else {
            if (firstZero && fita[i] != 0) {
                dirEsq[i] = dirEsq[i+1] + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        fita[i] = min(dirEsq[i], esqDir[i]);
    }

    /*bool foundPeak = true;
    for (int i = N-1; i >= 0; i--) {
        if (foundPeak) {
            if (fita[i] == 0) {
                foundPeak = false;
            }
        } else {
            if (fita[i] == fita[i+1] + 1 || fita[i] == fita[i+1]) {
                foundPeak = true;
            } else {
                fita[i] = fita[i+1] + 1;
            }
        }
    }*/

    for (int i = 0; i < N; i++) {
        if (fita[i] > 9) fita[i] = 9;
    }

    for (int i : fita) {
        cout << i << " ";
    }
}