//
// Created by Luis Filipe on 9/10/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int maxDistance = INT_MIN;
int maxNode = INT_MIN;
unordered_map<int, unordered_set<int>> adjList;
unordered_set<int> visited;

void dfs(int node, int distance) {
    visited.insert(node);
    if (distance > maxDistance) {
        maxDistance = distance;
        maxNode = node;
    }
    for (int x : adjList[node]) {
        if (visited.count(x) == 0) {
            dfs(x, distance+1);
        }
    }
}

int main() {
    Fast;
    int n;
    cin >> n;

    int a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }

    dfs(1, 0);
    maxDistance = -1;
    visited.clear();
    dfs(maxNode, 0);

    cout << maxDistance;
}