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
#define MAX 50


//structs
struct Aviao {
	char codigo[7];
	char modelo[10];
	int capacidade;
	char nomeCliente[64];
	char paisOrigCliente[32];
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
	char data[8];
	int velocidadeMax;
};

// declarando as structs
struct Aviao aviao[MAX];
struct PistaTeste pistaTeste[MAX];
struct Testes testes[MAX];

//prototipos das funções
void inclusaoAviao(struct Aviao aviao[]);
void alteracaoAviao(struct Aviao aviao[]);
void inclusaoPista (struct PistaTeste pistaTeste[] ,int codigoSeguemcial);
int mostraMenuAviao ();
int mostraMenuPista ();
int mostrarMenuTeste ();
int mostrarAlteracaoAviao();


int main(void) {
int resp,continuar ;
int codigoSeguemcial ;

codigoSeguemcial = 1000 ;

    char tecla;
    int i, opcao;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    do {
    
    gotoxy(19,6); printf("           <<<   M E N U   >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
   
    	setlocale(LC_ALL, "C");
    for (i=34;i<=45;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(46,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(46,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(46,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  Menu Avião");
       gotoxy(34,12);printf("  Menu Pista");
       gotoxy(34,13);printf("  Menu Teste");
      
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              
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
    if (tecla == 27)
       opcao = 0; // Indicando que saiu do menu sem escolher
    textcolor(15);
    textbackground(7);
    if (opcao == 1){
    	 textcolor(7);
      		 textbackground(0);
    			gotoxy(5, 3);
    	   fflush(stdin);
    	   
    			 opcao=mostraMenuAviao ();	
    			 printf ("%i",opcao);
    	
	if (opcao == 1){
	
		system("cls");
		inclusaoAviao(aviao);
	}else if (opcao == 2){
		system("cls");
		
			gotoxy(5, 3);
				alteracaoAviao(aviao);
	}
	
	
		printf ("para continuar aperte [0]" );
		scanf ("%d",&continuar);

    fflush(stdin);
    getch();
    	system ("cls");
    return 0;
}else if (opcao == 2){
	
	 textcolor(7);
       textbackground(0);
       	gotoxy(5, 3);
			mostraMenuPista();
		
		if (opcao == 1){
			
			system("cls");
			inclusaoPista (pistaTeste,codigoSeguemcial);
			
		}
		
		printf ("para continuar aperte [0]" );
		scanf ("%d",&continuar);

    fflush(stdin);
    getch();
    	system ("cls");
    return 0;
	
}else if (opcao == 3){
	 textcolor(7);
       textbackground(0);
	mostrarMenuTeste();
		
			
	printf ("para continuar aperte [0]" );
	scanf ("%d",&continuar);
	
	}
}while(continuar == 0);
return 0 ;
}
int mostrarMenuTeste (){
	
setlocale(LC_ALL, "C");
char tecla;
    int i, opcao;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    gotoxy(19,6); printf("           <<<  A V I A O   >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
    for (i=34;i<=49;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(49,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(49,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(49,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR TESTE");
       gotoxy(34,12);printf("  ALTERAR TESTE");
       gotoxy(34,13);printf("  EXCLUIR TESTE");
      
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              
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

int mostraMenuPista (){
	
		setlocale(LC_ALL, "C");
char tecla;
    int i, opcao;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    gotoxy(19,6); printf("           <<<  P I S T A  >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
    for (i=34;i<=49;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(49,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(49,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(49,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR PISTA");
       gotoxy(34,12);printf("  ALTERAR PISTA");
     
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
          
              
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
int mostraMenuAviao (){
	setlocale(LC_ALL, "C");
char tecla;
    int i, opcao,resp;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    gotoxy(19,6); printf("           <<<  A V I A O   >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
    for (i=34;i<=49;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(49,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(49,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(49,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR AVIÃO");
       gotoxy(34,12);printf("  ALTERAR AVIAO");
       gotoxy(34,13);printf("  EXCLUIR AVIAO");
      
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              
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
    
return opcao;
}

void inclusaoPista (struct PistaTeste pistaTeste[],int codigoSeguemcial ) {
		
	int i;

		printf ("\t\t<< I N C L U S A O  P I S T A >>>\n");
		printf ("|ENDEREÇO :\n");
		fflush(stdin);
		fgets (pistaTeste[i].enderecoPista,128,stdin);
		printf ("|UF da pista:\n");
		fgets (pistaTeste[i].uf,2,stdin);
		fflush(stdin);
	do{
		printf ("|Tamanho do circuito (km) :");
		scanf ("%f",&pistaTeste[i].tamanhoCircuito);
}while (pistaTeste[i].tamanhoCircuito < 0);
	printf ("|Velocidade maxima :\n");
	scanf ("%i",&pistaTeste[i].velocidadeMax);
	
	codigoSeguemcial =  codigoSeguemcial + 1;
	pistaTeste[i].codSequencial = codigoSeguemcial;
	printf ("%i\n",pistaTeste[i].codSequencial);

}



void inclusaoAviao(struct Aviao aviao[]){
char codigo[8];	
int i, flag;	
	 textcolor(0);
	 
	printf("\t\tINCLUSAO DE AVIAO");
	printf("\n\n");

	do{
		flag = 0;
		printf("|Identificação: ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		while(codigo[0] == '\n'){
			printf("codigo invalido, digite novamente:");
			fflush(stdin);
			fgets(codigo,8,stdin);
		}
		for(i=0;i<MAX;i++){
			if(stricmp(codigo,aviao[i].codigo) == 0){
				printf("codigo já registrado, digite outro codigo");
				flag++;
			}			
		}
		if(flag == 0){
			strcpy(aviao[0].codigo,codigo);
		}
			
	}while(flag == 1);
	printf("|Codigo do aviao: %s", aviao[0].codigo);//


	printf("\n");
	printf("|Digite o modelo do aviao:");
	fflush(stdin);
	fgets(aviao[0].modelo,11,stdin);
	while(aviao[0].modelo[0] == '\n'){
			printf("|Modelo invalido, digite novamente:");
			fflush(stdin);
			fgets(aviao[0].modelo,11,stdin);
	}
	printf("|Modelo do aviao: %s", aviao[0].modelo);//
	
	
	printf("\n");
	printf("|Digite a capacidade de passageiros do aviao: ");
	scanf("%d", &aviao[0].capacidade);
	while(aviao[0].capacidade <= 0){
		printf("|Codigo invalido, digite novamente:");
		scanf("%d", &aviao[0].capacidade);	
	}
	printf("|Capacidade do aviao: %d passageiros",aviao[0].capacidade);//


	printf("\n");
	printf("|Digite o nome do cliente: ");
	fflush(stdin);
	fgets(aviao[0].nomeCliente,64,stdin);
	while(aviao[0].nomeCliente[0] == '\n'){
			printf("|Nome inválido, digite novamente:");
			fflush(stdin);
			fgets(aviao[0].nomeCliente,64,stdin);
	}
	printf("|Nome do cliente : %s", aviao[0].nomeCliente);//
	
	
	printf("\n");
	printf("|Digite o país de origem do cliente: ");
	fflush(stdin);
	fgets(aviao[0].paisOrigCliente,32,stdin);
	printf("|País do cliente : %s", aviao[0].paisOrigCliente);	//
}
int mostrarAlteracaoAviao(){
		setlocale(LC_ALL, "C");
char tecla;
    int i, opcao,resp;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    gotoxy(19,6); printf("           <<<  A V I A O   >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
    for (i=34;i<=60;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(60,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(60,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(60,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  AlTERAR CODIGO");
       gotoxy(34,12);printf("  ALTERAR MODELO");
       gotoxy(34,13);printf("  AlTERAR CAPACIDADE");
	   gotoxy(34,14);printf("  AlTERAR NOME CLIENTE:");
       gotoxy(34,15);printf("  AlTERAR PAIS DO CLIENTE:");
      
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              case 4: gotoxy(34,14);printf("->"); break;
              case 5: gotoxy(34,15);printf("->"); break;
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
    

	return opcao;
}
void alteracaoAviao(struct Aviao aviao[]){
int retornoFuncao;	
	retornoFuncao=mostrarAlteracaoAviao();
	
}


	
	

