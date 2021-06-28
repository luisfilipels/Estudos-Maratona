//
// Created by Luis Filipe on 6/25/2021.
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

ll N, K;

const int MAX_N = 100010;
ll nums[MAX_N];
ll countElements[MAX_N];

ll totalUnique = 0;
ll totalRanges = 0;

void addNum(int index) {
    ll num = nums[index];
    countElements[num]++;
    if (countElements[num] == 1) {
        totalUnique++;
    }
}

void removeNum(int index) {
    ll num = nums[index];
    countElements[num]--;
    if (countElements[num] == 0) {
        totalUnique--;
    }
}

int main() {
    Fast;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0;
    for (int end = 0; end < N; end++) {
        addNum(end);
        while (totalUnique > K) {
            removeNum(start++);
        }
        totalRanges += end - start + 1;
    }

    cout << totalRanges;
}