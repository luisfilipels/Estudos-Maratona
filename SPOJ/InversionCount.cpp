//
// Created by luisf on 04/11/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

ll inversions (vector<ll> &arr) {

    if (arr.size() <= 1)
        return 0;

    ll n = arr.size();

    vector<ll> left;
    vector<ll> right;

    for (ll i = 0; i < n/2; i++) {
        left.push_back(arr[i]);
    }
    for (ll i = n/2, j = 0; i < n; i++, j++) {
        right.push_back(arr[i]);
    }

    ll count = 0;

    count += inversions(left);
    count += inversions(right);

    ll i = 0, j = 0;

    left.push_back(LONG_LONG_MAX);
    right.push_back(LONG_LONG_MAX);

    for (ll k = 0; k < n; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
            count += left.size() - i - 1;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n;
        cin >> n;

        vector<ll> v;

        ll a;
        for (ll i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }

        ll result = inversions(v);

        cout << result << endl;
    }
}