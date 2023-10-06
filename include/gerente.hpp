#ifndef GERENTE_HPP
#define GERENTE_HPP

void gerente();
void cadastrarSanduiche(std::string produto, float valor);
void cadastrarSuco(std::string produto, float valor);

void listarCardapioSanduiche();
void salvarCardapioSanduiche();

void listarCardapioSuco();
void salvarCardapioSuco();

void lerArquivoSanduiche();

void lerArquivoSucos();

void alterarPrecoSanduiche(std::string produto, float preco);
void atualizarCardapioSanduiche();

void alterarPrecoSuco(std::string produto, float preco);
void atualizarCardapioSuco();

void excluirDoCardapioSuco(std::string produto);

void excluirDoCardapioSanduiche(std::string produto);

#endif
