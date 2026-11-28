#include "solucionador.h"
#include <bits/stdc++.h>
using namespace std;

vector<char> resolver(const Tabuleiro& inicial) {
    //essa sera a lista dos movimentos, q começa vazia
    vector<char> caminho;

    // se ja estiver resolvida, a lista é vazia
    if (inicial.estaResolvido()){
        return caminho;
    }

    queue<Tabuleiro> fila;
    //tabela hash, com a chave sendo o texto do tabuleiro, e o no sendo o valor
    unordered_map<string, No> caderno;

    //o nó raiz é o primeiro, ent nao tem um pai
    No raiz;
    raiz.pai = "";
    raiz.movimento = ' ';
    //anota a casa principal
    caderno[inicial.paraTexto()] = raiz;
    //coloca a casa na fila.
    fila.push(inicial);

    //enquanto a fila nn esvaziar, vai repetindo
     while (!fila.empty()) {
        //destaca o primeiro da fila e coloca em atual
        Tabuleiro atual = fila.front();
        fila.pop();

        char direcoes[4] = {'C', 'B', 'E', 'D'};
        //  percorre as 4 direções 
            for (int k = 0; k < 4; k++) {
                char dir = direcoes[k];

                //se a direção é incorreta, pula e faz a proxima direção 
                if (!atual.podeMover(dir)) {
                    continue;
                }

                //copia o tabuleiro atual para mexermos apenas na cópia e mantendo o original
                Tabuleiro vizinho = atual;
                //faz a movimento na copia
                vizinho.mover(dir);

                string chave = vizinho.paraTexto();

                //se uma casa ja foi verificada, não volta nela 
                if (caderno.count(chave) > 0) {
                    continue;
                }

                //cria um no da casa
                No novo;
                //mostra de onde veio
                novo.pai = atual.paraTexto();
                //mostra de qual casa viemos 
                novo.movimento = dir;
                //anota onde passou
                caderno[chave] = novo;


                //coloca a casa na fila para ser verificada depois 
                fila.push(vizinho);

                if (vizinho.estaResolvido()) {
                    // achamos a saída, agora voltamos pelos pais
                    string atualChave = chave;
                    while (caderno[atualChave].pai != "") {
                        caminho.push_back(caderno[atualChave].movimento);
                        atualChave = caderno[atualChave].pai;
                    }
                    
                    //invertemos pois o caminho está de trás para frente
                    reverse(caminho.begin(), caminho.end());
                    return caminho;
                }

                fila.push(vizinho);

                if (vizinho.estaResolvido()) {
                    string atualChave = chave;
                    while (caderno[atualChave].pai != "") {
                        caminho.push_back(caderno[atualChave].movimento);
                        atualChave = caderno[atualChave].pai;
                    }

                    reverse(caminho.begin(), caminho.end());
                    return caminho;
                }
            }
        }
    return caminho;
}

