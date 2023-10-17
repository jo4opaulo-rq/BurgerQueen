#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "cliente.hpp"
using namespace std;

map<string, float> cardapioSanduicheCliente;
map<string, float> cardapioSucoCliente;
map<string, float> carrinhoCompras;

void retornarValorCarrinho();

void lerArquivoSanduicheCliente()
{
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::in);
  string temp;
  while (getline(arquivo, temp))
  {
    linha.push_back(temp);
  }
  arquivo.close();

  for (int i = 0; i < linha.size(); i += 2)
  {
    cardapioSanduicheCliente[linha[i]] = stof(linha[i + 1]);
  }
}

void listarCardapioSanduicheCliente()
{
  cout.precision(2);
  cout << fixed;
  map<string, float>::iterator it;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             CARDÁPIO SANDUICHES              |" << endl;
  cout << "|----------------------------------------------|" << endl;

  for (it = cardapioSanduicheCliente.begin(); it != cardapioSanduicheCliente.end(); ++it)
  {
    cout << "   \t" << it->first << " preço: R$" << it->second << '\n';
  }
  if (cardapioSanduicheCliente.empty())
  {
    cout << "|\t   Não foram nenhum sanduíche.         |" << endl;
  }
  cout << "|----------------------------------------------|" << endl;

}

void lerArquivoSucoCliente()
{
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::in);
  string temp;
  while (getline(arquivo, temp))
  {
    linha.push_back(temp);
  }
  arquivo.close();

  for (int i = 0; i < linha.size(); i += 2)
  {
    cardapioSucoCliente[linha[i]] = stof(linha[i + 1]);
  }
}

void listarCardapioSucoCliente()
{
  cout.precision(2);
  cout << fixed;
  map<string, float>::iterator it;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             CARDÁPIO SUCOS                   |" << endl;
  cout << "|----------------------------------------------|" << endl;

  for (it = cardapioSucoCliente.begin(); it != cardapioSucoCliente.end(); ++it)
  {
    cout << "   \t" << it->first << " preço: R$" << it->second << '\n';
  }
  cout << "|----------------------------------------------|" << endl;

  if (cardapioSucoCliente.empty())
  {
    cout << "|\t   Não foram nenhum suco                    |" << endl;
    cout << "|----------------------------------------------|" << endl;
  }
}

void adiconarNoCarrinho(int sanduicheOusuco)
{
  cin.ignore();
  string produto;

  lerArquivoSanduicheCliente();
  lerArquivoSucoCliente();
  map<string, float>::iterator it;
  if (sanduicheOusuco == 1)
  {
    listarCardapioSanduicheCliente();
    cout << "Escolha seu sanduíche:  ";
    getline(cin, produto);
    carrinhoCompras.insert(*cardapioSanduicheCliente.find(produto));
    cout << "Pedido adicionado\n";
  }
  if (sanduicheOusuco == 2)
  {
    listarCardapioSucoCliente();
    cout << "Escolha seu suco:  ";
    getline(cin, produto);
    carrinhoCompras.insert(*cardapioSucoCliente.find(produto));
    cout << "Pedido adicionado\n";

  }

}

void retornarCarrinho()
{ 
  cout.precision(2);
  cout << fixed;
  map<string, float>::iterator it;
  float totalcompra = 0;
  for (it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++){
    totalcompra += it->second;
       
  }
  cout << "|----------------------------------------------|" << endl;
  cout << "|               \U0001f6d2   SEUS PEDIDOS              |" << endl;
  cout << "|----------------------------------------------|" << endl;
  for (it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++)
  {
    cout << "      \t" << it->first << " R$:" << it->second << endl;
  }
  if (!carrinhoCompras.empty())
  {
    cout << "                          Valor total R$" << totalcompra << endl;
  }
  if (carrinhoCompras.empty())
  {
    cout << "|\t     Seu carrinho está vazio.          |" << endl;
  }
  cout << "|----------------------------------------------|" << endl;

}

void retornarValorCarrinho()
{
  cout.precision(2);
  cout << fixed;
  map<string, float>::iterator it;
  float totalcompra;
  if (carrinhoCompras.empty())
  {
    cout << "Seu carrinho está vazio." << endl;
  }
  else{
    for (it = carrinhoCompras.begin(); it != carrinhoCompras.end(); it++)
    {
       totalcompra += it->second;
       
    }
    cout << "Total: R$" << totalcompra << endl;
  }
  
}


void excluirPedido()
{
  cin.ignore();
  string pedido;

  if (!carrinhoCompras.empty()) // verifica se o map está vazio
  { 
    retornarCarrinho();
    cout << "Qual pedido deseja remover?: ";
    getline(cin, pedido);
    carrinhoCompras.erase(pedido);
    cout << "Pedido  excluido" << endl;
  }
  else
  {
    cout << "Pedido não encontrado!!!" << endl;
  }
}

void cliente() // função principal
{

  int escolha = 1;
  lerArquivoSanduicheCliente();
  lerArquivoSucoCliente();

  while (escolha != 0)
  {
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
      system("clear");
      listarCardapioSanduicheCliente();
      break;
    case 2: 
      system("clear");
      listarCardapioSucoCliente();
      break;
    case 3: 
      int escolhaProduto;
      cout << "O que deseja comprar:\n1 - sanduiche \n2 - suco  " << endl;
      cout << "Escolha entre 1 ou 2: ";
      cin >> escolhaProduto;
      adiconarNoCarrinho(escolhaProduto);

      break;
    case 4: 
      retornarValorCarrinho();
      break;
    case 5: 
      retornarCarrinho();
      break;
    case 6: 
      excluirPedido();
      break;
    default: 
      break;
    }
  }
}