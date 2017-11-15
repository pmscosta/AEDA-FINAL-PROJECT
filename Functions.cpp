/*
 * Functions.cpp
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#include "Functions.h"
#include <sstream>
#include <list>

using namespace std;

Association * Associacao;

void initialize() {
	lerficheiroAssociacao();
	lerficheiroAreas();
	lerficheiroAssociados();
	lerficheiroEventos();
}

void initialize2() {
	Associacao = new Association(
			"ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA");
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

		stringstream infoEvent(line);

		string type_of_event;

		getline(infoEvent, type_of_event, '/');

		if (type_of_event == "SummerSchool") {

			string type, date, local, theme, trainer;

			int requester, organizer, money;

			char garbage;

			string former_name, former_inst;

			getline(infoEvent, date, '/');
			getline(infoEvent, local, '/');
			getline(infoEvent, theme, '/');

			infoEvent >> garbage;

			vector<Associate *> event_request;

			vector<Associate *> event_organizers;

			list<string> trainers;

			while (infoEvent.peek() != ']') {

				infoEvent >> requester;

				for (size_t t = 0; t < Associacao->getAssociates().size();
						t++) {

					if (requester
							== Associacao->getAssociates().at(t)->getUniqueID()) {
						event_request.push_back(
								Associacao->getAssociates().at(t));
						event_organizers.push_back(
								Associacao->getAssociates().at(t));
					}
				}
				infoEvent >> garbage;
			}

			infoEvent >> garbage;		// ']'
			infoEvent >> garbage;		// '/'
			infoEvent >> garbage;		// '['

			while (infoEvent.peek() != ']') {

				infoEvent >> organizer;

				for (size_t t = 0; t < Associacao->getAssociates().size();
						t++) {

					if (organizer
							== Associacao->getAssociates().at(t)->getUniqueID()) {
						event_organizers.push_back(
								Associacao->getAssociates().at(t));
					}
				}
				infoEvent >> garbage;
			}

			infoEvent >> garbage;		// ']'
			infoEvent >> garbage;		// '/'

			infoEvent >> money;

			infoEvent >> garbage;		// '/'

			infoEvent >> garbage;		// '['



			while (infoEvent.peek() != ']') {

				getline(infoEvent, former_name, '/');
				getline(infoEvent, former_inst, '/');
				trainer = former_name + " " + former_inst;
				trainers.push_back(trainer);
			}



			SummerSchool * newSummer = new SummerSchool(event_request,
					event_organizers, date, local, theme, Associacao, trainers);
			Associacao->addEvent(newSummer);

		} else {

			string date, local, theme;
			int requester, organizer, money;
			char garbage;

			int predicted_participants;

			getline(infoEvent, date, '/');

			getline(infoEvent, local, '/');

			getline(infoEvent, theme, '/');

			vector<Associate *> event_request;

			vector<Associate *> event_organizers;

			infoEvent >> garbage;

			while (infoEvent.peek() != ']') {

				infoEvent >> requester;

				for (size_t t = 0; t < Associacao->getAssociates().size();
						t++) {

					if (requester
							== Associacao->getAssociates().at(t)->getUniqueID()) {
						event_request.push_back(
								Associacao->getAssociates().at(t));
						event_organizers.push_back(
								Associacao->getAssociates().at(t));
					}
				}
				infoEvent >> garbage;
			}

			infoEvent >> garbage;		// ']'
			infoEvent >> garbage;		// '/'
			infoEvent >> garbage;		// '['

			while (infoEvent.peek() != ']') {

				infoEvent >> organizer;

				for (size_t t = 0; t < Associacao->getAssociates().size();
						t++) {

					if (organizer
							== Associacao->getAssociates().at(t)->getUniqueID()) {
						event_organizers.push_back(
								Associacao->getAssociates().at(t));
					}
				}
				infoEvent >> garbage;
			}

			infoEvent >> garbage;		// ']'
			infoEvent >> garbage;		// '/'

			infoEvent >> money;

			infoEvent >> garbage;		// '/'

			infoEvent >> predicted_participants;

			Conference * newConf = new Conference(event_request,
					event_organizers, date, local, theme, Associacao,
					predicted_participants);

			Associacao->addEvent(newConf);

		}

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

void limparficheiros() {
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
		size_t selected = 0;
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
	int uniqueID;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o Identificador Unico do Associado: ";
	cin >> uniqueID;

	Associate * associado;
	try {
		associado = Associacao->getAssoById(uniqueID);
	} catch (NoSuchID & e) {
		cout << "\nNao existe nenhum associado com o ID: " << e.getID()
				<< ".\nVoltando ao menu principal..." << endl << endl;
		sleep(1);
		return;
	}

	string associadoinfo = associado->showInfo();
	cout << endl << associadoinfo;

	sleep(1);
}

//-----------------------EVENTOS----------------------//

void criarEvento() {
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

	/*
	 * AQUI TEM DE SE PERGUNTAR PRIMEIRO SE SE TRATA DE UM SUMMERSCHOOL OU CONFERENCE
	 * E DEPOIS CHAMAR O CONSTRUCTOR RESPETIVO
	 * A UNICA DIFERENCA SERA QUE O DE CONFERENTE TEM UM NUMERO ESPERADO DE PARTICIPANTES
	 * E O SUMMERSCHOOL TEM UMA LISTA DE TRAINERS AKA FORMADORES
	 * VER A IMPLEMENTACAO NAS RESPETIVAS CLASSES
	 * A LISTA DOS FORMADORES AINDA TEMOS DE DISCUTIR MELHOR ISSO
	 * FAZ SENTIDO OS FORMADORES NAO SEREM OBRIGATORIAMENTE ASSOCIADOS, ACHO EU
	 *
	 */

	cout << "Introduza o numero de Associados que querem criar um Evento: ";
	cin >> numAsso;

	for (int i = 0; i < numAsso; i++) {
		cout << "Introduza o Identificador Unico do " << i + 1
				<< "º Associado que quer criar um Evento: ";
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
	cout
			<< "\nIntroduza o numero de Associados que vao ajudar a organizar o Evento: ";
	cin >> numAsso;
	for (int i = 0; i < numAsso; i++) {
		cout << "Introduza o Identificador Unico do " << i + 1
				<< "º Associado que quer ajudar a organizar o Evento: ";
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

	cin.clear();
	cin.ignore(10000, '\n');

	string date, local, theme;
	cout << "\nIntroduza a data do evento: ";
	getline(cin, date);
	cout << "\nIntroduza o local do evento: ";
	getline(cin, local);
	cout << "\nIntroduza o tema do evento: ";
	getline(cin, theme);

	/*

	Event * evento;
	try {
		evento = new Event(event_request, event_organizers, date, local, theme,
				Associacao);
	} catch (const NoSupportGiven & e) {
		cout << "\nEm " << e.getTotal() << " associados, " << e.getLate()
				<< " tem pagamentos em atraso. Impossivel criar evento!"
				<< ".\nVoltando ao menu principal..." << endl << endl;
		sleep(1);
		return;
	}
	Associacao->addEvent(evento);


	*/

	cout << "Evento criado com sucesso!";
	sleep(1);
}

void removerEvento() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void alterarEvento() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verInfoEvento() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	cout << Associacao->showEvents();

}

//-----------------------COTAS-------------------------//

void pagarCotas() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verAssociadosCotas() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

//-----------------------REDE--------------------------//

void divulgarEmail() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}

void verEmails() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	//completar...

}
