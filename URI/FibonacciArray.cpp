//
// Created by luisf on 30/10/2020.
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

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        unsigned long long fibFirst = 0;
        unsigned long long fibSecond = 1;
        unsigned long long res;

        for (int i = 2; i <= n; i++) {
            res = fibFirst + fibSecond;
            fibFirst = fibSecond;
            fibSecond = res;
        }

        if (n == 0) res = 0;
        if (n == 1) res = 1;

        cout << "Fib(" << n << ") = " << res << endl;
    }
}