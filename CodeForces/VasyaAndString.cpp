//
// Created by luisf on 09/07/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

string s;
ll k, n;

ll checkChar (char c) {
    ll left = 0, right = 0;
    ll count = 0;

    ll maxVal = 0;

    bool alreadySubtracted = false;

    while (right < n) {
        while (right < n && count <= k) {
            if (s[right] == c) {
                if (!alreadySubtracted) {
                    count++;
                }
                if (count > k) {
                    alreadySubtracted = true;
                    break;
                }
            }
            right++;
            alreadySubtracted = false;
        }
        maxVal = max(maxVal, right - left);
        while (count > k) {
            if (s[left] == c) {
                count--;
            }
            left++;
        }
    }

    return maxVal;
}

int main() {
    Fast;

    cin >> n >> k;

    cin >> s;

    ll r1 = checkChar('a');
    ll r2 = checkChar('b');

    cout << max(r1, r2);
}