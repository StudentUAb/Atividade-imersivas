/*
 * ActiviltyList.cpp
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#include "ActivityList.h" //incluimos o cabecalho da classe

using namespace std;

//*** CONTRUTORES E DESTRUTORES ***//

ActivityList::ActivityList(){} //Implementacao do constructor
ActivityList::~ActivityList() {} //Implementacao do destructor

//** METODOS PRIVADOS **//

//este metodo encontra uma atividade pelo seu ID, util quando queremos obter as atividades a combinar
//devolve o apontador para a atividade requerida
Activity* ActivityList::findActivity(int id) {
	
	//Percorre a lista de atividades ate encontrar a que possui o ID desejado
	//definimos o iterador para o inicio e iteramos
	for (it = Activities.begin(); it != Activities.end(); it++) {
		if(it->getId() == id) {
			return &*it;
		}
	}
	
	//se nao encontrar nada devolve nulo
	return NULL;
}

//** GETTERS **//
list<Activity> ActivityList::getActivities(){return this->Activities;}
list<Activity>::iterator ActivityList::getIt(){return this->it;}

//** METODOS PUBLICOS **//

//este metodo ordena a nossa lista consoante o modo que desejamos
//ele recebe o modo de ordenacao ou seja um numero que corresponde 
//ao tipo de coordenada e a sua ordem ascendente ou descendente
void ActivityList::sortActivities(int mode) {
	
	//usamos um switch para decidir qual o modo ordenar
	switch (mode){
		case 1:	//sistema, ordem ascendente
			//a ordenacao é bem simples apenas usamos o sort da biblioteca lista e comparamos a sua variavel
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getSystem() <= act2.getSystem();
			});
			break;
		
		case 2:	//sistema, ordem descendente
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getSystem() >= act2.getSystem();
			});
			break;
		
		case 3:	//narrativa, ordem ascendente
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getNarrative() <= act2.getNarrative();
			});
			break;
		
		case 4:	//narrativa, ordem descendente
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getNarrative() >= act2.getNarrative();
			});
			break;
		
		case 5:	//agencia, ordem ascendente
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getAgency() <= act2.getAgency();
			});
			break;
		
		case 6:	//agencia, ordem descendente
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getAgency() >= act2.getAgency();
			});
			break;
		
		case 7:	//Por ordem de insercao (ou seja, ID)
			Activities.sort([](Activity & act1, Activity & act2) {
				return act1.getId() <= act2.getId();
			});
			break;
		
		default:
			break;
	}

}

//este metodo apenas obtem dimensoes para tornar as listas mais bonitas (desnecessario)
//serve apenas para obter as dimensoes do texto para que quando
//se imprimir a lista saia uma tabela direita e bonita com recurso a biblioteca iomanip
//devolve um apontador para o array de tamanhos
int* ActivityList::getLengthForTable(){

	static int max[3] = {7,8,8};	//definimos um array para guardar os tamanhos minimos

	//so interessa analizar o tamanho de titulo, descricao e url, porque as coordenadas sao sempre pequenas
	//iteramos pelas atividades da lista e recolhemos os valores maximos de cada
	for (it = Activities.begin(); it != Activities.end(); it++) {
	   max[0] = (signed int) (it->getTitle().length() ) > max[0] ? it->getTitle().length() : max[0];
	   max[1] = (signed int) (it->getDescription().length() ) > max[1] ? it->getDescription().length() : max[1];
	   max[2] = (signed int) (it->getUrl().length() ) > max[2] ? it->getUrl().length() : max[2];
	}

	return max;
}

//este metodo recolhe o proximo ID para uma atividade
//usamos o ID para facilitar as identificacoes de atividades
int ActivityList::getNewId(){

	//Determina o ID da nova actividade
	//incrementando 1 ao tamanho da lista 
	//podemos fazer isto pois nao estamos a eliminar nada da lista
	int id = Activities.size() +1;
	return id;
	
}

//este metodo adiciona uma atividade a lista de atividades
//metodo bem simples apenas faz push da atividade para o fim da lista
//recebe a atividade a inserir
void ActivityList::addActivity(Activity& activity){

	Activities.push_back(activity);	//colocacao no final da lista
}

//este metodo obtem as atividades a serem combinadas e combina-as
//por recurso a sobrecarga de operador da classe da atividade
void ActivityList::combineActivities(int id1, int id2){

	//Encontra as atividades a combinar,
	//chamando o metodo privado para o efeito passando o ID
	Activity * a1 = findActivity(id1);
	Activity * a2 = findActivity(id2);

	//Se alguma das atividades não existir, aborta a operacao de combinacao
	//e lanca erro ao utilizador
	if(a1 == NULL || a2 == NULL ) {
		throw false;
	}

	//Combina as duas actividades com a sobrecarga de operador
	Activity* combined = *a1 + *a2;
	
	//obtemos um novo ID para a nova atividade
	//combinada e fazemos set dele
	int id = getNewId();
	combined->setId(id);
	
	//adicionamos a atividade a lista
	addActivity(*combined);

}



