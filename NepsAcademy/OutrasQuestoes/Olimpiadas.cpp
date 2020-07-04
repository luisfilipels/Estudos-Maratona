//
// Created by luisf on 03/07/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

struct Pais {
    ll ouro = 0;
    ll prata = 0;
    ll bronze = 0;

    int id;
};

struct comparator {
    inline bool operator() (const Pais &p1, const Pais &p2) {
        if (p1.ouro != p2.ouro) {
            return  p1.ouro > p2.ouro;
        } else {
            if (p1.prata != p2.prata) {
                return p1.prata > p2.prata;
            } else {
                if (p1.bronze != p2.bronze) {
                    return p1.bronze > p2.bronze;
                }
                return p1.id < p2.id;
            }
        }
    }
};

int main() {
    Fast;

    int n, m;
    cin >> n >> m;

    vector<Pais> v;

    for (int i = 0; i < n; i++) {
        Pais p;
        p.id = i+1;
        v.push_back(p);
    }

    for (int i = 0; i < m; i++) {
        int ouro, prata, bronze;
        cin >> ouro >> prata >> bronze;
        v[ouro-1].ouro++;
        v[prata-1].prata++;
        v[bronze-1].bronze++;
    }

    sort(v.begin(), v.end(), comparator());

    for (int i = 0; i < n; i++) {
        cout << v[i].id << " ";
    }


}