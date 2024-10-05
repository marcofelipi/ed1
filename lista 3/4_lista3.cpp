#include <iostream>
using namespace std;

#include "pilha.hpp"

void copiaPilha(Pilha *p1, Pilha *p2)
{
    Pilha paux; //pilha auxiliar que vai conter os empilhamentos inversos
    inicializaP(&paux, p1->tam);
    while (!vaziaP(p1)) //diferente de vazia
    {
        int aux = desempilhaP(p1); //desempilha de p1
        empilhaP(&paux, aux); //empilha em paux
    }
    while (!vaziaP(&paux)) //diferente de vazia
    {
        int aux = desempilhaP(&paux); //desempilha de paux
        empilhaP(p2, aux); //empilha na p2
    }
//    mostraP(&paux);
    destroiP(&paux);

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Pilha p2;
    inicializaP(&p1, 10);
    inicializaP(&p2, 10); //inicializando as duas pilhas
    empilhaP(&p1, 100);
    empilhaP(&p1, 40);
    empilhaP(&p1, -3);
    empilhaP(&p1, 5);
    empilhaP(&p1, 51);
    empilhaP(&p1, 444); //empilhando pilha p1
    cout<<"P1:"<<endl;
    mostraP(&p1);
    cout<<endl<<endl;
    cout<<"P2:"<<endl;
    copiaPilha(&p1, &p2);//chama a função
    mostraP(&p2);
}
