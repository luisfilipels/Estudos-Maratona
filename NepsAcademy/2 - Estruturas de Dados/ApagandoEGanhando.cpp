//
// Created by luisf on 12/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<char> stack;

    int n, d;

    vector<string> answer;

    while (true) {
        cin >> n >> d;

        if (n == 0 && d == 0) break;

        string lido;
        cin >> lido;

        stack.push(lido[0]);
        int apagados = 0;
        for (int i = 1; i < lido.size(); i++) {
            char atual = lido[i];
            if (atual > stack.top() && apagados < d) {
                while (!stack.empty() && atual > stack.top() && apagados < d) {
                    stack.pop();
                    apagados++;
                }
            }
            if (stack.size() < n - d) {
                stack.push(atual);
            }
        }
        string s;
        while (!stack.empty()) {
            s += stack.top();
            stack.pop();
        }
        answer.push_back(s);


    }

    for (string s : answer) {
        for (int i = s.size()-1; i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;
    }
}