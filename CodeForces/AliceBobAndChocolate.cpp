//
// Created by luisf on 13/07/2020.
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

    ll n;
    cin >> n;

    ll chocolates[n];

    for (int x = 0; x < n; x++) {
        cin >> chocolates[x];
    }

    ll i = 0, j = n-1;

    ll a = 0, b = 0;

    char last = '*';

    while (i < j) {
        ll mini = min(chocolates[i], chocolates[j]);

        if (mini == chocolates[i]) {
            last = 'a';
        } else {
            last = 'b';
        }

        chocolates[i] -= mini;
        chocolates[j] -= mini;

        if (chocolates[i] == 0 && chocolates[j] == 0) {
            if (j - i == 2) {
                a += 2;
                b++;
                cout << a << " " << b;
                return 0;
            }
        }

        if (chocolates[i] == 0) {
            i++;
            a++;
        }
        if (chocolates[j] == 0) {
            j--;
            b++;
        }
    }

    if (chocolates[i] != 0 || chocolates[j] != 0) {
        if (last == 'a') {
            b++;
        } else {
            a++;
        }
    }


    cout << a << " " << b;

}