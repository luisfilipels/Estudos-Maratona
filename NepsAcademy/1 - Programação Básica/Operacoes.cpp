//
// Created by luisf on 05/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char oper;

    cin >> oper;

    double num1, num2;

    cin >> num1 >> num2;

    cout.precision(2);

    if (oper == 'M') {
        cout << fixed << num1 * num2;
    } else {
        cout << fixed << num1 / num2;
    }
}