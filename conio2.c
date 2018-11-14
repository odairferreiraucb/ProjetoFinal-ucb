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
void validaCodigo(struct Aviao aviao[]);
int alteracaoAviao(struct Aviao aviao[]);
int inclusaoPista (struct PistaTeste pistaTeste[] ,int codigoSeguemcial);
int mostraMenuAviao ();
int mostraMenuPista ();
int mostrarMenuTeste ();
int mostrarAlteracaoAviao();
int mostrarMenuPrimcipal();

int main(void) {
int resp,continuar ;
int codigoSeguemcial ;
char tecla;
    int i, opcao;
	setlocale(LC_ALL, "");
int tempo = clock(); //começa a contar o tempo
while(clock() - tempo < 3000){ //enquanto não se passaram 5segundos
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

while(clock() - tempo < 3000){ //enquanto não se passaram 5segundos
}
}
codigoSeguemcial = 1000 ;

do{
opcao = mostrarMenuPrimcipal ();
    if (tecla == 27)
       opcao = 0; // Indicando que saiu do menu sem escolher
    textcolor(15);
    textbackground(0);
    if (opcao == 1){
   	 textcolor(7);
      	textbackground(0);
    	gotoxy(5, 3);
    	   fflush(stdin);
    	   
    		opcao=mostraMenuAviao ();	
    			
    	
	if (opcao == 1){
		do{
			system("cls");
			inclusaoAviao(aviao);
			printf ("Deseja continuar ?\nComtinuar [0]-Parar [1]");
			scanf ("%i",&resp);
		
			 if (resp == 1){
				opcao=4;
			}
	 
		}while(resp == 0);
		}else if (opcao == 2){
			system("cls");
				gotoxy(5, 3);
					opcao = alteracaoAviao(aviao);
					if (opcao == 0 ){
					
					resp = mostrarAlteracaoAviao();
				}
					if (resp == 6){
						opcao=4;
					}
		}
		
}else if (opcao == 2){

	 textcolor(7);
       textbackground(0);
       	gotoxy(5, 3);
 	opcao =	mostraMenuPista();
 		
	 if (opcao == 3){
	 opcao = 4;
	 
		}else if (opcao == 1){
			do{
			
			system("cls");
			codigoSeguemcial=inclusaoPista (pistaTeste,codigoSeguemcial);
			
			printf ("Deseja continuar ?\nComtinuar [0]-Parar [1]");
			scanf ("%i",&resp);
		
			 if (resp == 1){
				opcao = 4;
			}
		}while (resp == 0);
			
	}
		
		
		

   
	
}else if (opcao == 3){
	 textcolor(7);
       textbackground(0);
		resp =	mostrarMenuTeste();
		if (resp == 4){
			opcao=4;
		}
			

	
	}else if (opcao == 4){
			system("cls");
		
			gotoxy(5, 3);
			printf ("<< O B R I G A D O >>");
			break;
	}

}while(opcao == 4);
return 0 ;
}

int mostrarMenuPrimcipal(){
setlocale(LC_ALL, "C");
  char tecla;
    int i, opcao;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    
	clrscr();
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
       gotoxy(34,14);printf("  sair      ");
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              case 4: gotoxy(34,14);printf("->"); break;
              
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


int mostrarMenuTeste (){
	
setlocale(LC_ALL, "C");
char tecla;
    int i, opcao;
    textbackground(0); // Define cor de fundo
    clrscr();          // Limpa a tela
    _setcursortype(0); // Desliga o cursor
    textcolor(15);     // Define cor de face
    
    gotoxy(19,6); printf("           <<<  P I S T A - T E S T E   >>>");
    // DESENHAR UM QUADRADO
    // Desenha as linhas horizontais do quadrado
    textcolor(7);
    for (i=34;i<=50;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(50,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(50,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(50,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR TESTE");
       gotoxy(34,12);printf("  ALTERAR TESTE");
       gotoxy(34,13);printf("  EXCLUIR TESTE");
       gotoxy(34,14);printf("  VOLTAR AO MENU");
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
            case 4: gotoxy(34,14);printf("->"); break;
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
    for (i=34;i<=50;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(50,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(50,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(50,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR PISTA");
       gotoxy(34,12);printf("  ALTERAR PISTA");
      gotoxy(34,13);printf("  VOLTAR AO MENU");
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
    textbackground(0);
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
    for (i=34;i<=51;i++) {
        gotoxy(i,9);printf("%c", 196);
        gotoxy(i,18);printf("%c", 196);
    }
    // Desenha as linhas verticais do quadrado
    for (i=9;i<=17;i++) {
        gotoxy(33,i);printf("%c", 179);
        gotoxy(51,i);printf("%c", 179);
    }
    // Desenha os quanto cantos do quadrado
    gotoxy(33,9);printf("%c", 218);
    gotoxy(51,9);printf("%c", 191);
    gotoxy(33,18);printf("%c", 192);
    gotoxy(51,18);printf("%c", 217);

    // OPERACAO DO MENU
    opcao = 1; // Seleciona a primeira opcao do menu
    do {
    	setlocale(LC_ALL, "");
       textcolor(7);
       textbackground(0);
       gotoxy(34,11);printf("  INCLUIR AVIÃO");
       gotoxy(34,12);printf("  ALTERAR AVIAO");
       gotoxy(34,13);printf("  EXCLUIR AVIAO");
       gotoxy(34,14);printf("  VOLTAR AO MENU");
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
              case 1: gotoxy(34,11);printf("->"); break;
              case 2: gotoxy(34,12);printf("->"); break;
              case 3: gotoxy(34,13);printf("->"); break;
              case 4: gotoxy(34,14);printf("->"); break;
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

int inclusaoPista (struct PistaTeste pistaTeste[],int codigoSeguemcial ) {
		  textcolor(7);
    textbackground(0);
	int i;
	setlocale(LC_ALL, "C");
		printf ("\t\t<< I N C L U S A O  P I S T A >>>\n");
		printf ("|ENDEREÇO :\n");
	
		fgets (pistaTeste[0].enderecoPista,128,stdin);
		printf ("|UF da pista:\n");
		fgets (pistaTeste[0].uf,2,stdin);
		fflush(stdin);
	do{
		printf ("|Tamanho do circuito (km) :");
		scanf ("%f",&pistaTeste[0].tamanhoCircuito);
}while (pistaTeste[0].tamanhoCircuito < 0);
	printf ("|Velocidade maxima :\n");
	scanf ("%i",&pistaTeste[0].velocidadeMax);
	
	codigoSeguemcial =  codigoSeguemcial + 1;
	pistaTeste[0].codSequencial = codigoSeguemcial;
	printf ("O seu codico seguemcial e:\n ");
	printf ("%i",pistaTeste[0].codSequencial);
return codigoSeguemcial;
}



void inclusaoAviao(struct Aviao aviao[]){
char codigo[8];	
int i, flag;	
	 
	 
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
    
    gotoxy(19,6); printf("           <<<  P I S T A - T E S T E  >>>");
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
       gotoxy(34,16);printf("  VOLTAR AO MENU");
       
      
       // Escreve o item selecionado em destaque
      textcolor(15); 
       //textbackground(1);
       switch (opcao) {
            case 1: gotoxy(34,11);printf("->"); break;
            case 2: gotoxy(34,12);printf("->"); break;
            case 3: gotoxy(34,13);printf("->"); break;
            case 4: gotoxy(34,14);printf("->"); break;
            case 5: gotoxy(34,15);printf("->"); break;
            case 6: gotoxy(34,16);printf("->"); break;
              
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
int alteracaoAviao(struct Aviao aviao[]){
int retornoFuncao, i, posicao,resp,opcao;
char codigo[7], modelo[10], nome[64];	
do{
	//criar um for pra fazer a varredura  iqual no case um alteração ::gustavo 
 	system ("cls");
		printf ("informe sua codigo de indentificação : ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		
		system ("cls");
	
		if (strcmp(aviao[0].codigo,codigo) == 0) {
			
			textcolor(10);
		 	printf ("\t\tCODIGO VALIDO...\n\n");
		 	 system ("pause");
			system ("cls");
			i=0;
				
				printf ("|MODELDO AVIAO: %s\n",aviao[i].modelo);
				printf ("---------------------------|\n");
				printf ("|NOME DO CLIENTE : %s\n",aviao[i].nomeCliente);
				printf ("---------------------------|\n");
				printf ("|PAIS DO CLIENTE : %s\n",aviao[i].nomeCliente);
				printf ("---------------------------|\n");
				printf ("|CAPACIDADE DO AVIAO : %i\n",aviao[i].capacidade);
				printf ("---------------------------|\n");
				printf ("|CODIGO: %s",aviao[i].codigo);
				printf ("---------------------------|\n\n\n");
					 system ("pause");
			
			retornoFuncao = mostrarAlteracaoAviao();
			
		
		}else 
			
		  textcolor(12);
		  system ("cls");			 	
	      printf ("CODIGO INVALIDO\nTENTE NOVAMENTE\n\n");
	   
	      printf ("\n\nDeseja continuar ?\nComtinuar [0]-Parar [1]\n\n");
			scanf ("%i",&resp);
			   system ("pause");
	      if (resp == 1){
	      
	      	opcao=4;
	      	
		  }
		
	
	}while(resp == 0);
	
		switch(retornoFuncao){
		
	case 1:
		printf("alteração de código de identificação\n");
		printf("Inserimento de um novo código de id:");
		validaCodigo(aviao);
		
	case 2:
		printf("alteração de modelo do avião\n");
		
		printf("Inserimento de um novo modelo de avião:");
		printf("\nInsira aqui: ");
		fflush(stdin);
		fgets(modelo,10,stdin);
		while(modelo[0] == '\n'){
			printf("codigo invalido, digite novamente:");
			fflush(stdin);
			fgets(modelo,10,stdin);
		}
		strcpy(aviao[0].modelo,modelo);
		
	
	case 3:	
		printf("alteração de capacidade do avião\n");
		
		printf("Inserimento de uma nova capacidade do avião:");
		printf("\nInsira aqui: ");
		scanf("%d", &aviao[0].capacidade);
		while(aviao[0].capacidade <=0){
			printf("Capacidade inválida, digite novamente: ");
			scanf("%d", &aviao[0].capacidade);
		}
	
	
	case 4:
		printf("alteração de nome do cliente\n");
		
		printf("Inserimento de um novo nome do cliente:");
		printf("\nInsira aqui: ");
		fflush(stdin);
		fgets(nome,64,stdin);
		while(nome[0] == '\n'){
			printf("nome inválido, digite novamente:");
			fflush(stdin);
			fgets(nome,64,stdin);
		}
		strcpy(aviao[0].nomeCliente,nome);
		
		
	case 5:
		printf("alteração de país de origem do cliente\n");
		
	}

	return opcao;
}

void validaCodigo(struct Aviao aviao[]){
char codigo[8];
int flag, i;	
	do{
		flag = 0;
		printf("| Código de Identificação: ");
		fflush(stdin);
		fgets(codigo,8,stdin);
		while(codigo[0] == '\n'){
			printf("codigo invalido, digite novamente:");
			fflush(stdin);
			fgets(codigo,8,stdin);
		}
		if((codigo[0] >=65 && codigo[0] <=90) || (codigo[0] >=97 && codigo[0] <=122 )){
			if((codigo[1] >=65 && codigo[1] <=90) || (codigo[1] >=97 && codigo[1] <=122 )){
				if((codigo[2] >=65 && codigo[2] <=90) || (codigo[2] >=97 && codigo[2] <=122 )){
					if(codigo[3] >=48 && codigo[3] <=57){
						if(codigo[4] >=48 && codigo[4] <=57){
							if(codigo[5] >=48 && codigo[5] <=57){
								if(codigo[6] >=48 && codigo[6] <=57){
									
								}else{
									printf("codigo invalido, verifique e tente novamente: ");
									flag++;
								}
							}else{
								printf("codigo invalido, verifique e tente novamente: ");
								flag++;
							}
						}else{
							printf("codigo invalido, verifique e tente novamente: ");
							flag++;
						}	
					}else{
						printf("codigo invalido, verifique e tente novamente: ");
						flag++;
					}
				}else{printf("codigo invalido, verifique e tente novamente: ");
					flag++;
				}
			}else{
				printf("codigo invalido, verifique e tente novamente: ");
				flag++;
			}
		}else{
			printf("codigo invalido, verifique e tente novamente: ");
			flag++;
		}
		for(i=0;i<MAX;i++){
			if(stricmp(codigo,aviao[i].codigo) == 0){
				printf("codigo já registrado, digite outro codigo");
				flag++;
			}			
		}
		if(flag == 0){
			printf("codigo registrado com sucesso");
			strcpy(aviao[0].codigo,codigo);
		}
	}while(flag >= 1);	
}
