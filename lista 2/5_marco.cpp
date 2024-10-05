#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "pilha.hpp"
#define tamPilha 6

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Pilha par;
    Pilha impar;
    int valor;
    int menu;
    system("cls");
    inicializaP(&p1, tamPilha); //p1 por referencia, tampilha
    if(verificaInicializacaoP(&p1))
            cout<<"\nPilha nova inicializada.";
    for(int i=0; i<tamPilha; i++)
    {

        cout<<"Valor a ser inserido: ";
        cin>>valor;
        if(buscaP(&p1, valor) == true)
        {
            cout<<"Valor já inserido!! Não são permitidos valores repetidos";
            continue;
        }
        bool resultado = empilhaP(&p1, valor);
        if(resultado == true)
            cout << "O valor " << valor << " foi empilhado com sucesso!\n";
        else
            cout << "Não foi possível empilhar o valor " << valor <<"!\n";

        if (cheiaP(&p1) == true)
        {
            cout<<"Pilha cheia.";
        }
    }

    do{
        cout<<"MENU:"<<endl;
        cout<<"1 - zerar as 3 pilhas: ";
        cout<<"2 - mostrar pilha inicial: ";
        cout<<"3 -  pares: ";
        cout<<"4 -  impares: ";
        cin>>menu;
        if (menu==1)
        {
            destroiP(&p1);
            destroiP(&par);
            destroiP(&impar);
        }

    }while(menu!=0)
}

