//
// Created by luisf on 05/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    int quadrado[N][N];

    for (int l = 0; l < N; l++) {
        for (int c = 0; c < N; c++) {
            cin >> quadrado[l][c];
        }
    }

    int referencia = 0;

    for (int c = 0; c < N; c++) {
        referencia += quadrado[0][c];
    }

    for (int l = 1; l < N; l++) {
        int linhaAtual = 0;
        for (int c = 0; c < N; c++) {
            linhaAtual += quadrado[l][c];
        }
        if (linhaAtual != referencia) {
            cout << -1;
            exit(0);
        }
    }

    for (int c = 0; c < N; c++) {
        int colunaAtual = 0;
        for (int l = 0; l < N; l++) {
            colunaAtual += quadrado[l][c];
        }
        if (colunaAtual != referencia) {
            cout << -1;
            exit(0);
        }
    }

    int diagPrincipal = 0;
    for (int d = 0; d < N; d++) {
        diagPrincipal += quadrado[d][d];
    }
    if (diagPrincipal != referencia) {
        cout << -1;
        exit(0);
    }

    int diagSecundaria = 0;
    for (int d = 0; d < N; d++) {
        diagSecundaria += quadrado[d][N-d-1];
    }
    if (diagSecundaria != referencia) {
        cout << -1;
        exit(0);
    }

    cout << referencia;
}