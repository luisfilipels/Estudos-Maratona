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
    int tabuleiro[N];

    for (int i = 0; i < N; i++) {
        cin >> tabuleiro[i];
    }

    int resposta[N];

    if (N >= 2) {
        resposta[0] = 0;
        resposta[0] += tabuleiro[0] == 1 ? 1 : 0;
        if (N >= 2) {
            resposta[0] += tabuleiro[1] == 1 ? 1 : 0;
        }

        for (int i = 1; i < N-1; i++) {
            resposta[i] = 0;
            resposta[i] += tabuleiro[i-1] == 1 ? 1 : 0;
            resposta[i] += tabuleiro[i] == 1 ? 1 : 0;
            resposta[i] += tabuleiro[i+1] == 1 ? 1 : 0;
        }

        resposta[N-1] = 0;
        resposta[N-1] += tabuleiro[N-1] == 1 ? 1 : 0;
        resposta[N-1] += tabuleiro[N-2] == 1 ? 1 : 0;
    } else {
        resposta[0] = 0;
        resposta[0] += tabuleiro[0] == 1 ? 1 : 0;
    }

    for (int i = 0; i < N; i++) {
        cout << resposta[i];
    }



}