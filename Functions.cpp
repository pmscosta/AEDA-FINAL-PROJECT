/*
 * Functions.cpp
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#include "Functions.h"
#include "Associate.h"
#include "Area.h"
#include "Association.h"
#include "SubArea.h"
#include "Event.h"
#include "SummerSchool.h"
#include "Conference.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

//=======================USEFUL FUNCTIONS================================
//=======================================================================

bool is_number(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

//=======================================================================

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

void ano(){
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	char opcao;
	cout << "Ano atual: " << Associacao->getCurrentYear() << endl;
	cout << "\nIncrementar um ano (S/N): ";
	while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N') {
		cin >> opcao;
		switch (opcao) {
		case 's':
			Associacao->updateYear();
			break;
		case 'S':
			Associacao->updateYear();
			break;
		case 'n':
			break;
		case 'N':
			break;
		default:
			cout << "Opcao invalida. Introduza uma nova opcao: ";
		}
	}
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

			string type, date, local, theme;

			int requester, organizer;

			long double money;

			char garbage;

			string former_name, former_inst;

			getline(infoEvent, date, '/');
			getline(infoEvent, local, '/');
			getline(infoEvent, theme, '/');

			infoEvent >> garbage;

			vector<Associate *> event_request;

			vector<Associate *> event_organizers;

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

			list<Trainer *> trainers;

			while (infoEvent.peek() != ']') {

				getline(infoEvent, former_name, '/');
				getline(infoEvent, former_inst, '/');
				Trainer * newTrainer = new Trainer(former_name, former_inst);
				trainers.push_back(newTrainer);

				//cout << "one time\n";
			}

			infoEvent >> garbage;

			SummerSchool * newSummer = new SummerSchool(event_request,
					event_organizers, date, local, theme, Associacao, trainers,
					money);
			Associacao->addEvent(newSummer);

		} else {

			string date, local, theme;
			int requester, organizer;
			long double money;
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
					predicted_participants, money);

			Associacao->addEvent(newConf);

		}

	}
	file.close();
}

void guardarficheiroAreas() {
	ofstream file("areas.txt");

	//Imunologia e Infeção/Imunologia e Inflamação/IMI-IMU/Microbiologia e Infeção/IMI-MIC

	vector<Area *> areas_vector = Associacao->getAreas();
	for (size_t i = 0; i < areas_vector.size(); i++) {

		file << areas_vector.at(i)->getName() << "/";

		vector<SubArea *> subareas_vector = areas_vector.at(i)->getSubAreas();
		for (size_t t = 0; t < subareas_vector.size(); t++) {

			if (t == (subareas_vector.size() - 1)) {
				file << subareas_vector.at(t)->getName() << "/"
						<< subareas_vector.at(t)->getInitials();

				if (i != areas_vector.size() - 1)
					file << endl;
			} else
				file << subareas_vector.at(t)->getName() << "/"
						<< subareas_vector.at(t)->getInitials() << "/";
		}
	}

	file.close();
}

void guardarficheiroAssociacao() {
	ofstream file("association.txt");

	//Name/ 231.7/ 242.4/ 4

	file << Associacao->getName() << "/";
	file << Associacao->getFund() << "/";
	file << Associacao->getAnnualPay() << "/";
	file << Associacao->getCurrentYear();

	file.close();
}

void guardarficheiroAssociados() {
	ofstream file("associates.txt");

	//1/Pedro Costa/FEUP/[Neurociências, Envelhecimento e Doenças Degenerativas/Imunologia e Infeção/]/50.4/[40/2/70/]/4

	vector<Associate *> associates_vector = Associacao->getAssociates();
	for (size_t i = 0; i < associates_vector.size(); i++) {

		file << associates_vector.at(i)->getUniqueID() << "/";
		file << associates_vector.at(i)->getName() << "/";
		file << associates_vector.at(i)->getInstitution() << "/[";

		vector<Area *> areas_interest =
				associates_vector.at(i)->getInterestAreas();
		for (size_t t = 0; t < areas_interest.size(); t++) {

			file << areas_interest.at(t)->getName() << "/";
		}
		file << "]" << "/" << associates_vector.at(i)->getPersonalWallet()
				<< "/[";

		vector<int> years_vector = associates_vector.at(i)->getPaidYears();
		for (size_t t = 0; t < years_vector.size(); t++) {

			file << years_vector.at(t) << "/";
		}

		file << "]" << "/" << associates_vector.at(i)->getDivulgations();

		if (i != associates_vector.size() - 1)
			file << endl;

	}

	file.close();
}

void guardarficheiroEventos() {
	ofstream file("events.txt");

	/*SummerSchool/15-02-1998/Vila Real/Pirocas Piroclásticas/[1/5/3/]/[7/15/]/5000/[Zé/FEUP/Carlos/FCUP/]
	 Conference/15-02-2017/Porto/Conas Magnificas/[1/2/3/]/[4/5/]/1000/300*/

	vector<Event *> event_vector = Associacao->getEvents();

	for (size_t i = 0; i < event_vector.size(); i++) {

		if (event_vector.at(i)->getType() == "SummerSchool") {
			file << event_vector.at(i)->getType() << "/";
			file << event_vector.at(i)->getDate() << "/";
			file << event_vector.at(i)->getLocal() << "/";
			file << event_vector.at(i)->getTheme() << "/[";

			vector<Associate *> requesters_vector =
					event_vector.at(i)->getRequest();

			vector<int> used_ids;

			for (size_t t = 0; t < requesters_vector.size(); t++) {

				file << requesters_vector.at(t)->getUniqueID() << "/";
				used_ids.push_back(requesters_vector.at(t)->getUniqueID());
			}

			file << "]/[";

			vector<Associate *> organizers_vector =
					event_vector.at(i)->getOrganizers();
			for (size_t t = 0; t < organizers_vector.size(); t++) {
				if (find(used_ids.begin(), used_ids.end(),
						organizers_vector.at(t)->getUniqueID())
						== used_ids.end())
					file << organizers_vector.at(t)->getUniqueID() << "/";
			}

			file << "]/" << event_vector.at(i)->getSupport() << "/[";

			list<Trainer *> trainers = event_vector.at(i)->getTrainers();

			for (auto it = trainers.begin(); it != trainers.end(); it++) {
				file << (*it)->getName() << "/" << (*it)->getInstitution()
						<< "/";
			}

			file << "]";

		} else {
			file << event_vector.at(i)->getType() << "/";
			file << event_vector.at(i)->getDate() << "/";
			file << event_vector.at(i)->getLocal() << "/";
			file << event_vector.at(i)->getTheme() << "/[";

			vector<Associate *> requesters_vector =
					event_vector.at(i)->getRequest();

			vector<int> used_ids;

			for (size_t t = 0; t < requesters_vector.size(); t++) {

				file << requesters_vector.at(t)->getUniqueID() << "/";
				used_ids.push_back(requesters_vector.at(t)->getUniqueID());
			}

			file << "]/[";

			vector<Associate *> organizers_vector =
					event_vector.at(i)->getOrganizers();
			for (size_t t = 0; t < organizers_vector.size(); t++) {
				if (find(used_ids.begin(), used_ids.end(),
						organizers_vector.at(t)->getUniqueID())
						== used_ids.end())
					file << organizers_vector.at(t)->getUniqueID() << "/";
			}

			file << "]/" << event_vector.at(i)->getSupport() << "/";
			file << event_vector.at(i)->getEstimative();

		}

		if (i != event_vector.size() - 1)
			file << endl;
	}

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
	cout << "\nIndique quais as areas de interesse do Associado: " << endl;

	vector<Area *> areas = Associacao->getAreas();
	for (size_t t = 0; t < areas.size(); t++) {
		cout << t << ": " << areas.at(t)->getName() << endl;
	}

	string list;
	cout << "\nIntroduza as opcoes separadas por espacos: ";
	getline(cin, list);

	stringstream numbers(list);

	vector<Area *> newInterest; //O VETOR QUE IRA CONTER AS AREAS DE INTERESSE DO ASSOCIADO

	while (!numbers.eof()) {
		size_t selected = 0;
		if (!(numbers >> selected))
			cout
					<< "\nUm dos valores introduzidos nao foi um inteiro.\n" << endl;
		if (selected >= areas.size() || selected < 0) { //SE UM DOS INDICES ESCOLHIDOS NAO CORRESPONDE A NENHUM DOS APRESENTADOS
			cout << "\nNao existe a opcao " << selected << endl;
			sleep(1);
			return;
		}

		newInterest.push_back(areas.at(selected));
	}

	Associate * newAsso = new Associate(Associacao, nome, instituicao,
			newInterest);

	Associacao->addAssociate(newAsso);
	Associacao->updateAllAssociates();

	cout << "\nAssociado adicionado com sucesso!" << endl << endl;

	sleep(1);
}

void removerAssociado() {
	int uniqueID;
	string tempID;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o Identificador Unico do Associado a remover: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, tempID);

	if (!is_number(tempID)) {
		cout
				<< "O valor introduzido nao e um inteiro.\n" << endl;
		return;
	}

	uniqueID = stoi(tempID);

	try {
		Associacao->removeAssociate(uniqueID);
	} catch (NoSuchID & e) {
		cout << "\nNao existe nenhum associado com o ID: " << e.getID() << endl;
		sleep(1);
		return;
	}

	cout << "\nAssociado removido com sucesso!" << endl;

	sleep(1);
}

void alterarAssociado() {
	string tempID;
	int uniqueID;
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cout << "Introduza o Identificador Unico do Associado: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, tempID);

	if (!is_number(tempID)) {
		cout
				<< "O valor introduzido nao e um inteiro.\n" << endl;
		return;
	}

	uniqueID = stoi(tempID);

	Associate * alterar;
	try {
		alterar = Associacao->getAssoById(uniqueID);
	} catch (const NoSuchID & e) {
		cout << "\nNao existe nenhum associado com o ID: " << e.getID() << endl;
		sleep(1);
		return;
	}

	cout << "\nQual o atributo que pretende mudar: " << endl;

	cout << "\t0: Areas de Interesse" << endl;
	cout << "\t1: Instituicao" << endl;

	cout << "\nInsira uma opcao: ";
	string opcao;
	getline(cin, opcao);

	if (!is_number(opcao)) {
		cout
				<< "O valor introduzido nao e um inteiro.\n" << endl;
		return;
	}

	int escolha = stoi(opcao);

	switch (escolha) {
	case 0: {
		cout
				<< "\nTodas as areas de interesse do associado foram eliminadas. Escolha as novas areas de interesse.\n";
		vector<Area *> areas = Associacao->getAreas();
		for (size_t t = 0; t < areas.size(); t++) {
			cout << t << ": " << areas.at(t)->getName() << endl;
		}

		string list;
		cout << "\nIntroduza as opcoes separadas por espacos: ";
		getline(cin, list);

		stringstream numbers(list);

		vector<Area *> newInterest; //O VETOR QUE IRA CONTER AS AREAS DE INTERESSE DO ASSOCIADO

		while (!numbers.eof()) {
			size_t selected = 0;
			if (!(numbers >> selected))
				cout
						<< "\nUm dos valores introduzidos nao foi um inteiro.\n" << endl;
			if (selected >= areas.size() || selected < 0) { //SE UM DOS INDICES ESCOLHIDOS NAO CORRESPONDE A NENHUM DOS APRESENTADOS
				cout << "\nNao existe a opcao " << selected << endl;
				sleep(1);
				return;
			}

			newInterest.push_back(areas.at(selected));
		}

		alterar->setInterestAreas(newInterest);

		cout << "Areas de Interesse alteradas com sucesso!\n";
		return;
		break;
	}
	case 1: {
		cout << "Qual a nova area de interesse do associado? ";
		string institution;
		getline(cin, institution);
		alterar->setInstitution(institution);
		cout << "Instituicao alterada com sucesso!\n";
		return;
		break;

	}
	default:
		cout << "Opcao Invalida" << endl;
		return;
	}

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
		cout << "\nNao existe nenhum associado com o ID: " << e.getID() << endl;
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

	string type;
	cout << "Indique o tipo de evento (Summer School ou Conference): ";
	getline(cin, type);

	bool typeevento; //true se for summer school e false se for conference
	if(type == "Summer School" || type == "summer school")
		typeevento = true;
	else if(type == "Conference" || type == "conference")
		typeevento = false;
	else{
		cout << "\nNao existe essa opcao\n";
		return;
	}


	cout << "\nIntroduza o numero de Associados que querem criar o Evento: ";
	cin >> numAsso;

	for (int i = 0; i < numAsso; i++) {
		cout << "Introduza o Identificador Unico do " << i + 1
				<< "º Associado que quer criar um Evento: ";
		cin >> uniqueID;
		try {
			associado = Associacao->getAssoById(uniqueID);
		} catch (NoSuchID & e) {
			cout << "\nNao existe nenhum associado com o ID: " << e.getID() << endl;
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
			cout << "\nNao existe nenhum associado com o ID: " << e.getID() << endl;
			sleep(1);
			return;
		}
		event_organizers.push_back(associado);
	}

	cin.clear();
	cin.ignore(10000, '\n');

	string date, local, theme;
	cout << "\nIntroduza a data do evento (dd-mm-aaaa): ";
	getline(cin, date);
	cout << "\nIntroduza o local do evento: ";
	getline(cin, local);
	cout << "\nIntroduza o tema do evento: ";
	getline(cin, theme);


	if(typeevento){
		int numFormadores;
		cout << "\nIntroduza o numero de formadores do evento: ";
		cin >> numFormadores;
		list<Trainer *> trainers;
		cin.clear();
		cin.ignore(10000, '\n');
		for(int i = 0; i < numFormadores; i++){
			string nome, instituicao;
			cout << "\nIntroduza o nome do " << i + 1 << "º Formador: ";
			getline(cin, nome);
			cout << "Introduza o nome da sua intituicao: ";
			getline(cin, instituicao);
			Trainer * trainer = new Trainer(nome,instituicao);
			trainers.push_back(trainer);
		}
		SummerSchool * escola;
		try {
			escola = new SummerSchool(event_request, event_organizers, date, local, theme,
					Associacao, trainers);
		} catch (const NoSupportGiven & e) {
			cout << "\nEm " << e.getTotal() << " associados, " << e.getLate()
					 << " tem pagamentos em atraso. Impossivel criar evento!\n\n";
			sleep(1);
			return;
		}
		Associacao->addEvent(escola);
	}

	else {
		int numEsperado;
		cout << "\nIntroduza um numero esperado de Participantes: ";
		cin >> numEsperado;
		Conference * conferencia;
		try {
			conferencia = new Conference(event_request, event_organizers, date, local, theme,
					Associacao, numEsperado);
		} catch (const NoSupportGiven & e) {
			cout << "\nEm " << e.getTotal() << " associados, " << e.getLate()
					 << " tem pagamentos em atraso. Impossivel criar evento!\n\n";
			sleep(1);
			return;
		}
		Associacao->addEvent(conferencia);
		cout << endl;
	}

	cout << "Evento criado com sucesso!\n";
	sleep(1);
}

void removerEvento() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;

	cin.clear();
	cin.ignore(10000, '\n');
	string data;
	cout << "Introduza a data do evento a remover (dd-mm-aaaa): ";
	getline(cin, data);

	try {
		Associacao->removeEvent(data);
	} catch (const NoSuchDate & e) {
		cout << "\nNao existe nenhum evento com a data " << e.getDate() << endl;
		sleep(1);
		return;
	}

	cout << "\nEvento removido com sucesso!\n";
	sleep(1);
}

void alterarEvento() {
	cout << endl << endl;
	cout << "--------------------------------------------- " << endl;
	cout << "ASSOCIACAO PORTUGUESA INVESTIGACAO CIENTIFICA" << endl;
	cout << "--------------------------------------------- " << endl;
	cout << endl << endl;
	cin.clear();
	cin.ignore(10000, '\n');

	string data;
	cout << "Introduza a data do evento a alterar (dd-mm-aaaa): ";
	getline(cin, data);

	Event * alterar;
	try {
		alterar = Associacao->getEventByDate(data);
	} catch (const NoSuchDate & e) {
		cout << "\nNao existe nenhum evento com a data " << e.getDate() << endl;
		sleep(1);
		return;
	}

	string type = alterar->getType();
	bool typeevento; //true se for summer school e false se for conference
	if(type == "SummerSchool")
		typeevento = true;
	else if(type == "Conference")
		typeevento = false;

	cout << "\nQual o atributo que pretende mudar: " << endl;

	cout << "\t0: Data" << endl;
	cout << "\t1: Local" << endl;
	cout << "\t2: Tema" << endl;
	if(typeevento)
		cout << "\t3: Formadores" << endl;
	else
		cout << "\t3: Numero esperado de Participantes" << endl;

	cout << "\nInsira uma opcao: ";
	string opcao;
	getline(cin, opcao);

	if (!is_number(opcao)) {
		cout
				<< "O valor introduzido nao e um inteiro.\n" << endl;
		return;
	}

	int escolha = stoi(opcao);

	switch (escolha) {
	case 0:
	{
		cout << "\nQual a nova data do evento? ";
		string data;
		getline(cin, data);
		alterar->setDate(data);
		cout << "\nData alterada com sucesso!\n";
		break;
	}
	case 1:
	{
		cout << "\nQual o novo local do evento? ";
		string local;
		getline(cin, local);
		alterar->setLocal(local);
		cout << "\nLocal alterado com sucesso!\n";
		break;
	}
	case 2:
	{
		cout << "\nQual o novo tema do evento? ";
		string tema;
		getline(cin, tema);
		alterar->setTheme(tema);
		cout << "\nTema alterado com sucesso!\n";
		break;
	}
	case 3:
	{
		if(typeevento){
			int numFormadores;
			cout << "\nIntroduza o numero de novos formadores do evento: ";
			cin >> numFormadores;
			list<Trainer *> trainers;
			cin.clear();
			cin.ignore(10000, '\n');
			for(int i = 0; i < numFormadores; i++){
				string nome, instituicao;
				cout << "\nIntroduza o nome do " << i + 1 << "º Formador: ";
				getline(cin, nome);
				cout << "Introduza o nome da sua intituicao: ";
				getline(cin, instituicao);
				Trainer * trainer = new Trainer(nome,instituicao);
				trainers.push_back(trainer);
			}
			SummerSchool * novo = new SummerSchool(alterar->getRequest(),alterar->getOrganizers(),alterar->getDate(),alterar->getLocal(),alterar->getTheme(), Associacao, trainers);
			Associacao->removeEvent(alterar->getDate());
			Associacao->addEvent(novo);
			cout << "\nFormadores alterados com sucesso!\n";
			break;
		}
		else{
			int numEsperado;
			cout << "\nIntroduza o novo numero esperado de Participantes: ";
			cin >> numEsperado;
			Conference * novo = new Conference(alterar->getRequest(),alterar->getOrganizers(),alterar->getDate(),alterar->getLocal(),alterar->getTheme(), Associacao, numEsperado);
			Associacao->removeEvent(alterar->getDate());
			Associacao->addEvent(novo);
			cout << "\nNumero esperado de Participantes alterado com sucesso!\n";
			break;
		}
	}
	default:
		cout << "Opcao Invalida" << endl;
		return;
	}


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
