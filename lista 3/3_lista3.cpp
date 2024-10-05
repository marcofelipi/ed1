#include <iostream>
using namespace std;

#include "pilha.hpp"

void inverterPilha(Pilha *p)
{
    Pilha aux1;
    Pilha aux2;
    inicializaP(&aux1, p->tam);
    inicializaP(&aux2, p->tam);

    while (!vaziaP(p)) //diferente de vazia
    {
        int aux = desempilhaP(p); //valoraux
        empilhaP(&aux1, aux);
    }
    while (!vaziaP(&aux1))
    {
        int aux = desempilhaP(&aux1);
        empilhaP(&aux2, aux);
    }
    while (!vaziaP(&aux2))
    {
        int aux = desempilhaP(&aux2);
        empilhaP(p, aux);
    }
    destroiP(&aux1);
    destroiP(&aux2);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p;
    inicializaP(&p, 10);
    empilhaP(&p, 100);
    empilhaP(&p, 40);
    empilhaP(&p, -3);
    empilhaP(&p, 5);
    empilhaP(&p, 1);
    cout<<"PILHA ANTES DA INVERSÃO: \n";
    mostraP(&p);
    inverterPilha(&p);
    cout<<"PILHA DEPOIS DA INVERSÃO: \n";

    mostraP(&p);

}

