//
// Created by luisf on 17/08/2020.
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
    int n;

    int winningCandidate, maxVoteAmount;
    int current;

    // Usar cin para o n, e Fast no início resultam em TLE!

    map<int, int> votes;
    map<int, int>::iterator it;

    while (scanf("%d", &n) != EOF) {
        votes.erase(votes.begin(), votes.end());

        winningCandidate = -1;
        maxVoteAmount = 0;

        for (int i = 0; i < n; i++) {
            cin >> current;

            if (votes.count(current) != 0) {
                votes[current]++;
            } else {
                votes[current] = 1;
            }
        }

        for (it = votes.begin(); it != votes.end(); it++) {
            if ((*it).second > maxVoteAmount) {
                winningCandidate = (*it).first;
                maxVoteAmount = (*it).second;
            }
        }

        cout << winningCandidate << endl;
    }
}