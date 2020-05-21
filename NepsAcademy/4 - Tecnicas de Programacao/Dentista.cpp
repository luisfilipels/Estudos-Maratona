//
// Created by luisf on 20/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

struct Compromisso {
    int inicio;
    int fim;
};

bool comparaCompromisso (Compromisso a, Compromisso b) {
    return a.fim < b.fim;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; // numero de consultas

    cin >> n;

    Compromisso compromissos[n];

    for (int i = 0; i < n; i++) {
        cin >> compromissos[i].inicio >> compromissos[i].fim;
    }

    sort(compromissos, compromissos+n, comparaCompromisso);

    int horarioLivre = 0;

    int conta = 0;

    for (int i = 0; i < n; i++) {
        if (compromissos[i].inicio >= horarioLivre) {
            conta++;
            horarioLivre = compromissos[i].fim;
        }
    }

    cout << conta;

}