//
// Created by Luis Filipe on 8/26/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

ll gcd (ll a, ll b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    Fast;

    ll n, m;
    cin >> n >> m;

    ll x = m;
    while (gcd(x, n) > 1) {
        x--;
    }

    cout << x;

}