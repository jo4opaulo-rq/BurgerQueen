#include <iostream>
#include <map>
#include "gerente.hpp"
#include <stdlib.h> 

using namespace std;

int main(){
    int escolha;
    
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
            cout << "Volte sempre\n";
            break;
        
        
        case 1:
            cout << "1\n";
            
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