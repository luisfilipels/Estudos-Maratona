//
// Created by luisf on 23/06/2020.
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

    int n;
    cin >> n;

    int squared = n * n;

    int quadrado[n][n];

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < n; c++) {
            cin >> quadrado[l][c];
        }
    }

    int sum = 0;
    for (int c = 0; c < n; c++) {
        sum += quadrado[0][c];
    }

    for (int l = 0; l < n; l++) {
        int currSum = 0;
        for (int c = 0; c < n; c++) {
            currSum += quadrado[l][c];
        }
        if (currSum != sum) {
            cout << -1;
            return 0;
        }
    }

    for (int c = 0; c < n; c++) {
        int currSum = 0;
        for (int l = 0; l < n; l++) {
            currSum += quadrado[l][c];
        }
        if (currSum != sum) {
            cout << -1;
            return 0;
        }
    }

    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += quadrado[i][i];
    }
    if (currSum != sum) {
        cout << -1;
        return 0;
    }

    currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += quadrado[i][n-i-1];
    }
    if (currSum != sum) {
        cout << -1;
        return 0;
    }

    cout << sum;

}