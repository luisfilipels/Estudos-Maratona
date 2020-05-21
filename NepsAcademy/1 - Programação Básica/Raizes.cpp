//
// Created by luisf on 03/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout.precision(4);

    for (int i = 0; i < N; i++) {
        double atual;
        cin >> atual;
        cout << fixed << sqrt(atual) << '\n';
    }
}