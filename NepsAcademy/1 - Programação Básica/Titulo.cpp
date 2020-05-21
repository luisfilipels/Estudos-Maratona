//
// Created by luisf on 05/05/2020.
//

#include <iostream>
#include <vector>

using namespace std;

string title(string F){
    vector<string> v;
    string current = "";
    for (char c : F) {
        if (c != ' ') {
            current += c;
        } else {
            v.push_back(current);
            current = "";
        }
    }
    v.push_back(current);
    string returnString = "";
    for (string s : v) {
        s[0] = toupper(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == toupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
        returnString += s + " ";
    }
    return returnString;
}

int main(){
    string F;

    getline(cin, F);

    cout << title(F) << "\n";
}