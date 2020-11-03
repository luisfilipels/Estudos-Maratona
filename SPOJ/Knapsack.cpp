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

int sizes[MAXSN], values[MAXSN];
int dp[MAXSN][MAXSN];
int s, n;

int func(int remainingSpace, int currentItem) {
    if (remainingSpace < 0) return -1000;

    if (currentItem > n) return 0;

    if (dp[remainingSpace][currentItem] != -1)
        return dp[remainingSpace][currentItem];

    int take = func(remainingSpace - sizes[currentItem], currentItem + 1) + values[currentItem];
    int notTake = func(remainingSpace, currentItem+1);

    dp[remainingSpace][currentItem] = max(take, notTake);

    return dp[remainingSpace][currentItem];
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