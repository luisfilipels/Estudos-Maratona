//
// Created by luisf on 14/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;

    cin >> n >> d;

    int nums[n * 2];

    for (int i = 0; i < n; i++) {
        int atual;
        cin >> atual;
        nums[i] = atual;
        nums[i + n] = atual;
    }

    int left = 0, right = -1, sum = 0, count = 0;
    bool countMade = false;
    while (true) {
        while (right + 1 < left + n && sum < d) {
            sum += nums[++right];
        }
        if (sum == d && left < n) {
            count++;
            countMade = false;
        }
        sum -= nums[left];
        left++;
        if (left >= n) {
            break;
        }
    }

    cout << count;
}