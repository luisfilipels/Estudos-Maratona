//
// Created by luisf on 30/07/2020.
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

    deque<char> deque;

    string s;
    cin >> s;

    bool turn = true;
    for (char c : s) {
        deque.push_back(c);
        int n = deque.size();
        if (n > 1) {
            char current = c;
            char previous = deque[n-2];
            if (current == previous) {
                deque.pop_back();
                deque.pop_back();
                turn = !turn;
            }
        }
    }
    if (turn) {
        cout << "No";
    } else {
        cout << "Yes";
    }

}