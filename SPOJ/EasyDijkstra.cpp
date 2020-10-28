//
// Created by luisf on 27/10/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

struct Vertex {
    int id;

    vector<pair<int,int>> edges; // First: destination. Second: weight
};

int main() {
    int tests;

    cin >> tests;

    for (int t = 0; t < tests; t++) {
        int v, e;
        unordered_map<int, Vertex> map;
        for (int i = 1; i <= v; i++) {
            Vertex toAdd;
            toAdd.id = i;
            map.insert(mp(i, toAdd));
        }

        for (int i = 0; i < e; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            map[a].edges.emplace_back(mp(b, c));
        }

        int origin, dest;
        cin >> origin >> dest;

        priority_queue<pair<int, int>> pq;   // cost, vertex
        unordered_set<int> visited;
        int costs[v+1];
        for (int i = 1; i <= v; i++) {
            costs[i] = INT_MAX-100;
        }
        costs[origin] = 0;
        pq.push({0, origin});

        while (!pq.empty()) {
            Vertex current = map[pq.top().second];
            pq.pop();

            if (visited.count(current.id) != 0) continue;
            visited.insert(current.id);

            int currDistance = costs[current.id];

            for (int i = 0; i < current.edges.size(); i++) {
                pair<int,int> currentNeighbor = current.edges[i];
                int desti = currentNeighbor.first;
                int cost = currentNeighbor.second;

                if (currDistance + cost < costs[desti]) {
                    costs[desti] = currDistance + cost;
                    pq.push(mp(-costs[desti], desti));
                }
            }
        }

        cout << costs[dest];
    }
}