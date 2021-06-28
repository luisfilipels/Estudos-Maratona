//
// Created by Luis Filipe on 6/28/2021.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

const int MAX_N = 100010;
ll nums[MAX_N];

ll N, S;

bool good(ll sum) {
    return sum <= S;
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0;
    ll sum = 0;
    double result = 0;
    for (int end = 0; end < N; end++) {
        sum += nums[end];
        while (!good(sum)) {
            sum -= nums[start++];
        }
        ll n = end - start + 1;
        double summation = (double)(n * (n + 1))/2;
        result += summation;
    }

    cout << (ll) result;
}