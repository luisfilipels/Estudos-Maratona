//
// Created by Luis Filipe on 6/23/2021.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

const int MAX_N = 100000;
ll vecA[MAX_N];
ll vecB[MAX_N];

void count(ll n, ll m) {

    unordered_map<ll, ll> countA;
    unordered_map<ll, ll> countB;

    for (int i = 0; i < n; i++) {
        ll currentNum = vecA[i];
        if (countA.count(currentNum) > 0) {
            countA[currentNum] = countA[currentNum] + 1;
        } else {
            countA[currentNum] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        ll currentNum = vecB[i];
        if (countB.count(currentNum) > 0) {
            countB[currentNum] = countB[currentNum] + 1;
        } else {
            countB[currentNum] = 1;
        }
    }

    ll count = 0;

    for (auto const& x : countA) {
        if (countB.count(x.first) > 0) {
            count += (x.second * countB[x.first]);
        }
    }

    cout << count;

    /*ll count = 0;
    int currentNumber;
    while (i < N && j < m) {
        currentNumber = min(vecA[i], vecB[j]);
        int startA = i, startB = j;
        while (i < N && vecA[i] == currentNumber) {
            i++;
        }
        while (j < m && vecB[j] == currentNumber) {
            j++;
        }
        count += (ll)((i - startA) * (j - startB));
    }
    cout << count;*/
}

int main() {
    Fast;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> vecA[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vecB[i];
    }

    count(n, m);
}