//
// Created by luisf on 12/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string codigo = "";
    int n;

    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string linha;
        getline(cin, linha);
        codigo += linha;
    }

    int conta = 0;
    for (char c : codigo) {
        if (c == '{' || c == '}') {
            if (conta == 0) {
                if (c == '{') {
                    conta++;
                } else {
                    conta--;
                    break;
                }
            } else {
                if (c == '{') {
                    conta++;
                } else {
                    conta--;
                    if (conta < 0) {
                        break;
                    }
                }
            }
        }
    }
    if (conta == 0) {
        cout << "S";
    } else {
        cout << "N";
    }
}