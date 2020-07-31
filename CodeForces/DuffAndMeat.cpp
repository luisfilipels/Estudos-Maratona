//
// Created by Luis Filipe on 7/30/2020.
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

    int n;
    cin >> n;

    int cost = 0;

    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++) {
        int currentNeed;
        int currentPrice;
        cin >> currentNeed;
        cin >> currentPrice;
        if (currentPrice < minPrice) {
            minPrice = currentPrice;
        }
        cost += minPrice * currentNeed;
    }
    cout << cost;
}