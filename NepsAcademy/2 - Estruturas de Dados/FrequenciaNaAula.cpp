//
// Created by luisf on 13/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> set;

    int n;

    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!(set.find(num) != set.end())) {
            set.insert(num);
            count++;
        }
    }

    cout << count;
}