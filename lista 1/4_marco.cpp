#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define TAM 10

using namespace std;
struct registro
{
    int cpf;
    string nome;
    int ano;
};
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numclientes;
    cout<<"Número de clientes: ";
    cin>>numclientes;
    registro *clientes = new registro[numclientes]; //ponteiro clientes do tipo struct registro, com tamanho numclientes

    for(int i = 0; i < numclientes; i++)
    {
        cout << "Informe o CPF do " << i+1 << " cliente: ";
        cin >> clientes[i].cpf;
        fflush(stdin);//limpa entrada
        cout << "Informe o Nome do " << i+1 << " cliente: ";
        getline(cin, clientes[i].nome); //pra receber string
        fflush(stdin);
        cout << "Informe o ANO de nascimento do " << i+1 << " cliente: ";
        cin >> clientes[i].ano;
        fflush(stdin);

        cout << endl;
    }

    cout << "Clientes cadastrados " << endl;
    for(int x = 0; x < numclientes; x++)
    {

        cout << "CPF: " << clientes[x].cpf << endl;
        fflush(stdin);
        cout << "Nome: " << clientes[x].nome << endl;
        fflush(stdin);
        cout << "Ano de nascimento: " << clientes[x].ano << endl;
        fflush(stdin);

        cout << endl;
    }
    if (clientes!=NULL)
    {
        delete[] clientes;
        cout<<"Liberou memória.";
    }

}

