//
// Created by luisf on 11/06/2020.
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

    ll n, k, l, c, d, p, nl, np;
    // n: amigos
    // k: garrafas
    // l: conteudo de cada garrafa, em ml
    // c: numero de limoes
    // d: numero de fatias por limao
    // p: gramas de sal
    // nl:ml necessario para uma fatia
    // np:gramas de p necessario para uma fatia

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    ll maxLiquid = (k * l) / nl;
    ll slices = c * d;
    ll salt = p / np;

    ll result = min(min(maxLiquid, slices), salt) / n;

    cout << result;
}