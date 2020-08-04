//
// Created by Luis Filipe on 8/3/2020.
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
    Fast;

    int n;

    cin >> n;
    while (n) {
        deque<int> mainStack;
        stack<int> helperStack;
        for (int i = 0; i < n; i++) {
            int read;
            cin >> read;
            mainStack.push_front(read);
        }
        int expected = 1;
        while (!mainStack.empty()) {
            if (!mainStack.empty() && mainStack.back() == expected) {
                mainStack.pop_back();
                expected++;
            } else if (!helperStack.empty() && helperStack.top() == expected) {
                helperStack.pop();
                expected++;
            } else {
                int temp = mainStack.back();
                mainStack.pop_back();
                helperStack.push(temp);
            }
        }
        bool flag = false;
        while (!helperStack.empty()) {
            if (helperStack.top() == expected) {
                expected++;
                helperStack.pop();
            } else {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
        cin >> n;
    }
}