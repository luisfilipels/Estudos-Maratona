//
// Created by luisf on 07/05/2020.
//

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long copyArr[N];

    for (int i = 0; i < N; i++) {
        copyArr[i] = arr[i];
    }

    int conta = 0;
    vector<long> v;

    sort(copyArr, copyArr + N);

    for (int i = 0; i < N; i++) {
        if (copyArr[i] != arr[i]) {
            conta++;
            v.push_back(arr[i]);
        }
    }

    sort(v.begin(), v.end());
    cout << conta << "\n";
    for (int i : v) {
        cout << i << " ";
    }
}