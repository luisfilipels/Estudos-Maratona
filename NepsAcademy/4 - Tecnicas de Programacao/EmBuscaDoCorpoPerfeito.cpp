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

#define MAXN 2001   // Maximo de pedacos

ll pesos[MAXN];
ll valores[MAXN];

ll dp[MAXN][MAXN];

ll p, n; // Quanto aguenta comer, quantos pedacos existem

ll max (ll x, ll y) {
    if (x > y) {
        return x;
    }
    return y;
}

ll knapsack (ll obj, ll aguenta) {

    if (dp[obj][aguenta] != -1) {
        return dp[obj][aguenta];
    }

    if (aguenta <= 0 || obj == n) {
        dp[obj][aguenta] = 0;
        return 0;
    }

    ll naoPega = knapsack(obj+1, aguenta);

    if (aguenta - pesos[obj] >= 0) {
        ll pega = valores[obj] + knapsack(obj + 1, aguenta - pesos[obj]);

        dp[obj][aguenta] = max(naoPega, pega);
        return dp[obj][aguenta];
    }

    dp[obj][aguenta] = naoPega;
    return naoPega;

}

int main() {
    Fast;

    memset(dp, -1, sizeof(dp));

    cin >> p >> n;

    for (ll i = 0; i < n; i++) {
        cin >> pesos[i];
        cin >> valores[i];
    }

    cout << knapsack(0, p);
}