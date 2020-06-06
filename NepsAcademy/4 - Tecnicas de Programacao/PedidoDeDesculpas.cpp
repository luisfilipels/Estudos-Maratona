//
// Created by luisf on 05/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

#define MAXF 1010

ll comp[MAXF];
ll vezes[MAXF];

ll dp[MAXF][MAXF];

ll c, f;

ll max (ll x, ll y) {
    if (x > y) {
        return x;
    }
    return y;
}

ll knapsack (ll fraseAtual, ll espacoSobrando) {

    if (dp[fraseAtual][espacoSobrando] != -1) {
        return dp[fraseAtual][espacoSobrando];
    }

    if (espacoSobrando <= 0 || fraseAtual == f) {
        dp[fraseAtual][espacoSobrando] = 0;
        return 0;
    }

    ll naoColoca = knapsack(fraseAtual+1, espacoSobrando);

    if (espacoSobrando - comp[fraseAtual] >= 0) {
        ll coloca = vezes[fraseAtual] + knapsack(fraseAtual + 1, espacoSobrando - comp[fraseAtual]);

        dp[fraseAtual][espacoSobrando] = max(naoColoca, coloca);
        return dp[fraseAtual][espacoSobrando];
    }

    dp[fraseAtual][espacoSobrando] = naoColoca;
    return naoColoca;

}


int main() {
    Fast;

    int teste = 1;

    while (true) {

        cin >> c >> f; // espaço do cartão, número de frases

        if (c == 0 && f == 0) break;

        memset(dp, -1, sizeof(dp));

        for (ll i = 0; i < f; i++) {
            cin >> comp[i];
            cin >> vezes[i];
        }

        cout << "Teste " << teste++ << endl;
        cout << knapsack(0, c) << endl;
        cout << endl;
    }

    return 0;

}