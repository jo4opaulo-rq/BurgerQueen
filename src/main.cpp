#include <iostream>
#include <map>
#include "gerente.hpp"
#include "cliente.hpp"
#include <stdlib.h> 

using namespace std;

int main(){
    int escolha;
    lerArquivoSanduiche();
    lerArquivoSucos();
    string produto;

    
    
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
            cliente();
            break;
        case 2:
            gerente();
            break;
        default:
            cout<< "Opção inválida\n";
            break;
        }
    }

}