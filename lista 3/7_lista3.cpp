#include <iostream>
using namespace std;

#include "pilha.hpp"

struct Caixa
{
 int codigo;
 float peso;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int menu;
    do{
        cout<<"MENU:"<<endl;
        cout<<"0 - Sair do programa"<<endl;
        cout<<"1 - Definir quantidade de caixas"<<endl;
        cout<<"2 - Carregar caixa"<<endl;
        cout<<"3 - Descarregar caixa"<<endl;
        cout<<"4 - Mostrar carga"<<endl;
        cin>>menu;
    }while(menu!=0);


}
