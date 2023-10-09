#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "gerente.hpp"
#include <fstream>
using namespace std;

map<string, float> cardapioSanduiche;
map<string, float> cardapioSuco;

void cadastrarSanduiche(string produto, float valor)
{
  cardapioSanduiche[produto] = valor;
  cout << "Sanduíche cadastrado com sucesso" << endl;
}

void cadastrarSuco(string produto, float valor)
{
  cardapioSuco[produto] = valor;
}

void listarCardapioSanduiche()
{
  cout.precision(2);
  cout << fixed;
  map<string, float>::iterator it;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             CARDÁPIO SANDUICHES              |" << endl;
  cout << "|----------------------------------------------|" << endl;

  for (it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); ++it)
  {
    cout << "   \t" << it->first << " preço: R$" << it->second << '\n';
  }
  cout << "|----------------------------------------------|" << endl;
}

void listarCardapioSuco()
{
  cout.precision(2);
  cout << fixed;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             CARDÁPIO SUCOS                   |" << endl;
  cout << "|----------------------------------------------|" << endl;

  map<string, float>::iterator it;
  for (it = cardapioSuco.begin(); it != cardapioSuco.end(); ++it)
  {
    cout << "       \t" << it->first << " preço: R$" << it->second << '\n';
  }
  cout << "|----------------------------------------------|" << endl;
}

void salvarCardapioSanduiche()
{
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::out);
  for (it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}

void salvarCardapioSuco()
{
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::out);
  for (it = cardapioSuco.begin(); it != cardapioSuco.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}

void lerArquivoSanduiche()
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
  if (linha.empty())
  {
    cout << "Sem sanduiches cadastrados" << endl;
  }
  else
  {
    for (int i = 0; i < linha.size(); i += 2)
    {
      cardapioSanduiche[linha[i]] = stof(linha[i + 1]);
    }
  }
}

void lerArquivoSucos()
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
  if (linha.empty())
  {
    cout << "Sem sucos cadastrados" << endl;
  }
  else
  {
    for (int i = 0; i < linha.size(); i += 2)
    {
      cardapioSuco[linha[i]] = stof(linha[i + 1]);
    }
  }
}

void alterarPrecoSanduiche(string produto, float preco)
{
  map<string, float>::iterator it;

  for (it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); ++it)
  {
    if (it->first == produto)
    {
      cardapioSanduiche[produto] = preco;
      cout << "Valor atualizado" << endl;
    }
    else
    {
        //cout << "\t Esse sanduiche não está no cardápio\n";
      cout << "";
    }
  }
}

void alterarPrecoSuco(string produto, float preco)
{
  map<string, float>::iterator it;
  for (it = cardapioSuco.begin(); it != cardapioSuco.end(); ++it)
  {
    if (it->first == produto)
    {
      cardapioSuco[produto] = preco;
    }
      // if (cardapioSuco[it->first] != produto)
      // {
      //   cout << "\t Esse suco não está no cardápio\n";
      // }
    else{
      cout << "";
    }
    
  }
}

void atualizarCardapioSuco()
{
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::out); // Apaga o arquivo original

  // Reescreve todo o arquivo do zero com os dados do map
  for (it = cardapioSuco.begin(); it != cardapioSuco.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}

void atualizarCardapioSanduiche()
{
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::out);  // Apaga o arquivo original

  // Reescreve todo o arquivo do zero com os dados do map
  for (it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
}

void excluirDoCardapioSanduiche(string produto)
{
  if (!cardapioSanduiche.empty())
  { // verifica se o map está vazio
    cardapioSanduiche.erase(produto);
    atualizarCardapioSanduiche(); // Chama a função para atualizar o arquivo
    cout << "Sanduiche  excluido" << endl;
  }
  else
  {
    cout << "Sanduiche não encontrado!!!" << endl;
  }
}
void excluirDoCardapioSuco(string produto)
{
  if (!cardapioSuco.empty())
  { // verifica se o map está vazio
    cardapioSuco.erase(produto);
    atualizarCardapioSuco(); // Chama a função para atualizar o arquivo
    cout << "Suco  excluido" << endl;
  }
  else
  {
    cout << "Suco não encontrado!!!" << endl;
  }
}

void gerente()
{
  int escolha;
  string sanduiche, suco;
  float precoSanduiche, precoSuco;

  lerArquivoSucos();
  lerArquivoSanduiche();

  while (escolha != 0)
  {
    cout << "\t**********************************\n";
    cout << "\t*  1 - Listar sanduiches         *\n";
    cout << "\t*  2 - Listar sucos              *\n";
    cout << "\t*  3 - Cadastrar sanduiche       *\n";
    cout << "\t*  4 - Cadastrar suco            *\n";
    cout << "\t*  5 - Atualizar preço sanduiche *\n";
    cout << "\t*  6 - Atualizar preço suco      *\n";
    cout << "\t*  7 - Excluir sanduiche         *\n";
    cout << "\t*  8 - Excluir suco              *\n";
    cout << "\t*  0 - Sair                      *\n";
    cout << "\t**********************************\n";
    cout << "Digite sua escolha: ";
    cin >> escolha;

    if (escolha == 1)
    {
      // lerArquivoSanduiche();
      listarCardapioSanduiche();
    }

    if (escolha == 2)
    {
      listarCardapioSuco();
    }

    if (escolha == 3)
    {
      cin.ignore();
      cout << "Sanduiche: ";
      // cin >> sanduiche;
      getline(cin, sanduiche);

      cout << "Preço: ";
      cin >> precoSanduiche;
      cadastrarSanduiche(sanduiche, precoSanduiche);
      salvarCardapioSanduiche();
    }

    if (escolha == 4)
    {
      cin.ignore();
      cout << "Suco: ";
      // cin >> suco;
      getline(cin, suco);
      cout << "Preço: ";
      cin >> precoSuco;
      cadastrarSuco(suco, precoSuco);
      salvarCardapioSuco();
    }

    if (escolha == 5)
    {
      cin.ignore();
      float novoPrecoSanduiche;
      cout << "Informe o produto para atualizar o valor: ";
        //cin >> sanduiche;
      getline(cin, sanduiche);
      cout << "Novo valor: ";
      cin >> novoPrecoSanduiche;
      alterarPrecoSanduiche(sanduiche, novoPrecoSanduiche);
      atualizarCardapioSanduiche();
    }

    if (escolha == 6)
    {
      cin.ignore();
      float novoPreco;
      cout << "Informe o produto para atualizar o valor: ";
        //cin >> suco;
      getline(cin, suco);

      cout << "Novo valor: ";
      cin >> novoPreco;
      alterarPrecoSuco(suco, novoPreco);
      atualizarCardapioSuco();
    }

    if (escolha == 7)
    {
      cin.ignore();
      string excluirSanduiche;
      cout << "Qual sanduiche deseja excluir: ";
      // cin >> excluirSanduiche;
      getline(cin, excluirSanduiche);
      excluirDoCardapioSanduiche(excluirSanduiche);
    }

    if (escolha == 8)
    {
      string excluirSuco;
      cin.ignore();
      cout << "Qual bebida deseja excluir: ";
      // cin >> excluirSuco;
      getline(cin, excluirSuco);
      excluirDoCardapioSuco(excluirSuco);
    }
  }
}
