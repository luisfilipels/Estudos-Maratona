//
// Created by luisf on 18/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;

    cin >> n >> l;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sellers;
    priority_queue<int, vector<int>, greater<int>> sellersAvailable;

    int count[n+1];

    for (int i = 0; i < n; i++) {
        sellers.push(make_pair(0, 0));
        sellersAvailable.push(i + 1);
        count[i+1] = 0;
    }

    for (int i = 0; i < l; i++) {
        int duration;
        cin >> duration;

        pair<int,int> lastSale = sellers.top();
        sellers.pop();

        if (lastSale.second != 0) {
            sellersAvailable.push(lastSale.second);
        }

        int nextSalesman = sellersAvailable.top();
        sellersAvailable.pop();

        if (nextSalesman == lastSale.second) {
            sellers.push(make_pair(duration+lastSale.first, nextSalesman));
        } else {
            sellers.push(make_pair(duration, nextSalesman));
        }

        count[nextSalesman]++;

    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << count[i] << endl;
    }


}