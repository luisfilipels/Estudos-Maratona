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

    ll even = 0;
    ll odd = 0;

    bool isEven = true;

    for (int i = n.length()-1; i >= 0; i--) {
        if (isEven) {
            even += n[i] - '0';
        } else {
            odd += n[i] - '0';
        }
        isEven = !isEven;
    }

    cout << ((even - odd) % 11 == 0 ? "S" : "N");

    return 0;
}