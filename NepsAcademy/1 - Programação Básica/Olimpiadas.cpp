//
// Created by luisf on 07/05/2020.
//

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Country {
    int id;
    int ouros;
    int pratas;
    int bronzes;
};

bool compareCountry (const Country &A, const Country &B) {
    if (A.ouros != B.ouros) return A.ouros > B.ouros;

    else if (A.pratas != B.pratas) return A.pratas > B.pratas;

    else if (A.bronzes != B.bronzes) return A.bronzes > B.bronzes;

    return A.id < B.id;
}

int main() {

    int N, M;

    cin >> N >> M;

    Country countries[N+10];

    memset(countries, 0, sizeof(countries));

    for (int i = 1; i <= N; i++) {
        countries[i].id = i;
    }

    for (int i = 0; i < M; i++) {
        int ouro, prata, bronze;
        cin >> ouro >> prata >> bronze;
        countries[ouro].ouros++;
        countries[prata].pratas++;
        countries[bronze].bronzes++;
    }

    sort(countries+1, countries + N + 1, compareCountry);

    for (int i = 1; i <= N; i++) {
        cout << countries[i].id << " ";
    }

}