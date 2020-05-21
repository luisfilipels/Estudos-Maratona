//
// Created by luisf on 05/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    string atual;

    int conta[10];

    fill(conta, conta+sizeof(conta)/sizeof(int), 0);

    for (int i = 0; i < N; i++) {
        cin >> atual;
        for (char c : atual) {
            conta[c - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << i << " - " << conta[i] << "\n";
    }
}