//
// Created by luisf on 03/07/2020.
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

    ll n, l;
    cin >> n >> l;

    ll arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    ll maxDif = 0;
    for (int i = 1; i < n; i++) {
        maxDif = max(maxDif, arr[i] - arr[i-1]);
    }

    double dif = (double) maxDif / 2;

    double difLeft;
    if (arr[0] != 0) {
        difLeft = arr[0];
    } else {
        difLeft = INT_MAX;
    }

    double difRight;
    if (arr[n-1] != l) {
        difRight = l - arr[n-1];
    } else {
        difRight = INT_MAX;
    }

    cout.precision(10);

    if (difLeft != INT_MAX && difRight != INT_MAX) {
        cout << fixed << max(max(difLeft, difRight), dif);
    } else if (difLeft != INT_MAX) { //difright = max
        cout << fixed << max(difLeft, dif);
    } else if (difRight != INT_MAX){
        cout << fixed << max(difRight, dif);
    } else {
        cout << fixed << dif;
    }


}