//
// Created by luisf on 02/06/2020.
//

#include <bits/stdc++.h>

using namespace std;

void mergeSortInversions(vector<int> &v) {
    if (v.size() == 1) {
        return;
    }

    vector<int> leftHalf, rightHalf;

    for (int i = 0; i < v.size()/2; i++) {
        leftHalf.push_back(v[i]);
    }
    for (int i = v.size()/2; i < v.size(); i++) {
        rightHalf.push_back(v[i]);
    }

    mergeSortInversions(leftHalf);
    mergeSortInversions(rightHalf);

    int i = 0, j = 0, k = 0;

    while (i < leftHalf.size() && j < rightHalf.size()) {
        if (leftHalf[i] < rightHalf[j]) {
            v[k++] = leftHalf[i++];
        } else {
            v[k++] = rightHalf[j++];
        }
    }

    if (i == leftHalf.size()) {
        for (; k < v.size(); k++) {
            v[k] = rightHalf[j++];
        }
    } else if (j == rightHalf.size()) {
        for (; k < v.size(); k++) {
            v[k] = leftHalf[i++];
        }
    }
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

    mergeSortInversions(v);

    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << " ";
    }

}