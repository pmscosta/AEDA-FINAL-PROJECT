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

void guardarficheiroAreas(Association * association) {
	ofstream file("areas.txt");

	//Imunologia e Infeção/Imunologia e Inflamação/IMI-IMU/Microbiologia e Infeção/IMI-MIC

	vector <Area *> areas_vector = association->getAreas();
	for(size_t i = 0; i < areas_vector.size(); i++){

		file << areas_vector.at(i)->getName() << "/";

		vector <SubArea *> subareas_vector = areas_vector.at(i)->getSubAreas();
		for(size_t t; t < subareas_vector.size(); t++){

			if(t == (subareas_vector.size() - 1))
				file << subareas_vector.at(t)->getName() << "/" << subareas_vector.at(t)->getInitials() << endl;
			else
				file << subareas_vector.at(t)->getName() << "/" << subareas_vector.at(t)->getInitials() << "/";
		}
	}

	file.close();
}

void guardarficheiroAssociacao(Association * association) {
	ofstream file("association.txt");


	//Name/ 231.7/ 242.4/ 4

	file << association->getName() << "/";
	file << association->getFund() << "/";
	file << association->getAnnualPay() << "/";
	file << association->getCurrentYear();

	file.close();
}

void guardarficheiroAssociados(Association * association) {
	ofstream file("associates.txt");

	//1/Pedro Costa/FEUP/[Neurociências, Envelhecimento e Doenças Degenerativas/Imunologia e Infeção/]/50.4/[40/2/70/]/4

	vector <Associate *> associates_vector = association->getAssociates();
	for(size_t i = 0; i < associates_vector.size(); i++){

		file << associates_vector.at(i)->getUniqueID() << "/";
		file << associates_vector.at(i)->getName() << "/";
		file << associates_vector.at(i)->getInstitution() << "/[";

		vector<Area *> areas_interest = associates_vector.at(i)->getInterestAreas();
		for(size_t t = 0; t < areas_interest.size(); t++){

			file << areas_interest.at(t)->getName() << "/";
		}
		file << "]" << "/" << associates_vector.at(i)->getPersonalWallet() << "/[";

		vector<int> years_vector = associates_vector.at(i)->getPaidYears();
		for(size_t t = 0; t < years_vector.size(); t++){

			file << years_vector.at(t) << "/";
		}

		file << "]" << "/" << associates_vector.at(i)->getDivulgations() << endl;

	}

	file.close();
}

void guardarficheiroEventos(Association * association) {
	ofstream file("events.txt");

	/*Summer School/15-02-1998/Vila Real/Pirocas Piroclásticas/[1/5/3/]/[7/15/]/5000/300
	 Conference/15-02-2017/Porto/Conas Magnificas/[1/2/3/]/[4/5/]/1000/[Zé/FEUP/Carlos/FCUP/]*/

	vector<Event *> event_vector = association->getEvents();
	for(size_t i = 0; i < event_vector.size(); i++){

		file << event_vector.at(i)->getDate() << "/";
		file << event_vector.at(i)->getLocal() << "/";
		file << event_vector.at(i)->getTheme() << "/[";

		vector<Associate *> requesters_vector = event_vector.at(i)->getRequest();
		for(size_t t = 0; t < requesters_vector.size(); t++){

			file << requesters_vector.at(t)->getUniqueID() << "/";
		}

		file << "]/[";

		vector<Associate *> organizers_vector = event_vector.at(i)->getOrganizers();
		for(size_t t = 0; t < organizers_vector.size(); t++){

			file << organizers_vector.at(t)->getUniqueID() << "/";
		}

		file << "]/" << event_vector.at(i)->getSupport() << "/";


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
	cout << "\nIntroduza o numero de Associados que vao ajudar a organizar o Evento: ";
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

	cin.clear();
	cin.ignore(10000, '\n');

	string date, local, theme;
	cout << "\nIntroduza a data do evento: ";
	getline(cin, date);
	cout << "\nIntroduza o local do evento: ";
	getline(cin, local);
	cout << "\nIntroduza o tema do evento: ";
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

	cout << "Evento criado com sucesso!";
	sleep(1);
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
