//
// Created by luisf on 20/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int moedas[] = {1, 5, 10, 25, 50, 100};
    
    int conta = 0;
    
    int n;
    
    cin >> n;
    
    int moedaAtual = 5;
    
    while (n > 0) {
        if (moedas[moedaAtual] <= n) {
            n -= moedas[moedaAtual];
            conta++;
        } else {
            moedaAtual--;
        }
    }
    
    cout << conta;
}