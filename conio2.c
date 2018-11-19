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
		char codigo[7];
		int capacidade;
		char nomeCliente[64];
		char paisOrigCliente[32];
		char modelo[10];
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
	char idAviao[7];
	int idPista;
	char data[1000];
	int velocidadeMax;
};

// declarando as structs
struct Aviao aviao[MAX];
struct PistaTeste pistaTeste[MAX];
struct Testes testes[MAX];

//prototipos das funções
int inclusaoAviao(struct Aviao aviao[], int cont);
void validaCodigo(struct Aviao aviao[], int cont);
int alteracaoAviao(struct Aviao aviao[]);
int inclusaoPista (struct PistaTeste pistaTeste[] ,int codigoSeguemcial, int *pcont);
int mostraMenuAviao ();
int mostraMenuPista ();
int mostrarMenuTeste ();
int mostrarAlteracaoAviao();
int mostrarMenuPrimcipal();
int mostraMenuConsulta ();
void mostrarConsultaAviao (struct Aviao aviao[],int i );
void mostrarConsultaPista (struct PistaTeste pistaTeste[],int i );

// "CONT" É PARA A STRUCT DE AVIAO, CONT2 PARA PISTAS
int main(void) {
int resp,continuar,cont = 0, cont2 =0,codigoS;
int codigoSeguemcial ;
char tecla,codigo[7];
int i, opcao;
char agora[1000],data[100];


setlocale(LC_ALL, "");
int tempo = clock(); //começa a contar o tempo
while(clock() - tempo < 3000) { //enquanto não se passaram 5segundos
	textcolor(14);
	textbackground(0);
	printf ("      ____________________			 \n");
	printf ("      |           | |	 |	         \n");
	printf ("      |  _________| |	 |           \n");
	printf ("      |  |   	    | 	 |           \n");
	printf ("      |  |     	    |    |     \n");
	printf ("      |  |    ______|    |     	     \n");
	printf ("      |  |   |____  |	 |           \n");
	printf ("      |  |_______|  |	 |__________ \n");
	printf ("      |             |              | \n");
	printf ("      |_____________|______________| \n");
	printf ("             A-V-I-Õ-E-S                                   ");

	tempo = clock();

	while(clock() - tempo < 3000) { //enquanto não se passaram 5segundos
	}
}
codigoSeguemcial = 1000 ;

do {
textbackground(0);
	opcao = mostrarMenuPrimcipal ();
	if (tecla == 27)
		opcao = 0; // Indicando que saiu do menu sem escolher
	textcolor(15);
	textbackground(0);
	if (opcao == 1) {
		textcolor(7);
		textbackground(0);
		gotoxy(5, 3);
		fflush(stdin);

		opcao=mostraMenuAviao ();


		if (opcao == 1) {
			do {
				system("cls");
				cont = inclusaoAviao(aviao, cont);
				printf("%d", cont);
				getch();
				printf ("Deseja continuar ?\nComtinuar [0]-Parar [1]");
				scanf ("%i",&resp);

				if (resp == 1) {
					opcao=4;
				}

			} while(resp == 0);
		} else if (opcao == 2) {
			system("cls");
			gotoxy(5, 3);
			opcao = alteracaoAviao(aviao);
			if (opcao == 0 ) {
				system("cls");
					gotoxy(5, 3);
					resp = mostrarAlteracaoAviao();
			}
			if (resp == 6) {
				opcao=4;
			}
		}

	} else if (opcao == 2) {

		textcolor(7);
		textbackground(0);
		gotoxy(5, 3);
		opcao =	mostraMenuPista();

		if (opcao == 3) {
			opcao = 4;

		} else if (opcao == 1) {
			do {

				system("cls");
				codigoSeguemcial = inclusaoPista (pistaTeste,codigoSeguemcial,&cont2);
				
				do{
								
					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
					scanf ("%i",&resp);
				}while (resp != 0 & resp !=1 );
				
				if (resp == 1) {
					opcao = 4;
				}
			} while (resp == 0);

		}

	} else if (opcao == 3) {
	
		resp =	mostrarMenuTeste();
		if (resp == 1){
			do{
					
				textcolor(7);
		textbackground(0);
			fflush(stdin);
			system("cls");
			gotoxy(5, 3);
			printf ("Informe o codigo : ");
					fgets(codigo,8,stdin);
			
					 for (i=0;i<MAX;i++){
					 	if(stricmp(codigo,aviao[i].codigo) == 0){
					 			textcolor(10);
					 				printf ("CODIGO[%s] VALIDO .....\n\n",aviao[i].codigo);
								textcolor(7);
								system ("pause");
					  do{
							textcolor(7);
							textbackground(0);
					fflush(stdin);
					system("cls");
					gotoxy(5, 3);
				
					printf ("Informe o codigo seguemcial: ");
					scanf ("%i",&codigoS);
			
					 for (i=0;i<MAX;i++){
					 	if(codigoS == pistaTeste[i].codSequencial){
					 			textcolor(10);
					 		  	printf ("CODIGO[%i] VALIDO .....\n\n",pistaTeste[i].codSequencial);
					 		 	textcolor(7);
					 		 		time_t agora;
					 		 	_strdate(agora);
					 		 
					 		 
					 	//	testes[i].data = agora;
					 		 	printf ("%s",agora);
					 			do{
								
					 					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
										scanf ("%i",&resp);
									}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						 }
				//	
					 } if(codigoS != pistaTeste[i].codSequencial){
							
							system ("cls");
							textcolor(12);
								printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");	
					 				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
								scanf ("%i",&resp);
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						}
						}while(resp==0);
							
					 		 
					 		
						 }
					 	
					 } if(stricmp(codigo,aviao[i].codigo) != 0){
							
							system ("cls");
							textcolor(12);
								printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");	
								do{
								
					 				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
									scanf ("%i",&resp);
								}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						}
					
		}while(resp==0);
			
		}else if  (resp == 4) {
			opcao=4;
		}



	} else if (opcao == 5) {
		system("cls");

		gotoxy(5, 3);
		printf ("<< O B R I G A D O >>");
		break;
	} else if (opcao == 4 ) {
		textcolor(7);
		textbackground(0);
			do{
			
				system("cls");
				resp = mostraMenuConsulta ();
			
				if (resp == 1) {
					fflush(stdin);
					system("cls");
					gotoxy(5, 3);
					printf ("Informe o codigo : ");
					fgets(codigo,8,stdin);
			
					 for (i=0;i<MAX;i++){
					 	if(stricmp(codigo,aviao[i].codigo) == 0){
					 		 mostrarConsultaAviao (aviao,i);
					 		 
					 			do{
								
					 					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
										scanf ("%i",&resp);
									}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						 }
					 	
					 } if(stricmp(codigo,aviao[i].codigo) != 0){
							
							system ("cls");
							textcolor(12);
								printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");	
								do{
								
					 				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
									scanf ("%i",&resp);
								}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						}
					
						
					//	(stricmp (codigo,aviao[i].codigo) != 0 ||resp == 1 )
	
				} else if (resp == 2) {
					fflush(stdin);
					system("cls");
					gotoxy(5, 3);
					printf ("Informe o codigo seguemcial: ");
					scanf ("%i",&codigoS);
			
					 for (i=0;i<MAX;i++){
					 	if(codigoS == pistaTeste[i].codSequencial){
					 		  mostrarConsultaPista (pistaTeste,i );
					 		 	
					 			do{
								
					 					printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
										scanf ("%i",&resp);
									}while (resp != 0 & resp !=1 );
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						 }
					 	
					 } if(codigoS != pistaTeste[i].codSequencial){
							
							system ("cls");
							textcolor(12);
								printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");	
					 				printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
								scanf ("%i",&resp);
								system ("pause");
								if (resp == 1) {
	
									opcao=4;
	
								}
						}
							
			
				} else if (resp == 3) {
					opcao=4;
				}

			}while (resp==0);
			}
		}while(opcao == 4);

		return 0 ;
	}

void mostrarConsultaAviao (struct Aviao aviao[],int i ){
	system("cls");
		setlocale(LC_ALL, "C");
		printf ("|Codico de indentificação : %s\n ",aviao[i].codigo);
							printf ("|Modelo do avião : %s \n",aviao[i].modelo);
							printf ("|Capacidade do avião : %i \n",aviao[i].capacidade);
							printf ("|Nome do cliente : %s \n",aviao[i].nomeCliente);
							printf ("|Pais de origem do cliente : %s \n",aviao[i].paisOrigCliente);
							system ("pause");

}
void mostrarConsultaPista (struct PistaTeste pistaTeste[],int i ){
	system("cls");
		setlocale(LC_ALL, "C");
							printf ("|Codico seguencial de indentificação : %i\n ",pistaTeste[i].codSequencial);
							printf ("|Endereço da pista : %s \n",pistaTeste[i].enderecoPista);
							printf ("|Tamanho da pista  : %f \n",pistaTeste[i].tamanhoCircuito);
							printf ("|UF da pista : %s \n",pistaTeste[i].uf);
							printf ("|Velocidade maxima da pista : %i \n",pistaTeste[i].velocidadeMax);
							system ("pause");

}
int mostraMenuConsulta () {

	char tecla;
	int i, opcao;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(7);     // Define cor de face

	gotoxy(19,6);
	setlocale(LC_ALL, "C");
		clrscr();
	printf("           <<<  C-O-N-S-U-L-T-A   >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=50; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(50,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(50,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(50,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  LISTA AVIÃO");
		gotoxy(34,12);
		printf("  LISTA PISTA");
		gotoxy(34,13);
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
			case 3:
				gotoxy(34,13);
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
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face


	clrscr();
	gotoxy(19,6);
	printf("           <<<   M E N U   >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);

	setlocale(LC_ALL, "C");
	for (i=34; i<=45; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(46,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(46,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(46,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  Menu Avião");
		gotoxy(34,12);
		printf("  Menu Pista");
		gotoxy(34,13);
		printf("  Menu Teste");
		gotoxy(34,14);
		printf("  Consulta  ");
		gotoxy(34,15);
		printf("  sair      ");
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
			case 3:
				gotoxy(34,13);
				printf("->");
				break;
			case 4:
				gotoxy(34,14);
				printf("->");
				break;
			case 5:
				gotoxy(34,15);
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

	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	gotoxy(19,6);
	printf("           <<<  P I S T A - T E S T E   >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=50; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(50,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(50,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(50,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  INCLUIR TESTE");
		gotoxy(34,12);
		printf("  ALTERAR TESTE");
		gotoxy(34,13);
		printf("  EXCLUIR TESTE");
		gotoxy(34,14);
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
			case 3:
				gotoxy(34,13);
				printf("->");
				break;
			case 4:
				gotoxy(34,14);
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

	textcolor(15);
	textbackground(7);
	return (opcao);

}

int mostraMenuPista () {

	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	gotoxy(19,6);
	printf("           <<<  P I S T A  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=50; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(50,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(50,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(50,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  INCLUIR PISTA");
		gotoxy(34,12);
		printf("  ALTERAR PISTA");
		gotoxy(34,13);
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
			case 3:
				gotoxy(34,13);
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

	textcolor(15);
	textbackground(0);
	return (opcao);

}
int mostraMenuAviao () {
	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	gotoxy(19,6);
	printf("           <<<  A V I A O   >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=51; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(51,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(51,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(51,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  INCLUIR AVIÃO");
		gotoxy(34,12);
		printf("  ALTERAR AVIAO");
		gotoxy(34,13);
		printf("  EXCLUIR AVIAO");
		gotoxy(34,14);
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
			case 3:
				gotoxy(34,13);
				printf("->");
				break;
			case 4:
				gotoxy(34,14);
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

	textcolor(15);
	textbackground(0);

	return opcao;
}

int inclusaoPista (struct PistaTeste pistaTeste[],int codigoSeguemcial, int *pcont) {
	int cont;
	cont = *pcont;
	textcolor(7);
	textbackground(0);
	int i;
	setlocale(LC_ALL, "C");
	printf ("\t\t<< I N C L U S A O  P I S T A >>>\n");
	printf ("|ENDEREÇO :\n");
	fflush(stdin);
	fgets (pistaTeste[cont].enderecoPista,128,stdin);
	printf ("|UF da pista:\n");
	fgets (pistaTeste[cont].uf,2,stdin);
	fflush(stdin);
	do {
		printf ("|Tamanho do circuito (km) :");
		scanf ("%f",&pistaTeste[cont].tamanhoCircuito);
	} while (pistaTeste[cont].tamanhoCircuito < 0);
	printf ("|Velocidade maxima :\n");
	scanf ("%i",&pistaTeste[cont].velocidadeMax);

	codigoSeguemcial =  codigoSeguemcial + 1;
	pistaTeste[cont].codSequencial = codigoSeguemcial;
	printf ("O seu codico seguemcial e:\n ");
	printf ("%i",pistaTeste[cont].codSequencial);
	cont++;
	*pcont = cont;
	
	return codigoSeguemcial;
}



int inclusaoAviao(struct Aviao aviao[],int cont) {


	printf("\t\tINCLUSAO DE AVIAO");
	printf("\n\n");

	validaCodigo(aviao, cont);
	
	printf("\n");
	printf("|Digite o modelo do aviao:");
	fflush(stdin);
	fgets(aviao[cont].modelo,11,stdin);
	while(aviao[cont].modelo[0] == '\n') {
		printf("|Modelo invalido, digite novamente:");
		fflush(stdin);
		fgets(aviao[cont].modelo,11,stdin);
	}
	
	printf("|Modelo do aviao: %s", aviao[cont].modelo);//
	printf("|codigo do aviao: %s", aviao[cont].codigo);//


	printf("\n");
	printf("|Digite a capacidade de passageiros do aviao: ");
	scanf("%d", &aviao[cont].capacidade);
	while(aviao[cont].capacidade <= 0) {
		printf("|capacidade inválida, digite novamente:");
		scanf("%d", &aviao[cont].capacidade);
	}
	printf("|Capacidade do aviao: %d passageiros",aviao[cont].capacidade);//


	printf("\n");
	printf("|Digite o nome do cliente: ");
	fflush(stdin);
	fgets(aviao[cont].nomeCliente,64,stdin);
	while(aviao[cont].nomeCliente[0] == '\n') {
		printf("|Nome inválido, digite novamente:");
		fflush(stdin);
		fgets(aviao[cont].nomeCliente,64,stdin);
	}
	printf("|Nome do cliente : %s", aviao[cont].nomeCliente);//


	printf("\n");
	printf("|Digite o país de origem do cliente: ");
	fflush(stdin);
	fgets(aviao[cont].paisOrigCliente,32,stdin);
	printf("|País do cliente : %s", aviao[cont].paisOrigCliente);	//
	
	cont ++;			
	
	return cont;
}


int mostrarAlteracaoAviao() {
	setlocale(LC_ALL, "C");
	char tecla;
	int i, opcao,resp;
	textbackground(0); // Define cor de fundo
	clrscr();          // Limpa a tela
	_setcursortype(0); // Desliga o cursor
	textcolor(15);     // Define cor de face

	gotoxy(19,6);
	printf("           <<<  P I S T A - T E S T E  >>>");
	// DESENHAR UM QUADRADO
	// Desenha as linhas horizontais do quadrado
	textcolor(7);
	for (i=34; i<=60; i++) {
		gotoxy(i,9);
		printf("%c", 196);
		gotoxy(i,18);
		printf("%c", 196);
	}
	// Desenha as linhas verticais do quadrado
	for (i=9; i<=17; i++) {
		gotoxy(33,i);
		printf("%c", 179);
		gotoxy(60,i);
		printf("%c", 179);
	}
	// Desenha os quanto cantos do quadrado
	gotoxy(33,9);
	printf("%c", 218);
	gotoxy(60,9);
	printf("%c", 191);
	gotoxy(33,18);
	printf("%c", 192);
	gotoxy(60,18);
	printf("%c", 217);

	// OPERACAO DO MENU
	opcao = 1; // Seleciona a primeira opcao do menu
	do {
		setlocale(LC_ALL, "");
		textcolor(7);
		textbackground(0);
		gotoxy(34,11);
		printf("  AlTERAR CODIGO");
		gotoxy(34,12);
		printf("  ALTERAR MODELO");
		gotoxy(34,13);
		printf("  AlTERAR CAPACIDADE");
		gotoxy(34,14);
		printf("  AlTERAR NOME CLIENTE:");
		gotoxy(34,15);
		printf("  AlTERAR PAIS DO CLIENTE:");
		gotoxy(34,16);
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
			case 3:
				gotoxy(34,13);
				printf("->");
				break;
			case 4:
				gotoxy(34,14);
				printf("->");
				break;
			case 5:
				gotoxy(34,15);
				printf("->");
				break;
			case 6:
				gotoxy(34,16);
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
int alteracaoAviao(struct Aviao aviao[]) {
	int retornoFuncao, i, posicao,resp,opcao;
	char codigo[7], modelo[10], nome[64];
	do {
		// arrumar problema de invalido
		system ("cls");
		printf ("informe sua codigo de indentificação : ");
		fflush(stdin);
		fgets(codigo,8,stdin);

		system ("cls");
		for(i= 0;i<MAX;i++){
			if (stricmp(aviao[i].codigo,codigo) == 0) {

				textcolor(10);
				printf ("\t\tCODIGO VALIDO...\n\n");
				system ("pause");
				system ("cls");

				printf ("|MODELDO AVIAO: %s\n",aviao[i].modelo);
				printf ("---------------------------|\n");
				printf ("|NOME DO CLIENTE : %s\n",aviao[i].nomeCliente);
				printf ("---------------------------|\n");
				printf ("|PAIS DO CLIENTE : %s\n",aviao[i].paisOrigCliente);
				printf ("---------------------------|\n");
				printf ("|CAPACIDADE DO AVIAO : %d\n",aviao[i].capacidade);
				printf ("---------------------------|\n");
				printf ("|CODIGO: %s",aviao[i].codigo);
				printf ("---------------------------|\n\n\n");
				system ("pause");
				
				retornoFuncao = mostrarAlteracaoAviao();
				break;		
			}else{
				
				system ("cls");
				printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");	
			}
		}
		system("cls");
			gotoxy(5, 3);
		printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
		scanf ("%i",&resp);
		system ("pause");
		if (resp == 1){

			opcao = 4;
		}


	} while(resp == 0);
	system("cls");
	switch(retornoFuncao) {
		
		case 1:
			printf("alteração de código de identificação\n");
			printf("Inserimento de um novo código de id:");
			validaCodigo(aviao, i);

		case 2:
			printf("alteração de modelo do avião\n");

			printf("Inserimento de um novo modelo de avião:");
			printf("\nInsira aqui: ");
			fflush(stdin);
			fgets(modelo,10,stdin);
			while(modelo[0] == '\n') {
				printf("codigo invalido, digite novamente:");
				fflush(stdin);
				fgets(modelo,10,stdin);
			}
			strcpy(aviao[i].modelo,modelo);


		case 3:
			printf("alteração de capacidade do avião\n");

			printf("Inserimento de uma nova capacidade do avião:");
			printf("\nInsira aqui: ");
			scanf("%d", &aviao[i].capacidade);
			while(aviao[i].capacidade <=0) {
				printf("Capacidade inválida, digite novamente: ");
				scanf("%d", &aviao[i].capacidade);
			}


		case 4:
			printf("alteração de nome do cliente\n");

			printf("Inserimento de um novo nome do cliente:");
			printf("\nInsira aqui: ");
			fflush(stdin);
			fgets(nome,64,stdin);
			while(nome[i] == '\n') {
				printf("nome inválido, digite novamente:");
				fflush(stdin);
				fgets(nome,64,stdin);
			}
			strcpy(aviao[i].nomeCliente,nome);


		case 5:
			printf("alteração de país de origem do cliente\n");

	}

	return opcao;
}

void validaCodigo(struct Aviao aviao[], int cont) {
	char codigo[8];
	int flag, i;
	do {
		flag = 0;
		printf("| Código de Identificação: ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		
		while(codigo[0] == '\n') {
			printf("codigo invalido, digite novamente:");
			fflush(stdin);
			fgets(codigo,8,stdin);
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
		for(i=0; i<MAX; i++) {
			if(stricmp(codigo,aviao[i].codigo) == 0) {
				printf("codigo já registrado, digite outro codigo");
				flag++;
			}
		}
		if(flag == 0) {
			printf("codigo registrado com sucesso");
			strcpy(aviao[cont].codigo,codigo);
			printf("\ncodigo do aviao : %s", aviao[cont].codigo);
		}
	} while(flag >= 1);
}
