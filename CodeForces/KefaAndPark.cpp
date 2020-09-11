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

int countPossibleLeaves = 0;
int n, m;

struct Node {
    int id;
    bool hasCat = false;

    Node(int id) {
        this->id = id;
    }

    unordered_set<int> neighbors;
};

unordered_map<int, Node*> vertices;
unordered_set<int> visited;

void dfs (int node, int catCount) {
    Node *current = vertices[node];
    if (catCount == m+1) return;
    if (current->neighbors.size() <= 1 && current->id != 1) {
        countPossibleLeaves++;
        return;
    }
    visited.insert(current->id);
    for (int neighbor : current->neighbors) {
        if (visited.count(neighbor) == 0) {
            if (vertices[neighbor]->hasCat) {
                dfs(neighbor, catCount+1);
            } else {
                dfs(neighbor, 0);
            }
        }
    }
}

int main() {
    Fast;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        vertices[i] = new Node(i);
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) vertices[i]->hasCat = true;
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vertices[a]->neighbors.insert(b);
        vertices[b]->neighbors.insert(a);
    }

    if (vertices[1]->hasCat == 1) {
        dfs(1, 1);
    } else {
        dfs(1, 0);
    }

    cout << countPossibleLeaves;
}