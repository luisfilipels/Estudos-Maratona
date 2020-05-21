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

    int maiorSeq = 0;
    int seqAtual = 0;
    int *ultimo = nullptr;

    for (int i = 0; i < N; i++) {
        int atual;
        cin >> atual;
        if (ultimo == nullptr) {
            ultimo = new int;
            *ultimo = atual;
            seqAtual = 1;
            maiorSeq = 1;
        } else {
            if (atual == *ultimo) {
                seqAtual++;
                maiorSeq = max(maiorSeq, seqAtual);
            } else {
                *ultimo = atual;
                seqAtual = 1;
                maiorSeq = max(maiorSeq, seqAtual);
            }
        }
    }

    cout << maiorSeq;
}