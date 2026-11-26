#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
using namespace std;

class Tabuleiro {
public:
    Tabuleiro(int n);

    int getN() const;
    int getPeca(int linha, int coluna) const;
    int getLinhaVazio() const;
    int getColunaVazio() const;

    bool estaResolvido() const;
    void imprimir() const;

    bool podeMover(char direcao) const;
    bool mover(char direcao);

private:
    int n;
    vector<vector<int>> casas;
    int linhaVazio;
    int colunaVazio;

};

#endif 