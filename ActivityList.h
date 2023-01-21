/*
 * ActiviltyList.h
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#include <list>			//chamamos a biblioteca list, que vamos usar como estrutura para guardar as atividades
#include "Activity.h"	//disponibilizamos a classe de atividade pois a lista vai operar com atividades

#ifndef ACTIVITYLIST_H_
#define ACTIVITYLIST_H_

using namespace std;

class ActivityList {

	private:
		/*** VARIAVEIS PRIVADAS ***/
		list<Activity> Activities;		//Definimos a lista de atividades
		list<Activity>::iterator it;	//definimos o iterador pois vamos sempre usa-lo

		/*** METODOS PRIVADOS ***/
		
		
		Activity* findActivity(int);	//este metodo encontra uma atividade pelo seu id - util quando queremos obter as atividades a combinar

	public:

		//*** CONSTRUTORES E DESTRUTORES ***//
		ActivityList();				//construtor da lista de atividades
		virtual ~ActivityList();	//destrutor da lista de atividades

		//*** GETTER ***//
		list<Activity> getActivities();
		list<Activity>::iterator getIt();

		//** METODOS PUBLICOS**//
		int getNewId();						//este metodo recolhe o proximo id para uma atividade
		void addActivity(Activity&);		//este metodo adiciona uma atividade a lista de atividades (equivalente ao setter)
		void sortActivities(int);		//este metodo ordena a nossa lista consoante o modo que desejamos
		int* getLengthForTable();		//este metodo apenas obtem dimensoes para tonar as listas mais bonitas (desnecessario)
		void combineActivities(int, int);	//este metodo obtem as atividades a serem combinadas e combina-as
};

#endif /* ACTIVITYLIST_H_ */
