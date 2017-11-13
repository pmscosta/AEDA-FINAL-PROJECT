/*
 * Network.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: jubas
 */

#include "Network.h"

using namespace std;

//Constructors

Network::Network() {
	// TODO Auto-generated constructor stub

}


//Destructors

Network::~Network() {
	// TODO Auto-generated destructor stub
}


//Set Methods

void Network::setMails(vector<Mail*> mails) : mails(mails) {};


//Get Methods

vector<Mail *> Network::getMails() const{
	return this->mails;
}
