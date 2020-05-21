//
// Created by luisf on 11/05/2020.
//

#include <bits/stdc++.h>

#define AS 1
#define VALETE 11
#define DAMA 12
#define REI 13

using namespace std;

unordered_map<char, int> m;

struct Card {
    int valor;
    char naipe;

    Card (int x, char s) {
        this->valor = x;
        this->naipe = s;
    }
};

bool compare (Card p1, Card p2) {
    if (p1.valor != p2.valor) {
        return p1.valor > p2.valor;
    }
    return m[p1.naipe] > m[p2.naipe];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Paus < Ouros < Copas < Espadas
    // C      D       H        S
    m['C'] = 1;
    m['D'] = 2;
    m['H'] = 3;
    m['S'] = 4;

    int playerNum, cardsForEachPlayer, cardsInDeck;

    while (true) {
        cin >> playerNum >> cardsForEachPlayer >> cardsInDeck;

        //      p                   m                       n
        if (playerNum == 0 && cardsForEachPlayer == 0 && cardsInDeck == 0) break;

        vector<Card> players[playerNum];

        int currentPlayer = 0;
        int cardsDealt = 0;

        stack<Card> discardStack;
        stack<Card> helpGetCardStack;
        stack<Card> getCardStack;
        bool dealtFirstCardToDiscard = false;

        for (int c = 0; c < cardsInDeck; c++) {
            int valor;
            char naipe;
            cin >> valor >> naipe;
            Card newCard(valor,naipe);
            if (cardsDealt == cardsForEachPlayer) {
                cardsDealt = 0;
                currentPlayer++;
            }
            if (currentPlayer == playerNum) {
                if (!dealtFirstCardToDiscard) {
                    discardStack.push(newCard);
                    dealtFirstCardToDiscard = true;
                } else {
                    helpGetCardStack.push(newCard);
                }
            } else {
                players[currentPlayer].push_back(newCard);
                cardsDealt++;
            }
        }
        while (!helpGetCardStack.empty()) {
            getCardStack.push(helpGetCardStack.top());
            helpGetCardStack.pop();
        }

        bool mustGetOne = false;
        bool mustGetTwo = false;
        bool mustLoseTurn = false;
        int order = 1;

        switch (discardStack.top().valor) {
            case DAMA:
                order = -1;
                break;
            case 7:
                mustGetTwo = true;
                break;
            case AS:
                mustGetOne = true;
                break;
            case VALETE:
                mustLoseTurn = true;
                break;
        }

        currentPlayer = 0;

        while (true) {
            if (mustGetOne) {
                mustGetOne = false;
                players[currentPlayer].push_back(getCardStack.top());
                getCardStack.pop();
            } else if (mustGetTwo) {
                mustGetTwo = false;
                players[currentPlayer].push_back(getCardStack.top());
                getCardStack.pop();
                players[currentPlayer].push_back(getCardStack.top());
                getCardStack.pop();
            } else if (mustLoseTurn) {
                mustLoseTurn = false;
            } else {
                sort(players[currentPlayer].begin(), players[currentPlayer].end(), compare);
                bool foundCard = false;
                Card currentCardToCompare = discardStack.top();
                for (int i = 0; i < players[currentPlayer].size(); i++) {
                    Card c = players[currentPlayer][i];
                    if (c.naipe == currentCardToCompare.naipe || c.valor == currentCardToCompare.valor) {
                        foundCard = true;
                        switch (c.valor) {
                            case DAMA:
                                order = order == 1 ? -1 : 1;
                                break;
                            case 7:
                                mustGetTwo = true;
                                break;
                            case AS:
                                mustGetOne = true;
                                break;
                            case VALETE:
                                mustLoseTurn = true;
                                break;
                        }
                        discardStack.push(c);
                        players[currentPlayer].erase(players[currentPlayer].begin()+i);
                    }
                    if (foundCard) {
                        break;
                    }
                }
                if (players[currentPlayer].empty()) {
                    break;
                }
                if (!foundCard) {
                    Card currentCardToCompare = discardStack.top();
                    Card newCard = getCardStack.top();
                    getCardStack.pop();
                    if (newCard.naipe == currentCardToCompare.naipe || newCard.valor == currentCardToCompare.valor) {
                        switch (newCard.valor) {
                            case DAMA:
                                order = order == 1 ? -1 : 1;
                                break;
                            case 7:
                                mustGetTwo = true;
                                break;
                            case AS:
                                mustGetOne = true;
                                break;
                            case VALETE:
                                mustLoseTurn = true;
                                break;
                        }
                        discardStack.push(newCard);
                    } else {
                        players[currentPlayer].push_back(newCard);
                    }
                }
            }
            currentPlayer = (currentPlayer + order) % playerNum;
            if (currentPlayer == -1) {
                currentPlayer = playerNum-1;
            }
        }
        cout << currentPlayer + 1 << "\n";
    }
}