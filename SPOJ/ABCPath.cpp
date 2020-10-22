//
// Created by luisf on 22/10/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

char letters[60][60];
bool visited[60][60];

typedef long long ll;

int H, W;

int dfs (int i, int j) {
    int ma = 0;
    int in , jn;
    if (i <= 0 || i > H || j <= 0 || j > W) return 0;
    for ( in = -1; in <= 1; in ++) {
        for (int jn = -1; jn <= 1; jn++) {
            if ( in == 0 && jn == 0) continue;

            if (letters[i + in ][j + jn] == letters[i][j] + 1 && !visited[i + in ][j + jn]) {
                visited[i + in ][j + jn] = true;
                ma = max(ma, dfs(i + in , j + jn));
            }

        }
    }
    return ma + 1;
}

int main() {
    //Fast;

    int cases = 1;
    while (true) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) break;
        if (H == 0 || W == 0) {
            cout << 0 << endl;
            continue;
        }


        memset(letters, '-', sizeof letters);
        for (int i = 1; i <= H; i++) {
            char str[50];
            scanf("%s", str);
            for (int j = 0; j <= W; j++) {
                letters[i][j + 1] = str[j];
            }
        }

        memset(visited, false, sizeof(visited));
        int maxVal = 0;
        for (int r = 1; r <= H; r++) {
            for (int c = 1; c <= W; c++) {
                if (letters[r][c] == 'A') {
                    visited[r][c] = true;
                    maxVal = max(maxVal, dfs(r, c));
                }
            }
        }

        cout << "Case " << cases++ << ": " << maxVal << endl;
    }
}