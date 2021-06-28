//
// Created by Luis Filipe on 6/24/2021.
//

/*
L = 0
for R = 0..n-1
    add(a[R])
    while not good():
        remove(a[L])
        L++
    add_to_sum()
*/

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

int main() {
    Fast;

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0;
    ll sum = 0;
    ll totalRanges = 0;
    for (int end = 0; end < N; end++) {
        sum += nums[end];
        while (sum > S) {
            sum -= nums[start++];
        }
        totalRanges += end - start + 1;
    }

    cout << totalRanges;
}