//
// Created by luisf on 02/06/2020.
//

#include <bits/stdc++.h>

using namespace std;

int inversions (vector<int> v) {
    int inversoes = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                inversoes++;
            }
        }
    }
    return inversoes;
}

int mergeSortInversions(vector<int> &v) {
    if (v.size() == 1) return 0;

    vector<int> leftHalf, rightHalf;

    int inversoes = 0;

    for (int i = 0; i < v.size()/2; i++) {
        leftHalf.push_back(v[i]);
    }
    for (int i = v.size()/2; i < v.size(); i++) {
        rightHalf.push_back(v[i]);
    }

    inversoes += mergeSortInversions(leftHalf);
    inversoes += mergeSortInversions(rightHalf);

    leftHalf.push_back(INT_MAX);
    rightHalf.push_back(INT_MAX);

    int i = 0, j = 0;

    for (int k = 0; k < v.size(); k++) {
        if (leftHalf[i] <= rightHalf[j]) {
            v[k] = leftHalf[i++];
        } else {
            // Elemento da direita é maior do que da esquerda (inversão)
            // Ademais, como leftHalf e rightHalf estão ordenados, isso quer dizer que todos os elementos de leftHalf após
            // a posição i são maiores que a[j], logo, estão invertidos.
            // Por exemplo (https://www.youtube.com/watch?v=k9RQh21KrH8):
            /*
             *                i                       j
             * leftHalf = [1, 3, 5]      rightHalf = [2, 4, 6]
             * v = [1, *, *, *, *, *]
             *
             * Vemos que leftHalf[i] é maior que rightHalf[j], mas não apenas isso. Vemos também que leftHalf[i+1] é maior
             * que rightHalf[j], o que configura 2 inversões.
             */
            v[k] = rightHalf[j++];

            inversoes += leftHalf.size() - i - 1;
        }
    }

    return inversoes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 4, 3, 5, 2, 6};

    cout << inversions(v) << endl;

    cout << mergeSortInversions(v) << endl;

}