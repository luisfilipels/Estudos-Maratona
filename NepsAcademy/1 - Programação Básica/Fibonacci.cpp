//
// Created by luisf on 06/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int fibonacci (int dp [], int n) {
    if (n == 0 || n == 1) {
        return dp[n];
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = fibonacci(dp, n-1) + fibonacci(dp, n-2);
    return dp[n];
}

int main() {
    int N;

    cin >> N;

    int dp[N+1];
    memset(dp, 0, (N+1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;

    cout << fibonacci(dp, N);
}