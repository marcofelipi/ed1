#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "pilha.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    int tamPilha, valor;
    int menu;
    do{
        cout<<"\nMENU:"<<endl;
        cout<<"0 - Sair do programa"<<endl;
        cout<<"1 - Criar pilha"<<endl;
        cout<<"2 - Inserir elemento"<<endl;
        cout<<"3 - Remover elemento"<<endl;
        cout<<"4 - Consultar elemento"<<endl;
        cout<<"5 - Mostrar pilha"<<endl;
        cin>>menu;
        if(menu>=1 and menu<=5)
        {
            if ()
            continue;
        }
        if(menu==0)
        {
            system("cls");
            cout<<"Programa encerrado.";
        }
        if(menu==1)
        {
            system("cls");
            cout<<"Tamanho da pilha: ";
            cin>>tamPilha;
            if (verificaInicializacaoP(&p1) == true)
            {
                cout<<"Pilha já inicializada.";
                destroiP(&p1);
                cout<<"Pilha removida e memória desalocada.";
            }
            inicializaP(&p1, tamPilha); //p1 por referencia, tampilha
            cout<<"\nPilha nova inicializada.";

        }
        if(menu==2)
        {
            system("cls");
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
        if(menu==3)
        {
            system("cls");
            if (vaziaP(&p1) == false)
            {
                int desempilhado = desempilhaP(&p1);
                cout<<desempilhado<<" foi removido da pilha. "<<endl;
            }
            mostraP(&p1);
        }
        if(menu==4)
        {
            system("cls");
            cout << "Informe um valor para buscar na pilha:";
            cin >> valor;
            if(buscaP(&p1, valor) == true)
                cout << "O valor " << valor << " foi encontrado na pilha!\n";
            else
                cout << "O valor " << valor << " NÃO foi encontrado na pilha!\n";
        }
        if(menu==5)
        {
            system("cls");
            mostraP(&p1);
        }
    }while(menu!=0);
}
