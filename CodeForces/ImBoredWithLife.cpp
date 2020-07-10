//
// Created by luisf on 09/07/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

ll fact (ll x) {
    for (ll y = x-1; y >= 2; y--) {
        x *= y;
    }
    return x;
}

int main() {
    Fast;

    ll a, b;
    cin >> a >> b;

    ll mini = min(a,b);

    cout << fact(mini);

}