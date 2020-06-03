//
// Created by luisf on 13/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c, n;

    cin >> c >> n;

    map<long,long> currentlyInstalled;

    for (int i = 0; i < c; i++) {
        int prog, ver;
        cin >> prog >> ver;
        currentlyInstalled[prog] = ver;
    }

    map<long,long> mustBeInstalled;

    for (int i = 0; i < n; i++) {
        int prog, ver;
        cin >> prog >> ver;
        if (currentlyInstalled.count(prog) > 0) {
            if (currentlyInstalled[prog] < ver) {
                currentlyInstalled[prog] = ver;
                mustBeInstalled[prog] = ver;
            }
        } else {
            mustBeInstalled[prog] = ver;
        }
    }

    if (mustBeInstalled.empty()) {
        cout << 0;
    } else {
        for (auto &it : mustBeInstalled) {
            cout << it.first << " " << it.second << endl;
        }
    }



}