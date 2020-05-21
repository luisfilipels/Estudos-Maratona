//
// Created by luisf on 06/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main () {
    int dp[31];

    int N = 1;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 7;

    for (int i = 4; i < 31; i++) {
        dp[i] = (int)pow(2, i-1) + dp[i-1];
    }

    vector<int> v;

    while (N != 0) {
        cin >> N;
        v.push_back(N);

    }

    v.pop_back();

    for (int i = 0; i < v.size(); i++) {
        cout << "Teste " << i+1 << "\n";
        cout << dp[v[i]] << "\n";
        cout << "\n";
    }
}