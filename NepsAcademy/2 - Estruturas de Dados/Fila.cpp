//
// Created by luisf on 11/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> v;
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int atual;
        cin >> atual;
        v.push_back(atual);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int atual;
        cin >> atual;
        s.insert(atual);
    }

    for (int i = 0; i < n; i++) {
        if (!(s.find(v[i]) != s.end())) {
            cout << v[i] << " ";
        }
    }

}