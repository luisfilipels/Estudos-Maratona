//
// Created by Luis Filipe on 6/23/2021.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

const int MAX_N = 100000;
int vecA[MAX_N];
int vecB[MAX_N];
int vecC[MAX_N];

void merge(int n, int m) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (vecA[i] < vecB[j]) {
            vecC[k++] = vecA[i++];
        } else {
            vecC[k++] = vecB[j++];
        }
    }
    while (i < n) {
        vecC[k++] = vecA[i++];
    }
    while (j < m) {
        vecC[k++] = vecB[j++];
    }

    for (i = 0; i < k; i++) {
        cout << vecC[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> vecA[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vecB[i];
    }

    merge(n, m);
}