//
// Created by luisf on 09/06/2020.
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

    string n;
    cin >> n;

    int last = n[n.size()-1] - '0';

    cout << (last % 2 == 0 ? "S" : "N") << endl;

    int soma = 0;
    for (int i = 0; i < n.length(); i++) {
        soma += n[i] - '0';
    }
    cout << (soma % 3 == 0 ? "S" : "N") << endl;

    cout << (last % 5 == 0 ? "S" : "N") << endl;

}