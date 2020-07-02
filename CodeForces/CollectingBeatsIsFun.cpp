//
// Created by luisf on 01/07/2020.
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

    int k;
    cin >> k;

    int count[10];
    memset(count, 0, sizeof(int) * 10);

    for (int r = 0; r < 4; r++) {
        string current;
        cin >> current;
        for (int c = 0; c < 4; c++) {
            if (current[c] == '.') continue;
            count[current[c] - '0']++;
            if (count[current[c] - '0'] > 2 * k) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}