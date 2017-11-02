/*
 * Menu.cpp
 */

#include "menu.h"

using namespace std;
string filename;

void menu(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Ler ficheiro com informações guardadas" << endl;
	cout << " 2 - Criar novo ficheiro" << endl;
	cout << " 3 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 3){
		cin >> opcao;
		switch(opcao){
			case 1:
				lerficheiro();
				break;
			case 2:
				criarficheiro();
				break;
			case 3:
				sair();
				break;
			default:
				cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
}

void menu2(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Gestão de Associados" << endl;
	cout << " 2 - Gestão de Eventos" << endl;
	cout << " 3 - Gestão de Cotas" << endl;
	cout << " 4 - Gestão da Rede de Distribuição" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			submenu1();
			break;
		case 2:
			submenu2();
			break;
		case 3:
			submenu3();
			break;
		case 4:
			submenu4();
			break;
		case 5:
			menu();
			break;
		case 6:
			sair();
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
}

void submenu1(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Adicionar Associado" << endl;
	cout << " 2 - Remover Associado" << endl;
	cout << " 3 - Alterar informações de um Associado" << endl;
	cout << " 4 - Ver informações sobre um Associado" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Função adicionar um novo associado
			break;
		case 2:
			//Função remover um associado
			break;
		case 3:
			//Função alterar informações de um associado
			break;
		case 4:
			//Função que mostra informações sobre um associado
			break;
		case 5:
			menu();
			break;
		case 6:
			sair();
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
}

void submenu2(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Criar Evento" << endl;
	cout << " 2 - Remover Evento" << endl;
	cout << " 3 - Alterar informações de um Evento" << endl;
	cout << " 4 - Ver informações sobre um Evento" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Função que cria um evento
			break;
		case 2:
			//Função que remove um evento
			break;
		case 3:
			//Função que altera informações de um evento
			break;
		case 4:
			//Função que mostra informações sobre um evento
			break;
		case 5:
			menu();
			break;
		case 6:
			sair();
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
}

void submenu3(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Pagar cota anual" << endl;
	cout << " 2 - Ver Associados com cotas em atraso" << endl;
	cout << " 3 - Anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 4){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Função para pagar a cota anual de um associado
			break;
		case 2:
			//Função que mostra os associados com cotas em atraso
			break;
		case 3:
			menu();
			break;
		case 4:
			sair();
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
}

void submenu4(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIAÇÃO PORTUGUESA INVESTIGAÇÃO CIENTÍFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Divulgar Email para a Rede" << endl;
	cout << " 2 - Ver Emails da Rede" << endl;
	cout << " 3 - Anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opção: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Função para enviar um email para a rede
			break;
		case 2:
			//Função que mostra os emails da rede
			break;
		case 3:
			menu();
			break;
		case 4:
			sair();
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}

}

void sair(){
	char opcao;
	cout << endl;
	cout << "Deseja guardar as alterações feitas? (S/N): ";
	while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
		cin >> opcao;
		switch(opcao){
		case 's':
			guardarficheiro();
			break;
		case 'S':
			guardarficheiro();
			break;
		case 'n':
			break;
		case 'N':
			break;
		default:
			cout << "Opção inválida. Introduza uma nova opção: ";
		}
	}
	exit(0);
}


void lerficheiro(){
	ifstream file;
	cout << endl;
	cout << "Introduza o nome do ficheiro: ";
	do{
		cin >> filename;
		file.open(filename);
		if (!file.is_open())
			cout << "Nome ficheiro inválido. Introduza novamente o nome do ficheiro: ";
	} while(!file.is_open());


	//Tratamento de ler o ficheiro aqui
	/*
	string line;
	getline(file, line);
	cout << line;*/

	file.close();
}

void criarficheiro(){
	ofstream file;
	cout << endl;
	cout << "Introduza o nome para o ficheiro: ";
	do {
		cin >> filename;
		file.open(filename);
		if (!file.is_open())
			cout << "Erro na criação do ficheiro.";
	} while(!file.is_open());


	//Tratamento de escrever no ficheiro aqui


	file.close();
}


void guardarficheiro(){
	ofstream file (filename);

	//Guardar no ficheiro
	//file << "";

	file.close();
	cout << "Ficheiro guardado!";
	usleep(1000);
}
