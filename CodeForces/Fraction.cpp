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

bool isIrreducible (ll num, ll den) {
    for (ll i = 2; i <= num; i++) {
        if (num % i == 0 && den % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    Fast;

    ll n;
    cin >> n;

    ll answer = 1;

    for (ll i = 1; i <= n/2; i++) {
        ll num = i;
        ll den = n-i;
        if (isIrreducible(num,den)) {
            answer = max(answer, num);
        }
    }

    cout << answer << " " << n - answer;

    return 0;
}