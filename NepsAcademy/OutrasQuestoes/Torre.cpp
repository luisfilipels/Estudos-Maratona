//
// Created by luisf on 01/07/2020.
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

    ll tabuleiro[n][n];
    ll somaLinhas[n];
    ll somaColunas[n];

    memset(somaLinhas, 0, sizeof(ll) * n);
    memset(somaColunas, 0, sizeof(ll) * n);

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < n; c++) {
            cin >> tabuleiro[l][c];
            somaLinhas[l] += tabuleiro[l][c];
            somaColunas[c] += tabuleiro[l][c];
        }
    }

    ll maxVal = 0;

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < n; c++) {
            maxVal = max(maxVal, somaLinhas[l] + somaColunas[c] - (2 * tabuleiro[l][c]));
        }
    }

    cout << maxVal;

}