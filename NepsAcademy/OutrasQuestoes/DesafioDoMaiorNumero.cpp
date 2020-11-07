//
// Created by luisf on 06/11/2020.
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
    int n;
    cin >> n;
    int res = 0;
    while (n != 0) {
        res = max(res, n);
        cin >> n;
    }

    cout << res;
}