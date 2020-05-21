//
// Created by luisf on 11/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

bool compare (pair<int, string> p1, pair<int, string> p2) {
    int minimum = min(p1.second.size(), p2.second.size());
    string s1 = p1.second;
    string s2 = p2.second;
    for (int i = 0; i < minimum; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] < s2[i];
        }
    }
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;

    cin >> n >> t;

    vector<pair<int, string>> v[t];

    vector<pair<int, string>> all;


    for (int i = 0; i < n; i++) {
        string nome;
        int hab;
        cin >> nome >> hab;
        all.emplace_back(hab, nome);
    }

    sort(all.begin(), all.end());
    int currentTeam = 0;
    for (int i = n-1; i >= 0; i--) {
        v[currentTeam].push_back(all[i]);
        currentTeam = (currentTeam + 1) % t;
    }

    for (int i = 0; i < t; i++) {
        cout << "Time " << i+1 << endl;
        sort(v[i].begin(), v[i].end(), compare);
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].second << endl;
        }
        cout << endl;
    }
}