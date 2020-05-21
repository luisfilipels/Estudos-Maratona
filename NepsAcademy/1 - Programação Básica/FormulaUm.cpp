//
// Created by luisf on 07/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

struct Piloto {
    int id = -1;
    int pontuacao = 0;
    vector<int> vitoriasPorPosicao;

    explicit Piloto (int p) {
        for (int i = 0; i < p; i++) {
            vitoriasPorPosicao.push_back(0);
        }
    }
};

bool comparePilot (Piloto A, Piloto B) {
    if (A.pontuacao != B.pontuacao) return A.pontuacao > B.pontuacao;

    return A.id < B.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int g = 1, p = 1; //G: Grandes premios, P: Pilotos
    vector<vector<int>> respostas;

    while (true) {
        cin >> g >> p;  // Ler G e P para cada instância

        if (g == 0 && p == 0) break;

        vector<Piloto> v;   // Vetor de vetor que contém cada ordem de colocações dos pilotos

        for (int i = 0; i < p; i++) {
            Piloto novo(p);
            novo.id = i+1;      // Criar piloto, e atribuir sua id
            v.push_back(novo);
        }
        for (int i = 0; i < g; i++) {
            for (int j = 0; j < p; j++) {
                int pos;
                cin >> pos;
                v[j].vitoriasPorPosicao[pos-1]++;   // Contabilizar vitórias desse piloto, seja lá qual a posição em que tenha terminado um GP
            }
        }

        int s;
        cin >> s;

        vector<vector<int>> sistemas;

        for (int i = 0; i < s; i++) {   // Armazenando um sistema.
            int k;
            cin >> k;

            vector<int> novo;
            sistemas.push_back(novo);
            for (int j = 0; j < k; j++) {
                int a;
                cin >> a;
                sistemas[sistemas.size()-1].push_back(a);
            }
        }

        for (vector<int> sistema : sistemas) {
            vector<int> novaResposta;
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < sistema.size(); j++) {
                    v[i].pontuacao += v[i].vitoriasPorPosicao[j] * sistema[j];  // Para cada posição do sistema, a pontuação do piloto aumenta pelo número de vitórias que ele teve na posição j
                }
            }
            sort(v.begin(), v.end(), comparePilot);
            int pontuacaoCampea = v[0].pontuacao;
            int i = 0;
            while (v[i].pontuacao == pontuacaoCampea) {
                novaResposta.push_back(v[i].id);
                i++;
            }
            for (int i = 0; i < v.size(); i++) {
                v[i].pontuacao = 0;
            }
            respostas.push_back(novaResposta);
        }
    }

    for (vector<int> vencedores : respostas) {
        for (int x : vencedores) {
            cout << x << " ";
        }
        cout << endl;
    }
}

/*int g, n;

vector<int> solvre(vector<vector<int>> &posicoes, vector<int> &sistema){
    vector<int> pontos(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            pontos[i] += sistema[j]*posicoes[i][j];
        }
    }
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, pontos[i]);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(pontos[i] == maxi) ans.push_back(i);
    }
    return ans;
}

int main(){
    while(cin >> g >> n, n){
        vector<vector<int>> posicoes(n, vector<int>(n,0));
        for(int i = 0; i < g; i++){
            for(int j = 0; j < n; j++){
                int aux;
                scanf("%d", &aux);
                aux--; // indexar em 0
                posicoes[j][aux]++;
            }
        }
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            vector<int> sistema;
            int m;
            scanf("%d", &m);
            sistema.resize(n, 0);
            for(int j = 0; j < m; j++){
                int aux;
                scanf("%d", &aux);
                sistema[j] = aux;
            }
            vector<int> ans = solvre(posicoes, sistema);
            for(int j : ans){
                printf("%d ", j+1);
            }
            printf("\n");
        }
    }
    return 0;
}*/