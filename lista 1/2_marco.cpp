#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

#define TAM 10

main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int *pvet = new int[TAM]; // vetor com 10 lugares

    cout << "vetor: ";
    for(int i = 0; i < TAM; i++)
    {
        pvet[i] = rand() % 31 + 20;

        cout << pvet[i] << " ";
    }

    cout << endl;

    delete[] pvet; //libera a memoria alocada
}
