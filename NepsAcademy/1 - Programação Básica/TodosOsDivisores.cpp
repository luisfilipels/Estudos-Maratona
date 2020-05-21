//
// Created by luisf on 03/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;

    vector<int> v;

    for (int i = 1; i <= X/2; i++) {
        if (X % i == 0) v.push_back(i);
    }
    v.push_back(X);
    for (int i : v) {
        cout << i << " ";
    }
}