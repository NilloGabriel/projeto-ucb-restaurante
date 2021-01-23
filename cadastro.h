#include <string.h>

int leValidaCodigo();
void leValidaNome(char *nm);
void leValidaDescricao(char *desc);
float leValidaPreco();
int leValidaTipo();


Item cadastrar(){
	Item x;
	Item y;
	int flag;
	
	system("cls");
	
	if(x.tipo == 1){
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CADASTRAR COMIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
		x.cod = leValidaCodigo(x.cod);
		leValidaNome(x.nome);
		leValidaDescricao(x.descricao);
		x.preco = leValidaPreco(x.preco);
		x.tipo = leValidaTipo(x.tipo);
		x.removido = 0;
		
		return x;
	}
	
	if(x.tipo == 2){
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CADASTRAR BEBIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
		x.cod = leValidaCodigo(x.cod);
		leValidaNome(x.nome);
		leValidaDescricao(x.descricao);
		x.preco = leValidaPreco(x.preco);
		x.tipo = leValidaTipo(x.tipo);
		x.removido = 0;
		
		return x;
	}
	
	if(x.tipo == 3){
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      CADASTRAR VINHOS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
	
		x.cod = leValidaCodigo(x.cod);
		leValidaNome(x.nome);
		leValidaDescricao(x.descricao);
		x.preco = leValidaPreco(x.preco);
		x.tipo = leValidaTipo(x.tipo);
		x.removido = 0;
		
		return x;
	}
}

int leValidaCodigo(){
	FILE *fp;
	Item x;
	Item y;
	int c, flag;
	
	do{
		flag=0;
		
		puts("Informe o código do item:");
		scanf("%i", &c);
		
		if(c <= 0){
			puts("\nCódigo Inválido.\n");
			flag=1;
		}else{
			if((fp=fopen("comida.bin", "rb"))!=NULL){
				while(fread(&x, sizeof(Item), 1, fp) == 1){
					if(x.tipo == 1){
						if(c == x.cod){
							flag = 1;
							puts("\nCódigo já existe na base de dados.\n");
							fclose(fp);
							break;
						}
					}
				}
				fclose(fp);
			}
			
			if((fp=fopen("bebida.bin", "rb"))!=NULL){
				while(fread(&x, sizeof(Item), 1, fp) == 1){
					if(x.tipo == 2){
						if(c == x.cod){
							flag = 1;
							puts("\nCódigo já existe na base de dados.\n");
							fclose(fp);
							break;
						}
					}
				}
				fclose(fp);
			}	
			
			if((fp=fopen("vinho.bin", "rb"))!=NULL){
				while(fread(&x, sizeof(Item), 1, fp) == 1){
					if(x.tipo == 3){
						if(c == x.cod){
							flag = 1;
							puts("\nCódigo já existe na base de dados.\n");
							fclose(fp);
							break;
						}
					}
				}
				fclose(fp);
			}	
		}
	}while(flag==1);

	return c;
}


void leValidaNome(char *nm){
    do{
		puts("\nInforme o nome do item:");
		fflush(stdin);
		gets(nm);
		
		if(strcmp(nm, "") == 0){
			puts("Informe um nome não vazio.");
		}
	}while(strcmp(nm, "") == 0);
}

void leValidaDescricao(char *desc){
    do{
		puts("\nInforme a descrição do item:");
		fflush(stdin);
		gets(desc);
		
		if(strcmp(desc, "") == 0){
			puts("Informe uma descrição não vazia.");
		}
	}while(strcmp(desc, "") == 0);
}

float leValidaPreco(){	
	float prec;

    do{
		puts("\nInforme o preço do item:");
		scanf("%f", &prec);
		fflush(stdin);
		
		if(prec < 0){
			printf("\nPreço não pode ser menor que 0.\n");
		}
	}while(prec < 0);
	
	return prec;
}

int leValidaTipo(){
    int flag;
	int t;

    do{
		flag=0;
		printf("\n\tESCOLHA O TIPO DO ITEM:\n");
		printf("\t __________________________________________\n");
		printf("\t|   OPÇÃO    |           FUNÇÕES           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     1      |           COMIDAS           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     2      |           BEBIDAS           |\n");
		printf("\t|------------|-----------------------------|\n");
		printf("\t|     3      |           VINHOS            |\n");
		printf("\t|____________|_____________________________|\n");
		scanf("%i", &t);
		
		switch(t){
			case 1:
				return 1;
				break;
			case 2:
				return 2;
			    break;
			case 3:
				return 3;
				break;
			default:
				puts("Opção Inválida.");
				flag=1;
		}
	}while(flag==1);
}

void armazenarComida(Item x){
	FILE *fp;
	if((fp=fopen("comida.bin", "ab"))!=NULL){
		if(x.tipo==1){
			fwrite(&x, sizeof(Item), 1, fp);
			fclose(fp);
		}else{
			puts("\nVocê está tentando cadastrar o item na área errada.\n");
		}	
	}else{
		puts("\nArquivo não localizado.");
	}
}


void armazenarBebidas(Item x){
	FILE *fp;
	if((fp=fopen("bebida.bin", "ab"))!=NULL){
		if(x.tipo==2){
			fwrite(&x, sizeof(Item), 1, fp);
			fclose(fp);
		}else{
			puts("\nVocê está tentando cadastrar o item na área errada.\n");
		}	
	}else{
		puts("\nArquivo não localizado.");
	}	
}

void armazenarVinhos(Item x){
	FILE *fp;
	if((fp=fopen("vinho.bin", "ab"))!=NULL){
		if(x.tipo==3){
			fwrite(&x, sizeof(Item), 1, fp);
			fclose(fp);
		}else{
			puts("\nVocê está tentando cadastrar o item na área errada.\n");
		}	
	}else{
		puts("\nArquivo não localizado.");
	}	
}

