#include <iostream>
using namespace std;

#include "pilha-dinamica.hpp"

double mediaAritmeticaP(Pilha *p)
{
    NoPilha *atual = p->topo;
    float soma = 0;
    int cont = 0;

    while (atual != NULL)
    {
        soma += atual->dado;
        cont++;
        atual = atual->prox;
    }

    return (soma) / cont;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p;
    empilhaP(&p, 55);
    empilhaP(&p, 10);
    empilhaP(&p, 25);
    empilhaP(&p, 12);
    cout << "Valores empilhados:\n";
    mostraP(&p);

    float media = mediaAritmeticaP(&p);

    cout << "Média aritmética dos valores na pilha: " << media << endl;

    return 0;
}
