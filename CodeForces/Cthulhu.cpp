//
// Created by luisf on 28/08/2020.
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

    unordered_set<int> nonVisited;

    for (int i = 0; i < n; i++) {
        nonVisited.insert(i);
    }

    unordered_map<int, vector<int>> adjList;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x-1].pb(y-1);
        adjList[y-1].pb(x-1);
    }

    queue<pair<int,int>> queue;
    queue.push(mp(*nonVisited.begin(), -1));
    bool foundCycle = false;
    while (!queue.empty()) {
        int element = queue.front().first;
        int previous = queue.front().second;
        queue.pop();
        nonVisited.erase(element);
        for (int neighbor : adjList[element]) {
            if (neighbor == previous) continue;
            if (nonVisited.count(neighbor) != 0) {
                queue.push(mp(neighbor, element));
            }
            else foundCycle = true;
        }
    }

    if (foundCycle && nonVisited.empty()) {
        cout << "FHTAGN!";
    } else {
        cout << "NO";
    }

}