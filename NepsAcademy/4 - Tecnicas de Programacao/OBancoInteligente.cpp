//
// Created by luisf on 28/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

const int N = 6;
const int S = 5001;

int valores[] = {2, 5, 10, 20, 50, 100};
int quant[N];
int dp[S];
int s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < 6; i++) {
        cin >> quant[i];
    }

    dp[0] = 1;
    for (int moedaAtual = N-1; moedaAtual >= 0; moedaAtual--) {
        //Vamos tentar adicionar moedas começando da de mais alto valor.
        for (int somaAtual = s; somaAtual >= 0; somaAtual--) {
            // Vamos começar obtendo valores de soma a partir da soma s, para cada uma das moedas que tentarmos adicionar.
            for (int moedaAtualUsadas = 1; moedaAtualUsadas <= quant[moedaAtual] && somaAtual - moedaAtualUsadas * valores[moedaAtual] >= 0; moedaAtualUsadas++) {
                // Vamos adicionar uma quantidade da moeda atual que não exceda o máximo de moedas disponíveis, e que
                // não execeda o valor de somaAtual.
                dp[somaAtual] += dp[somaAtual - moedaAtualUsadas * valores[moedaAtual]];
                /*
                 * Acrescentamos em dp[moedaAtual] o número de maneiras com que se pode somar o valor de somaAtual - moedaAtualUsadas * valores[moedaAtual].
                 * Se estamos com moedaAtualUsadas moedas de valor valores[moedaAtual], dp[moedaAtual] deve receber o número de maneiras com que podemos somar
                 * o valor de somaAtual - moedaAtualUsadas * valores[moedaAtual], pois teremos na prática, o número de maneiras com que podemos somar esse valor,
                 * sem considerar as moedas que estão sendo adicionadas como sendo uma nova maneira.
                 * Por exemplo, para quant = [6 1 1 1 0 0], s = 12, moedaAtual = 1 (ou seja, moeda 5), somaAtual = 7 e moedaAtualUsadas = 1,
                 * o número de maneiras com que podemos somar somaAtual é o número de maneiras com que podemos somar 7 - (1 * 5) = 2. Ou seja,
                 * para somarmos 7, usamos o número de maneiras com que podemos somar 2, mais uma moeda de 5.
                 */
            }
        }
    }

    cout << dp[s];

}