#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

void gerarV(int *v, int tam)
{
    v = new int[tam];

    for (int i=0; i<tam; i++)
    {
        v[i] = rand()%100;
    }
}

void gerarV(int **v, int tam)
{
    if(*v != NULL)
        delete[] *v;

    *v = new int[tam];

    for (int i=0; i<tam; i++)
    {
        (*v)[i] = rand()%100;
    }

}

void mostrarV(int *v, int tam)
{
    cout << "Vetor: ";
    if(v!=NULL)
    {
        for (int i=0; i<tam; i++)
        {
            cout << v[i] << ", ";
        }
        cout << endl;
    }
    else
        cout << "NULL\n";
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *v = NULL;
    int tam, menu;

    do
    {
        cout << "\n###MENU###\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar vetor\n";
        cout << "2 - Mostar vetor\n";
        cout << "Digite a opção: ";
        cin >> menu;

        if(menu<0 || menu>3)
        {
            cout << "Erro: opção inválida!\n";
            continue;
        }
        if(menu == 1)
        {
            cout << "Informe o tamanho: ";
            cin >> tam;
            gerarV(&v, tam);
        }
        else if(menu == 2)
        {
            mostrarV(v, tam);
        }
    }
    while(menu != 0);

    if(v != NULL)
        delete[] v;


    return 0;
}
