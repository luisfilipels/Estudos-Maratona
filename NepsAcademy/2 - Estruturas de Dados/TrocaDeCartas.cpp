//
// Created by luisf on 13/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    int cartasA[a];
    int cartasB[b];

    for (int i = 0; i < a; i++) {
        int atual;
        cin >> atual;
        cartasA[i] = atual;
    }

    for (int i = 0; i < b; i++) {
        int atual;
        cin >> atual;
        cartasB[i] = atual;
    }

    set<int> setA, setB;

    for (int x : cartasA) {
        setA.insert(x);
    }

    for (int x : cartasB) {
        if (!(setA.find(x) != setA.end())) {
            setB.insert(x);
        }
    }

    int r1 = min(setA.size(), setB.size());

    setA.clear();
    setB.clear();

    for (int x : cartasB) {
        setB.insert(x);
    }

    for (int x : cartasA) {
        if (!(setB.find(x) != setB.end())) {
            setA.insert(x);
        }
    }

    int r2 = min(setA.size(), setB.size());

    cout << min(r1, r2);


}