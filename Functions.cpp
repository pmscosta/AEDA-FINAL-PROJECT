/*
 * Functions.cpp
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#include "Functions.h"

using namespace std;



//-----------------------FILES--------------------------//
string filename;

void lerficheiro(){
	ifstream file;
	cout << endl;
	cout << "Introduza o nome do ficheiro: ";
	do{
		cin >> filename;
		file.open(filename);
		if (!file.is_open())
			cout << "Nome ficheiro invalido. Introduza novamente o nome do ficheiro: ";
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
			cout << "Erro na criacao do ficheiro.";
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



//----------------------ASSOCIATES---------------------//

void adicionarAssociado(){
	string nome, instituicao;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o nome do Associado: ";
	getline(cin, nome);
	cout << "Introduza a instituicao do Associado: ";
	getline(cin, instituicao);

	//agora dar cout das areas da associacao numeradas...
	cout << "Indique quais as areas de interesse do Associado: ";
	//o utilizador agora tem de escolher quais sao, por exemplo, com numeros


	//falta o construtor do Associate

	//no fim podemos perguntar se deseja pagar ou assim e chamar outra funcao
}

