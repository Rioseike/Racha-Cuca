#include <iostream>
#include "tabuleiro.h"
using namespace std;

int main() {
    Tabuleiro t(4);
    t.embaralhar(20, 7);
    t.imprimir();
    cout << "Resolvido? " << (t.estaResolvido() ? "sim" : "nao") << endl;

    return 0;
}
    