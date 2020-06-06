//
// Created by luisf on 05/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int n, m;

int n1[1001];
int n2[1001];

int dp[1001][1001];

int getLCS() {
    int maxi = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (n1[i-1] == n2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

int main() {
    Fast;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> n1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> n2[i];
    }

    int ancestralLength = getLCS();

    cout << (n - ancestralLength) << " " << (m - ancestralLength);

    return 0;
}