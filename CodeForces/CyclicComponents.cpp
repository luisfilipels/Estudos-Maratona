//
// Created by luisf on 06/11/2020.
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
    unsigned int id;
    unordered_set<Vertex*> neighbors;
};

vector<Vertex*> vertices;

unsigned int n, m;

bool visited[200001];

bool dfs (unsigned vert, bool allHaveTwoNeighbors) {
    if (visited[vert]) return allHaveTwoNeighbors;

    Vertex *v = vertices[vert];
    visited[vert] = true;
    if (v->neighbors.size() != 2) allHaveTwoNeighbors = false;
    for (auto currentNeighbor : v->neighbors) {
        if (!visited[currentNeighbor->id]) {
            allHaveTwoNeighbors = dfs(currentNeighbor->id, allHaveTwoNeighbors) && allHaveTwoNeighbors;
        }
    }
    return allHaveTwoNeighbors;
}

int main() {
    cin >> n >> m;

    for (unsigned int i = 0; i < n; i++) {
        auto *v = new Vertex();
        v->id = i;
        vertices.push_back(v);
    }

    memset(visited, false, n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        vertices[a-1]->neighbors.insert(vertices[b-1]);
        vertices[b-1]->neighbors.insert(vertices[a-1]);
    }

    int count = 0;
    for (unsigned int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, true)) count++;
        }
    }

    cout << count;

}