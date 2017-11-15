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
#include <unistd.h> //for usleep(miliseconds) function

void initialize();

//-----------------------FILES--------------------------//

void lerficheiroAreas();

void lerficheiro();

void criarficheiro();

void guardarficheiro();

//----------------------ASSOCIATES---------------------//

void adicionarAssociado();

void removerAssociado();

void alterarAssociado();

void verInfoAssociado();

//----------------------AREAS-------------------------//

void verAreas();

#endif /* SUPER_MEME_FUNCTIONS_H_ */
