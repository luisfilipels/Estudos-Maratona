//
// Created by luisf on 05/05/2020.
//

using namespace std;

#include <bits/stdc++.h>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    int P,Q;

    char oper;

    cin >> P >> oper >> Q;

    if (oper == '+') {
        cout << (P + Q <= N ? "OK" : "OVERFLOW");
    } else {
        cout << (P * Q <= N ? "OK" : "OVERFLOW");
    }
}