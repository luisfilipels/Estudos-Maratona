//
// Created by Luis Filipe on 10/26/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

struct Coordinate {
    int r, c;
    int distance;

    Coordinate(int r, int c, int distance) {
        this->r = r;
        this->c = c;
        this->distance = distance;
    }
};

class Comparator {
public:
    bool operator() (const Coordinate &c1, const Coordinate &c2) {
        return c1.distance < c2.distance;
    }
};

bool isValid (int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    Fast;

    int n;
    cin >> n;

    int matrix[n][n];
    int dist[n][n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> matrix[r][c];
            dist[r][c] = INT_MAX;
        }
    }

    int movementsHor[4] = {-1, 0, 1, 0};
    int movementsVer[4] = {0, 1, 0, -1};

    dist[0][0] = 0;
    priority_queue<Coordinate, vector<Coordinate>, Comparator> pq;

    auto *start = new Coordinate(0,0,0);
    pq.push(*start);

    while (!pq.empty()) {
        Coordinate current = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int newR = current.r + movementsVer[i];
            int newC = current.c + movementsHor[i];

            if (isValid(newR, newC, n)) {
                if (dist[newR][newC] > dist[current.r][current.c] + matrix[newR][newC]) {
                    if (dist[newR][newC] != INT_MAX)
                    {
                        Coordinate *adj = new Coordinate(newR, newC, dist[newR][newC]);
                        priority_queue<Coordinate, vector<Coordinate>, Comparator> helper;
                        while (!pq.empty()) {
                            Coordinate currentC = pq.top();
                            pq.pop();
                            if (current.r == adj->r && current.c == adj->c && current.distance == adj->distance) {

                            } else {
                                helper.push(currentC);
                            }
                        }
                        while(!helper.empty()) {
                            Coordinate currentC = helper.top();
                            helper.pop();
                            pq.push(currentC);
                        }
                    }
                    dist[newR][newC] = dist[current.r][current.c] + matrix[newR][newC];

                    Coordinate *cor = new Coordinate(newR, newC, dist[newR][newC]);
                    pq.push(*cor);
                }
            }
        }
    }

    cout << dist[n-1][n-1];

}