//
// Created by luisf on 30/10/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

const int INF = 0x3f3f3f3f;

int n, a, b, c;
int dp[4001];

int cut(int x) {
    if (x < 0) return -INF;
    if (x == 0) return 0;

    if (dp[x] != -1) return dp[x];

    int cutA = cut(x - a) + 1;
    int cutB = cut(x - b) + 1;
    int cutC = cut(x - c) + 1;

    return dp[x] = max(max(cutA, cutB), cutC);
}

int main() {
    Fast;

    cin >> n >> a >> b >> c;

    memset(dp, -1, sizeof(dp));

    cout << cut(n);
}