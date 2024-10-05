#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define TAM 10

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int *pvet = NULL;
    int menu;
    do{
        cout << "MENU:" << endl;
        cout << "0 - sair do programa" << endl;
        cout << "1 - gerar vetor" << endl;
        cout << "2 - mostrar vetor" << endl;
        cin >> menu;
        if(menu == 0)
        {
            system("cls");
            cout<<"Programa encerrado!";
        }
        if (menu == 1)
        {
            if (pvet != NULL)
            {
                delete[] pvet; // liberar memória se vetor for diferente de nulo
                cout<<"Memória liberada. ";
            }

            pvet = new int[TAM]; // atribui valor ao pvet
            for (int i = 0; i < TAM; i++)
            {
                pvet[i] = rand() % 31 + 20;
            }
            cout << "Novo vetor gerado!" << endl;
        }

        if (menu == 2)
        {
            if (pvet == NULL)
            {
                cout << "vetor não pode ser nulo." << endl;
            }
            else // imprime vetor
            {
                for (int i = 0; i < TAM; i++)
                {
                    cout << pvet[i] << " ";
                }
                cout << endl;
            }
        }

    }while(menu != 0);


    if (pvet != NULL) // liberar memória do programa
    {
        delete[] pvet;
    }
}

