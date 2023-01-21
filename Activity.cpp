/*
 * Activity.cpp
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#include "Activity.h"

using namespace std;

//*** CONSTRUTORES E DESTRUTORES ***//

Activity::Activity(){} //implementacao do construtor padrao

//Construtor da classe personalizado. Usamos este construtor
//quando usamos a sobrecarga de operador para combinar duas atividades
//ele gerara a nova atividade originada pela combinacao
Activity::Activity(string title, string description, string url, float system, float narrative, float agency){

	this->title = title;
	this->description = description;
	this->url = url;
	this->system = system;
	this->narrative = narrative;
	this->agency = agency;
}

Activity::~Activity(){}	//implementacao do destrutor

//*** SETTERS ***//
//vemos que a maioria dos setters requerem validacao das variaveis
//para isso existe a validacao do elemento recebido em caso de nao validade devolve erro

//setter do ID no caso nao existe validacao pois ele e
//criado internamente pela classe da lista de atividades 
//que garante a sua isonomia
void Activity::setId(int id){
	this->id = id;
}

//setter do titulo aqui existe validacao
//queremos sempre que o titulo exista e nao seja nulo
//o setter recebe o elemento a inserir no objeto da atividade
void Activity::setTitle(string title){

	if(title.empty()){	//se nao existir elementos no titulo devolve erro
		throw false;
	}else{	//caso contrario define o titulo no objeto
		this->title = title;
	}
}

//setter da descricao aqui existe validacao
//queremos sempre que a descricao exista e nao seja nula
//o setter recebe o elemento a inserir no objeto da atividade
void Activity::setDescription(string description){	
	if(description.empty()){
		throw false;
	}else{
		this->description = description;
	}	
}

//setter do url aqui existe validacao
//queremos sempre que o url exista e comece por http:// ou https://
//o setter recebe o elemento a inserir no objeto da atividade
void Activity::setUrl(string url){

	//o requisito era que tinha que comecar por http:// ou https:// e nada mais
	//entao vamos apenas validar isso atraves da validacao de prefixos
	//existem outras formas de o fazer, e bem simples
	if (url.rfind("http://", 0) == 0 || url.rfind("https://", 0) == 0) { // pos=0 limita a pesquisa apenas ao prefixo
		this->url = url;
	}else{	//se nao for valido devolve erro
		throw false;
	}
}

//os setters do sistema, narrativa e agencia; aqui existe validacao
//queremos sempre que estejam no intervalo de 0 a 1
//os setters recebem o elemento a inserir no objeto da atividade
//aqui realizamos uma validacao simples
void Activity::setSystem(float system){

	if(system < 0 || system > 1) { 
		throw false;
	}else{
		this->system = system;
	}

}

void Activity::setNarrative(float narrative){

	if(narrative < 0 || narrative > 1) { 
		throw false;
	}else{
		this->narrative = narrative;
	}
}

void Activity::setAgency(float agency){

	if(agency < 0 || agency > 1) { 
		throw false;
	}else{
		this->agency = agency;
	}
}

//*** GETTERS ***//
//os getters sao de simples implementacao, apenas
//retornamos o valor do objeto pretendido
int Activity::getId(){ return this->id; }; 
string Activity::getTitle(){ return this->title; }; 
string Activity::getDescription(){ return this->description; }; 
string Activity::getUrl(){ return this->url; }; 
float Activity::getSystem(){ return this->system; }; 
float Activity::getNarrative(){ return this->narrative; }; 
float Activity::getAgency(){ return this->agency; }; 

//** METODO PUBLICO**//

//Aqui realizamos a sobrecarga de operador "+" como pretendido no enunciado
//ou seja, vai permitir realizar atividade + atividade podera ver essa "soma" no metodo combineActivities() da lista de atividades
//ele devolve uma nova atividade como era pretendido no exercicio e recebe a atividade como soma
Activity* Activity::operator+(Activity& activitie){

	//A aplicacao da sobrecarga pretendida e simples
	//Para cada uma das coordenadas, seleciona-se a coordenada maior entre as duas atividades a serem comparadas
	float _system = system, _narrative = narrative, _agency = agency;
	if(activitie.system > system) _system = activitie.system;
	if(activitie.narrative > narrative) _narrative = activitie.narrative;
	if(activitie.agency > agency) _agency = activitie.agency;
	
	//vamos unir agora os titulos, descricao e url
	string _title = activitie.title + " & " + title, _description = activitie.description + " & " + description, _url = activitie.url + " & " + url;
	
	//contruimos uma nova atividade com o resultado de ambas
	//repare-se que estamos a usar o construtor personalizado
	Activity * combination = new Activity(_title, _description, _url, _system, _narrative, _agency);

	//devolvemos a nova atividade
	return combination;
}
