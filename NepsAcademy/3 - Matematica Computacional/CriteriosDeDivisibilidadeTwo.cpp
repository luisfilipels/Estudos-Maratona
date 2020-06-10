//
// Created by luisf on 09/06/2020.
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

    string s;

    cin >> s;

    int n = s.length();

    string lastTwo;

    if (s.length() >= 2) {
        lastTwo = "aa";
        lastTwo[0] = s[n-2];
        lastTwo[1] = s[n-1];
        cout << (stoi(lastTwo) % 4 == 0 || lastTwo == "00" ? "S" : "N") << endl;
    } else {
        cout << (stoi(s) % 4 == 0 ? "S" : "N") << endl;
    }

    int soma = 0;
    for (int i = 0; i < s.length(); i++) {
        soma += s[i] - '0';
    }
    cout << (soma % 9 == 0 ? "S" : "N") << endl;

    if (lastTwo.empty()) {
        if (s == "0") {
            cout << "S" << endl;
            return 0;
        }
        cout << "N" << endl;
    } else {
        if (lastTwo == "00" || lastTwo == "25" || lastTwo == "50" || lastTwo == "75") {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

}