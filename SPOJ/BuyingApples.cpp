//
// Created by Luis Filipe on 11/3/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int n,k;

const int INF = 0x3f3f3f3f;

int prices[101];
int dp[1001][1001];

int func(int kilosRemaining, int currentIndex) {
    if (prices[currentIndex] == -1) return func(kilosRemaining, currentIndex + 1);

    if (currentIndex >= k && kilosRemaining > 0) return INF;

    if (kilosRemaining == 0) return 0;
    if (kilosRemaining < 0) return INF;

    if (dp[currentIndex][kilosRemaining] != INF) {
        return dp[currentIndex][kilosRemaining];
    }

    int take = func(kilosRemaining - (currentIndex + 1), currentIndex) + prices[currentIndex];
    int notTake = func(kilosRemaining, currentIndex + 1);

    if (take >= INF && notTake >= INF) dp[currentIndex][kilosRemaining] = INF;
    else dp[currentIndex][kilosRemaining] = min(take, notTake);

    return dp[currentIndex][kilosRemaining];
}

int main() {
    Fast;

    int C;
    cin >> C;

    for (int c = 0; c < C; c++) {
        cin >> n >> k;

        memset(dp, INF, sizeof(dp));

        for (int i = 0; i < k; i++) {
            cin >> prices[i];
        }

        int result = func(k, 0);

        if (result >= INF) cout << -1 << endl;
        else cout << result << endl;
    }
}