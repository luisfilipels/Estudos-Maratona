//
// Created by luisf on 15/07/2020.
//

// This lecture at MIT explains the mathematical basis of this question really nicely:
// https://www.youtube.com/watch?v=NuY7szYSXSw
// There is something wrong with this answer, as running it on SPOJ resulted in a segmentation fault :/
// But the general idea is here.

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

int gcd (int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct Jug {
    int capacity;
    int contents;

    Jug(int capacity) {
        this->capacity = capacity;
        contents = 0;
    }

    int fill() {
        int returnVal = dif();
        contents = capacity;
        return returnVal;
    }

    void add(int val) {
        this->contents += val;
    }

    void remove(int val) {
        this->contents -= val;
    }

    int dif() {
        return capacity - contents;
    }

    int empty(){
        this->contents = 0;
    }

    bool isEmpty () {
        return this->contents == 0;
    }

    bool isFull() {
        return this->contents == capacity;
    }

    void pour(Jug &to) {
        if (to.dif() < contents) {
            int dif = to.fill();
            remove(dif);
        } else {
            to.add(contents);
            empty();
        }
    }

};

int pour (Jug from, Jug to, int c) {

    int steps = 0;

    while (from.contents != c && to.contents != c) {
        if (from.isEmpty()) {
            from.fill();
            steps++;
        }

        from.pour(to);

        steps++;

        if (from.contents == c || to.contents == c) {
            return steps;
        }

        if (from.isEmpty()) {
            from.fill();
            steps++;
        }

        if (to.isFull()) {
            to.empty();
            steps++;
        }
    }

}

int main() {
    Fast;

    int t, a, b, c;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;

        if (c > a && c > b) {
            cout << -1 << endl;
            continue;
        }

        if (b > a) {
            int temp = b;
            b = a;
            a = temp;
        }

        int gcdRes = gcd(a, b);

        if (c % gcdRes != 0) {
            cout << -1 << endl;
            continue;
        }

        Jug A(a);
        Jug B(b);

        cout << min(pour(A, B, c), pour(B, A, c)) << endl;
    }

}