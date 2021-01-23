#include "leitura.h"
#define MAX 100

int contarComidas(){
	FILE *fp;
	Item xx;
	Item x[MAX];
	int ind = 0;
	
	if(xx.tipo == 1){ //Aqui essa consicional, deu bom
		fp = fopen("comida.bin", "rb");
	
		if(fp != NULL){
			while(1){
				Item xi;
				size_t r = fread(&xi, sizeof(Item), 1, fp);
					
				if(r < 1){
					break;
				}else{
					x[ind++] = xi;
				}
			}
			fclose(fp);
			return ind;
		}else{
			printf("\nArquivo vazio, por favor, cadastre uma comida\n");
		}	
	}
}

int contarBebidas(){
	FILE *fp;
	Item xx;
	Item y[MAX];
	int ind = 0;
	
	//if(xx.tipo == 2){ Deu ruim essa condicional
		fp = fopen("bebida.bin", "rb");
	
		if(fp != NULL){
			while(1){
				Item yi;
				size_t o = fread(&yi, sizeof(Item), 1, fp);
					
				if(o < 1){
					break;
				}else{
					y[ind++] = yi;
				}
			}
			fclose(fp);
			return ind;
		}else{
			printf("\nArquivo vazio, por favor, cadastre uma bebida\n");
		}	
	//}
}

int contarVinhos(){
	FILE *fp;
	Item xx;
	Item z[MAX];
	int ind = 0;
	
	//if(xx.tipo == 3){ Deu ruim essa condicional
		fp = fopen("vinho.bin", "rb");
	
		if(fp != NULL){
			while(1){
				Item zi;
				size_t p = fread(&zi, sizeof(Item), 1, fp);
					
				if(p < 1){
					break;
				}else{
					z[ind++] = zi;
				}
			}
			fclose(fp);
			return ind;
		}else{
			printf("\nArquivo vazio, por favor, cadastre um vinho\n");
		}	
	//}
}

void ordenarShellComidas(){
	int tamVetor = contarComidas();
	Item *temp;
	Item *xc[tamVetor];
	FILE *fp;
	int k = 0;
	int h = 1;
	int i, j;
	
	fp = fopen("comida.bin", "rb");
	
	for(k = 0; k < tamVetor; k++){
		xc[k] = malloc(sizeof(Item));
		fread(xc[k], sizeof(Item), 1, fp);
	}
	
	if(tamVetor == 0){
		return ;
	}
	fclose(fp);
	
	temp = malloc(sizeof(Item));
	
	while(h < tamVetor){
		h = 3*h+1;
	}
	
	while(h > 1){
		h = h/3;
		
		for(i = h; i < tamVetor; i++){
			temp = xc[i];
			j = i;
			
			while(j >= h && temp->cod < xc[j - h]->cod){
				xc[j] = xc[j - h];
				j = j - h;
			}
			xc[j] = temp;
		}
	}
	lerComida(xc, tamVetor);	
}

void ordenarShellBebidas(){
	int tamVetorB = contarBebidas();
	Item *tempB;
	Item *xd[tamVetorB];
	FILE *fp;
	int kq = 0;
	int hq = 1;
	int iq, jq;
	
	fp = fopen("bebida.bin", "rb");
	
	for(kq = 0; kq < tamVetorB; kq++){
		xd[kq] = malloc(sizeof(Item));
		fread(xd[kq], sizeof(Item), 1, fp);
	}
	
	if(tamVetorB == 0){
		return ;
	}
	fclose(fp);
	
	tempB = malloc(sizeof(Item));
	
	while(hq < tamVetorB){
		hq = 3*hq+1;
	}
	
	while(hq > 1){
		hq = hq/3;
		
		for(iq = hq; iq < tamVetorB; iq++){
			tempB = xd[iq];
			jq = iq;
			
			while(jq >= hq && tempB->cod < xd[jq - hq]->cod){
				xd[jq] = xd[jq - hq];
				jq = jq - hq;
			}
			xd[jq] = tempB;
		}
	}
	lerBebidas(xd, tamVetorB);		
}

void ordenarShellVinhos(){
	int tamVetorC = contarVinhos();
	Item *tempC;
	Item *xf[tamVetorC];
	FILE *fp;
	int kr = 0;
	int hr = 1;
	int ir, jr;
	
	fp = fopen("vinho.bin", "rb");
	
	for(kr = 0; kr < tamVetorC; kr++){
		xf[kr] = malloc(sizeof(Item));
		fread(xf[kr], sizeof(Item), 1, fp);
	}
	
	if(tamVetorC == 0){
		return ;
	}
	fclose(fp);
	
	tempC = malloc(sizeof(Item));
	
	while(hr < tamVetorC){
		hr = 3*hr+1;
	}
	
	while(hr > 1){
		hr = hr/3;
		
		for(ir = hr; ir < tamVetorC; ir++){
			tempC = xf[ir];
			jr = ir;
			
			while(jr >= hr && tempC->cod < xf[jr - hr]->cod){
				xf[jr] = xf[jr - hr];
				jr = jr - hr;
			}
			xf[jr] = tempC;
		}
	}
	lerVinhos(xf, tamVetorC);	
}






