/*
 * UserInterface.cpp
 *
 *      Author: Rudi Gualter
 *
 * 
 */

#include "UserInterface.h"

using namespace std;

//*** CONSTRUTORES E DESTRUTORES ***//

UserInterface::UserInterface(){}; //Implementacao do construtor
UserInterface::~UserInterface(){}; //Implementacao do destrutor

//** METODO PUBLICO **//

//Execucao da interface geral do utilizador
//e o unico metodo que necessita de ser publico
void UserInterface::execute(){
    
    ActivityList ativities;
    int option = -1;
    int orderOption = -1;

    do{

        option = menu();

        switch (option)
        {
        case 1:
            AddActivity(ativities);
            break;
        case 2:
            orderOption = selectOrder();
            if(orderOption == 1){
                showActivities(ativities, 1);
                cout << endl << "Lista ordenada por ordem ascendente de sistema." << endl;
            }else if(orderOption == 2){
                showActivities(ativities, 2);
                cout << endl << "Lista ordenada por ordem descendente de sistema." << endl;
            }
            break;
        case 3:
            orderOption = selectOrder();
            if(orderOption == 1){
                showActivities(ativities, 3);
                cout << endl << "Lista ordenada por ordem ascendente de narrativa." << endl;
            }else if(orderOption == 2){
                showActivities(ativities, 4);
                cout << endl << "Lista ordenada por ordem descendente de narrativa." << endl;
            }
            break;
        case 4:
            orderOption = selectOrder();
            if(orderOption == 1){
                showActivities(ativities, 5);
                cout << endl << "Lista ordenada por ordem ascendente de agencia." << endl;
            }else if(orderOption == 2){
                showActivities(ativities, 6);
                cout << endl << "Lista ordenada por ordem descendente de agencia." << endl;
            }
            break;
        case 5:
            showActivities(ativities, 7);
            cout << endl << "Lista ordenada por ordem de insercao." << endl;
            break;
        case 6:
            combineActivities(ativities);
            break;
        default:
            break;
        }

    }while (option != 7);
    
    
    cout << endl << "Adeus. Obrigado!" << endl;
    
}

//** METODOS PRIVADOS **//

//metodo de recolha de opcao do menu geral e impressao das opcoes
int UserInterface::menu(){

	int opcao=-1;   //definimos uma opcao invalida

    //apresentamos o menu
    cout << endl <<  "###################### Menu Geral ######################" << endl;
    cout << "1 - Adicionar uma atividade" << endl;
    cout << "2 - Listar atividades ordenadas por coordenada de sistema" << endl;
    cout << "3 - Listar atividades ordenadas por coordenada de narrativa" << endl;
    cout << "4 - Listar atividades ordenadas por coordenada de agencia" << endl;
    cout << "5 - Listar atividades ordenadas por ordem de insercao" << endl;
    cout << "6 - Criar uma atividade por combinacao de duas atividades" << endl;
    cout << "7 - Sair" << endl;

    //enquanto o utilizador nao quiser sair, entramos num loop
    //para se sair tem de se escolher '7'
	do{
		cout << endl << "Opcao: ";  //solicitamos a opcao
		cin >> opcao;   //obtemos a opcao do input

        //se a opcao nao estiver no intervalo permitido
        //avisamos o utilizador e limpamos o buffer da entrada para evitar erros
        if(opcao<1 || opcao>7){
            cout << "Introduza uma opcao valida! Entre 1 e 7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

	}while(opcao<1 || opcao>7);

    //limpamos o buffer da entrada para evitar erros
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return opcao;   //devolvemos a opcao escolhilda
}

//metodo de recolha de opcao ascendente ou descendente de ordenacao e apresentacao
int UserInterface::selectOrder(){

	int opcao=-1; //definimos uma opcao invalida

     //apresentamos o menu
    cout << "############### Escolha o tipo de ordenacao ##############" << endl;
    cout << "1 - Ascendente" << endl;
    cout << "2 - Descendente" << endl;
    cout << "3 - Voltar ao menu principal" << endl;

    //enquanto o utilizador nao quiser sair entramos num loop
    //para se sair tem que se escolher '3'
	do{
		cout << endl << "Opcao: "; //solicitamos a opcao
		cin >> opcao;   //obtemos a opcao do input

        //se a opcao nao estiver no intervalo permitido
        //avisamos o utilizador e limpamos o buffer da entrada para evitar erros
        if(opcao<1 || opcao>3){
            cout << "Introduza uma opcao valida! Entre 1 e 2." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

	}while(opcao<1 || opcao>3);

    //limpamos o buffer da entrada para evitar erros
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return opcao; //devolvemos a opcao escolhilda
}

//metodo para recolher os varios inputs do utilizador ao longo do programa
// este metodo e' valido para as varias recolhas que se faz
//ao utilizador desde o titulo da atividade ao valor das coordenadas
//e essencialmente usado pelo metodo de adicao de atividade (AddActivity)
//como tal recebe a atividade e o modo (que significa o que se quer recolher e inserir no objeto)
void UserInterface::UserInput(Activity& activity, int mode){

    //realizamos um switch onde cada caso recolhe uma variavel
    //e realiza a tentativa de set da variavel recolhida
    //repare-se que quando uma classe exige validacao de dados
    //e boa pratica o uso dos setters para essa realizacao
    switch(mode){
        case 1: //recolha e definicao do titulo da atividade
            //realizamos um try_catch, para verificarmos se o metodo set da classe
            //definiu a variavel corretamente, isto porque o proprio metodo 
            //realiza a validacao da sua variavel
            try{ 
                cout << "Insira o titulo da atividade: ";   //questionamos o titulo ao utilizador
                string title; //string para obter o titulo
                getline(cin, title);    //obtemos a linha dos dados
                activity.setTitle(title);   //chamamos o setter da classe da atividade passando o valor obtido
                
            }catch(bool e){ //se o metodo set devolver erro e' porque o titulo nao e' valido
                
                cout<< "O titulo nao pode ser vazio. "; //informamos o utilizador
                UserInput(activity, mode);  //voltamos a recolher o input
            }
            break;
        case 2: //recolha e definicao do descricao da atividade
            try{ 
                cout << "Insira a descricao da atividade: ";
                string description; 
                getline(cin, description);
                activity.setDescription(description);
                
            }catch(bool e){
                
                cout<< "A descricao nao pode estar vazia. ";
                UserInput(activity, mode);
            }
            break;
        case 3: //recolha e definicao do url da atividade
            try{ 
                cout << "Insira o URL da atividade: ";
                string url; 
                getline(cin, url);
                activity.setUrl(url);
                
            }catch(bool e){
                
                cout<< "O URL tem que comecar por 'http://' ou 'https://'. ";
                UserInput(activity, mode);
            }
            break;
        case 4: //recolha e definicao da coordenada de sistema da atividade
            try{ 
                cout << "Insira a coordenada de sistema: ";
                string system; 
                getline(cin, system);
                //nete caso especifico usamos a string para nao existirem confusoes
                //se definirmos a variavel como float e se introduzir uma letra, ela iria aceitar e atribuir 0
                //para evitar isto e' melhor recolher em string e validar se esta nao contem letras
                //usamos uma validacao regex mas poderiamos realizar esta verificacao de varias formas
                //repare-se que a validacao da coordenada continua dentro do seu metodo set.
                if (regex_match(system, regex("-?[0-9]+([\\.][0-9]+)?"))){
                    float toFloat = stof(system);
                    activity.setSystem(toFloat);
                }else{
                    throw true;
                }
            }catch(bool e){
                
                if(e){
                    cout<< "Nao inseriu um numero. ";
                }else{
                    cout<< "A coordenada tem que estar entre 0 e 1. ";
                }
                UserInput(activity, mode);
            }
            break;
        case 5: //recolha e definicao da coordenada de narrativa da atividade
            try{ 
                cout << "Insira a coordenada de narrativa: ";
                string narrative; 
                getline(cin, narrative);
                if (regex_match(narrative, regex("-?[0-9]+([\\.][0-9]+)?"))){
                    float toFloat = stof(narrative);
                    activity.setNarrative(toFloat);
                }else{
                    throw true;
                }
            }catch(bool e){
                
                if(e){
                    cout<< "Nao inseriu um numero. ";
                }else{
                    cout<< "A coordenada tem que estar entre 0 e 1. ";
                }
                UserInput(activity, mode);
            }
            break;
        case 6: //recolha e definicao da coordenada de agencia da atividade
            try{ 
                cout << "Insira a coordenada de agencia: ";
                string agency; 
                getline(cin, agency);
                if (regex_match(agency, regex("-?[0-9]+([\\.][0-9]+)?"))){
                    float toFloat = stof(agency);
                    activity.setAgency(toFloat);
                }else{
                    throw true;
                }
            }catch(bool e){
                
                if(e){
                    cout<< "Nao inseriu um numero. ";
                }else{
                    cout<< "A coordenada tem que estar entre 0 e 1. ";
                }
                UserInput(activity, mode);
            }
            break;
        
        default:
            break;
    }
}

//metodo para recolha de dados e adicao de atividade
//metodo simples que usa o metodo userInput para
//recolha e definicao de dados no objeto
void UserInterface::AddActivity(ActivityList& ativities){
        
        Activity activity;  //criamos uma nova atividade
        int id = ativities.getNewId();  //recolhemos um ID para ela atraves da classe da lista
        activity.setId(id); //definimos o ID no objeto com o seu setter
        //chamamos a recolha das varias variaveis
        UserInput(activity,1);  //titulo
        UserInput(activity,2);  //descricao
        UserInput(activity,3);  //url
        UserInput(activity,4);  //sistema
        UserInput(activity,5);  //narrativa
        UserInput(activity,6);  //agencia
        
        //adicionamos a nova atividade 'a lista de atividades
        //recorremos ao metodo da classe da lista
        ativities.addActivity(activity); 

        cout << "Atividade adicionada! Veja a lista:" << endl;  //informamos o utilizador do exito
        
        //com recurso ao metodo de mostrar atividades
        //mostramos as atividades ao utilizador, '7' significa
        //mostrar as atividades por ordem de insercao
        showActivities(ativities, 7);
}

//este metodo apresenta a lista de atividades consoante o modo que desejamos
//recebe o modo e chama o metodo privado que ordena do modo desejado e apresenta a lista
void UserInterface::showActivities(ActivityList& ativities, int mode){
	
    list<Activity> Activities = ativities.getActivities();
    list<Activity>::iterator it = ativities.getIt();
   
	// Verifica se ja ha atividades na lista
	//se nao existirem avisa o utilizador
	if (Activities.empty()) {
		cout << "Nao existem atividades imersivas!" << endl;
		return;
	}

	//recorremos ao metodo interno para ordenar a lista para o modo desejado
	//verifique o metodo para saber todos os modos
	ativities.sortActivities(mode);

	//obtemos os tamanhos ideais para apresentar a tabela (desnecessario, so' para embelezar)
	int* max;
	max = ativities.getLengthForTable();

	//Apresenta-se o cabecalho com recurso ao iomanip para ajustar a apresentacao com tamanhos de colunas
	cout << endl << "##################  LISTA DE ATIVIDADES ###################" << endl << endl;
	cout << left << setw(5) << setfill(' ') << "ID";
	cout << left << setw(max[0]+1) << setfill(' ') << "Titulo";
    cout << left << setw(max[1]+1) << setfill(' ') << "Descricao";
    cout << left << setw(max[2]+1) << setfill(' ') << "URL";
	cout << left << setw(11) << setfill(' ') << "Sistema";
	cout << left << setw(11) << setfill(' ') << "Narrativa";
	cout << left << setw(11) << setfill(' ') << "Agencia" << endl;

	//iteramos pelas atividades da lista e escrevemos as linhas com os dados pela ordem correta que foi selecionada.
	for (it = Activities.begin(); it != Activities.end(); it++) {

	   	cout << left << setw(5) << setfill(' ') << it->getId();
		cout << left << setw(max[0]+1) << setfill(' ') << it->getTitle();
		cout << left << setw(max[1]+1) << setfill(' ') << it->getDescription();
		cout << left << setw(max[2]+1) << setfill(' ') << it->getUrl();
		cout << left << setw(11) << setfill(' ') << it->getSystem();
		cout << left << setw(11) << setfill(' ') << it->getNarrative();
		cout << left << setw(11) << setfill(' ') << it->getAgency() << endl;
	}
}


//metodo de recolha de atividades para serem combinadas
//este metodo recolhe o input do utilizador de quais as atividades a combinar
//e depois o metodo da lista procede a combinacao
void UserInterface::combineActivities(ActivityList& ativities){
    
    //obtemos a quantidade de atividades existentes
    //recolhendo um possivel proximo ID como nao eliminamos atividades podemos fazer isto
    int listSize = ativities.getNewId()-1; 
    
    //se nao existirem atividades suficientes a combinar
    //o utilizador nao podera continuar e apresentamos a mensagem
    if(listSize < 2){
        cout << endl << "Sem atividades suficientes para combinar!" << endl;
        return;
    }

    //existindo suficientes, mostramos a lista de atividades ao utilizador
    //para que este possa escolher os ID a combinar
    showActivities(ativities, 7);

    //instanciamos dois ID com -1 representando 'valor inexistente'
    int id1=-1; 
    int id2=-1;

    //realizamos um loop para obter o primeiro id
    //enquanto o utilizador nao selecionar um id valido
    //sera sempre solicitado
	do{
		cout << endl << "Selecione o ID da primeira atividade que deseja combinar: ";
		cin >> id1;

        if(id1<1 || id1>listSize){
            cout << "Esse ID nao existe. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

	}while(id1<1 || id1>listSize);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //realizamos um loop para obter o segundo id
    //enquanto o utilizador nao selecionar um id valido
    //sera sempre solicitado
    do{
		cout << "Selecione o ID da segunda atividade que deseja combinar: ";
		cin >> id2;

        if(id2<1 || id2>listSize){
            cout << "Esse ID nao existe. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

	}while(id2<1 || id2>listSize);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //com recurso ao metodo que auxilia a combinacao e duas atividades da lista de atividades
    //procedemos 'a sua combinacao, usamos um try para evitar possiveis erros
    try{ 
        ativities.combineActivities(id1, id2);

    }catch(bool e){
        cout << "A Atividade selecionada nao pode ser encontrada.";
        return;
    }

    //apresentamos a mensagem de exito da combinacao
    cout << endl << "Atividades combinadas. A nova atividade foi adicionada ao final da lista. Veja a lista:" << endl;

    //e apresentamos a lista com a nova atividade
    //para que o utilizador possa verificar
    showActivities(ativities, 7);


}
