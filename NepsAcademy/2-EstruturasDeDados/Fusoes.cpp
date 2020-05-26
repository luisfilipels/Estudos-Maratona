//
// Created by luisf on 15/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int achar(int donos[], int banco) {
    int raiz = banco;

    while (raiz != donos[raiz]) {
        raiz = donos[raiz];
    }

    while (banco != raiz) { // Compressão de caminho
        int prox = donos[banco];
        donos[banco] = raiz;
        banco = prox;
    }

    return raiz;
}

void unir(int donos[], int banco1, int banco2) {
    int donoBanco1 = achar(donos, banco1);
    int donoBanco2 = achar(donos, banco2);

    if (donoBanco1 == donoBanco2)
        return;

    donos[donoBanco1] = donoBanco2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; // n: bancos, k: operacoes

    cin >> n >> k;

    int bancos [n+1];
    //int pesos [n+1];

    for (int i = 1; i <= n; i++) {
        bancos[i] = i;
    }

    vector<string> respostas;

    for (int i = 0; i < k; i++) {
        char oper;
        int banco1, banco2;

        cin >> oper >> banco1 >> banco2;

        if (oper == 'C') {
            int donoBanco1 = achar(bancos, banco1);
            int donoBanco2 = achar(bancos, banco2);
            if (donoBanco1 == donoBanco2) {
                respostas.push_back("S");
            } else {
                respostas.push_back("N");
            }
        } else {
            unir(bancos, banco1, banco2);
        }
    }

    for (string resposta : respostas) {
        cout << resposta << "\n";
    }


}
