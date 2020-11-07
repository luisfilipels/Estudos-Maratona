//
// Created by luisf on 06/11/2020.
//


#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int n;

int arr[20];
int dp[20];

int main() {
    Fast;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 0;
    }

    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        int maxDP = 0;
        for (int j = i; j >= 0; j--) {
            if (arr[j] < arr[i] && dp[j] > maxDP) {
                maxDP = dp[j];
            }
        }
        dp[i] = maxDP + 1;
        maxVal = max(maxVal, dp[i]);
    }

    cout << maxVal;
}