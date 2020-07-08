//
// Created by luisf on 07/07/2020.
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
    // Pode-se haver a primeira ideia de inserir os números num set e fazer alguma verificação envolvendo arr[i] e arr[i] * k,
    // porém, o correto a se fazer é pensar nessa questão em termos de arr[i] e arr[i] / k, o que facilita o trabalho a ser
    // realizado uma vez que o array tenha sido ordenado.

    Fast;

    ll n, k;
    cin >> n >> k;

    ll arr[n];

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    unordered_set<ll> set;

    for (ll i = 0; i < n; i++) {
        ll div = arr[i] / k;
        ll mod = arr[i] % k;
        if (set.count(div) == 0) {
            set.insert(arr[i]);
        } else {
            if (mod != 0) {
                set.insert(arr[i]);
            }
        }
    }

    cout << set.size();

}