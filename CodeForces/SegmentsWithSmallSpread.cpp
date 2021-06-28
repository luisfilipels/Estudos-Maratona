//
// Created by Luis Filipe on 6/28/2021.
//

/*
L = 0
for R = 0..n-1
    add(a[R])
    while not good():
        remove(a[L])
        L++
    add_to_sum()
*/

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

struct Stack {
    vector<ll> s, smin = {LLONG_MAX}, smax = {LLONG_MIN};

    void push(ll x) {
        s.pb(x);
        smin.pb(::min(smin.back(), x));
        smax.pb(::max(smax.back(), x));
    }

    ll pop() {
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }

    bool isEmpty() {
        return s.empty();
    }

    ll min() {
        return smin.back();
    }

    ll max() {
        return smax.back();
    }
};

Stack s1, s2;

void add(ll x) {
    s2.push(x);
}

void remove() {
    if (s1.isEmpty()) {
        while (!s2.isEmpty()) {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}


ll K, N;
const int MAX_N = 100010;
ll nums[MAX_N];

bool good() {
    ll mini = min(s1.min(), s2.min());
    ll maxi = max(s1.max(), s2.max());

    return maxi - mini <= K;
}

int main() {
    Fast;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0;
    ll sum = 0;
    for (int end = 0; end < N; end++) {
        add(nums[end]);
        while (!good()) {
            remove();
            start++;
        }
        sum += end - start + 1;
    }

    cout << sum;
}