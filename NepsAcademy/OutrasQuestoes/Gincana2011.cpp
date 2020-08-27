//
// Created by Luis Filipe on 8/26/2020.
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
        int a, b;
        cin >> a >> b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }

    int count = 0;

    while (!nonVisited.empty()) {
        count++;
        queue<int> queue;
        queue.push(*nonVisited.begin());
        while (!queue.empty()) {
            int element = queue.front();
            queue.pop();
            nonVisited.erase(element);
            for (int neighbor : adjList[element]) {
                if (nonVisited.count(neighbor) != 0) {
                    queue.push(neighbor);
                }
            }
        }
    }

    cout << count;
}