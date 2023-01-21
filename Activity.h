/*
 * Activity.h
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Activity{

	private:
		//*** VARIAVEIS DA CLASSE ***//
		//usamos um parametro ID para facilitar as selecoes e ate a vizualizacao do utilizador,
		//devemos sempre considerar uma chave primaria unica quando poderemos ter repetidos (no caso, titulos) e uma boa pratica
		int id;	
		//Instanciamos as variaveis da classe como requerido.
		string title;
		string description;
		string url;
		float system, narrative, agency;

	public:
		//*** CONSTRUTORES E DESTRUTORES ***//
		//repare-se que temos dois tipos de construtor
		//como existe validacao de variaveis e sempre boa pratica instanciar as variaveis atraves dos seus setters
		//nunca devemos recolher inputs no construtor nem realizar validacoes diretamente no construtor
		//isto porque se existir uma subclasse da atividade os construtores vao entrar em conflito
		//neste exercicio nao e o caso mas vamos manter as boas praticas
		Activity(); //Construtor da classe
		//este construtor personalizado e usado para criar a nova atividade quando usamos a sobrecarga de operador como iremos ver
		Activity(string, string, string, float, float, float); //Construtor da classe personalizado
		virtual ~Activity(); //destrutor da classe
		
		//*** SETTERS ***//
		//e sempre boa pratica definir setters para as variaveis 
		//mesmo que nao se usem agora, mais tarde podem vir a ser usados
		//estamos a dar modularidade ao programa
		//no caso do exercicio, os setters sao usados para validar as variaveis da classe
		void setId(int);
		void setTitle(string); 
		void setDescription(string);
		void setUrl(string);
		void setSystem(float);
		void setNarrative(float);
		void setAgency(float);

		//*** GETTERS ***//
		//devemos sempre instanciar os getters pois permitem acesso ao valores do objeto
		int getId(); 
		string getTitle(); 
		string getDescription();
		string getUrl();
		float getSystem();
		float getNarrative();
		float getAgency();

		//** METODO PUBLICO**//
		
		Activity* operator+(Activity&); //Sobrecarga de operador de soma como requerido no enunciado
		
};

#endif /* ACTIVITY_H_ */
