//
// Created by luisf on 05/05/2020.
//

#include <iostream>
#include <cmath>

using namespace std;

bool eh_primo(int x){
    if (x == 1) return false;
    int raiz = sqrt(x);
    for (int i = 2; i <= raiz; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int x;

    cin>>x;

    if(eh_primo(x)){
        cout << "S" << "\n";
    }else{
        cout << "N" << "\n";
    }
}