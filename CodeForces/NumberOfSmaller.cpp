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

void count(int n, int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        while (i < n && vecA[i] < vecB[j]) {
            i++;
        }
        j++;
        cout << i<< " ";
    }
    while (j < m) {
        cout << i << " ";
        j++;
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

    count(n, m);
}