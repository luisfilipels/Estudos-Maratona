//
// Created by Luis Filipe on 7/5/2021.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

ll w, h, n;

bool good(ll mid) {
    return (mid / w) * (mid / h) >= n;
}

int main() {
    Fast;

    cin >> w >> h >> n;

    ll start = 0;
    ll end = 1;
    while (!good(end)) end *= 2;

    while (end > start + 1) {
        ll mid = start + (end - start)/2;

        if (good(mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }

    cout << end;
}