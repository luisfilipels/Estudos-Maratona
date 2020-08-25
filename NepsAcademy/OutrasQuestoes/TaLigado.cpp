//
// Created by luisf on 24/08/2020.
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

    unordered_map<int, unordered_set<int>> adjList;

    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 0) {
            cout << (adjList[a].count(b) != 0 ? 1 : 0) << endl;
        } else {
            adjList[a].insert(b);
            adjList[b].insert(a);
        }
    }
}