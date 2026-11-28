#include <iostream>
#include "tabuleiro.h"
#include "solucionador.h"
using namespace std;

int main() {
    Tabuleiro t(3);
    t.embaralhar(20, 42);
    t.imprimir();

    vector<char> solucao = resolver(t);

    cout << "Solucao (" << solucao.size() << " movimentos): ";
    for (int i = 0; i < solucao.size(); i++) {
        cout << solucao[i] << " ";
    }
    cout << endl;

    // aplica a solução para conferir
    for (int i = 0; i < solucao.size(); i++) {
        t.mover(solucao[i]);
    }
    cout << "Resolvido? " << (t.estaResolvido() ? "sim" : "nao") << endl;
    return 0;
}