//
// Created by luisf on 21/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;

    cin >> n >> m;

    long long conta = 0;

    long long anterior = 0;

    for (int i = 0; i < n; i++) {
        long long atual;
        cin >> atual;

        long long maximum, minimum;

        maximum = max(atual, m - atual);
        minimum = min(atual, m - atual);

        if (minimum >= anterior) {  // Tentamos usar o minimo primeiro, pois a questão quer a menor das sequências possíveis
            conta += minimum;
            anterior = minimum;
        }

        if (minimum < anterior && maximum >= anterior){
            conta += atual;
            anterior = atual;
        }

        if (maximum < anterior) {   // A cada novo mergulho, pelo menos a mesma distância do mergulho anterior foi explorada
            conta = -1;
            break;
        }
    }

    cout << conta;
}