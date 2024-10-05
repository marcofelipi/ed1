
#ifndef _HPP_PILHA_DINAMICACHAR
#define _HPP_PILHA_DINAMICACHAR

#include <iostream>
#include <string> //biblioteca usada para formatar a impressão da pilha

using namespace std;

struct NoPilha
{
    char dado;    // agora o dado é do tipo char para armazenar caracteres
    NoPilha *prox; // próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha() { // Construtor. Inicialização da pilha
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
    NoPilha *novo = new NoPilha(); // cria um novo nó
    if (novo == nullptr) // sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; // armazena o dado no nó
    novo->prox = p->topo; // o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; // atualiza o topo da pilha para o nó criado.
    return true;
}

// pop (desempilhar)
char desempilhaP(Pilha *p)
{
    char dado = '\0'; // valor default para char

    if (!vaziaP(p)) // se não estiver vazia, desempilha
    {
        dado = p->topo->dado; // pega o dado armazenado no topo
        NoPilha *apagar = p->topo; // guarda o nó do topo em uma variável auxiliar
        p->topo = p->topo->prox; // atualiza o topo para o próximo elemento

        delete apagar; // libera a memória
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

// Mostra o conteúdo da pilha
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
