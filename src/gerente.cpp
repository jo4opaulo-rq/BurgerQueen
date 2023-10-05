#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "gerente.hpp"
#include <fstream>
using namespace std;

map<string, float> cardapioSanduiche;
map<string, float> cardapioSuco;

void cadastrarSanduiche(string produto, float valor){
  cardapioSanduiche[produto]= valor;
}

void cadastrarSuco(string produto, float valor){
  cardapioSuco[produto]= valor;
}

void listarCardapioSanduiche(){
    map<string, float>::iterator it;
    for (it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); ++it) {
    cout << "Produto: "<< it->first << "\nValor: " << it->second << '\n';
  }
}

void listarCardapioSuco(){
    map<string, float>::iterator it;
    for (it = cardapioSuco.begin(); it != cardapioSuco.end(); ++it) {
    cout << "Produto: "<< it->first << "\nValor: " << it->second << '\n';
  }
}

void salvarCardapioSanduiche(){
    map<string, float>::iterator it;
    fstream arquivo;
    arquivo.open("cardapio/sanduiches.txt", ios::out);
    for(it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    }
}

void salvarCardapioSuco(){
    map<string, float>::iterator it;
    fstream arquivo;
    arquivo.open("cardapio/sucos.txt", ios::out);
    for(it = cardapioSuco.begin(); it != cardapioSuco.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    } 
}

void lerArquivoSanduiche(){
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::in);
  string temp;
  while(getline(arquivo, temp)){
    linha.push_back(temp);
  }
  arquivo.close();
  if(linha.empty()){
    cout << "Sem sanduiches cadastrado" <<endl;
  }else{
    for(int i = 0; i < linha.size(); i+=2){ 
     cardapioSanduiche[linha[i]]= stof(linha[i+1]);
    }
  }
}

void lerArquivoSucos(){
  vector<string> linha;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::in);
  string temp;
  while(getline(arquivo, temp)){
    linha.push_back(temp);
  }
  arquivo.close();
  if(linha.empty()){
    cout << "Sem sucos cadastrados" <<endl;
  }else{
    for(int i = 0; i < linha.size(); i+=2){ 
     cardapioSuco[linha[i]]= stof(linha[i+1]);
    }
  }
}

void alterarPrecoSanduiche(string produto, float preco){
  cardapioSanduiche[produto] = preco;
}

void alterarPrecoSuco(string produto, float preco){
  cardapioSuco[produto] = preco;
}

void atualizarCardapioSuco(){
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sucos.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(it = cardapioSuco.begin(); it != cardapioSuco.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    }
}

void atualizarCardapioSanduiche(){
  map<string, float>::iterator it;
  fstream arquivo;
  arquivo.open("cardapio/sanduiches.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(it = cardapioSanduiche.begin(); it != cardapioSanduiche.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    }
}


void excluirDoCardapioSuco(string produto){
    if(!cardapioSuco.empty()){     // verifica se o map está vazio
      cardapioSuco.erase(produto);
      atualizarCardapioSuco(); // Chama a função para atualizar o arquivo
      cout << "Bebida  excluido" << endl;
    } 
    else{
       cout << "Bebida não encontrado!!!" << endl;
    }  
  
}

void gerente(){
  int escolha;
  string sanduiche, suco;
  float precoSanduiche, precoSuco;
  
  lerArquivoSucos();
  

  while (escolha != 0){
    cout << "\t**********************************\n";
    cout << "\t*  1 - Listar sanduiches         *\n";
    cout << "\t*  2 - Listar sucos              *\n";
    cout << "\t*  3 - Cadastrar sanduiche       *\n";
    cout << "\t*  4 - Cadastrar suco            *\n";
    cout << "\t*  5 - Atualizar preço sanduiche *\n";
    cout << "\t*  6 - Atualizar preço suco      *\n";
    cout << "\t*  8 - Excluir suco              *\n";
    cout << "\t*  0 - Sair                      *\n";
    cout << "\t**********************************\n";
    cout << "Digite sua escolha: ";    
    cin >> escolha;
    
    if (escolha == 1){
      lerArquivoSanduiche();
      listarCardapioSanduiche();
    }
    
    if (escolha == 2){
      listarCardapioSuco();
    }

    if (escolha == 3){
      cout << "Sanduiche: ";
      cin >> sanduiche;
      cout << "Preço: ";
      cin >> precoSanduiche;
      cadastrarSanduiche(sanduiche, precoSanduiche);
      salvarCardapioSanduiche();
    }

    if (escolha == 4){
      cout << "Suco: ";
      cin >> suco;
      cout << "Preço: ";
      cin >> precoSuco;
      cadastrarSuco(suco, precoSuco);
      salvarCardapioSuco();
    }

    if (escolha == 5){
      float novoPrecoSanduiche;
      cout << "Informe o produto para atualizar o valor: ";
      cin >> sanduiche;
      cout << "Novo valor: ";
      cin >> novoPrecoSanduiche;
      alterarPrecoSanduiche(sanduiche, novoPrecoSanduiche);
      atualizarCardapioSanduiche();

    }
    
    if (escolha == 6){
      float novoPreco;
      cout << "Informe o produto para atualizar o valor: ";
      cin >> suco;
      cout << "Novo valor: ";
      cin >> novoPreco;
      alterarPrecoSuco(suco, novoPreco);
      atualizarCardapioSuco();
    }

    if (escolha == 8)
    {
      string excluirSuco;
      cout << "Qual bebida deseja excluir: ";
      cin >> excluirSuco;
      excluirDoCardapioSuco(excluirSuco);
    }
    
    
    
    
    
    // case 3:
    //   cout << "Sanduiche: ";
    //   cin >> sanduiche;
    //   cout << "Preço: ";
    //   cin >> precoSanduiche;
    //   cadastrarSanduiche(sanduiche, precoSanduiche);
    //   salvarCardapioSanduiche();
    //   break;

    // case 4:
    //   cout << "Suco: ";
    //   cin >> suco;
    //   cout << "Preço: ";
    //   cin >> precoSuco;
    //   cadastrarSuco(suco, precoSuco);
    //   salvarCardapioSuco();

  }
}

         