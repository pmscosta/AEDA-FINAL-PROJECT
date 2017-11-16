/*
 * Functions.h
 *
 *  Created on: 14/11/2017
 *      Author: nl
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_



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
