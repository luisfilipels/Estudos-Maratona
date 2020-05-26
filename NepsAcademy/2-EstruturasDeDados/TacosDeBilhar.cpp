//
// Created by luisf on 13/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c;

    cin >> c;

    unordered_set<int> set;

    int count = 0;
    for (int i = 0; i < c; i++) {
        int curr;
        cin >> curr;
        if (!(set.find(curr) != set.end())) {
            count += 2;
            set.insert(curr);
        } else {
            set.erase(curr);
        }
    }
    cout << count;
}