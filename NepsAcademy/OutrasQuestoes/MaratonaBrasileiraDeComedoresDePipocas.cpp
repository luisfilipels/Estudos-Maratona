//
// Created by luisf on 13/11/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int popcornsOriginal[10010];

bool canEat (int n, int time, int popcornPerSecond, int competitors) {
    if (time <= 0) return false;

    int currentPopcorn = 0;
    int popcorns[n];
    memcpy(popcorns, popcornsOriginal, n * sizeof(int));
    while (competitors > 0 && currentPopcorn < n) {
        int currentTime = time;
        while(currentPopcorn < n && currentTime > 0) {
            while(popcorns[currentPopcorn] > 0) {
                popcorns[currentPopcorn] -= popcornPerSecond;
                currentTime--;
                if (currentTime < 0) {
                    popcorns[currentPopcorn] = popcornsOriginal[currentPopcorn];
                    currentPopcorn--;
                    break;
                }
            }
            currentPopcorn++;
        }
        competitors--;
    }
    if (currentPopcorn == n) {
        return true;
    }
    return false;
}

int main() {
    int n, c, t;

    cin >> n >> c >> t;

    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> popcornsOriginal[i];
        m = max(m, popcornsOriginal[i]);
    }

    int start = 0, end = INT_MAX;

    while (start < end) {
        int attempt = (end - start) / 2 + start;

        if(canEat(n, attempt, t, c)) {
            end = attempt-1;
        } else {
            start = attempt+1;
        }
    }

    bool tryMinus1 = canEat(n, start-1, t, c);
    bool tryMinus0 = canEat(n, start, t, c);

    if (start-1 >= 0 && tryMinus1) {
        cout << start-1;
    } else if (start >= 0 && tryMinus0) {
        cout << start;
    } else {
        cout << start+1;
    }

    /*for (int i = 0; i < 100; i++) {
        cout << "i =" << i << ": " << canEat(n, i, t, c) << endl;
    }*/
}
