#include "cadastro.h"
#include "ordenacao.h"
#include "busca.h"
#include "alteracao.h"
#include "deleta.h"

void mainMenu();
void leValidaLogin(char texto1[], char texto2[]);
void menuAdministrativo();
void menuComidas();
void menuBebidas();
void menuVinhos();
void menuCliente();

void mainMenu(){
	int op;
	
	do{
		printf("\n");
		printf("\t ___________________________________________\n");
		printf("\t|  _______________________________________  |\n");
		printf("\t| |                                       | |\n");
		printf("\t| |                                       | |\n");
		printf("\t| |                                       | |\n");
		printf("\t| |              CARDÁPIO DO              | |\n");
		printf("\t| |                                       | |\n");
		printf("\t| |         RESTAURANTE RODRIGUES         | |\n");
		printf("\t| |                                       | |\n");
	    printf("\t| |                                       | |\n");
	    printf("\t| |            GABRIEL D'NILLO            | |\n");
	    printf("\t| |                                       | |\n");
	    printf("\t| |                                       | |\n");
	    printf("\t| |_______________________________________| |\n");
	    printf("\t|___________________________________________|\n");
	    printf("\n");
	    
	    printf("\n\tESCOLHA A ÁREA QUE DESEJA ENTRAR:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |         FUNCIONÁRIO         |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |           CLIENTE           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |       SAIR DO PROGRAMA      |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &op);
		        
		switch(op){
		    case 1:
		       	login();
		        break;
		    case 2:
		    	menuCliente();
		        break;
		    case 3:
		        exit(1);
		        break;
		    default:
		        puts("Opção Inválida.");
		}
	    
	    system("pause");
		system("cls");
	}while(1);
}

int login(){
	char usuario[25];
	char senha[25];
	
	do{
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      AREA DOS FUNCIONÁRIOS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
		leValidaLogin(usuario, "Usuário");
		printf("\n");
		leValidaLogin(senha, "Senha");
		
		if((strcmp(usuario, "admin") != 0) || (strcmp(senha, "admin") != 0)){
			puts("\nUsuário ou senha incorreto.");
			system("pause");
		}
		
		system("cls");
	}while((strcmp(usuario, "admin")!=0)||(strcmp(senha, "admin")!=0));
	
	do{
		
		menuAdministrativo();
		
		system("pause");
		system("cls");
	}while(1);
	
	return 1;
}

void leValidaLogin(char texto1[], char texto2[]){
	do{
		printf("%s:\n", texto2);
		fflush(stdin);
		gets(texto1);
		if(strcmp(texto1,"")==0){
			printf("%s obrigatório\n\n", texto2);
		}
	}while(strcmp(texto1,"")==0);
}

void menuAdministrativo(){
	int op;
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      AREA ADMINISTRATIVA   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	
	printf("\n\tESCOLHA O CARDÁPIO NO QUAL QUEIRA TRABALHAR:\n");
	printf("\t __________________________________________\n");
	printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
	printf("\t|------------|-----------------------------|\n");
	printf("\t|     1      |           COMIDAS           |\n");
	printf("\t|------------|-----------------------------|\n");
	printf("\t|     2      |           BEBIDAS           |\n");
	printf("\t|------------|-----------------------------|\n");
	printf("\t|     3      |           VINHOS            |\n");
	printf("\t|------------|-----------------------------|\n");
	printf("\t|     4      |        MENU PRINCIPAL       |\n");
	printf("\t|------------|-----------------------------|\n");
	printf("\t|     5      |       SAIR DO PROGRAMA      |\n");
	printf("\t|____________|_____________________________|\n");
	scanf("%i", &op);
		
	switch(op){
		case 1:
			menuComidas();
			break;
		case 2:
			menuBebidas();
		    break;
		case 3:
			menuVinhos();
			   break;
		case 4:
			system("cls");
			mainMenu();
			break;
		case 5:
			exit(1);
			break;
		default:
			puts("Opção Inválida.");
	}

}

void menuComidas(){
	int op;
	
	do{
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CARDÁPIO DE COMIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		printf("\n\tESCOLHA:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |      CADASTRAR COMIDAS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |       LISTAR COMIDAS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |       EDITAR COMIDAS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     4      |       DELETAR COMIDAS       |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     5      |      PESQUISAR COMIDAS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     6      |      MENU ADMINISTRATIVO    |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     7      |       SAIR DO PROGRAMA      |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				armazenarComida(cadastrar());
				break;
			case 2:
				ordenarShellComidas();
			    break;
			case 3:
				alterarComida();
				break;
			case 4:
				removerComida();
				break;
			case 5:
				buscaComida();
				break;
			case 6:
				menuAdministrativo();
				break;
			case 7:
				exit(1);
				break;
			default:
				puts("Opção Inválida.");
		}
		
		system("pause");
		system("cls");
	}while(1);
}

void menuBebidas(){
	int op;
	
	do{
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CARDÁPIO DE BEBIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		printf("\n\tESCOLHA:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |      CADASTRAR BEBIDAS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |       LISTAR BEBIDAS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |       EDITAR BEBIDAS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     4      |       DELETAR BEBIDAS       |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     5      |      PESQUISAR BEBIDAS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     6      |      MENU ADMINISTRATIVO    |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     7      |       SAIR DO PROGRAMA      |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				armazenarBebidas(cadastrar());
				break;
			case 2:
				ordenarShellBebidas();
			    break;
			case 3:
				alterarBebida();
				break;
			case 4:
				removerBebida();
				break;
			case 5:
				buscaBebida();
				break;
			case 6:
				menuAdministrativo();
				break;
			case 7:
				exit(1);
				break;
			default:
				puts("Opção Inválida.");
		}
		
		system("pause");
		system("cls");
	}while(1);
}

void menuVinhos(){
	int op;
	
	do{
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CARDÁPIO DE VINHOS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		printf("\n\tESCOLHA:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |       CADASTRAR VINHOS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |        LISTAR VINHOS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |        EDITAR VINHOS        |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     4      |        DELETAR VINHOS       |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     5      |       PESQUISAR VINHOS      |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     6      |      MENU ADMINISTRATIVO    |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     7      |       SAIR DO PROGRAMA      |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				armazenarVinhos(cadastrar());
				break;
			case 2:
				ordenarShellVinhos();
			    break;
			case 3:
				alterarVinho();
				break;
			case 4:
				removerVinho();
				break;
			case 5:
				buscaVinho();
				break;
			case 6:
				menuAdministrativo();
				break;
			case 7:
				exit(1);
				break;
			default:
				puts("Opção Inválida.");
		}
		
		system("pause");
		system("cls");
	}while(1);
}

void menuCliente(){
	int op;
	
	system("cls");
		
	do{
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CARDÁPIO RESTAURANTE RODRIGUES   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		printf("\n\tESCOLHA O CARDÁPIO NO QUAL QUEIRA CONFERIR:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |           COMIDAS           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |           BEBIDAS           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |           VINHOS            |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     4      |        MENU PRINCIPAL       |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     5      |       SAIR DO PROGRAMA      |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				ordenarShellComidas();
				break;
			case 2:
				ordenarShellBebidas();
			    break;
			case 3:
				ordenarShellVinhos();
				break;
			case 4:
				system("cls");
				mainMenu();
				break;
			case 5:
				exit(1);
				break;
			default:
				puts("Opção Inválida.");
		}
		
		system("pause");
		system("cls");
	}while(1);
}


