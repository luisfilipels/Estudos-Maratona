//
// Created by luisf on 12/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    queue<char> q;

    for (char c = 'a'; c <= 'p'; c++) {
        q.push(c);
    }

    for (int i = 0; i < 15; i++) {
        char t1 = q.front();
        q.pop();
        char t2 = q.front();
        q.pop();
        int m, n;

        cin >> m >> n;

        if (m > n) {
            q.push(t1);
        } else {
            q.push(t2);
        }
    }

    cout << (char)toupper(q.front());

}