#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Erro: divis�o por zero!" << endl;
        return 0;
    }
}

main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    ifstream entrada("entrada.txt");

    if(!entrada)
    {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
    }

    string line, operacao;
    double num1, num2;

    while (getline(entrada, line))
    {
        stringstream ss(line);
        ss >> operacao >> num1 >> num2;

        if (operacao == "SOMA")
        {
            cout << "Resultado da soma: " << soma(num1, num2) << endl;
        }
        else if (operacao == "SUBTRACAO")
        {
            cout << "Resultado da subtra��o: " << subtracao(num1, num2) << endl;
        }
        else if (operacao == "MULTIPLICACAO")
        {
            cout << "Resultado da multiplica��o: " << multiplicacao(num1, num2) << endl;
        }
        else if (operacao == "DIVISAO")
        {
            cout << "Resultado da divis�o: " << divisao(num1, num2) << endl;
        }
        else
        {
            cerr << "Opera��o inv�lida: " << operacao << endl;
        }
    }

    entrada.close();
}
