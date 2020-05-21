//
// Created by luisf on 15/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

/*struct Client {
    int horaChegada;
    int atendimento;

    Client(int horaChegada, int atendimento) {
        this->horaChegada = horaChegada;
        this->atendimento = atendimento;
    }

};

struct CompareClientLine {
    bool operator () (Client const& c1, Client const& c2) {
        return c1.horaChegada < c2.horaChegada;
    }
};

struct CompareClientAttendance {
    bool operator () (Client const& c1, Client const& c2) {
        if (c1.horaChegada == c2.horaChegada) {
            return c1.atendimento < c2.atendimento;
        }
        return c1.horaChegada < c2.horaChegada;
    }
};*/

int main() {
    // normal priority queue (top is largest): priority_queue<int> q;
    // minheap pq (top is smallest): priority_queue<int, vector<int>, greater<int>> q;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c, n; // caixas, clientes

    cin >> c >> n;

    int count = 0;

    priority_queue<int, vector<int>, greater<int>> caixas;

    for (int i = 0; i < c; i++) {
        caixas.push(0);
    }

    for (int i = 0; i  < n; i++) {
        int t, d;
        cin >> t >> d;

        int horaDoMaisAntigoFimDeAtendimento = caixas.top();
        caixas.pop();

        if (horaDoMaisAntigoFimDeAtendimento > t + 20) {    // Se o fim do atendimento ocorrer num tempo maior que o tempo de chegada desse cliente mais 20
            count++;
        }

        caixas.push(max(t, horaDoMaisAntigoFimDeAtendimento) + d);  // O atendimento do novo cliente pode começar na hora em que ele chegar (se houver caixa livre), ou na hora de saída do último cliente.
    }

    cout << count;
}