#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

void alterarComida(){
	Item x;
	FILE *fp;
	int codigo;
	
	if((fp=fopen("comida.bin", "r+b"))!=NULL){
	
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      ALTERAR COMIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código da comida a ser alterado:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo == x.cod && x.removido == 0){
				puts(ANSI_COLOR_GREEN "\n\tDados atuais:");
				printf("\t\tCódigo: %i\n", x.cod);
				printf("\t\tNome: %s\n", x.nome);
				printf("\t\tDescrição: %s\n", x.descricao);
				printf("\t\tPreço: %.2f\n", x.preco);
				printf("\t\tTipo: Comida\n\n" ANSI_COLOR_RESET);
				
				fseek(fp, -(long) sizeof(Item), SEEK_CUR);
				puts("Alteração dos dados atuais:");	
				leValidaDescricao(x.descricao);
				x.preco = leValidaPreco(x.preco);
				
				fwrite(&x, sizeof(Item), 1, fp);
				fseek(fp, sizeof(Item)*0, SEEK_END);
				puts("\nDADO ALTERADO COM SUCESSO!");
			}
		}
		
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
	}else{
		puts("\nArquivo não localizado.");
	}
}

void alterarBebida(){
	Item x;
	FILE *fp;
	int codigo;
	
	if((fp=fopen("bebida.bin", "r+b"))!=NULL){
	
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      ALTERAR BEBIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código da bebida a ser alterado:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo == x.cod && x.removido == 0){
				puts(ANSI_COLOR_YELLOW "\n\tDados atuais:");
				printf("\t\tCódigo: %i\n", x.cod);
				printf("\t\tNome: %s\n", x.nome);
				printf("\t\tDescrição: %s\n", x.descricao);
				printf("\t\tPreço: %.2f\n", x.preco);
				printf("\t\tTipo: Bebida\n\n" ANSI_COLOR_RESET);
				
				fseek(fp, -(long) sizeof(Item), SEEK_CUR);
				puts("Alteração dos dados atuais:");	
				leValidaDescricao(x.descricao);
				x.preco = leValidaPreco(x.preco);
				
				fwrite(&x, sizeof(Item), 1, fp);
				fseek(fp, sizeof(Item)*0, SEEK_END);
				puts("\nDADO ALTERADO COM SUCESSO!");
			}
		}
		
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
	}else{
		puts("\nArquivo não localizado.");
	}
}

void alterarVinho(){
	Item x;
	FILE *fp;
	int codigo;
	
	if((fp=fopen("vinho.bin", "r+b"))!=NULL){
	
		system("cls");
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      ALTERAR VINHOS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código do vinho a ser alterado:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo == x.cod && x.removido == 0){
				puts(ANSI_COLOR_RED "\n\tDados atuais:");
				printf("\t\tCódigo: %i\n", x.cod);
				printf("\t\tNome: %s\n", x.nome);
				printf("\t\tDescrição: %s\n", x.descricao);
				printf("\t\tPreço: %.2f\n", x.preco);
				printf("\t\tTipo: Vinho\n\n" ANSI_COLOR_RESET);
				
				fseek(fp, -(long) sizeof(Item), SEEK_CUR);
				puts("Alteração dos dados atuais:");	
				leValidaDescricao(x.descricao);
				x.preco = leValidaPreco(x.preco);
				
				fwrite(&x, sizeof(Item), 1, fp);
				fseek(fp, sizeof(Item)*0, SEEK_END);
				puts("\nDADO ALTERADO COM SUCESSO!");
			}
		}
		
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
	}else{
		puts("\nArquivo não localizado.");
	}
}
