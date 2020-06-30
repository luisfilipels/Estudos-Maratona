//
// Created by luisf on 29/06/2020.
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

    int T;

    cin >> T;

    for (int t = 0; t < T; t++) {
        int R, C;
        cin >> R >> C;
        string row;
        int image [R][C];
        for (int r = 0; r < R; r++) {
            cin >> row;
            for (int c = 0; c < row.length(); c++) {
                image[r][c] = row[c] == '1' ? 1 : 0;
            }
        }

        int corruptedPixels = 0;
        int sparePixels = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (r == 0 || r == R-1 || c == 0 || c == C-1) {
                    if (image[r][c] == 0) corruptedPixels++;
                } else {
                    if (image[r][c] == 1) sparePixels++;
                }
            }
        }
        if (sparePixels - corruptedPixels >= 0) {
            cout << corruptedPixels << endl;
        } else {
            cout << -1 << endl;
        }
    }
}