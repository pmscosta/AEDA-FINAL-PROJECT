/*
 * Functions.h
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#ifndef SUPER_MEME_FUNCTIONS_H_
#define SUPER_MEME_FUNCTIONS_H_

#include "Associate.h"
#include "Area.h"
#include "Association.h"
#include "SubArea.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h> //for usleep(miliseconds) function


//-----------------------FILES--------------------------//

void lerficheiroAreas();

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
