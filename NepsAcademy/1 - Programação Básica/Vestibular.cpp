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

    string gabarito, respostas;

    cin >> gabarito >> respostas;

    int acertos = 0;
    for (int i = 0; i < N; i++) {
        acertos += gabarito[i] == respostas[i] ? 1 : 0;
    }

    cout << acertos;

}