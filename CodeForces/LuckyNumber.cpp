//
// Created by luisf on 11/06/2020.
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

    string n;

    cin >> n;

    ll count = 0;

    for (char c : n) {
        if (c == '4' || c == '7') {
            count++;
        }
        if (count > 7) break;
    }

    cout << (count == 7 || count == 4 ? "YES" : "NO");

}