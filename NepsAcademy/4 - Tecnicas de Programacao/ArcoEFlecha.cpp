//
// Created by luisf on 02/06/2020.
//

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll mergeSortInversions(vector<ll> &v) {
    if (v.size() == 1) return 0;

    vector<ll> leftHalf, rightHalf;

    ll inversoes = 0;

    for (int i = 0; i < v.size()/2; i++) {
        leftHalf.push_back(v[i]);
    }
    for (int i = v.size()/2; i < v.size(); i++) {
        rightHalf.push_back(v[i]);
    }

    inversoes += mergeSortInversions(leftHalf);
    inversoes += mergeSortInversions(rightHalf);

    leftHalf.push_back(LONG_LONG_MIN);
    rightHalf.push_back(LONG_LONG_MIN);

    int i = 0, j = 0;

    for (int k = 0; k < v.size(); k++) {
        if (leftHalf[i] <= rightHalf[j]) {
            v[k] = rightHalf[j++];
            inversoes += leftHalf.size() - i - 1;
        } else {
            v[k] = leftHalf[i++];
        }
    }

    return inversoes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    ll penalty = 0;

    vector<ll> v;
    ll x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ll dist = (x*x) + (y*y);
        v.push_back(dist);
    }

    penalty = mergeSortInversions(v);

    cout << penalty;

    return 0;
}