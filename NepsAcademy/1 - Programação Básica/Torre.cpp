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

    int tabuleiro[N][N];

    int somaLinha[N];
    fill(somaLinha, somaLinha+sizeof(somaLinha)/sizeof(int), 0);

    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            cin >> tabuleiro[l][c];
            somaLinha[l] += tabuleiro[l][c];
        }
    }

    int somaColuna[N];
    fill(somaColuna, somaColuna+sizeof(somaColuna)/sizeof(int), 0);

    for (int c = 0; c < N; c++) {
        for (int l = 0; l < N; l++) {
            somaColuna[c] += tabuleiro[l][c];
        }
    }

    int maxSum = 0;

    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            maxSum = max(maxSum, somaLinha[l] + somaColuna[c] - tabuleiro[l][c] - tabuleiro[l][c]);
        }
    }

    cout << maxSum;
}