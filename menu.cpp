/*
 * Menu.cpp
 */

#include "menu.h"

using namespace std;

void menu(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Ler ficheiro com informacoes guardadas" << endl;
	cout << " 2 - Criar novo ficheiro" << endl;
	cout << " 3 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
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
				cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
}

void menu2(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Gestao de Associados" << endl;
	cout << " 2 - Gestao de Eventos" << endl;
	cout << " 3 - Gestao de Cotas" << endl;
	cout << " 4 - Gestao da Rede de Distribuicao" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
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
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
}

void submenu1(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Adicionar Associado" << endl;
	cout << " 2 - Remover Associado" << endl;
	cout << " 3 - Alterar informacoes de um Associado" << endl;
	cout << " 4 - Ver informacoes sobre um Associado" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			adicionarAssociado();
			break;
		case 2:
			removerAssociado();
			break;
		case 3:
			//Funcao alterar informacoes de um associado
			break;
		case 4:
			//Funcao que mostra informacoes sobre um associado
			break;
		case 5:
			menu();
			break;
		case 6:
			sair();
			break;
		default:
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
}

void submenu2(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Criar Evento" << endl;
	cout << " 2 - Remover Evento" << endl;
	cout << " 3 - Alterar informacoes de um Evento" << endl;
	cout << " 4 - Ver informacoes sobre um Evento" << endl;
	cout << " 5 - Anterior" << endl;
	cout << " 6 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Funcao que cria um evento
			break;
		case 2:
			//Funcao que remove um evento
			break;
		case 3:
			//Funcao que altera informacoes de um evento
			break;
		case 4:
			//Funcao que mostra informacoes sobre um evento
			break;
		case 5:
			menu();
			break;
		case 6:
			sair();
			break;
		default:
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
}

void submenu3(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Pagar cota anual" << endl;
	cout << " 2 - Ver Associados com cotas em atraso" << endl;
	cout << " 3 - Anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while(opcao < 1 || opcao > 4){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Funcao para pagar a cota anual de um associado
			break;
		case 2:
			//Funcao que mostra os associados com cotas em atraso
			break;
		case 3:
			menu();
			break;
		case 4:
			sair();
			break;
		default:
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
}

void submenu4(){
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << " 1 - Divulgar Email para a Rede" << endl;
	cout << " 2 - Ver Emails da Rede" << endl;
	cout << " 3 - Anterior" << endl;
	cout << " 4 - Sair" << endl;

	int opcao = 0;
	cout << endl;
	cout << "Introduza uma opcao: ";
	while(opcao < 1 || opcao > 6){
		cin >> opcao;
		switch(opcao){
		case 1:
			//Funcao para enviar um email para a rede
			break;
		case 2:
			//Funcao que mostra os emails da rede
			break;
		case 3:
			menu();
			break;
		case 4:
			sair();
			break;
		default:
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}

}

void sair(){
	char opcao;
	cout << endl;
	cout << "Deseja guardar as alteracoes feitas? (S/N): ";
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
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
	exit(0);
}
