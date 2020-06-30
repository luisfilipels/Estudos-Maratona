//
// Created by luisf on 29/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

#define MAXN 10001

/*
 * Não há necessidade de ordenar os elementos de l a r nessa questão. De fato, fazer isso resulta em TLE.
 * Para resolver essa questão, pense no exemplo seguinte:
 *
 * idx= 1 2 3 4 5 6
 * arr= 1 4 3 2 5 6
 *
 * Digamos que l = 2, r = 5 e x = 5. Quantos números anteriores a arr[x] existem entre l e r? Existem 3 de tais números (4, 3, 2).
 * Se, em hipótese, ordenarmos arr, teremos:
 *
 * idx = 1 2 3 4 5 6
 * arr = 1 2 3 4 5 6
 *
 * Depois da ordenação, permanece havendo os números (4, 3, 2), ou seja, 3 números antes de arr[x], com isso, podemos concluir que arr[x] não mudou de posição.
 * E se x = 2? Antes de ordenarmos, vemos que não há número anterior a 4 nesse intervalo (4 já é o primeiro número). E depois da ordenação? Agora existem 2 números
 * antes de 4 nesse intervalo, o que nos leva a concluir que o 4 mudou de posição.
 */

int main() {
    Fast;
    
    int n, m;
    cin >> n >> m;

    array<int,MAXN> arr{};

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        int less = 0;
        int val = arr[x];
        for (int j = l; j <= r; j++) {
            if (arr[j] < val) {
                less++;
            }
        }
        if (less == x - l) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}