//
// Created by luisf on 09/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int main() {
    Fast;

    string input;

    cin >> input;

    vector<int> pilha;

    for (int i = 0; i < input.length(); i++) {
        vector<int>::iterator it = upper_bound(pilha.begin(), pilha.end(), input[i]);

        if(it==pilha.end()) pilha.pb(input[i]);

        // porém, se it apontar para alguma posição válida do vector
        // colocamos v[i] no topo desta pilha, substintuindo o valor que it aponta por v[i]
        else *it = input[i];
    }

    cout << pilha.size();
}