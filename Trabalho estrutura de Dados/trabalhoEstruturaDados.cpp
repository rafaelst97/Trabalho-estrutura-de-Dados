// Trabalho estrutura de Dados.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//


#include "pch.h"
#include "eventos.h"
#include "listaEstatica.h"
#include "listaEncadeada.h"
#include "sobrecargasInput.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{	
	THora testeHora;
	testeHora.hora = 0;
	testeHora.minuto = 0;
	TData testeData;
	testeData.dia = 0;
	testeData.mes = 0;
	testeData.ano = 0;

	cin >> testeHora;
	cout << testeHora;
	cin >> testeData;
	cout << testeData;

}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
