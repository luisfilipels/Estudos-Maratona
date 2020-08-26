//
// Created by luisf on 26/08/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

short visited[1002][1002];
short mapa[1002][1002];

int maxCount = 0;
bool shouldContinue = true;

bool isValid (int l, int c, int n, int m) {
    return l >= 0 && l < n && c >= 0 && c < m && (mapa[l][c] == 1 || mapa[l][c] == 2 || mapa[l][c] == 3) && visited[l][c] == 0;
}

void dfs (int l, int c, int n, int m, int count) {
    if (!isValid(l, c, n, m) || !shouldContinue) return;
    visited[l][c] = 1;
    if (mapa[l][c] == 3) {
        maxCount = count;
        shouldContinue = false;
        return;
    }
    dfs(l-1, c, n, m, count+1);
    dfs(l+1, c, n, m, count+1);
    dfs(l, c+1, n, m, count+1);
    dfs(l, c-1, n, m, count+1);
}

int main() {
    Fast;

    int n, m;

    cin >> n >> m;

    int startL, startC;

    for (int l = 0; l < 1001; l++) {
        for (int c = 0; c < 1001; c++) {
            visited[l][c] = 0;
            mapa[l][c] = 0;
        }
    }

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < m; c++) {
            cin >> mapa[l][c];
            if (mapa[l][c] == 2) {
                startL = l;
                startC = c;
            }
        }
    }

    dfs(startL, startC, n, m, 1);

    cout << maxCount;


}