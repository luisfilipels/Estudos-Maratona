//
// Created by luisf on 11/06/2020.
//

//
// Created by luisf on 11/06/2020.
//

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

    ll p1, c1, p2, c2;

    cin >> p1 >> c1 >> p2 >> c2;

    ll m1 = p1 * c1;
    ll m2 = p2 * c2;

    if (m1 == m2) {
        cout << "0";
    } else if (m1 > m2) {
        cout << "-1";
    } else {
        cout << "1";
    }

}