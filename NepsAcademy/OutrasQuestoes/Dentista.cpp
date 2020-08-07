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
    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(v.begin(), v.end());

    stack<pair<int,int>> stack;

    for (pair<int,int> p : v) {
        if (!stack.empty()) {
            if (p.first < stack.top().second) { // Conflito
                if (p.second < stack.top().second) {
                    stack.pop();
                    stack.push(p);
                }
            } else {
                stack.push(p);
            }
        } else {
            stack.push(p);
        }
    }

    cout << stack.size();
}