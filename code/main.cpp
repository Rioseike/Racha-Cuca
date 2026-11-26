#include <iostream>
#include "tabuleiro.h"
using namespace std;

int main() {
    Tabuleiro t(4);
    t.imprimir();
    
    cout << endl << "Mover C:" << endl;
    t.mover('C');
    t.imprimir();

    cout << endl << "Mover E:" << endl;
    t.mover('E');
    t.imprimir();

    cout << endl << "Mover D (volta):" << endl;
    t.mover('D');
    t.imprimir();

    cout << endl << "Mover B (volta):" << endl;
    t.mover('B');
    t.imprimir();
    cout << "Resolvido? " << (t.estaResolvido() ? "sim" : "nao") << endl;

    cout << endl << "Mover B de novo (invalido): ";
    cout << (t.mover('B') ? "moveu" : "nao moveu") << endl;

    
    

    return 0;
}