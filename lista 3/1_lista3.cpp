#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "pilhachar.hpp"

bool textopalindromo (string str)
{
    //cout << "string recebida: " << str << endl;
    Pilha p;
    inicializaP(&p, str.size());
    for(int i=0; i<str.size(); i++)
    {
      //  cout << str[i] << " ";
        if (isalpha(str[i])>0)
        {
            empilhaP(&p, str[i]);

        }

    }
   // cout << endl;
    bool palindromo = true;
    for (int i=0; i<str.size(); i++)
    {
        if (isalpha(str[i]) > 0)
        {
            char c = desempilhaP(&p);

            if(toupper(c) != toupper(str[i]))
            {
                palindromo = false;
                break;
            }
        }
    }
    destroiP(&p);
    return palindromo;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string str;
    cout<<"Digite um texto: ";
    getline(cin, str);
    fflush(stdin);

    cout<<"Frase lida: "<<str<<endl;

    if (textopalindromo(str))
        cout<< str << " é um palindromo!\n";
    else
        cout<< str << " não é um palindromo!\n";


}
