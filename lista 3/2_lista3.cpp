#include <iostream>
using namespace std;

#include "pilha.hpp"

void estatisticaP(Pilha *p, int *menor, int *maior, float *media)
{
    if (vaziaP(p)) // se vazia, menor maior e media = 0
    {
        *menor = 0;
        *maior = 0;
        *media = 0;
        return;
    }
    *menor = 100000; // Inicializa menor
    *maior = -100000; // Inicializa maior
    float soma = 0;
    int cont = 0;

    for (int i = p->topo; i>p->base; i--) // começa pelo topo, e desce ate a base
    {
        int valor = p->dados[i];
        if (valor < *menor) // substitui 0 pelo menor
        {
            cout<<"Substitui o menor "<<*menor<<" por "<<valor<<endl;
            *menor = valor;
        }
        if (valor > *maior) //substitui 0 pelo maior
        {
            cout<<"Substitui o maior "<<*maior<<" por "<<valor<<endl;
            *maior = valor;
        }
        soma += valor;
        cont++;
        *media = soma / cont;
    }
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
    mostraP(&p);
    int menor, maior;
    float media;
    estatisticaP(&p, &menor, &maior, &media);
    cout<<"\nMenor: "<<menor<<endl;
    cout<<"Maior: "<<maior<<endl;
    cout<<"Média: "<<media<<endl;

}
