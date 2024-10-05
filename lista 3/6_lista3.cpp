#include <iostream>
using namespace std;

#include "pilha.hpp"

bool pilhasIguais(Pilha *p1, Pilha *p2)
{
    if (p1->topo != p2->topo) //se tamanhos diferentes
    {
        return false;
    }

    Pilha paux1, paux2;
    inicializaP(&paux1, p1->tam); // guarda o p1 que vai ser desempilhado
    inicializaP(&paux2, p2->tam); // guarda o p2 que vai ser desempilhado
    bool iguais = true; // comeca verdadeiro

    while (!vaziaP(p1) && !vaziaP(p2)) // enquanto as pilhas não estão vazias
    {
        int aux1 = desempilhaP(p1); // desempilha de p1 e vai pro aux1
        int aux2 = desempilhaP(p2); // desempilha de p2 e vai pro aux2

        if (aux1 != aux2)// se forem diferentes
        {
            iguais = false;
        }

        empilhaP(&paux1, aux1); // guarda em paux1
        empilhaP(&paux2, aux2); // guarda em paux2
    }

    // restaura p1
    while (!vaziaP(&paux1))
    {
        empilhaP(p1, desempilhaP(&paux1));
    }

    // restaura p2
    while (!vaziaP(&paux2))
    {
        empilhaP(p2, desempilhaP(&paux2));
    }

    return iguais;
}

int contaPares(Pilha *p)
{
    int contpar = 0;
    Pilha paux;
    inicializaP(&paux, p->tam); // mesma lógica, guarda os desempilhados

    while (!vaziaP(p)) // enquanto a pilha não está vazia
    {
        int elem = desempilhaP(p); // desempilha
        if (elem % 2 == 0) // se o elemento é par
        {
            contpar++; // incrementa contador de pares
        }
        empilhaP(&paux, elem); // guarda o elemento na pilha auxiliar
    }

    // restaura a pilha original
    while (!vaziaP(&paux))
    {
        empilhaP(p, desempilhaP(&paux));
    }

    return contpar; // retorna a contagem de pares
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Pilha p2;
    inicializaP(&p1, 10);
    inicializaP(&p2, 10);

    empilhaP(&p1, 100);
    empilhaP(&p1, 40);
    empilhaP(&p1, -3);

    empilhaP(&p2, 100);
    empilhaP(&p2, 40);
    empilhaP(&p2, -3);
    empilhaP(&p2, 100);

    cout << "P1: ";
    mostraP(&p1);
    cout << "P2: ";
    mostraP(&p2);

    if (pilhasIguais(&p1, &p2))
    {
        cout << "As pilhas são iguais." << endl;
    }
    else
    {
        cout << "As pilhas são diferentes." << endl;
    }

    int contpar1 = contaPares(&p1); // contar pares na pilha 1
    int contpar2 = contaPares(&p2); // contar pares na pilha 2

    cout << "\nPares na pilha 1: " << contpar1;
    cout << "\nPares na pilha 2: " << contpar2 << endl;

    return 0;
}
