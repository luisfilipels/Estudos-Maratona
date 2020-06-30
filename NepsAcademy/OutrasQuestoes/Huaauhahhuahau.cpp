//
// Created by luisf on 29/06/2020.
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
    
    string s;

    cin >> s;

    string s2;

    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            s2 += c;
        }
    }

    int i = 0, j = s2.length()-1;

    while (i < j) {
        if (s2[i] != s2[j]) {
            cout << "N";
            return 0;
        }
        i++;
        j--;
    }
    cout << "S";
}