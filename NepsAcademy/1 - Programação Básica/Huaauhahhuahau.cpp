//
// Created by luisf on 05/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string entrada;

    cin >> entrada;

    string filtro;

    for (char c : entrada) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            filtro += c;
        }
    }

    int left = 0, right = filtro.size()-1;

    while (left < right) {
        if (filtro[left] != filtro[right]) {
            cout << "N";
            exit(0);
        }
        left++;
        right--;
    }

    cout << "S";
}