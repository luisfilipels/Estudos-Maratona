//
// Created by luisf on 13/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; // Instâncias

    cin >> t;

    vector<string> final;

    for (int i = 0; i < t; i++) {
        int m, n;

        cin >> m >> n;
        string pt, jp;

        unordered_map<string, string> dicionarioJPPT;

        cin.ignore();

        for (int j = 0; j < m; j++) {
            getline(cin, jp);
            getline(cin, pt);
            dicionarioJPPT[jp] = pt;
        }

        for (int j = 0; j < n; j++) {
            string linha;
            getline(cin, linha);
            string palavra;
            final.emplace_back("");
            int current = final.size()-1;
            for (char c : linha) {
                if (c != ' ') {
                    palavra += c;
                } else {
                    if (dicionarioJPPT.find(palavra) != dicionarioJPPT.end()) {
                        final[current] += dicionarioJPPT[palavra];
                    } else {
                        final[current] += palavra;
                    }
                    final[current] += " ";
                    palavra = "";
                }
            }
            if (dicionarioJPPT.find(palavra) != dicionarioJPPT.end()) {
                final[current] += dicionarioJPPT[palavra];
            } else {
                final[current] += palavra;
            }
        }
        final.emplace_back("");
        dicionarioJPPT.clear();
    }

    for (string s : final) {
        cout << s << endl;
    }
}