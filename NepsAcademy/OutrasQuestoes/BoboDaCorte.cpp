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

int n;

int main() {
    Fast;

    cin >> n;

    int maxVotes = 0;
    int carlosVotes;

    cin >> carlosVotes;
    maxVotes = max(carlosVotes, maxVotes);

    for (int i = 1; i < n; i++) {
        int candidateVote;
        cin >> candidateVote;
        maxVotes = max(maxVotes, candidateVote);
    }

    if (carlosVotes == maxVotes) cout << "S";
    else cout << "N";
}