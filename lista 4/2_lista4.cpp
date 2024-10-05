#include <iostream>
using namespace std;

#include "pilhadinamica_char.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    string str;
    getline(cin, str);
    fflush(stdin);

    Pilha p;


    for (int i=0; i<str.size(); i++)
    {
        if (str[i]!=' ')
            empilhaP(&p, str[i]);
        //mostraP(&p);
        if (str[i] == ' ' || i==str.size()-1)
        {
            while(!vaziaP(&p))
            {
                cout<<desempilhaP(&p);
            }
            cout<<' ';
        }
    }
    cout<<endl;
    mostraP(&p);

}
