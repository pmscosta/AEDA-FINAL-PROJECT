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

void guardarficheiroAreas();

void guardarficheiroAssociacao();

void guardarficheiroAssociados();

void guardarficheiroEventos();

void limparficheiros();

//----------------------ASSOCIATES---------------------//

void adicionarAssociado();

void removerAssociado();

void alterarAssociado();

void verInfoAssociado();

//----------------------EVENTS-------------------------//


#endif /* SUPER_MEME_FUNCTIONS_H_ */
