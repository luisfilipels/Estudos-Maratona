//
// Created by luisf on 01/07/2020.
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

    int n, m;

    cin >> n >> m;

    vector<pair<ll, int>> v;

    for (int i = 1; i <= n; i++) {
        pair<ll, int> current;
        current.second = i;
        current.first = 0;
        for (int j = 0; j < m; j++) {
            ll time;
            cin >> time;
            current.first += time;
        }
        v.push_back(current);
    }

    sort(v.begin(), v.end());

    cout << v[0].second << endl << v[1].second << endl << v[2].second;

    return 0;
}