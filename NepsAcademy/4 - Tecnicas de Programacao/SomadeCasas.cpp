//
// Created by luisf on 26/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

// Solução usando um map
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int,int> map;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (map.count(arr[i]) != 0) {
            int a = arr[map[arr[i]]], b = arr[i];
            cout << a << " " << b;
            return 0;
        }
        map.insert(make_pair(k-arr[i], i));
    }
}

// Solução usando two pointers
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int inicio = 0, fim = n-1;
    while (inicio < fim) {
        if (arr[inicio] + arr[fim] == k) {
            cout << arr[inicio] << " " << arr[fim];
            return 0;
        } else if (arr[inicio] + arr[fim] < k) {
            inicio++;
        } else {
            fim--;
        }
    }
}