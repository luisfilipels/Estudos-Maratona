//
// Created by luisf on 03/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    int bits[N];

    for (int i = 0; i < N; i++) {
        cin >> bits[i];
    }

    int conta = 0;

    for (int i = 2; i < N; i++) {
        if (bits[i] == 0 && bits[i-1] == 0 && bits[i-2] == 1) conta++;
    }

    cout << conta;
}