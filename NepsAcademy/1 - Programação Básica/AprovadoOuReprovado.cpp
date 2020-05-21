//
// Created by luisf on 03/05/2020.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double A, B;
    cin >> A >> B;

    double media = (A + B)/2;

    if (media >= 7) {
        cout << "Aprovado";
    } else if (media < 7 && media >= 4) {
        cout << "Recuperacao";
    } else {
        cout << "Reprovado";
    }

    return 0;
}
