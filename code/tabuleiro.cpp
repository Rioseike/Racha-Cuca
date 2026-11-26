#include "tabuleiro.h"
#include<bits/stdc++.h>
using namespace std;

Tabuleiro::Tabuleiro(int n) {
    this->n = n;
    //      copia linhas embaixo            esse vetor coloca numeros 0 em todas as colunas
     casas = vector<vector<int>>(n, vector<int>(n, 0));

    //essas repetições atribuem o valor de cada casa em i e j
    int contador = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            casas[i][j] = contador;
            contador++;
        }
    }

    // mostra qual é o bloco vazio, e guarda onde ele está
    casas[n - 1][n - 1] = 0;
    linhaVazio = n - 1;
    colunaVazio = n - 1;
}

//Esses são os getters que pegam as informações dos tabuleiros
int Tabuleiro::getN() const {
    return n;
}

int Tabuleiro::getPeca(int linha, int coluna) const {
    return casas[linha][coluna];
}

int Tabuleiro::getLinhaVazio() const {
    return linhaVazio;
}

int Tabuleiro::getColunaVazio() const {
    return colunaVazio;
}

//Implementar a função que verifica se os numeros das casas estão em ordem
bool Tabuleiro::estaResolvido() const {
    int esperado = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == n - 1) {
                return casas[i][j] == 0;
            }
            //se for diferente do numero esperado na casa, o jogo continua
            if (casas[i][j] != esperado) {
                return false;
            }
            esperado++;
        }
    }
    //quando for true, o tabuleiro está resolvido
    return true;
}

//Essa função imprime os valores da casa para a gente visualizar o tabuleiro
void Tabuleiro::imprimir() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (casas[i][j] == 0) {
                cout << setw(3) << "_";
            } else {
                cout << setw(3) << casas[i][j];
            }
        }
        cout << endl;
    }
}