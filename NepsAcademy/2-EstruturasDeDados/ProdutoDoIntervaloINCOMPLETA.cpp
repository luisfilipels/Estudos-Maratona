//
// Created by luisf on 18/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

void construirArvore (int arvore[], int arr[], int atual, int comeco, int fim) {
    if (comeco == fim) {
        arvore[atual] = arr[comeco];
    } else {
        int meio = (comeco + fim)/2;
        int esq = atual*2;
        int dir = (atual*2)+1;
        construirArvore(arvore, arr, esq, comeco, meio);
        construirArvore(arvore, arr, dir, meio+1, fim);
        int noEsq = arvore[esq];
        int noDir = arvore[dir];
        if (noDir == 0 || noEsq == 0) {
            arvore[atual] = 0;
        } else if ((noEsq > 0 && noDir < 0) || (noEsq < 0 && noDir > 0)) {
            arvore[atual] = -1;
        } else {
            arvore[atual] = 1;
        }
    }
}

void atualizarArvore(int arvore[], int atual, int comeco, int fim, int pos, int novo_valor) {
    if (comeco == fim) {
        arvore[atual] = novo_valor;
    } else {
        int meio = (comeco + fim)/2;
        int esq = atual*2;
        int dir = (atual*2)+1;
        if (pos <= meio) {
            atualizarArvore(arvore, esq, comeco, meio, pos, novo_valor);
        } else {
            atualizarArvore(arvore, dir, meio+1, fim, pos, novo_valor);
        }
        int noEsq = arvore[esq];
        int noDir = arvore[dir];
        if (noDir == 0 || noEsq == 0) {
            arvore[atual] = 0;
        } else if ((noEsq > 0 && noDir < 0) || (noEsq < 0 && noDir > 0)) {
            arvore[atual] = -1;
        } else {
            arvore[atual] = 1;
        }
    }
}

int consultarArvore(int arvore[], int atual, int comeco, int fim, int A, int B) {
    if (A <= comeco && fim <= B) {
        return arvore[atual];
    }
    if (comeco > B || fim < A) {
        return INT_MIN;
    }
    int esq = atual*2;
    int dir = (atual*2) + 1;
    int meio = (comeco + fim)/2;

    int resposta_esquerda = consultarArvore(arvore, esq, comeco, meio, A, B);
    int resposta_direita = consultarArvore(arvore, dir, meio+1, fim, A, B);

    if (resposta_direita == INT_MIN) return resposta_esquerda;
    if (resposta_esquerda == INT_MIN) return resposta_direita;

    if (resposta_direita == 0 || resposta_esquerda == 0) {
        return 0;
    } else if ((resposta_esquerda > 0 && resposta_direita < 0) || (resposta_esquerda < 0 && resposta_direita > 0)) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k; // Numero de elementos, numero de rodadas

    while (cin >> n >> k) {
        int nums[n];
        int arvore[n*4];

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        construirArvore(arvore, nums, 1, 0, n-1);

        string resposta;

        for (int i = 0; i < k;i++) {
            char oper;
            int i1, i2;
            cin >> oper >> i1 >> i2;

            if (oper == 'C') {
                atualizarArvore(arvore, 1, 0, n-1, i1-1, i2);
            } else {
                int resp = consultarArvore(arvore, 1, 0, n-1, i1-1, i2-1);
                if (resp > 0) {
                    resposta += '+';
                } else if (resp < 0) {
                    resposta += '-';
                } else {
                    resposta += '0';
                }
            }
        }

        cout << resposta << endl;
    }

}