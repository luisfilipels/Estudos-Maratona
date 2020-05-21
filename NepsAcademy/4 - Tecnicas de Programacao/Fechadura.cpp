//
// Created by luisf on 20/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; // pinos, altura

    cin >> n >> m;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int movimentos = 0;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] != m) {
            int dif = arr[i] - m;
            arr[i] = arr[i] - dif;
            arr[i+1] = arr[i+1] - dif;
            movimentos += abs(dif);
        }
    }

    cout << movimentos;
}