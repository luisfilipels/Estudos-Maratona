//
// Created by luisf on 13/11/2020.
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

    int v, n;

    cin >> v >> n;

    int total = v * n;

    cout << (int)ceil(total * 0.1);

    for (int i = 2; i <= 9; i++) {
        double x = (total * (i / 10.0));
        cout << " " << (int)ceil(x);
    }
}