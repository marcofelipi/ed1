#include<iostream>
#include<string>
#include<ctime>

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

    cout << "###MENU###\n";
    cout << "0- Sair\n";
    cout << "1- Gerar\n";
	cout << "2- Gerar pasando o vetor por refer�ncia\n";
    cout << "3- Mostar\n";
    do
    {
        cout << "Digite a op��o: ";
        cin >> menu;

        if(menu<0 || menu>3)
        {
            cout << "Erro: op��o inv�lida!\n";
            continue;
        }

        if(menu==1){
            cout << "Informe o tamanho: ";
            cin >> tam;
			cout << "Endere�o de V antes de gerar o vetor: " << v << endl;
            gerarV(v, tam);
			cout << "Endere�o de V depois de gerar o vetor: " << v << endl;
        }
		if(menu==2){
            cout << "Informe o tamanho: ";
            cin >> tam;
			cout << "Endere�o de V antes de gerar o vetor: " << v << endl;
            gerarV(&v, tam);
			cout << "Endere�o de V depois de gerar o vetor: " << v << endl;
        }
        else if(menu == 3)
        {
            mostrarV(v, tam);

        }

    }while(menu!=0);

    if(v!=NULL)
        delete[] v;


    return 0;
}
