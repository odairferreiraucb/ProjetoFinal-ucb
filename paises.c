//https://stackoverflow.com/questions/3028642/regular-expression-for-letters-numbers-and
//https://regex101.com/
/*
CORES - TEXTCOLOR e TEXTBACKGROUND:
Preto....... BLACK..... 0
Azul........ BLUE...... 1
Verde....... GREEN..... 2
Cian........ CYAN...... 3
Vermelho.... RED....... 4
Magenta..... MAGENTA... 5
Marrom...... BROWN..... 6
Cinza Claro. LIGHTGRAY. 7

CORES - TEXTCOLOR:
Cinza Escuro... DARKGRAY..... 8
Azul Claro..... LIGHTBLUE.... 9
Verde Claro.... LIGHTGREEN... 10
Cian Claro..... LIGHTCYAN.... 11
Vermelho Claro. LIGHTRED..... 12
Magenta Claro.. LIGHTMAGENTA. 13
Amarelo........ YELLOW....... 14
Branco......... WHITE........ 15
*/
#include "conio2.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define MAX 5


//structs
struct Aviao {
	    int idTeste;
		char codigo[7];
		int capacidade;
		char nomeCliente[64];
		char paisOrigCliente[32];
		char modelo[10];
		int idExclusao;
	};
	
struct PistaTeste {
	int codSequencial;
	char enderecoPista[128];
	char uf[2];
	float tamanhoCircuito;
	int velocidadeMax;
	char codigoMelhorAviao[7];
};

struct Testes {
	int idPista;
	char idAviao[7];
	int idTeste;
	char data[1000];
	int velocidadeMax;
	int idExclusao;
};

// declarando as structs
struct Aviao aviao;
struct PistaTeste pistaTeste;
struct Testes testes;

//prototipos das funções
//principal
int mostrarMenuPrimcipal();
//avião 
int mostraMenuAviao ();
int inclusaoAviao(struct Aviao aviao, int cont,FILE *arq);
int alteracaoAviao(struct Aviao aviao,FILE *arq);
int mostrarAlteracaoAviao();
void exclusaoAviao(struct Aviao aviao, struct Testes testes,FILE *arq,FILE *arq1,FILE *arqT);
//pista
int mostraMenuPista ();
int inclusaoPista (struct PistaTeste pistaTeste ,int codigoSequencial, int *pcont,FILE *arqP);
int alteraPista (struct PistaTeste pistaTeste, FILE *arqP );
void exclusaoTeste(struct Testes testes,FILE *arqT,FILE * arqT1);
//teste
int inclusaoTeste(struct Testes testes,FILE *arqT,FILE *arq,FILE *arqP,struct PistaTeste pistaTeste,struct Aviao aviao,int idTeste);
int alterarTeste(struct Testes testes,FILE *arqT);
int mostrarMenuAlterar ();
//consulta
int mostraMenuConsulta ();
void mostrarConsultaAviao (struct Aviao aviao,char cod[],FILE *arq);
void mostrarConsultaPista (struct PistaTeste pistaTeste,int codigoS ,FILE *arqP);

struct Aviao validaCodigo(struct Aviao aviao,FILE *arq);
int mostrarMenuAlterarPista ();
// RELATORIOS 
int mostrarRelatorioTeste ();
int menuRelatorio ();
int mostrarRelatorioAviao ();
int mostrarRelatorioPista();
int relatorioR2 (struct Aviao aviao,FILE *arq);
int relatorioR3 (struct Testes testes,FILE *arqT,struct PistaTeste pistaTeste,FILE *arqP);
// "CONT" É PARA A STRUCT DE AVIAO, CONT2 PARA PISTAS
int main(void) {
int resp,continuar,cont = 0, cont2 =0,codigoS;
int codigoSequencial;
char tecla,codigo[7];
int i, opcao,idTeste;
char agora[1000],data[100];
FILE *arq;
FILE *arq1;
FILE *arqP;
FILE *arqT;
FILE * arqT1;

setlocale(LC_ALL, "");
//int tempo = clock(); //começa a contar o tempo
//while(clock() - tempo < 3000) { //enquanto não se passaram 5segundos
//	textcolor(14);
//	textbackground(0);
//	printf ("      ____________________			 \n");
//	printf ("      |           | |	 |	         \n");
//	printf ("      |  _________| |	 |           \n");
//	printf ("      |  |   	    | 	 |           \n");
//	printf ("      |  |     	    |    |     \n");
//	printf ("      |  |    ______|    |     	     \n");
//	printf ("      |  |   |____  |	 |           \n");
//	printf ("      |  |_______|  |	 |__________ \n");
//	printf ("      |             |              | \n");
//	printf ("      |_____________|______________| \n");
//	printf ("             A-V-I-Õ-E-S                                   ");
//
//	tempo = clock();
//
//	while(clock() - tempo < 3000) { //enquanto não se passaram 5segundos
//	}
//}	
	

	




do {
	
textbackground(15);
	opcao = mostrarMenuPrimcipal ();
	if (tecla == 27)
		opcao = 0; // Indicando que saiu do menu sem escolher
	textcolor(7);
	textbackground(0);
	if (opcao == 1) {
		textcolor(7);
		textbackground(15);
		gotoxy(5, 3);
		fflush(stdin);

		opcao=mostraMenuAviao ();


		if (opcao == 1) {
			textcolor(0);
		textbackground(15);
			do {
				system("cls");
				cont = inclusaoAviao(aviao, cont,arq);
				
				getch();
				printf ("Deseja continuar ?\n Continuar[0]   Parar[1]:");
				scanf ("%i",&resp);
				while(resp != 0 && resp !=1){
					printf("numero inválido, digite novamente, Continuar[0]   Parar[1]:");
					scanf ("%i",&resp);
				}

				if (resp == 1) {
					opcao=4;
				}

			} while(resp == 0);
		} else if (opcao == 2) {
	do{
			textcolor(0);
		textbackground(15);
			system("cls");
			gotoxy(5, 3);
			 opcao=alteracaoAviao(aviao,arq);
			
		if (opcao != 6){
						do{
							system("cls");
							gotoxy(5, 5);		
					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
					scanf ("%i",&resp);
					}while (resp != 0 & resp !=1 );
				if (resp == 1) {
					opcao = 4;
				}
		}else {
				opcao=4;
				resp=1;
			
	
		}
	} while (resp == 0);
		}else if (opcao == 3 ){
			textcolor(0);
		textbackground(15);
			do{
			
			exclusaoAviao(aviao,testes,arq,arq1,arqT);
		//	arq = remove("structAviao"); apaga toto o arquivo
					do{
								
					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
					scanf ("%i",&resp);
					}while (resp != 0 & resp !=1 );
				
				if (resp == 1) {
					opcao = 4;
				}
			} while (resp == 0);
		}

	} else if (opcao == 2) {

		textcolor(0);
	textbackground(15);
		gotoxy(5, 3);
		opcao =	mostraMenuPista();
		
		if (opcao == 3) {
			opcao = 4;

		} else if (opcao == 1) {
					textcolor(0);
					textbackground(15);
			do {

				system("cls");
			codigoSequencial = inclusaoPista (pistaTeste,codigoSequencial,&cont2,arqP);
				
				do{
								
					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
					scanf ("%i",&resp);
				}while (resp != 0 & resp !=1 );
				
				if (resp == 1) {
					opcao = 4;
				}
			} while (resp == 0);

		}else if (opcao==2){
		textcolor(0);
		textbackground(15);
		
		do{
			
		system("cls");
			gotoxy(5, 3);
			 opcao = alteraPista (pistaTeste,arqP );
		if (opcao!= 5){
		 	do{							
		
			
				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
				scanf ("%i",&resp);
			}while (resp != 0 & resp !=1 );
				system ("pause");
			if (resp == 1) {
	
			opcao=4;
		}
			
		}else{	
			opcao=4;
			resp=1;
		
		}
		}while(resp==0);
	}
	} else if (opcao == 3) {
		textcolor(0);
		textbackground(15);
		resp =	mostrarMenuTeste();
		if (resp == 1){
					textcolor(0);
		textbackground(15);
			do{
		
					gotoxy(5, 3);
					system("cls");
				 idTeste = inclusaoTeste( testes,arqT,arq,arqP,pistaTeste,aviao,idTeste);
				 do{							
				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
				scanf ("%i",&resp);
			}while (resp != 0 & resp !=1 );
					system ("pause");
				if (resp == 1) {
			
					opcao=4;
				}
			}while (resp==0);
		 }else if (resp == 2){
		 		
		textcolor(0);
		textbackground(15);
		gotoxy(5, 3);
		system("cls");
		 	do{
			 
		 		
			
		 	opcao=alterarTeste(testes,arqT);
		 	if(opcao!= 4){
			
		 do{							
			printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
			scanf ("%i",&resp);
			}while (resp != 0 & resp !=1 );
			system ("pause");
			if (resp == 1) {
	
					opcao=4;
			}
		}
	}while (resp==0);
}else if (resp == 3){
		textcolor(0);
		textbackground(15);
	do{
	system("cls");
	gotoxy(5, 3);
	exclusaoTeste( testes,arqT,arqT1);
	do{							
		printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
		scanf ("%i",&resp);
	}while (resp != 0 & resp !=1 );
			system ("pause");
		if (resp == 1) {
	
			opcao=4;
		}
}while(resp ==0);
	}else if  (resp == 4) {
			opcao=4;
		}



	} else if (opcao == 5) {
	do{
	
				gotoxy(5, 3);	
				system("cls");
			opcao= menuRelatorio ();
		if (opcao != 4){
			if (opcao==1){
						textcolor(0);
			textbackground(15);
				do {
			
					gotoxy(5, 3);	
					system("cls");
					opcao=relatorioR2 (aviao,arq);
			if (opcao!=2){
					
			do{							
			printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
			scanf ("%i",&resp);
			}while (resp != 0 & resp !=1 );
			system ("pause");
	
		if (resp == 1) {
	
			opcao=4;
		}
	}else {
		resp=1;
		opcao=4;
	}
	}while (resp==0);
			}else if (opcao==2){
						textcolor(0);
						textbackground(15);
				do{
					gotoxy(5, 3);	
					system("cls");
			opcao = relatorioR3 (testes,arqT,pistaTeste,arqP);
		if (opcao!=3){
		
			
				do{							
			printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
			scanf ("%i",&resp);
			}while (resp != 0 & resp !=1 );
			system ("pause");
	
		if (resp == 1) {
	
			opcao=4;
		}
	}else {
		resp=1;
		opcao=4;
	}
		}while (resp==0);
			}else if (opcao==3){
				textcolor(0);
				textbackground(15);
			do{
				opcao=mostrarRelatorioTeste();
		if (opcao !=3){
		
				
				if (opcao==1){
				system("cls");
				gotoxy(5, 3);
					relatorioR5(testes,arqT,pistaTeste,arqP);
				}else if (opcao==2){
				system("cls");
				gotoxy(5, 3);
					relatorioR6( testes,arqT);
				}
					do{							
				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
				scanf ("%i",&resp);
				}while (resp != 0 & resp !=1 );
				system ("pause");
				if (resp == 1) {
	
					opcao=4;
				}
			}else {
				resp=1;
				opcao=4;
			}
		}while(resp==0);
			}
	
	}else {
		resp =1;
		opcao=4;
	}
}while(resp ==0);
		
		  
		  
		  
	} else if (opcao == 4 ) {
		textcolor(0);
		textbackground(15);
			do{
			
			
				system("cls");
				resp = mostraMenuConsulta ();
			
				if (resp == 1) {
						textcolor(0);
						textbackground(15);
			do{
					system ("cls");
					printf ("informe seu codigo de indentificação aviao : ");
					fflush(stdin);
					fgets(codigo,8,stdin);
					
							mostrarConsultaAviao (aviao,codigo,arq);
						
				system("pause");
						do{
								
					 		printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
							scanf ("%i",&resp);
							}while (resp != 0 & resp !=1 );
								system ("pause");
							if (resp == 1) {
							opcao=4;
	
								}
					}while(resp==0);
				} else if (resp == 2){
						textcolor(0);
						textbackground(15);
					fflush(stdin);
					system("cls");
					gotoxy(5, 3);
					printf ("Informe o codigo seguemcial: ");
					scanf ("%i",&codigoS);
			
					
					 		  mostrarConsultaPista (pistaTeste,codigoS,arqP );
					 		 			system ("pause");
					 			do{
								
					 					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
										scanf ("%i",&resp);
									}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						 
					 	
			
			
				} else if (resp == 3) {
					opcao=4;
				}

			}while (resp==0);
			}
		}while(opcao == 4);
		

		return 0 ;
	}
int mostrarRelatorioTeste (){
		setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=80; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(80,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(80,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(80,18);printf("%c", 188);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  PESQUISAR PELO UF");
		gotoxy(53,12);
		printf("  PESQUISAR POR VELOCIDADE");
		gotoxy(53,13);
		printf("  VOLTAR AO MENU");

		
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
		
		
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 5;
			if (opcao == 6)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC
		
	return opcao;
}
	int menuRelatorio (){
		setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=75; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(75,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(75,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(75,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Relatorio Avião");
		gotoxy(53,12);
		printf("  Relatorio Pista");
		gotoxy(53,13);
		printf("  Relatorio Teste");
		gotoxy(53,14);
		printf("  Voltar ao Menu ");
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
			case 4:
				gotoxy(53,14);
				printf("->");
				break;
			
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 4;
			if (opcao == 5)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC

		return opcao;
	
	}
	int relatorioR3 (struct Testes testes,FILE *arqT,struct PistaTeste pistaTeste,FILE *arqP){
			int codigoP;
		int opcao;
		char data[1000];
		arqT=fopen ("structTeste","rb");
		arqT=fopen ("structTeste","ab");
		opcao=mostrarRelatorioPista();
	
		switch (opcao){
			case 1:
					system("cls");
					gotoxy(5, 3);
					printf ("Informe o codigo da pista : ");
					scanf ("%i",&codigoP);
					while (fread(&testes,sizeof(testes),1,arqT) ){
						if (testes.idPista==codigoP){
							printf ("|AVIAO: %s\t|PISTA: %i \t|DATA: %s \t|VELOCIDADE: %i",testes.idAviao,testes.idPista,testes.data,testes.velocidadeMax);
							
						}
					}
					break;
			case 2:
				system("cls");
					gotoxy(5, 3);
			 printf ("Informe a data do teste : ");
			 	fflush(stdin);
				fgets(data,1000,stdin);
					while (fread(&testes,sizeof(testes),1,arqT)){
					if(data==testes.data ){
					printf ("|AVIAO: %s\t|PISTA: %i \t|DATA: %s \t|VELOCIDADE: %i",testes.idAviao,testes.idPista,testes.data,testes.velocidadeMax);

				}
			}
		
			 break;		
	}
		fclose (arqT);
		fclose (arqT);
		return opcao;
	}
int  relatorioR2 (struct Aviao aviao,FILE *arq){
	arq=fopen ("structAviao","rb");

	int opcao ;
	char nome [64];
	opcao = mostrarRelatorioAviao();
	switch (opcao){
		case 1:
			system("cls");
			gotoxy(5, 3);
			printf ("Informe o nome do cliente :");
			fflush(stdin);
			fgets (nome,64,stdin);
				while (fread(&aviao,sizeof(aviao),1,arq) ){
				if (strcmp(aviao.nomeCliente,nome)==0  ) {
					if (aviao.idTeste==1){
					
									printf ("|CODIGO. %s\t |MODELO: %s\t|CAPACIDADE. %i|NOME: %s|PAIS. brasil\n\n\n",aviao.codigo,aviao.modelo,aviao.capacidade,aviao.nomeCliente);
}
			}
			}
			
		
		
	}
		
		
	fclose (arq);
	return opcao;
}
	int mostrarRelatorioPista(){
	setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=80; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(80,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(80,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(80,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  PESQUISAR PELO ID PISTA");
		gotoxy(53,12);
		printf("  PESQUISAR PELA DATA");
		gotoxy(53,13);
		printf("  VOLTAR AO MENU");
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;

		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 3;
			if (opcao == 4)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC
		return opcao;
	}
	int mostrarRelatorioAviao (){
		

	setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=75; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(75,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(75,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(75,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  PESQUISA PELO NOME");
		gotoxy(53,12);
		printf("  VOLTAR AO MENU");
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
		

		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 3;
			if (opcao == 4)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC

	textcolor(0);
	textbackground(15);
	return opcao;
	system ("pause");
}
	
void mostrarConsultaAviao (struct Aviao aviao,char cod[],FILE *arq ){
arq=fopen ("structAviao","rb");

		textcolor(0);
		textbackground(15);
		system("cls");
		setlocale(LC_ALL, "C");
	while (fread(&aviao,sizeof(aviao),1,arq)){
			if (strcmp(aviao.codigo,cod)==0){
			
		printf ("|Codico de indentificação : %s\n ",aviao.codigo);
							printf ("|Modelo do avião : %s \n",aviao.modelo);
							printf ("|Capacidade do avião : %i \n",aviao.capacidade);
							printf ("|Nome do cliente : %s \n",aviao.nomeCliente);
							printf ("|Pais de origem do cliente : %s \n",aviao.paisOrigCliente);
						}
		}
fclose (arq);
}
void mostrarConsultaPista (struct PistaTeste pistaTeste,int codigoS ,FILE *arqP){
		arqP = fopen ("structPista","rb");
	system("cls");
			textcolor(0);
		textbackground(15);
		setlocale(LC_ALL, "C");
		
		while (fread(&pistaTeste,sizeof(pistaTeste),1,arqP)){
			if (codigoS == pistaTeste.codSequencial){
							printf ("|Codico seguencial de indentificação : %i\n ",pistaTeste.codSequencial);
							printf ("|Endereço da pista : %s \n",pistaTeste.enderecoPista);
							printf ("|Tamanho da pista  : %f \n",pistaTeste.tamanhoCircuito);
							printf ("|UF da pista : %s \n",pistaTeste.uf);
							printf ("|Velocidade maxima da pista : %i \n",pistaTeste.velocidadeMax);
						}
				}
				fclose (arqP);
}
int mostraMenuConsulta () {
setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=70; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(70,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(70,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(70,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Lista Avião");
		gotoxy(53,12);
		printf("  Lista Pista");
		gotoxy(53,13);
		printf("  Voltar ao Menu ");
	
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
		
			
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 3;
			if (opcao == 4)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC
	textcolor(15);
	textbackground(0);
	return opcao;
	system ("pause");
}

int mostrarMenuPrimcipal() {
	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   M E N U   >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=70; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(70,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(70,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(70,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Menu Avião");
		gotoxy(53,12);
		printf("  Menu Pista");
		gotoxy(53,13);
		printf("  Menu Teste");
		gotoxy(53,14);
		printf("  Consulta  ");
		gotoxy(53,15);
		printf("  RELATORIO ");
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
			case 4:
				gotoxy(53,14);
				printf("->");
				break;
			case 5:
				gotoxy(53,15);
				printf("->");
				break;
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 5;
			if (opcao == 6)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC

	return opcao;
}


int mostrarMenuTeste () {

		setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=70; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(70,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(70,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(70,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Incluir Teste");
		gotoxy(53,12);
		printf("  Alterar Teste");
		gotoxy(53,13);
		printf("  excluir Teste ");
		gotoxy(53,14);
		printf("  Voltar ao Menu ");
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
			case 4:
				gotoxy(53,14);
				printf("->");
				break;
			
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 4;
			if (opcao == 5)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC


	textcolor(15);
	textbackground(7);
	return (opcao);

}

int mostraMenuPista () {
setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=70; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(70,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(70,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(70,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Incluir Pista");
		gotoxy(53,12);
		printf("  Alterar Pista");
		gotoxy(53,13);
		printf("  Voltar ao Menu ");
	
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
		
			
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 3;
			if (opcao == 4)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC

	textcolor(15);
	textbackground(0);
	return (opcao);

}
int mostraMenuAviao () {
	setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<   A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=70; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(70,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(70,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(70,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(53,11);
		printf("  Incluir Avião");
		gotoxy(53,12);
		printf("  Alterar Avião");
		gotoxy(53,13);
		printf("  excluir Avião");
		gotoxy(53,14);
		printf("  Voltar ao Menu");
	
		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(53,11);
				printf("->");
				break;
			case 2:
				gotoxy(53,12);
				printf("->");
				break;
			case 3:
				gotoxy(53,13);
				printf("->");
				break;
			case 4:
				gotoxy(53,14);
				printf("->");
				break;
			
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 4;
			if (opcao == 5)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC


	textcolor(15);
	textbackground(0);

	return opcao;
}

int  inclusaoPista (struct PistaTeste pistaTeste,int codigoSequencial, int *pcont,FILE *arqP) {
int cont,i=0;	
	arqP=fopen ("structPista","rb");
	if (arqP== NULL){
	
		arqP=fopen ("structPista","ab");
				pistaTeste.codSequencial=1;
		fwrite (&pistaTeste,sizeof (pistaTeste),1,arqP);
			fclose(arqP);
	}
	fclose(arqP);

	arqP=fopen ("structPista","r+b");

	textcolor(0);
	textbackground(15);
	setlocale(LC_ALL, "");
	printf ("\t\t<< I N C L U S A O  P I S T A >>>\n");
	printf ("|ENDEREÇO :\n");
	fflush(stdin);
	fgets (pistaTeste.enderecoPista,128,stdin);
	while(pistaTeste.enderecoPista[0] == '\n'){
		printf("Endereço invalido, digite novamente: ");
		fflush(stdin);
		fgets (pistaTeste.enderecoPista,128,stdin);
	}
	
	printf ("|UF da pista:\n");
	fflush(stdin);
	fgets (pistaTeste.uf,3,stdin);
	pistaTeste.uf[0] = toupper(pistaTeste.uf[0]);

	printf ("|Tamanho do circuito (km) :");
	scanf ("%f",&pistaTeste.tamanhoCircuito);
	while(pistaTeste.tamanhoCircuito <= 0){
		printf("tamanho inválido, digite novamente: ");
		scanf ("%f",&pistaTeste.tamanhoCircuito);
	}
	printf ("|Velocidade maxima :\n");
	scanf ("%d",&pistaTeste.velocidadeMax);
	while(pistaTeste.tamanhoCircuito <= 0){
		printf("velocidade invalida, digite novamente: ");
		scanf ("%d",&pistaTeste.velocidadeMax);
	}
	while (fread(&pistaTeste,sizeof(pistaTeste),1,arqP)){
		if (pistaTeste.codSequencial >= 1001){
			i++;
		}
	
}

 pistaTeste.codSequencial= 1000 +i;
	
		pistaTeste.codSequencial=	pistaTeste.codSequencial +1;
			
	printf ("O seu código sequencial e: ");
	printf ("%i",pistaTeste.codSequencial);

	fwrite (&pistaTeste,sizeof (pistaTeste),1,arqP);
	fclose(arqP);
	return codigoSequencial;
}



int inclusaoAviao(struct Aviao aviao,int cont,FILE *arq) {
	textcolor(0);
		textbackground(15);
	arq=fopen ("structAviao","ab");
	if (arq== NULL){
		printf ("Erro na abertura do arquivo ...");
		exit (1);
	}
	printf("\t\t INCLUSAO DE AVIAO");
	printf("\n\n");
	aviao=validaCodigo(aviao,arq);
	
	printf("\n");
	printf("|Digite o modelo do aviao:");
	fflush(stdin);
	fgets(aviao.modelo,11,stdin);
	while(aviao.modelo[0] == '\n') {
		printf("|Modelo inválido, digite novamente:");
		fflush(stdin);
		fgets(aviao.modelo,11,stdin);
	}


	printf("\n");
	printf("|Digite a capacidade de passageiros do aviao: ");
	scanf("%d", &aviao.capacidade);
	while(aviao.capacidade <= 0) {
		printf("|capacidade inválida, digite novamente:");
		scanf("%d", &aviao.capacidade);
	}


	printf("\n");
	printf("|Digite o nome do cliente: ");
	fflush(stdin);
	fgets(aviao.nomeCliente,64,stdin);
	while(aviao.nomeCliente[0] == '\n') {
		printf("|Nome inválido, digite novamente:");
		fflush(stdin);
		fgets(aviao.nomeCliente,64,stdin);
	}


	printf("\n");
	printf("|Digite o país de origem do cliente: ");
	fflush(stdin);
	fgets(aviao.paisOrigCliente,32,stdin);
	
	system("cls"); 
	printf("|Modelo do aviao: %s", aviao.modelo);//
	printf("|codigo do aviao: %s\n", aviao.codigo);//
	printf("|Capacidade do aviao: %d passageiros\n",aviao.capacidade);//
	printf("|Nome do cliente : %s", aviao.nomeCliente);//
	printf("|País do cliente : %s", aviao.paisOrigCliente);	//

	aviao.idExclusao=0;
	fwrite (&aviao,sizeof(aviao),1,arq);
	fclose(arq);
	cont ++;			
	
	return cont;
}


int mostrarAlteracaoAviao() {
setlocale(LC_ALL, "");
	char tecla;
	int i, opcao;
	textbackground(15); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	     // Define cor de face

	textcolor(1);
	clrscr();
	gotoxy(41,6);
	printf("           <<<  A L T E R A - A V I Ã O  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(0);

	setlocale(LC_ALL, "C");
	for (i=50; i<=71; i++) {
		gotoxy(i,9);
		printf("%c", 205);
		gotoxy(i,18);+
		printf("%c", 205);
	}
	// Desenha as linhas verticais do quadrado
for (i=9; i<=17; i++) {
		gotoxy(50,i);printf("%c", 179);
		gotoxy(71,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(50,9);printf("%c", 218);
	gotoxy(71,9);printf("%c", 191);
	gotoxy(50,18);printf("%c", 200);
	gotoxy(71,18);printf("%c", 188);


	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(0);
		textbackground(15);
		gotoxy(51,11);
		printf("  AlTERAR CODIGO");
		gotoxy(51,12);
		printf("  ALTERAR MODELO");
		gotoxy(51,13);
		printf("  AlTERAR CAPACIDADE");
		gotoxy(51,14);
		printf("  AlTERAR CLIENTE");
		gotoxy(51,15);
		printf("  AlTERAR PAIS ");
		gotoxy(51,16);
		printf("  VOLTAR AO MENU");


		// Escreve o item selecionado em destaque
		textcolor(0);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(51,11);
				printf("->");
				break;
			case 2:
				gotoxy(51,12);
				printf("->");
				break;
			case 3:
				gotoxy(51,13);
				printf("->");
				break;
			case 4:
				gotoxy(51,14);
				printf("->");
				break;
			case 5:
				gotoxy(51,15);
				printf("->");
				break;
			case 6:
				gotoxy(50,16);
				printf("->");
				break;

		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 6;
			if (opcao == 7)
				opcao = 1;
		}
		
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC




	textcolor(15);
	textbackground(0);

	return opcao;
}
int alteraPista (struct PistaTeste pistaTeste, FILE *arqP ){
arqP = fopen ("structPista","r+b");
int codigoUsuario,opcao;
char novoEndereco[64],novoUf[2];
			textcolor(0);
		textbackground(15);
	printf ("Informe o codigo sequencial da pista ");
	scanf ("%i",&codigoUsuario);
	while(codigoUsuario <=0 || codigoUsuario >9999){
		printf("código inválido, digite novamente: ");
		scanf ("%i",&codigoUsuario);
	}
	
	while (fread(&pistaTeste,sizeof(pistaTeste),1,arqP)){
		
		if (codigoUsuario == pistaTeste.codSequencial){
			textcolor(10);
			printf ("\t\tCODIGO VALIDO...\n\n");
			system ("pause");
			system ("cls");

			printf ("|ENDEREÇO DA PISTA: %s\n",pistaTeste.enderecoPista);
			printf ("---------------------------|\n");
			printf ("|UF DA PISTA : %s\n",pistaTeste.uf);
			printf ("---------------------------|\n");
			printf ("|TAMANHO  DA PISTA : %f\n",pistaTeste.tamanhoCircuito);
			printf ("---------------------------|\n");
			printf ("|VELOCIDADE MAXIMA : %i\n",pistaTeste.velocidadeMax);
			printf ("---------------------------|\n");
			system ("pause");
				
			system ("cls");
			opcao=mostrarMenuAlterarPista();
	
			switch (opcao) { 
			case 1:
					system("cls");
					gotoxy(5, 3);
					printf ("informe o novo endereço da pista : ");
					fflush(stdin);
					fgets(novoEndereco,64,stdin);
					while(novoEndereco[0] == '\n'){
						printf("endereço inválido, digite novamente: ");
						fflush(stdin);
						fgets(novoEndereco,64,stdin);
					}
					strcpy(pistaTeste.enderecoPista,novoEndereco);
					fseek(arqP,sizeof(pistaTeste)*-1,SEEK_CUR);
					fwrite (&pistaTeste,sizeof(pistaTeste),1,arqP);
					fseek(arqP,0,SEEK_SET);
			break;
			case 2:
					system("cls");
					gotoxy(5, 3);
					printf ("Informe o novo UF da pista ");
					fflush(stdin);
					fgets(pistaTeste.uf,3,stdin);

					fseek(arqP,sizeof(pistaTeste)*-1,SEEK_CUR);
					fwrite (&pistaTeste,sizeof(pistaTeste),1,arqP);
					fseek(arqP,0,SEEK_SET);
			break;
			case 3:
					system("cls");
					gotoxy(5, 3);
					printf ("informe o novo tamanho da pista ");
					scanf ("%f",&pistaTeste.tamanhoCircuito);
					while(pistaTeste.tamanhoCircuito <= 0){
						printf("tamanho inválido, digite novamente: ");
						scanf ("%f",&pistaTeste.tamanhoCircuito);
					}
					
					fseek(arqP,sizeof(pistaTeste)*-1,SEEK_CUR);
					fwrite (&pistaTeste,sizeof(pistaTeste),1,arqP);
					fseek(arqP,0,SEEK_SET);
			break;
			case 4:
					system("cls");
					gotoxy(5, 3);
					printf ("informe a nova velocidade ");
					scanf ("%i",&pistaTeste.velocidadeMax);
					while(pistaTeste.velocidadeMax <= 0){
						printf("velocidade inválida, digite novamente: ");
						scanf ("%f",&pistaTeste.velocidadeMax);
					}
						
					fseek(arqP,sizeof(pistaTeste)*-1,SEEK_CUR);
					fwrite (&pistaTeste,sizeof(pistaTeste),1,arqP);
					fseek(arqP,0,SEEK_SET);
			break ;
			}
	
		}
	}
	fclose (arqP);
	return opcao;
}


int mostrarMenuAlterarPista (){
textcolor(7);
		textbackground(0);	
	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor

	gotoxy(19,6);
	printf("           <<<  MENU ALTERAR PISTA  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=54; i++) {
		gotoxy(i,9);printf("%c", 196);
		gotoxy(i,18);printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);printf("%c", 179);
		gotoxy(54,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);printf("%c", 218);
	gotoxy(54,9);printf("%c", 191);
	gotoxy(33,18);printf("%c", 192);
	gotoxy(54,18);printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		
		gotoxy(34,11);printf("  ALTERAR ENDEREÇO");
		gotoxy(34,12);printf("  ALTERAR UF");
		gotoxy(34,13);printf("  ALTERAR TAMANHO");
		gotoxy(34,14);printf("  ALTERAR VELOCIDADE");
		gotoxy(34,15);printf("  VOLTAR AO MENU");

		
		// Escreve o item selecionado em destaque
		textcolor(15);
		//textbackground(1);
		switch (opcao) {
			case 1:gotoxy(34,11);printf("->");break;
			case 2:gotoxy(34,12);printf("->");break;
			case 3:gotoxy(34,13);printf("->");break;
			case 4:gotoxy(34,14);printf("->");break;
			case 5:gotoxy(34,15);printf("->");break;
		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 6;
			if (opcao == 7)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC
	return opcao;
}

int alteracaoAviao(struct Aviao aviao,FILE *arq) {
arq = fopen ("structAviao","r+b");
int retornoFuncao, i, posicao,resp,opcao,cont=0, flag = 0;
char codigo[7], modelo[10], nome[64];


		system ("cls");
		printf ("informe seu codigo de indentificação : ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		while(codigo[0] == '\n'){
			printf("código inválido, digite novamente: ");
			fflush(stdin);
			fgets(codigo,8,stdin);
		}
		
		while (fread(&aviao,sizeof(aviao),1,arq)){
			
			if (stricmp(aviao.codigo,codigo)==0){

				textcolor(10);
				printf ("\t\tCODIGO VALIDO...\n\n");
				system ("pause");
				system ("cls");

				printf ("|MODELO DO AVIAO: %s\n",aviao.modelo);
				printf ("---------------------------|\n");
				printf ("|NOME DO CLIENTE : %s\n",aviao.nomeCliente);
				printf ("---------------------------|\n");
				printf ("|PAIS DO CLIENTE : %s\n",aviao.paisOrigCliente);
				printf ("---------------------------|\n");
				printf ("|CAPACIDADE DO AVIAO : %d\n",aviao.capacidade);
				printf ("---------------------------|\n");
				printf ("|CODIGO: %s",aviao.codigo);
				printf ("---------------------------|\n\n\n");
				system ("pause");
					
				system ("cls");
				
				
				opcao = mostrarAlteracaoAviao();
		
				switch(retornoFuncao) {	

				case 1:
					system("cls");
					gotoxy(5, 3);
					printf("alteração de código de identificação\n");
					printf("Inserimento de um novo código de id:");
					aviao=validaCodigo(aviao,arq);
					
					fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
					fwrite (&aviao,sizeof(aviao),1,arq);
					fseek(arq,0,SEEK_SET);
				
				break;
				case 2:
					system("cls");
					gotoxy(5, 3);
					printf("alteração de modelo do avião\n");
		
					printf("Inserimento de um novo modelo de avião:");
					printf("\nInsira aqui: ");
					fflush(stdin);
					fgets(modelo,10,stdin);
					while(modelo[0] == '\n') {
						printf("modelo invalido, digite novamente:");
						fflush(stdin);
						fgets(modelo,10,stdin);
					}
					strcpy(aviao.modelo,modelo);
					
					fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
					fwrite (&aviao,sizeof(aviao),1,arq);
					fseek(arq,0,SEEK_SET);
				
				
			 	break;
				case 3:
					system("cls");
					gotoxy(5, 3);
					printf("alteração de capacidade do avião\n");
		
					printf("Inserimento de uma nova capacidade do avião:");
					printf("\nInsira aqui: ");
					scanf("%d", &aviao.capacidade);
					while(aviao.capacidade <=0) {
						printf("Capacidade inválida, digite novamente: ");
						scanf("%d", &aviao.capacidade);
					}
					fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
					fwrite (&aviao,sizeof(aviao),1,arq);
					fseek(arq,0,SEEK_SET);
				
				break;
				case 4:
					system("cls");
					gotoxy(5, 3);
					printf("alteração de nome do cliente\n");
		
					printf("Inserimento de um novo nome do cliente:");
					printf("\nInsira aqui: ");
					fflush(stdin);
					fgets(nome,64,stdin);
					while(nome[0] == '\n') {
						printf("nome inválido, digite novamente:");
						fflush(stdin);
						fgets(nome,64,stdin);	
					}
				
					strcpy(aviao.nomeCliente,nome);
					fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
					fwrite (&aviao,sizeof(aviao),1,arq);
					fseek(arq,0,SEEK_SET);
					
				break;
				case 5:
					system("cls");
					gotoxy(5, 3);
					printf("alteração de país de origem do cliente\n");
					break;
				}
		
				
			}
		}

fclose(arq);

return opcao;
}

struct Aviao validaCodigo(struct Aviao aviao,FILE *arq) {
		//  fseek(arq,0,SEEK_CUR);
arq=fopen ("structAviao","r+b");
char codigo[8];
int flag, i;

	do {
		flag = 0;
		printf("\n| Código de Identificação: ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		
		while(codigo[0] == '\n') {
			printf("codigo invalido, digite novamente:");
			fflush(stdin);
			fgets(codigo,8,stdin);
		}
		while (fread(&aviao,sizeof(aviao),1,arq)){
			if (stricmp(aviao.codigo,codigo)==0){
				printf("codigo já registrado, digite outro codigo");
				flag++;
			}
		}
		if((codigo[0] >=65 && codigo[0] <=90) || (codigo[0] >=97 && codigo[0] <=122 )) {
			if((codigo[1] >=65 && codigo[1] <=90) || (codigo[1] >=97 && codigo[1] <=122 )) {
				if((codigo[2] >=65 && codigo[2] <=90) || (codigo[2] >=97 && codigo[2] <=122 )) {
					if(codigo[3] >=48 && codigo[3] <=57) {
						if(codigo[4] >=48 && codigo[4] <=57) {
							if(codigo[5] >=48 && codigo[5] <=57) {
								if(codigo[6] >=48 && codigo[6] <=57) {

								} else {
									printf("codigo invalido, verifique e tente novamente: ");
									flag++;
								}
							} else {
								printf("codigo invalido, verifique e tente novamente: ");
								flag++;
							}
						} else {
							printf("codigo invalido, verifique e tente novamente: ");
							flag++;
						}
					} else {
						printf("codigo invalido, verifique e tente novamente: ");
						flag++;
					}
				} else {
					printf("codigo invalido, verifique e tente novamente: ");
					flag++;
				}
			} else {
				printf("codigo invalido, verifique e tente novamente: ");
				flag++;
			}
		} else {
			printf("codigo invalido, verifique e tente novamente: ");
			flag++;
		}
	
	
		
		if(flag == 0) {
			printf("codigo registrado com sucesso");
			strcpy(aviao.codigo,codigo);
			printf("\ncodigo do aviao : %s", aviao.codigo);
		}
	} while(flag >= 1);

	fclose(arq);	
	return aviao;
}



void exclusaoAviao(struct Aviao aviao, struct Testes testes,FILE *arq,FILE *arq1,FILE *arqT){
arq=fopen ("structAviao","rb");

arq1 = fopen ("novoStruct","wb");
int retornoFuncao, i, j, posicao,resp,opcao, flag=0;
char codigo[7], excluir;

	system ("cls");
	printf ("informe o codigo de indentificação do aviao : ");
	fflush(stdin);
	fgets(codigo,8,stdin);
	while(codigo[0] == '\n'){
		printf("código inválido, digite novamente: ");
		fflush(stdin);
		fgets(codigo,8,stdin);
	}
	while (fread(&aviao,sizeof(aviao),1,arq)){
			if (strcmp(aviao.codigo,codigo)==0){
				printf("\n\nexclusão bem sucedida!\n");
			
		while (fread(&aviao,sizeof(aviao),1,arq)){
			if (strcmp(aviao.codigo,codigo)!=0){
			 			fwrite (&aviao,sizeof (aviao),1,arq1);
					
				}
//				aviao.idExclusao = 1;
//				
//				fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
//				fwrite (&aviao,sizeof(aviao),1,arq);
//				fseek(arq,0,SEEK_SET);
//				
//	
//		//	while (fread(&testes,sizeof(testes),1,arqT)){
//		//			if(stricmp(aviao.codigo,testes.idAviao) == 0)
//					textcolor(10);
//					system ("cls");
//					printf ("\t\tCODIGO VALIDO...\n\n");
//					system ("pause");
//					system ("cls");
//	
//					printf ("|MODELDO AVIAO: %s\n",aviao.modelo);
//					printf ("---------------------------|\n");
//					printf ("|NOME DO CLIENTE : %s\n",aviao.nomeCliente);
//					printf ("---------------------------|\n");
//					printf ("|PAIS DO CLIENTE : %s\n",aviao.paisOrigCliente);
//					printf ("---------------------------|\n");
//					printf ("|CAPACIDADE DO AVIAO : %d\n",aviao.capacidade);
//					printf ("---------------------------|\n");
//					printf ("|CODIGO: %s",aviao.codigo);
//					printf ("---------------------------|\n\n\n");
//					system ("pause");
//					printf("\n\nDeseja realmente EXCLUIR? [S/N]");
//					scanf(" %c", &excluir);
//					excluir = toupper(excluir);
//					while(excluir != 'S' && excluir != 'N'){
//						printf("caracter inválido, digite novamente: ");
//						scanf(" %c", &excluir);
//						excluir = toupper(excluir);
//					}
				
		
				
			}
		}
	}
				
			
 		
	
	fclose(arq);
	fclose (arq1);
	arq=fopen ("structAviao","wb");
	arq1 = fopen ("novoStruct","rb");
		while (fread(&aviao,sizeof(aviao),1,arq1)){
				fwrite (&aviao,sizeof (aviao),1,arq);
		}
	


	
	fclose(arq);
	fclose (arq1);
	system("pause");
}
	
		
void exclusaoTeste(struct Testes testes,FILE *arqT,FILE * arqT1){
	int codigo;
	char excluir;
	arqT=fopen ("structTeste","rb");
	arqT1=fopen ("novoTeste","wb");
	printf ("Informe o codigo do teste :");
	scanf ("%i",&codigo);
	while (fread(&testes,sizeof(testes),1,arqT)){
			if (codigo != testes.idTeste){
			fwrite (&testes,sizeof (testes),1,arqT1);
		}
	}
	fclose (arqT);
	fclose (arqT1);
	arqT=fopen ("structTeste","wb");
	arqT1=fopen ("novoTeste","rb");
	
	while (fread(&testes,sizeof(testes),1,arqT1)){
				fwrite (&testes,sizeof (testes),1,arqT);
		}
	
	fclose (arqT);
	fclose (arqT1);
	printf("\n\nexclusão bem sucedida!\n");
	system("pause");
}
int inclusaoTeste(struct Testes testes,FILE *arqT,FILE *arq,FILE *arqP,struct PistaTeste pistaTeste,struct Aviao aviao,int idTeste){
char codigo[7];
int i=0, flag, codigoP, velocM;
	arqT=fopen ("structTeste","rb");
	if (arqT== NULL){
	
		arqT=fopen ("structTeste","ab");
		testes.idTeste=1;
		fwrite (&testes,sizeof (testes),1,arqT);
			fclose(arqT);
	}
	fclose(arqT);
arqT=fopen ("structTeste","r+b");
arqP=fopen ("structPista","r");
arq=fopen ("structAviao","r+b");
		textcolor(0);
		textbackground(15);




	if (arqT== NULL){
		printf ("Erro na abertura..");
		exit (1);
	}

	system ("cls");
	printf ("informe seu codigo de indentificação do avião : ");
	fflush(stdin);
	fgets(codigo,8,stdin);
	while(codigo[0] == '\n'){
		printf("código inválido, digite novamente:");
		fgets(codigo,8,stdin);
	}
	
	while (fread(&aviao,sizeof(aviao),1,arq)){
			if (strcmp(aviao.codigo,codigo)==0){
				aviao.idTeste=1;
				fseek(arq,sizeof(aviao)*-1,SEEK_CUR);
				fwrite (&aviao,sizeof(aviao),1,arq);
				fseek(arq,0,SEEK_SET);
				strcpy(testes.idAviao,codigo);
				system ("cls");
				printf("digite o codigo sequencial da pista: ");
				scanf("%d",&codigoP);
				
				while(codigoP <= 0 || codigoP >9999){
					printf("código inválido, digite novamente:");
					scanf("%d",&codigoP);
				}
				
				while (fread(&pistaTeste,sizeof(pistaTeste),1,arqP)){
					if (codigoP == pistaTeste.codSequencial){
			
						testes.idPista=codigoP;
						fflush(stdin);
						printf("\n digite a velocidade maxima em km/h: ");
						scanf("%d", &velocM);
						while(velocM <= 0){
							printf("velocidade invalida, digite novamente: ");
							scanf("%d", &velocM);
						}
					
						while (fread(&testes,sizeof(testes),1,arqT)){
						if (testes.idTeste >= 1001){
							i++;
							}
	
						}

 					testes.idTeste= 1000 +i;
	
					testes.idTeste=	testes.idTeste +1;
					
						printf ("\n\nSeu id do teste é : %i ",testes.idTeste);
						
						testes.velocidadeMax = velocM;
						_strdate(testes.data);
						system("pause");
						fwrite (&testes,sizeof (testes),1,arqT);
					}
				}	
			}	
	}
	fclose(arqT);
	fclose(arqP);
	fclose(arq);
	return idTeste;
}


int alterarTeste(struct Testes testes,FILE *arqT){
	
	arqT=fopen ("structTeste","r+b");
	setlocale(LC_ALL, "");
char  menu, sn;
int flag = 0,opcao,codigo;
	gotoxy(5, 3);
	system("cls");
		textcolor(0);
		textbackground(15);
		
	printf(" ALTERAÇÃO TESTE \n");	
	printf("digite o codigo do teste: ");
	scanf ("%i",&codigo);
	while(codigo <=0){
		printf("código inválido, digite novamente: ");
		scanf ("%i",&codigo);
	}	
		
	
	while (fread(&testes,sizeof(testes),1,arqT)){
		if(codigo==testes.idTeste ){
			
			textcolor(10);
			printf ("\t\tCODIGO VALIDO...\n\n");
			system ("pause");
			system ("cls");

			printf ("|DATA DO TESTE: %s\n",testes.data);
			printf ("---------------------------|\n");
			printf ("|VELOCIDADE MAXIMA DO TESTE  : %i\n",testes.velocidadeMax);
			printf ("---------------------------|\n");
			printf ("|AVIAO DO TESTE : %s\n",testes.idAviao);
			printf ("---------------------------|\n");
			printf ("|PISTA DO TESTE : %d\n",testes.idPista);
			printf ("---------------------------|\n\n");
			system ("pause");
			
			
			opcao = mostrarMenuAlterar ();
			switch(opcao){
			case 1:
				
			gotoxy(5, 3);
			system("cls");
			printf ("Informe a nova velocidade: ");
			scanf ("%i",&testes.velocidadeMax);
				while(testes.velocidadeMax <= 0){
					printf("velocidade inválida, digite novamente: ");
					scanf ("%i",&testes.velocidadeMax);
				}
				
			fseek(arqT,sizeof(testes)*-1,SEEK_CUR);
			fwrite (&testes,sizeof(testes),1,arqT);
			fseek(arqT,0,SEEK_SET);
			break;
			case 2:
				
			opcao=4;
			
			break;
			}

		
		}
		
		
		return opcao;
	
	}
	fclose(arqT);
}


 int mostrarMenuAlterar (){
 	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
   // Define cor de face
	textcolor(7);
	textbackground(0);
	gotoxy(19,6);
	printf("           <<<  Menu Teste  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=55; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);printf("%c", 179);
		gotoxy(55,i);printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(55,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(55,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  ALTERAR VELOCIDADE ");
		gotoxy(34,12);
		printf("  VOLTAR AO MENU");
	
	
		// Escreve o item selecionado em destaque
		textcolor(15);
		//textbackground(1);
		switch (opcao) {
			case 1:
				gotoxy(34,11);
				printf("->");
				break;
			case 2:
				gotoxy(34,12);
				printf("->");
				break;
		

		}
		tecla = getch();    // Recebe a tecla pressionada
		if (tecla == -32) { // -32 = tecla especial (setas, etc...)
			tecla = getch(); // Recebe o novo valor ecoado no buffer por ser tecla especial
			if (tecla == 72) // Seta para cima
				opcao--;
			if (tecla == 80) // Seta para baixo
				opcao++;
			if (opcao == 0)
				opcao = 5;
			if (opcao == 6)
				opcao = 1;
		}
	} while ((tecla != 13) && (tecla != 27)); // 13=ENTER 27=ESC
 	return opcao;
 }
 

void relatorioR5(struct Testes testes,FILE *arqT,struct PistaTeste pistaTeste,FILE *arqP){
char ufP = 64 ;	
arqT=fopen ("structTeste","ab");
arqP=fopen ("structPista","ab");		
	
	
	while (fread(&pistaTeste,sizeof(pistaTeste),1,arqP) && ufP<91 ){
		ufP++;
		if(pistaTeste.uf[0] == ufP){
			while(fread(&testes,sizeof(testes),1,arqT));{
				if(pistaTeste.codSequencial == testes.idPista ){
					printf("UF da pista do teste: %s", pistaTeste.uf);
					printf("Identificação do avião: %s", testes.idAviao);
					printf("Identificação da pista: %d", testes.idPista);
					printf("Identificação do teste: %d", testes.idTeste);
					printf("velocidade máx: %d" ,testes.velocidadeMax);
					printf("data do teste : %s", testes.data);
				}
			}
		}
		printf("\n\n");
	}

}


void relatorioR6(struct Testes testes,FILE *arqT){
arqT=fopen ("structTeste","ab");	
int velocMin, velocMax;	
	
	
	printf("precisamos de um intervalo de velocidade para este relatório: \n");
	printf("digite o valor um valor mínimo de velocidade em km/h:");
	scanf("%d", &velocMin);
	while(velocMin <0){
		printf("valor inválido, digite novamente: ");
		scanf("%d", &velocMin);
	}
	printf("digite o valor um valor máximo de velocidade em km/h:");
	scanf("%d", &velocMax);
	while(velocMin <0){
		printf("valor inválido, digite novamente: ");
		scanf("%d", &velocMax);
	}
	system("cls");
	while(fread(&testes,sizeof(testes),1,arqT));{
		if(testes.velocidadeMax > velocMin && testes.velocidadeMax < velocMax){
			printf("UF da pista do teste: %s", pistaTeste.uf);
			printf("Identificação do avião: %s", testes.idAviao);
			printf("Identificação da pista: %d", testes.idPista);
			printf("Identificação do teste: %d", testes.idTeste);
			printf("velocidade máx: %d" ,testes.velocidadeMax);
			printf("data do teste : %s", testes.data);
		}
	}
	
}
