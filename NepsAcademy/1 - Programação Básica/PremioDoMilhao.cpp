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

    int soma_acumulada = 0;
    int dias = 0;

    while (soma_acumulada < 1000000) {
        int visitas;
        cin >> visitas;
        soma_acumulada += visitas;
        dias++;
    }

    cout << dias;
}