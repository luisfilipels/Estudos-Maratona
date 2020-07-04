//
// Created by luisf on 03/07/2020.
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

    ll n, t;

    cin >> n >> t;

    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;

    ll currSum = 0;
    ll currBooks = 0;
    ll maxBooks = 0;
    while (left < n) {
        while (right < n && currSum <= t) {
            currSum += arr[right++];
            currBooks++;
        }
        if (right == n) {
            if (currSum > t) {
                maxBooks = max(maxBooks, currBooks-1);
            } else {
                maxBooks = max(maxBooks, currBooks);
            }
        } else {
            maxBooks = max(maxBooks, currBooks-1);
        }
        while (left < right && currSum > t) {
            currSum -= arr[left++];
            currBooks--;
        }
        if (right == n) {
            break;
        }
    }

    cout << maxBooks;
}