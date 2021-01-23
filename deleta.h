void removerComida(){
	Item x;
	FILE *fp, *fpTmp;
	int codigo;
	
	fpTmp = fopen("comidaTmp.bin", "wb");
	
	if((fp=fopen("comida.bin", "rb"))!=NULL){
		
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      REMOVER COMIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código da comida a ser removido:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo != x.cod){		
				fwrite(&x, sizeof(Item), 1, fpTmp);
			}else{
				puts("\nCOMIDA REMOVIDA COM SUCESSO!");
			}
		}
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
		fclose(fpTmp);
	}
	
	fp = fopen("comida.bin", "wb");
	
	if((fpTmp=fopen("comidaTmp.bin", "rb"))!=NULL){
		while(fread(&x, sizeof(Item), 1, fpTmp) == 1){
			fwrite(&x, sizeof(Item), 1, fp);	
		}	
		
		fclose(fp);
		fclose(fpTmp);
	}
}

void removerBebida(){
	Item x;
	FILE *fp, *fpTmp;
	int codigo;
	
	fpTmp = fopen("bebidaTmp.bin", "wb");
	
	if((fp=fopen("bebida.bin", "rb"))!=NULL){
		
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      REMOVER BEBIDAS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código da bebida a ser removido:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo != x.cod){		
				fwrite(&x, sizeof(Item), 1, fpTmp);
			}else{
				puts("\nBEBIDA REMOVIDA COM SUCESSO!");
			}
		}
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
		fclose(fpTmp);
	}
	
	fp = fopen("bebida.bin", "wb");
	
	if((fpTmp=fopen("bebidaTmp.bin", "rb"))!=NULL){
		while(fread(&x, sizeof(Item), 1, fpTmp) == 1){
			fwrite(&x, sizeof(Item), 1, fp);	
		}	
		
		fclose(fp);
		fclose(fpTmp);
	}
}

void removerVinho(){
	Item x;
	FILE *fp, *fpTmp;
	int codigo;
	
	fpTmp = fopen("vinhoTmp.bin", "wb");
	
	if((fp=fopen("vinho.bin", "rb"))!=NULL){
		
		system("cls");
		
		printf(" //////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		printf("                      REMOVER VINHOS   \n");
		printf("\n");
		printf(" //////////////////////////////////////////////////////////////////////\n\n");
		
		puts("Informe o código do vinho a ser removido:");
		scanf("%i", &codigo);
		
		while(fread(&x, sizeof(Item), 1, fp) == 1){
			if(codigo != x.cod){		
				fwrite(&x, sizeof(Item), 1, fpTmp);
			}else{
				puts("\nVINHO REMOVIDA COM SUCESSO!");
			}
		}
		if(codigo != x.cod){
			puts("\nCódigo não encontrado na base de dados.");
		}
		fclose(fp);
		fclose(fpTmp);
	}
	
	fp = fopen("vinho.bin", "wb");
	
	if((fpTmp=fopen("vinhoTmp.bin", "rb"))!=NULL){
		while(fread(&x, sizeof(Item), 1, fpTmp) == 1){
			fwrite(&x, sizeof(Item), 1, fp);	
		}	
		
		fclose(fp);
		fclose(fpTmp);
	}
}
