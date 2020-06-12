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

    int n;

    cin >> n;

    string s;

    cin >> s;

    char last = s[0];
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == last) {
            count++;
        }
        last = s[i];
    }

    cout << count;

}