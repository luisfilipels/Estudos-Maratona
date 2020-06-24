//
// Created by luisf on 23/06/2020.
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

    ll n;

    cin >> n;

    string gabarito;
    cin >> gabarito;

    string respostas;
    cin >> respostas;

    int acertos = 0;
    for (int i = 0; i < gabarito.length(); i++) {
        if (gabarito[i] == respostas[i]) acertos++;
    }

    cout << acertos;
}