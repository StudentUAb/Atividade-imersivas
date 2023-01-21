/*
 * UserInterface.h
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <iostream>     //para operacoes de input e output
#include <string>       //para operacoes na class string (cadeia de carateres)
#include <limits>       //biblioteca de limites para analise de inputs
#include <regex>        //biblioteca regex para verificacoes (existem outras formas possiveis)
#include <iomanip>      //para tornar a aprsentacao das listas enquadrada no output (apenas para embelezar)
#include "ActivityList.h"       //disponibilizamos a classe da lista de atividades


using namespace std;

class UserInterface{

        private:
                /*** METODOS PRIVADOS ***/
                int menu();                             //metodo de recolha de opcao do menu geral e apresentacao das opcoes
                int selectOrder();                      //metodo de recolha de opcao ascendente e descendente de ordenacao e apresentacao de opcoes
                void combineActivities(ActivityList&);  //metodo de recolha de atividades a serem combinadas
                void UserInput(Activity& , int);        //metodo para recolher os varios inputs do utilizador ao longo do programa
                void AddActivity(ActivityList&);        //metodo para recolha de dados e adicao de atividade
                void showActivities(ActivityList&, int);		//este metodo apresenta a lista de atividades consoante o modo que desejamos
        public:
                //*** CONSTRUTORES E DESTRUTORES ***//
                UserInterface(); //Construtor da classe
                virtual ~UserInterface(); //Destrutor da classe

                //** METODO PUBLICO**//
                void execute(); //Executa a interface do utilizador

};


#endif /* USERINTERFACE_H_ */
