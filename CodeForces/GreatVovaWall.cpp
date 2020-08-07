//
// Created by Luis Filipe on 8/6/2020.
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

    stack<int> stack;

    int current;
    for (int i = 0; i < n; i++) {
        cin >> current;
        stack.push(current % 2);
        if (stack.size() >= 2) {
            int x, y;
            x = stack.top();
            stack.pop();
            y = stack.top();
            if (x == y) stack.pop();
            else stack.push(x);
        }
    }
    if (stack.size() <= 1) cout << "YES";
    else cout << "NO";
}