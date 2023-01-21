/*
 * Main.cpp
 *
 *      Author: Rudi Gualter
 *   
 */

#include "UserInterface.h"	//disponibilizamos a classe da interface

using namespace std;


int main(){

	//inicializa a classe da interface de utilizador
	//onde estao todos os metodos de recolha de dados e menus.
	UserInterface userInterface;
	//executamos a interface	
	userInterface.execute();

	return 0;
}




