//
// Created by luisf on 22/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    int faixas[n];

    faixas[0] = 0;
    for (int i = 1; i < n; i++) { // Ler faixas
        cin >> faixas[i];
    }

    int pontos[n];

    for (int i = 0; i < n; i++) { // Ler pontos por faixa
        cin >> pontos[i];
    }

    for (int i = 0; i < m; i++) { // Ler pontuação de cada ogro
        int atual;
        cin >> atual;
        int inicio = 0, fim = n;
        if (atual >= faixas[n-1]) {
            cout << pontos[n-1] << " ";
            continue;
        }
        while (inicio < fim - 1) {
            int meio = inicio + ((fim - inicio)/2);
            if (faixas[meio] <= atual) {
                inicio = meio;
            } else {
                fim = meio;
            }
        }
        cout << pontos[fim-1] << " ";

        // Com busca linear (ainda é aceito):
        /*for (int j = 0; j < n; j++) {
            if (atual >= faixas[j] && atual < faixas[j+1]) {
                cout << pontos[j] << " ";
                break;
            }
        }*/
    }


}