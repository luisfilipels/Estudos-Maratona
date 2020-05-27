//
// Created by luisf on 26/05/2020.
//

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, kfim, m; // números iniciais, alvo, modulo

    cin >> n >> kfim >> m;

    ll as[n+1];
    for (ll i = 1; i <= n; i++) {
        cin >> as[i];
    }

    ll fs[kfim+1];
    for (ll i = 1; i <= n; i++) {
        cin >> fs[i];
    }

    for (ll k = n+1; k <= kfim; k++) {
        ll sum = 0;
        for (ll i = 1; i <= n; i++) {
            sum += as[i] * fs[k-i];
        }
        fs[k] = sum % m;
    }

    cout << fs[kfim] % m;
}