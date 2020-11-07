//
// Created by luisf on 29/06/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

void sieve(int n, vector<bool> &isPrime) {
    for(int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <=n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    Fast;

    int n;
    cin >>n;

    vector<int> results;

    vector<bool> isPrime(n + 1, true);

    sieve(n, isPrime);

    isPrime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            int q = i;
            while(q <= n) {
                results.push_back(q);
                q *= i;
            }
        }
    }
    cout << results.size() << "\n";
    for(auto x: results)
    {
        cout << x << " ";
    }

}
