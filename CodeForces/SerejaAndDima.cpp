//
// Created by luisf on 15/07/2020.
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

    ll n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll s = 0, d = 0; // Sereja and Dima's points

    ll i = 0, j = n-1;

    char turn = 's';
    while (i <= j) {

        if (arr[i] > arr[j]) {
            if (turn == 's') {
                s += arr[i];
            } else {
                d += arr[i];
            }
            i++;
        } else {
            if (turn == 's') {
                s += arr[j];
            } else {
                d += arr[j];
            }
            j--;
        }

        turn = turn == 's' ? 'd' : 's';
    }

    cout << s << " " << d;
}