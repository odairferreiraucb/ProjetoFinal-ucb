#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Paises{
	char nomePaises[64];
};

struct Paises paises;


void validaPaises(struct Paises paises, FILE *arqPais);
void achaPaises(struct Paises paises, FILE *arqPais);

int main() {
FILE *arqPais;
validaPaises(paises, arqPais);
achaPaises(paises, arqPais);
}

void validaPaises(struct Paises paises, FILE *arqPais){
int resp; 
	arqPais=fopen ("paises.txt","a");
	if (arqPais== NULL){
		printf ("Erro na abertura..");
		exit (1);
	}	
	do{
		printf("digite o nome dos paises: ");
		fflush(stdin);
		fgets(paises.nomePaises,64,stdin);
		fwrite (&paises,sizeof(paises),1,arqPais);
		printf("continuar?");
		scanf("%d", &resp);
	}while(resp != 0);

	
	fclose(arqPais);
}


void achaPaises(struct Paises paises, FILE *arqPais){
char paisesB[64];
int flag = 0;
	arqPais = fopen ("paises.txt", "r");
	if (arqPais== NULL){
		printf ("Erro na abertura..");
		exit (1);
	}
	printf("digite o nome do pais:");
	fflush(stdin);
	fgets(paisesB,64,stdin);
	do{
		rewind(arqPais);	
		while (fread(&paises,sizeof(paises),1,arqPais)){
			if(stricmp(paises.nomePaises,paisesB) == 0){
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
fclose(arqPais);
}
