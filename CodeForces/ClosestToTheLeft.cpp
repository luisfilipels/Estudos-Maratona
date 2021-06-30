//
// Created by Luis Filipe on 6/29/2021.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int main() {
    Fast;

    int n, k;

    cin >> n >> k;

    int nums[100010];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < k; i++) {
        int start = -1, end = n;
        int query;
        cin >> query;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= query) {
                start = mid;
            } else {
                end = mid;
            }
        }
        cout << end << endl;
    }
}