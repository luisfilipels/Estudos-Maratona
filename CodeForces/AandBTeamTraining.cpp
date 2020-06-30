//
// Created by luisf on 29/06/2020.
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

    int count = 0;

    int n, m;

    cin >> n >> m;

    int big = max(n,m);
    int small = min(n,m);

    while (big > 0 && small > 0) {
        if (small >= 1 && big >= 2) {
            small--;
            big -= 2;
            count++;
        } else {
            break;
        }
        if (big < small) {
            int temp = big;
            big = small;
            small = temp;
        }
    }

    cout << count;
}