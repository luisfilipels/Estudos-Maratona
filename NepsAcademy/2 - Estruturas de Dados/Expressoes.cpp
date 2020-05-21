//
// Created by luisf on 12/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<char> stack;

    int t;

    cin >> t;

    vector<string> v;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        for (char c : s) {
            if (stack.empty()) {
                stack.push(c);
            } else {
                if (c == '(' || c == '[' || c == '{') {
                    stack.push(c);
                } else {
                    char top = stack.top();
                    if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}')) {
                        break;
                    } else {
                        stack.pop();
                    }
                }
            }
        }
        if (stack.empty()) {
            v.emplace_back("S");
        } else {
            v.emplace_back("N");
        }
        while (!stack.empty()) {
            stack.pop();
        }
    }
    for (string c : v) {
        cout << c << endl;
    }
}