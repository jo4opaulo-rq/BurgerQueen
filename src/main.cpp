#include <iostream>
#include <map>
#include "gerente.hpp"
#include "cliente.hpp"
#include <stdlib.h>

using namespace std;

int main()
{
    int escolha;
    lerArquivoSanduiche();
    lerArquivoSucos();
    string produto;
    string usuario;
    string senha;

    while (escolha != 0)
    {
        cout << "*******************\n";
        cout << "*  1 - Cliente    *\n";
        cout << "*  2 - Gerente    *\n";
        cout << "*  0 - Sair       *\n";
        cout << "*******************\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha)
        {
        case 0:
            break;
        case 1: 
            cout << endl;
            cout << "\t \U0001f96a Boas vindas ao BurgerQueen \U0001f964"<< endl;
            cout << endl;

            cliente(); // chama a função principal do arquivo cliente.cpp
            break;
        case 2:
            cin.ignore();
            cout << "Degite seu usuário: ";
            getline(cin, usuario);
            cout << "Degite seu senha: ";
            getline(cin, senha);
            if (usuario == "admin" && senha == "admin")
            {
                gerente(); // chama a função principal do arquivo gerente.cpp
            }
            else
            {
                cout << "\nUsuário ou senha incorreta" << endl;
            }
            break;
        default:
            cout << "Opção inválida\n";
            break;
        }
        break;
    }
}