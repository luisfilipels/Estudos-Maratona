//
// Created by Luis Filipe on 10/26/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

bool isValid (int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    Fast;

    int n;
    cin >> n;

    int matrix[n][n];
    int dist[n][n];
    bool visited[n][n];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> matrix[r][c];
            dist[r][c] = INT_MAX;
            visited[r][c] = false;
        }
    }

    dist[0][0] = 0;
    priority_queue<pair<int, pair<int,int>>> pq;

    pq.push(mp(0, mp(0, 0)));

    while (!pq.empty()) {
        pair<int, pair<int,int>> current = pq.top();
        pq.pop();

        int r = current.second.first;
        int c = current.second.second;

        if (visited[r][c]) continue;
        visited[r][c] = true;

        int currDist = dist[r][c];

        if (isValid(r+1, c, n) && currDist + matrix[r+1][c] < dist[r+1][c]) {
            dist[r+1][c] = currDist + matrix[r+1][c];
            pq.push(mp(-dist[r+1][c], mp(r+1, c)));
        }
        if (isValid(r-1, c, n) && currDist + matrix[r-1][c] < dist[r-1][c]) {
            dist[r-1][c] = currDist + matrix[r-1][c];
            pq.push(mp(-dist[r-1][c], mp(r-1, c)));
        }
        if (isValid(r, c+1, n) && currDist + matrix[r][c+1] < dist[r][c+1]) {
            dist[r][c+1] = currDist + matrix[r][c+1];
            pq.push(mp(-dist[r][c+1], mp(r, c+1)));
        }
        if (isValid(r, c-1, n) && currDist + matrix[r][c-1] < dist[r][c-1]) {
            dist[r][c-1] = currDist + matrix[r][c-1];
            pq.push(mp(-dist[r][c-1], mp(r, c-1)));
        }
    }

    cout << dist[n-1][n-1];

}