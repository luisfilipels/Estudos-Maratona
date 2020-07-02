//
// Created by luisf on 01/07/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int main() {
    Fast;
    unordered_map<int,int> map;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (map.count(arr[i]) > 0) {
            cout << arr[map[arr[i]]] << " " << arr[i];
            return 0;
        }
        map[k - arr[i]] = i;
    }
    return 0;
}