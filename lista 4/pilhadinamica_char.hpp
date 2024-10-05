
#ifndef _HPP_PILHA_DINAMICACHAR
#define _HPP_PILHA_DINAMICACHAR

#include <iostream>
#include <string> //biblioteca usada para formatar a impress�o da pilha

using namespace std;

struct NoPilha
{
    char dado;    // agora o dado � do tipo char para armazenar caracteres
    NoPilha *prox; // pr�ximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha() { // Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};

bool vaziaP(Pilha *p)
{
    return (p->topo == nullptr);
}

// push (empilhar)
bool empilhaP(Pilha *p, char dado)
{
    NoPilha *novo = new NoPilha(); // cria um novo n�
    if (novo == nullptr) // sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; // armazena o dado no n�
    novo->prox = p->topo; // o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; // atualiza o topo da pilha para o n� criado.
    return true;
}

// pop (desempilhar)
char desempilhaP(Pilha *p)
{
    char dado = '\0'; // valor default para char

    if (!vaziaP(p)) // se n�o estiver vazia, desempilha
    {
        dado = p->topo->dado; // pega o dado armazenado no topo
        NoPilha *apagar = p->topo; // guarda o n� do topo em uma vari�vel auxiliar
        p->topo = p->topo->prox; // atualiza o topo para o pr�ximo elemento

        delete apagar; // libera a mem�ria
    }

    return dado;
}

// peek (espia o topo)
char espiaP(Pilha* p)
{
    char dado = '\0';

    if (!vaziaP(p))
        dado = p->topo->dado;

    return dado;
}

// Mostra o conte�do da pilha
void mostraP(Pilha *p, string nome="")
{
    cout << "PILHA " << nome << ": " << endl;
    if (!vaziaP(p))
    {
        cout << "------------" << endl;
        NoPilha *no = p->topo;
        while (no != nullptr)
        {
            cout << "|" << no->dado << "|" << endl;
            cout << "------------" << endl;
            no = no->prox;
        }
    }
    else
    {
        cout << "------------" << endl;
        cout << "VAZIA\n";
        cout << "------------" << endl;
    }
}

// Busca na pilha
bool buscaP(Pilha *p, char dado)
{
    NoPilha *no = p->topo;
    while (no != nullptr)
    {
        if (no->dado == dado)
            return true;

        no = no->prox;
    }
    return false;
}

// Destroi a pilha
void destroiP(Pilha *p)
{
    while (!vaziaP(p))
        desempilhaP(p); // desempilha e descarta os valores
}

#endif // _HPP_PILHA_DINAMICACHAR
