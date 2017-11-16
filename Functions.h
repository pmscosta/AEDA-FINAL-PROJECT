/*
 * Functions.h
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

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
#include <sstream>
#include <unistd.h>

void initialize();

void initialize2();


//-----------------------FILES--------------------------//

void lerficheiroAreas();

void lerficheiroAssociacao();

void lerficheiroAssociados();

void lerficheiroEventos();

void guardarficheiros();

void guardarficheiroAreas(Association * association);

void guardarficheiroAssociacao(Association * association);

void guardarficheiroAssociados(Association * association);

void guardarficheiroEventos();

void limparficheiros();


//----------------------ASSOCIATES---------------------//

void adicionarAssociado();

void removerAssociado();

void alterarAssociado();

void verInfoAssociado();


//----------------------EVENTS-------------------------//

void criarEvento();

void removerEvento();

void alterarEvento();

void verInfoEvento();


//-----------------------COTAS-------------------------//

void pagarCotas();

void verAssociadosCotas();


//-----------------------REDE--------------------------//

void divulgarEmail();

void verEmails();



#endif /* FUNCTIONS_H_ */
