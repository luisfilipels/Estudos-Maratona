//
// Created by luisf on 12/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int,int>> intervalos;

    int p, s;

    cin >> p >> s;

    for (int i = 0; i < s; i++) {
        int comeco, fim;
        cin >> comeco >> fim;
        intervalos.emplace_back(comeco, fim);
    }

    sort(intervalos.begin(), intervalos.end());

    vector<pair<int,int>> newIntervalos;

    pair<int,int> intervaloAtual = intervalos[0];

    for (int i = 1; i < s; i++) {
        int comeco = max(intervaloAtual.first, intervalos[i].first);
        int fim = min(intervaloAtual.second, intervalos[i].second);

        if (comeco <= intervaloAtual.second) {
            intervaloAtual.second = max(intervaloAtual.second, intervalos[i].second);
        } else {
            newIntervalos.push_back(intervaloAtual);
            intervaloAtual = intervalos[i];
        }
    }
    newIntervalos.push_back(intervaloAtual);

    for (pair<int,int> pair : newIntervalos) {
        cout << pair.first << " " << pair.second << "\n";
    }
}