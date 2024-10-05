#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

float **gera_matriz(int lin, int col)
{
    float **mat = new float*[lin];
    for (int i = 0; i < lin; i++)
    {
        mat[i] = new float[col];
    }
    return mat;
}

void deleta_matriz(float **mat, int lin)
{
    for (int i = 0; i < lin; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

float **soma_mat(float **matA, float **matB, int lin, int col)
{
    float **resultado = gera_matriz(lin, col);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            resultado[i][j] = matA[i][j] + matB[i][j];
        }
    }
    return resultado;
}

void gera_random(float **matx, int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matx[i][j] = rand() % 101;
        }
    }
}

void mostra_matriz(float **matx, int lin, int col, const string& name)
{
    cout << "\nMatriz " << name << ":" << endl;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matx[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    int lin, col;

    cout << "Digite o número de linhas da matriz: ";
    cin >> lin;
    cout << "Digite o número de colunas da matriz: ";
    cin >> col;

    float **matrizA = gera_matriz(lin, col);
    float **matrizB = gera_matriz(lin, col);

    gera_random(matrizA, lin, col);
    gera_random(matrizB, lin, col);

    float **resultMat = soma_mat(matrizA, matrizB, lin, col);

    mostra_matriz(matrizA, lin, col, "A");
    mostra_matriz(matrizB, lin, col, "B");
    mostra_matriz(resultMat, lin, col, "Resultado");

    deleta_matriz(matrizA, lin);
    deleta_matriz(matrizB, lin);
    deleta_matriz(resultMat, lin);

    return 0;
}
