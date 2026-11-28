#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H
#include "tabuleiro.h"
#include <bits/stdc++.h>
using namespace std;

struct No {
    //Como o texto identifica o tabuleiro, ele funciona como um "ponteiro" para o pai
    string pai;
    char movimento;
    //cada tabuleiro aponta para o pai, e subindo de pai em pai chegamos à raiz de uma arvore
};

//devolve os movimentos                   nn deixa mexer no tabuleiro
vector<char> resolver(const Tabuleiro& inicial);

#endif