//
// Created by luisf on 02/06/2020.
//

#include <bits/stdc++.h>

using namespace std;

int countInversions (vector<int> &v) {
    if (v.size() == 1) return 0;

    int invs = 0;

    vector<int> leftHalf, rightHalf;

    for (int i = 0; i < v.size()/2; i++) {
        leftHalf.push_back(v[i]);
    }

    for (int i = v.size()/2; i < v.size(); i++) {
        rightHalf.push_back(v[i]);
    }

    invs += countInversions(leftHalf);
    invs += countInversions(rightHalf);

    leftHalf.push_back(INT_MAX);
    rightHalf.push_back(INT_MAX);

    int i = 0, j = 0;

    for (int k = 0; k < v.size(); k++) {
        if (leftHalf[i] <= rightHalf[j]) {
            v[k] = leftHalf[i++];
        } else {
            v[k] = rightHalf[j++];

            invs += leftHalf.size() - i - 1;
        }
    }

    return invs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int atual;
        cin >> atual;
        v.push_back(atual);
    }

    cout << countInversions(v);
}