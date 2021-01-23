#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define MAX 100

int buscaComida(){
	int id, flag = 0;
	Item x;
	FILE *fp;
	
	fp = fopen("comida.bin", "rb");
	
	if(fp == NULL){
		puts("\nArquivo não foi encontrado.\n");
		return ;
	} 
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      BUSCAR COMIDAS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	printf("\nInforme o código da comida que deseja buscar:\n");
	scanf("%i", &id);
	
	while(fread(&x, sizeof(x), 1, fp)){
		if(id == x.cod){
			printf(ANSI_COLOR_GREEN "\n\tCódigo: %i\n", x.cod);
			printf("\tNome: %s\n", x.nome);
			printf("\tDescrição: %s\n", x.descricao);
			printf("\tPreço: %.2f\n", x.preco);
			printf("\tTipo: Comida\n\n" ANSI_COLOR_RESET);
			
			flag = 1;
		}
	}
	
	if(!flag)
		puts("\nComida não foi encontrada.\n");
	
	fclose(fp);
}

int buscaBebida(){
	int id, flag = 0;
	Item x;
	FILE *fp;
	
	fp = fopen("bebida.bin", "rb");
	
	if(fp == NULL){
		puts("\nArquivo não foi encontrado.\n");
		return ;
	} 
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      BUSCAR BEBIDAS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	printf("\nInforme o código da bebida que deseja buscar:\n");
	scanf("%i", &id);
	
	while(fread(&x, sizeof(x), 1, fp)){
		if(id == x.cod){
			printf(ANSI_COLOR_YELLOW "\n\tCódigo: %i\n", x.cod);
			printf("\tNome: %s\n", x.nome);
			printf("\tDescrição: %s\n", x.descricao);
			printf("\tPreço: %.2f\n", x.preco);
			printf("\tTipo: Bebida\n\n" ANSI_COLOR_RESET);
			
			flag = 1;
		}
	}
	
	if(!flag)
		puts("\nBebida não foi encontrada.\n");
	
	fclose(fp);
}

int buscaVinho(){
	int id, flag = 0;
	Item x;
	FILE *fp;
	
	fp = fopen("vinho.bin", "rb");
	
	if(fp == NULL){
		puts("\nArquivo não foi encontrado.\n");
		return ;
	} 
	
	system("cls");
	
	printf(" //////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("                      BUSCAR VINHOS   \n");
	printf("\n");
	printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
	printf("\nInforme o código do vinho que deseja buscar:\n");
	scanf("%i", &id);
	
	while(fread(&x, sizeof(x), 1, fp)){
		if(id == x.cod){
			printf(ANSI_COLOR_RED "\n\tCódigo: %i\n", x.cod);
			printf("\tNome: %s\n", x.nome);
			printf("\tDescrição: %s\n", x.descricao);
			printf("\tPreço: %.2f\n", x.preco);
			printf("\tTipo: Vinho\n\n" ANSI_COLOR_RESET);
			
			flag = 1;
		}
	}
	
	if(!flag)
		puts("\nVinho não foi encontrado.\n");
	
	fclose(fp);
}
