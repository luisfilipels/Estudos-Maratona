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

ll oddFunction(ll n) {
    return (3l * n) + 1l;
}

ll evenFunction(ll n) {
    return n/2l;
}

int main() {
    Fast;

    ll n;
    cin >> n;

    ll count = 0;
    while (n != 1) {
        count++;
        if (n % 2 == 0) {
            n = evenFunction(n);
        } else {
            n = oddFunction(n);
        }
    }

    cout << count;


}