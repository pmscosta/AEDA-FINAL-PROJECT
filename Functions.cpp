/*
 * Functions.cpp
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#include "Functions.h"

using namespace std;

Association * Associacao;

void initialize(){
	lerficheiroAssociacao();
	lerficheiroAreas();
	lerficheiroAssociados();
	lerficheiroEventos();
}

void initialize2(){
	Associacao = new Association("ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA");
	limparficheiros();
}

//-----------------------FILES--------------------------//

void lerficheiroAreas() {
	ifstream file;
	string line;
	file.open("areas.txt");
	while (getline(file, line)) {
		Area * newArea = new Area(line);
		Associacao->addArea(newArea);
	}
	file.close();
}

void lerficheiroAssociacao() {
	ifstream file;
	string line;
	file.open("association.txt");
	while (getline(file, line)) {
		Associacao = new Association(line);
	}
	file.close();
}

void lerficheiroAssociados() {
	ifstream file;
	string line;
	file.open("associates.txt");
	while (getline(file, line)) {
		Associate * newAsso = new Associate(Associacao, line);
		Associacao->addAssociate(newAsso);
	}
	file.close();
}

void lerficheiroEventos() {
	ifstream file;
	string line;
	file.open("events.txt");
	while (getline(file, line)) {

	}
	file.close();
}

void guardarficheiroAreas() {
	ofstream file("areas.txt");

	//Guardar no ficheiro
	//file << "";

	file.close();
}

void guardarficheiroAssociacao() {
	ofstream file("association.txt");

	//Guardar no ficheiro
	//file << "";

	file.close();
}

void guardarficheiroAssociados() {
	ofstream file("associates.txt");

	//Guardar no ficheiro
	//file << "";

	file.close();
}

void guardarficheiroEventos() {
	ofstream file("events.txt");

	//Guardar no ficheiro
	//file << "";

	file.close();
}

void limparficheiros(){
	ofstream file;
	file.open("areas.txt", ofstream::out | ofstream::trunc);
	file.close();
	file.open("associates.txt", ofstream::out | ofstream::trunc);
	file.close();
	file.open("association.txt", ofstream::out | ofstream::trunc);
	file.close();
	file.open("events.txt", ofstream::out | ofstream::trunc);
	file.close();
}


//----------------------ASSOCIATES---------------------//

void adicionarAssociado() {
	string nome, instituicao;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Introduza o nome do Associado: ";
	getline(cin, nome);
	cout << "\nIntroduza a instituicao do Associado: ";
	getline(cin, instituicao);

	//agora dar cout das areas da associacao numeradas...
	cout << "\nIndique quais as areas de interesse do Associado: ";

	vector<Area *> areas = Associacao->getAreas();
	for (size_t t = 0; t < areas.size(); t++) {
		cout << t << ": " << areas.at(t)->getName() << endl;
	}

	string list;
	getline(cin, list);

	stringstream numbers(list);

	vector<Area *> newInterest; //O VETOR QUE IRA CONTER AS AREAS DE INTERESSE DO ASSOCIADO

	while (!numbers.eof()) {
		int selected = 0;
		numbers >> selected;
		if (selected >= areas.size() || selected < 0) { //SE UM DOS INDICES ESCOLHIDOS NAO CORRESPONDE A NENHUM DOS APRESENTADOS
			cout << "\nNao existe a opcao " << selected
					<< ".\nVoltando ao menu principal..." << endl << endl;
			sleep(1);
			return;
		}

		newInterest.push_back(areas.at(selected));
	}

	Associate * newAsso = new Associate(Associacao, nome, instituicao,
			newInterest);

	Associacao->addAssociate(newAsso);

	cout << "\nAssociado adicionado com sucesso!" << endl << endl;

	sleep(1);
}

void removerAssociado() {
	int uniqueID;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o Identificador Unico do Associado a remover: ";
	cin >> uniqueID;

	//compor a cena do cin

	try {
		Associacao->removeAssociate(uniqueID);
	} catch (NoSuchID & e) {
		cout << "\nNao existe nenhum associado com o ID: " << e.getID()
				<< ".\nVoltando ao menu principal..." << endl << endl;
		sleep(1);
		return;
	}

	cout << "\nAssociado removido com sucesso!" << endl << endl;

	sleep(1);
}

void alterarAssociado() {
	string name;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o nome do Associado: ";
	getline(cin, name);

	//completar...

}

void verInfoAssociado() {
	string name;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o nome do Associado: ";
	getline(cin, name);

	cout << Associacao->showAllAssociates();

}


//-----------------------EVENTOS----------------------//

void criarEvento(){
	int uniqueID, numAsso;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	Associate * associado;
	vector<Associate *> event_request, event_organizers;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Introduza o numero de Associados que querem criar um Evento: ";
	cin >> numAsso;

	for(int i = 0; i < numAsso; i++){
		cout << "Introduza o Identificador Unico do "<< i+1 << "º Associado que quer criar um Evento: ";
		cin >> uniqueID;
		try {
			associado = Associacao->getAssoById(uniqueID);
		} catch (NoSuchID & e) {
			cout << "\nNao existe nenhum associado com o ID: " << e.getID()
						<< ".\nVoltando ao menu principal..." << endl << endl;
			sleep(1);
			return;
		}
		event_request.push_back(associado);
	}

	event_organizers = event_request;
	cout << "Introduza o numero de Associados que vao ajudar a organizar o Evento: ";
	cin >> numAsso;
	for(int i = 0; i < numAsso; i++){
		cout << "Introduza o Identificador Unico do "<< i+1 << "º Associado que quer ajudar a organizar o Evento: ";
		cin >> uniqueID;
		try {
			associado = Associacao->getAssoById(uniqueID);
		} catch (NoSuchID & e) {
			cout << "\nNao existe nenhum associado com o ID: " << e.getID()
						<< ".\nVoltando ao menu principal..." << endl << endl;
			sleep(1);
			return;
		}
		event_organizers.push_back(associado);
	}

	string date, local, theme;
	cout << "Introduza a data do evento: ";
	getline(cin, date);
	cout << "Introduza o local do evento: ";
	getline(cin, local);
	cout << "Introduza o tema do evento: ";
	getline(cin, theme);

	Event * evento;
	try {
		evento = new Event(event_request,event_organizers,date,local,theme, Associacao);
	} catch (const NoSupportGiven & e) {
		cout << "\nEm " << e.getTotal() << " associados, " << e.getLate() << " tem pagamentos em atraso. Impossivel criar evento!"
					<< ".\nVoltando ao menu principal..." << endl << endl;
		sleep(1);
		return;
	}
	Associacao->addEvent(evento);
}

void removerEvento(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void alterarEvento(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verInfoEvento(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}


//-----------------------COTAS-------------------------//

void pagarCotas(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verAssociadosCotas(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}



//-----------------------REDE--------------------------//

void divulgarEmail(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verEmails(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}
