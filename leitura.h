#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

void lerComida(Item *vetx[],int n){
	int i = 0;
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      LISTAR COMIDAS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	for(i = 0; i < n; i++){
		printf(ANSI_COLOR_GREEN "\tC�digo: %i\n", vetx[i]->cod);
		printf("\tNome: %s\n", vetx[i]->nome);
		printf("\tDescri��o: %s\n", vetx[i]->descricao);
		printf("\tPre�o: %.2f\n", vetx[i]->preco);
		printf("\tTipo: Comida\n\n"ANSI_COLOR_RESET);
	}
}

void lerBebidas(Item *vetxd[],int m){
	int j = 0;
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      LISTAR BEBIDAS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	for(j = 0; j < m; j++){
		printf(ANSI_COLOR_YELLOW "\tC�digo: %i\n", vetxd[j]->cod);
		printf("\tNome: %s\n", vetxd[j]->nome);
		printf("\tDescri��o: %s\n", vetxd[j]->descricao);
		printf("\tPre�o: %.2f\n", vetxd[j]->preco);
		printf("\tTipo: Bebida\n\n" ANSI_COLOR_RESET);
	}
}

void lerVinhos(Item *vetxv[],int s){
	int v = 0;
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      LISTAR VINHOS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	for(v = 0; v < s; v++){
		printf(ANSI_COLOR_RED "\tC�digo: %i\n", vetxv[v]->cod);
		printf("\tNome: %s\n", vetxv[v]->nome);
		printf("\tDescri��o: %s\n", vetxv[v]->descricao);
		printf("\tPre�o: %.2f\n", vetxv[v]->preco);
		printf("\tTipo: Vinho\n\n" ANSI_COLOR_RESET);
	}
}


