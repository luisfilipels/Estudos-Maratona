//
// Created by Luis Filipe on 9/10/2020.
//
// From https://www.youtube.com/watch?v=qTRO41yezFs&list=PLlMaX94qhO1TJ28ImEv2RfQLW4OGQTcRE&index=6
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> adj[102];

int dist[102], max_dist = INT_MIN, ans;

void dfs(int v) {
    for (int x : adj[v]) {
        if (dist[x] != -1) continue;
        dist[x] = dist[v]+1;
        dfs(x);
    }
    if (dist[v] > max_dist) {
        max_dist = dist[v];
    }
}

int main() {
    Fast;

    int n;
    cin >> n;

    int test = 1;

    while (n != 0) {

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        int last_dist = INT_MAX;

        for (int i = 1; i <= n; i++) {
            max_dist = INT_MIN;
            for (int j = 1; j <= n; j++) dist[j] = -1;
            dist[i] = 0;
            dfs(i);
            if (max_dist < last_dist) {
                ans = i;
                last_dist = max_dist;
            }
        }

        cout << "Teste " << test++ << endl;
        cout << ans << endl << endl;
        cin >> n;
    }

    return 0;

}