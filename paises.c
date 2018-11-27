#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Paises{
	char nomePaises[64];
};

struct Paises paises;


void validaPaises(struct Paises paises, FILE *arq);
void achaPaises(struct Paises paises, FILE *arq);

int main() {
FILE *arq;
validaPaises(paises, arq);
achaPaises(paises, arq);
}

void validaPaises(struct Paises paises, FILE *arq){
int resp; 
	arq=fopen ("paises.txt","a");
	if (arq== NULL){
		printf ("Erro na abertura..");
		exit (1);
	}	
	do{
		printf("digite o nome dos paises: ");
		fflush(stdin);
		fgets(paises.nomePaises,64,stdin);
		fwrite (&paises,sizeof(paises),1,arq);
		printf("continuar?");
		scanf("%d", &resp);
	}while(resp != 0);

	
	fclose(arq);
}


void achaPaises(struct Paises paises, FILE *arq){
char paisesB[64];
int flag = 0;
	arq = fopen ("paises.txt", "r");
	if (arq== NULL){
		printf ("Erro na abertura..");
		exit (1);
	}
	printf("digite o nome do pais:");
	fflush(stdin);
	fgets(paisesB,64,stdin);
	do{
			
		while (fread(&paises,sizeof(paises),1,arq)){
			if(stricmp(paises.nomePaises,paisesB == 0)){
				printf("pais valido");
				printf("\n %s", paises.nomePaises);
				system("pause");
				flag++;
			}
		}
		if(flag == 0){
			printf("pais invalido, digite novamente: ");
			fflush(stdin);
			fgets(paisesB,64,stdin);
		}
	}while(flag == 0);
fclose(arq);
}
