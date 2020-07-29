//
// Created by Luis Filipe on 7/28/2020.
//

#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

bool isStart(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isEnd(char c) {
    return c == ')' || c == ']' || c == '}';
}

char getOpposite(char c) {
    switch (c) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
        case '{':
            return '}';
        case '}':
            return '{';
    }
}

int main() {
    Fast;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string input;
        cin >> input;

        stack<char> stack;
        int i;
        for (i = 0; i < input.length(); i++) {
            char c = input[i];
            if (stack.empty()) {
                if (isEnd(c)) {
                    stack.push('*');
                    break;
                } else {
                    stack.push(c);
                }
            } else {
                char top = stack.top();
                if (isStart(c)) {
                    stack.push(c);
                } else {
                    if (getOpposite(c) == top) stack.pop();
                    else {
                        stack.push('*');
                        break;
                    }
                }
            }
        }
        if (stack.empty()) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}