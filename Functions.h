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

void ano();


//-----------------------FILES--------------------------//

void lerficheiroAreas();

void lerficheiroAssociacao();

void lerficheiroAssociados();

void lerficheiroEventos();

void lerficheiroMails();

void guardarficheiros();

void guardarficheiroAreas();

void guardarficheiroAssociacao();

void guardarficheiroAssociados();

void guardarficheiroEventos();

void guardarficheiroMails();

void limparficheiros();


//----------------------ASSOCIATES---------------------//

void adicionarAssociado();

void removerAssociado();

void alterarAssociado();

void verInfoAssociado();

void organizarAssociados();


//----------------------EVENTS-------------------------//

void criarEvento();

void removerEvento();

void alterarEvento();

void verInfoEvento();

void organizarEventos();


//-----------------------COTAS-------------------------//

void pagarCotas();

void pagarTodasCotas();

void verAssociadosCotas();


//-----------------------REDE--------------------------//

void divulgarEmail();

void verEmails();

void organizarMails();



#endif /* FUNCTIONS_H_ */
