#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "cliente.hpp"
#include "gerente.hpp"
using namespace std;

map<string, float> cardapioSanduicheCliente;
map<string, float> cardapioSucoCliente;
map<string, float> carrinhoCompras;
void retornarCompras();
void lerArquivoSanduicheCliente(){
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::in);
  string temp;
  while(getline(arquivo, temp)){
    linha.push_back(temp);
  }
  arquivo.close();
    
    for(int i = 0; i < linha.size(); i+=2){ 
     cardapioSanduicheCliente[linha[i]]= stof(linha[i+1]);
    }
}


void listarCardapioSanduicheCliente(){
    map<string, float>::iterator it;
    cout << "|----------------------------------------------|" << endl;
    cout << "|             CARDÁPIO SANDUICHES              |"<< endl;
    cout << "|----------------------------------------------|" << endl;

    for (it = cardapioSanduicheCliente.begin(); it != cardapioSanduicheCliente.end(); ++it) {
    cout << "   \t"<< it->first << " preço: R$" << it->second << '\n';
    cout << "|----------------------------------------------|" << endl;
    }
    
    if(cardapioSanduicheCliente.empty()){
    cout << "|\t   Não foram nenhum sanduíche.         |" <<endl;
    cout << "|----------------------------------------------|" << endl;
    }
}

void lerArquivoSucoCliente(){
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::in);
  string temp;
  while(getline(arquivo, temp)){
    linha.push_back(temp);
  }
  arquivo.close();
    
    for(int i = 0; i < linha.size(); i+=2){ 
     cardapioSucoCliente[linha[i]]= stof(linha[i+1]);
    }
}

void listarCardapioSucoCliente(){
    map<string, float>::iterator it;
    cout << "|----------------------------------------------|" << endl;
    cout << "|             CARDÁPIO SUCOS                   |"<< endl;
    cout << "|----------------------------------------------|" << endl;

    for (it = cardapioSucoCliente.begin(); it != cardapioSucoCliente.end(); ++it) {
    cout << "   \t"<< it->first << " preço: R$" << it->second << '\n';
    }
    cout << "|----------------------------------------------|" << endl;

    
    if(cardapioSucoCliente.empty()){
    cout << "|\t   Não foram nenhum sanduíche.         |" <<endl;
    cout << "|----------------------------------------------|" << endl;
    }
}

// void listarProdutos(){
//     lerArquivoSanduicheCliente();
//     lerArquivoSucoCliente();
//     cout << "--------------------|---------------------" << endl; 
//     cout << "\tProduto              Preço" << endl;
//     cout << "--------------------|---------------------" << endl;
//     map<string, float>::iterator it;
//      for (it = cardapioSanduicheCliente.begin(); it != cardapioSanduicheCliente.end(); ++it) {
//         cout << "   \t"<< it->first << "           R$" << it->second << '\n';
//     }
    
//     for (it = cardapioSucoCliente.begin(); it != cardapioSucoCliente.end(); ++it) {
//     cout << "   \t"<< it->first << "                R$" << it->second << '\n';
//     }
//     cout << "--------------------|---------------------" << endl;
// }

void adiconarNoCarrinho(int sanduicheOusuco){
    cin.ignore();
    string produto;
    
    lerArquivoSanduicheCliente();
    lerArquivoSucoCliente();
    map<string, float>::iterator it;
    if (sanduicheOusuco == 1){
        listarCardapioSanduicheCliente();
        cout << "Escolha seu sanduíche:  ";
        getline(cin, produto);
        carrinhoCompras.insert(*cardapioSanduicheCliente.find(produto));

    }if (sanduicheOusuco == 2){   
        listarCardapioSucoCliente();
        cout << "Escolha seu suco:  ";
        getline(cin, produto);
        carrinhoCompras.insert(*cardapioSucoCliente.find(produto));  
    }
    
    fstream arquivo;
    arquivo.open("cardapio/carrinho.txt", ios::out);
    for(it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    } 
}
void retornarCarrinho(){ // adicionar layout !!!!!!!!!!!!!!!!!!!!
  map<string, float>::iterator it;
  for(it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++){ 
    cout  << it->first << endl;
    cout << it->second << endl;
    } 
}

void retornarValorCarrinho(){
  map<string, float>::iterator it;
  float totalcompra;

  for(it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++){ 
    totalcompra += it->second;
    } 
    cout << "Total: " << totalcompra << endl;
}
void excluirPedido(){
  cin.ignore();
  string pedido;
  cout << "Qual pedido deseja remover?: ";
  getline(cin, pedido);
  if(!carrinhoCompras.empty()){     // verifica se o map está vazio
    carrinhoCompras.erase(pedido);
    atualizarCardapioSuco(); // Chama a função para atualizar o arquivo
    cout << "Pedido  excluido" << endl;
  } 
  else{
      cout << "Pedido não encontrado!!!" << endl;
  }  
  
}


void cliente(){
    int escolha = 1;
    lerArquivoSanduicheCliente();
    lerArquivoSucoCliente();

    while (escolha != 0){
        cout << "\t**********************************\n";
        cout << "\t*  1 - Listar sanduiches         *\n";
        cout << "\t*  2 - Listar sucos              *\n";
        cout << "\t*  3 - Comprar                   *\n";
        cout << "\t*  4 - Total das compras         *\n";
        cout << "\t*  5 - Ver carrinho              *\n";
        cout << "\t*  6 - Excluir pedido            *\n";
        cout << "\t*  0 - Sair                      *\n";
        cout << "\t**********************************\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha)
        {
         case 0:
            cout << "Volte sempre\n";
            break;
        case 1:
            listarCardapioSanduicheCliente();
            break;
        case 2:
            listarCardapioSucoCliente();
            break;
        case 3:
            int escolhaProduto ;            
            cout << "O que deseja comprar:\n1 - sanduiche   2 - suco\n: ";
            cin >> escolhaProduto;
            adiconarNoCarrinho(escolhaProduto);
            
            break;
        case 4:
            retornarValorCarrinho();
            break;
        case 5:
            retornarCarrinho();
            break;

        // case 6:
        //     cin.ignore();
        //     string excluir_pedido;
        //     getline(cin, excluir_pedido);
        case 6:
          
        
        default:
            break;
        }


        // cout << "Digite sua escolha: ";
        // cin >> escolha;
        // if (escolha== 1)
        // {
        //         lerArquivoSanduicheCliente();

        //     listarCardapioSanduicheCliente();
        // }
        
    }
    
}