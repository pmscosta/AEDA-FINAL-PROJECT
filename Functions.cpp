/*
 * Functions.cpp
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#include "Functions.h"
#include <sstream>

using namespace std;

Association  * Associacao = new Association("ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA");

//-----------------------FILES--------------------------//
string filename;

void lerficheiroAreas(){
	ifstream file;
	cout << endl;
	cout << "Introduza o nome do ficheiro: ";
	do{
		cin >> filename;
		file.open(filename);
		if (!file.is_open())
			cout << "Nome ficheiro invalido. Introduza novamente o nome do ficheiro: ";
	} while(!file.is_open());



	string line;
	while(getline(file, line)){
		Area * newArea = new Area(line);
		Associacao->addArea(newArea);
	}


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

	vector<Area *> areas = Associacao->getAreas();
	for (size_t t = 0; t < areas.size(); t++){
		cout << t << ": " << areas.at(t)->getName() << endl;
	}

	string list;
	getline(cin, list);

	stringstream numbers (list);

	vector<Area *> newInterest;  //O VETOR QUE IRA CONTER AS AREAS DE INTERESSE DO ASSOCIADO

	while(!numbers.eof()){
		int selected = 0;
		numbers >> selected;
		if (selected >= areas.size() || selected < 0) {  //SE UM DOS INDICES ESCOLHIDOS NAO CORRESPONDE A NENHUM DOS APRESENTADOS
			cout << "Nao existe a opcao " << selected
					<< ".\nVoltando ao menu anterior.";
			return;
		}

		newInterest.push_back(areas.at(selected));

	}

	Associate * newAsso = new Associate(Associacao, nome, instituicao, newInterest);

	Associacao->addAssociate(newAsso);

	cout << "Associado adicionado com sucesso!\n";

	//no fim podemos perguntar se deseja pagar ou assim e chamar outra funcao
}

void removerAssociado(){
	int uniqueID;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o Identificador Unico do Associado a remover: ";
	cin >> uniqueID;

	//compor a cena do cin

	try{
		Associacao->removeAssociate(uniqueID);
	}catch(NoSuchID & e){
		cout << "Nao existe nenhum associado com o ID: " << e.getID() << ".\nVoltando ao menu anterior...\n";
		return;
	}

	cout << "\nAssociado removido com sucesso!\n";
}


void alterarAssociado(){
	string name;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o nome do Associado: ";
	getline(cin, name);


	//completar...



}

void verInfoAssociado(){
	string name;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o nome do Associado: ";
	getline(cin, name);

	//completar...

}


//-------------------------AREAS----------------------------

void verAreas(){

	vector<Area*> areas = Associacao->getAreas();

	for(size_t t = 0; t < areas.size(); t++){
		cout << areas.at(t)->getName() << ":\n";
		for (size_t k = 0; k < areas.at(t)->getSubAreas().size(); k++){
			cout << areas.at(t)->getSubAreas().at(k)->getName() << " - " << areas.at(t)->getSubAreas().at(k)->getInitials() << endl;
		}
		cout << endl;
	}

}





