//
// Created by luisf on 09/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

#define MAXN 1010

ll dp[MAXN];
ll nums[MAXN];

int main() {
    Fast;

    ll n;

    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dp[0] = 1;

    ll maxAnswer = 1;

    for (ll start = 1; start < n; start++) {
        ll currentNum = nums[start];
        ll maxDP = 0;
        for (ll back = start-1; back >= 0; back--) {
            if (nums[back] <= currentNum) {
                maxDP = max(maxDP, dp[back]);
            }
        }
        dp[start] = maxDP + 1;
        maxAnswer = max(maxAnswer, dp[start]);
    }

    cout << maxAnswer;

}