//
// Created by luisf on 15/05/2020.
//

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

int pontos[MAXN];
int guildas[MAXN];
int pontosguilda[MAXN];

int achar (int jogador) {
    int raiz = jogador;

    while (raiz != guildas[raiz]) {
        raiz = guildas[raiz];
    }

    while (jogador != raiz) { // Compressão de caminho
        int prox = guildas[jogador];
        guildas[jogador] = raiz;
        jogador = prox;
    }

    return raiz;
}

void unir (int jogador1, int jogador2) {
    int donoGuilda1 = achar(jogador1);
    int donoGuilda2 = achar(jogador2);

    if (donoGuilda1 == donoGuilda2)
        return;

    pontosguilda[donoGuilda2] += pontosguilda[donoGuilda1];
    guildas[donoGuilda1] = donoGuilda2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;

    while (true) {
        cin >> n >> m;

        if (n == m && m == 0) break;

        int vitorias = 0;

        for (int i = 1; i <= n; i++) {
            int atual;
            cin >> atual;
            pontos[i] = atual;
            pontosguilda[i] = atual;
            guildas[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int q, a, b;

            cin >> q >> a >> b;

            if (q == 1) {
                unir(a, b);
            } else {
                int guildaRafael = achar(1);
                int guildaA = achar(a);
                int guildaB = achar(b);

                if (guildaA == guildaRafael) {
                    int pontosA = pontosguilda[guildaA];
                    int pontosB = pontosguilda[guildaB];
                    if (pontosA > pontosB) {
                        vitorias++;
                    }
                } else if (guildaB == guildaRafael) {
                    int pontosA = pontosguilda[guildaA];
                    int pontosB = pontosguilda[guildaB];
                    if (pontosA < pontosB) {
                        vitorias++;
                    }
                }
            }
        }

        cout << vitorias << endl;

    }
}