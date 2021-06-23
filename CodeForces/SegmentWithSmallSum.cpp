//
// Created by Luis Filipe on 6/23/2021.
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
ll arr[MAX_N];

ll N, S;

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0;
    ll sum = 0;
    int maxLength = 0;
    for (int end = 0; end < N; end++) {
        sum += arr[end];
        while (sum > S) {
            sum -= arr[start++];
        }
        maxLength = max(maxLength, end - start + 1);
    }

    cout << maxLength;
}