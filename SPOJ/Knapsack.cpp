//
// Created by luisf on 03/11/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

#define MAXSN 2010

const int INF = 0x3f3f3f3f;

int sizes[MAXSN], values[MAXSN];
int dp[MAXSN][MAXSN];
int s, n;

int func(int remainingSpace, int currentItem) {
    if (remainingSpace < 0) return -INF;

    if (currentItem >= n) return 0;

    if (dp[currentItem][remainingSpace] != -1)
        return dp[currentItem][remainingSpace];

    int take = func(remainingSpace - sizes[currentItem], currentItem + 1) + values[currentItem];
    int notTake = func(remainingSpace, currentItem+1);

    dp[currentItem][remainingSpace] = max(take, notTake);

    return dp[currentItem][remainingSpace];
}

int main () {
    Fast;

    cin >> s >> n;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> sizes[i] >> values[i];
    }

    cout << func(s, 0);
}