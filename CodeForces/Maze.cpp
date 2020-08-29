//
// Created by Luis Filipe on 8/28/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

#define MAXN 500
#define MAXM 500

char maze[MAXN][MAXM];
bool visited[MAXN][MAXM];

int n, m, k, s = 0;

int visitCount = 0;

bool isValid (int l, int c) {
    return (l >= 0 && l < n && c >= 0 && c < m && maze[l][c] == '.' && !visited[l][c]);
}

void dfs (int l, int c) {
    if (visitCount == s - k) return;
    visitCount++;
    visited[l][c] = true;
    if (isValid(l+1, c)) dfs(l+1, c);
    if (isValid(l-1, c)) dfs(l-1, c);
    if (isValid(l, c+1)) dfs(l, c+1);
    if (isValid(l, c-1)) dfs(l, c-1);
}

int main() {
    Fast;

    cin >> n >> m >> k;

    pair<int,int> start = mp(-1,-1);
    for (int l = 0; l < n; l++) {
        for (int c = 0; c < m; c++) {
            cin >> maze[l][c];
            visited[l][c] = false;
            if (maze[l][c] == '.') {
                s++;
                if (start.first == -1) start = mp(l, c);
            }
        }
    }

    dfs(start.first, start.second);

    /*while (!queue.empty()) {
        if (visitCount == s - k - 2) break;
        int l = queue.front().first;
        int c = queue.front().second;
        visitCount++;
        visited[l][c] = true;
        queue.pop();
        if (isValid(l+1, c)) queue.push(mp(l+1,c));
        if (isValid(l-1, c)) queue.push(mp(l-1,c));
        if (isValid(l, c+1)) queue.push(mp(l,c+1));
        if (isValid(l, c-1)) queue.push(mp(l,c-1));
    }*/

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < m; c++) {
            if (!visited[l][c] && maze[l][c] == '.') {
                maze[l][c] = 'X';
            }
        }
    }

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < m; c++) {
            cout << maze[l][c];
        }
        cout << endl;
    }

}