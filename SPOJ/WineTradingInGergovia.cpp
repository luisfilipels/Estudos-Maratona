//
// Created by luisf on 30/07/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define MAXN 100001
typedef long long ll;

int arr[MAXN];

int main() {
    Fast;

    int n;

    cin >> n;

    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll s = 0, b = 0;
        ll cost = 0;
        while (true) {
            while (s < n && arr[s] >= 0) s++; // Find a seller
            while (b < n && arr[b] <= 0) b++; // Find a buyer
            if (s == n || b == n) break;      // If we reach this point, that means that the offer and demand have been satisfied.
            int amount = min(arr[b],abs(arr[s]));
            cost += amount * (abs(s - b));    // The cost must take into account the distance.
            arr[b] -= amount;
            arr[s] += amount;
        }
        cout << cost << endl;
        cin >> n;
    }
}