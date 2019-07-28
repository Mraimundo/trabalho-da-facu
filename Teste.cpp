#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char nome[50];

void gotoxy (int x, int y){


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), 	(COORD) {x,y});	
	
}
int main (){
int i, a=1;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
saved_attributes = consoleInfo.wAttributes;

SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....	
	 for(i=45; i<75; i++){
	 	gotoxy(i, 1); printf("%c",47);
	 	gotoxy(i, 5); printf("%c",47);
	 }
	
	 for(i=2; i<5; i++){
	 	gotoxy(45, i); printf("%c",47);
	 	gotoxy(74, i); printf("%c",47);
	 }

 
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................

// Essa Estrutura cria uma caixa ou box de Menu .........
	gotoxy(50, 9); printf("MENU FUNCIONARIO\n\n");
	gotoxy(21, 11); printf("\tEscolha pelo numero a opercação que quer realizar\n\n");
	
	// Cria a Box ou caixa de menu do administrador ..............................
	for(i=20; i<100; i++){
		gotoxy(i, 7); printf("%c",47);
		gotoxy(i, 37); printf("%c",47);
	}
	
	for(i=8; i<37; i++){
		gotoxy(20, i); printf("%c",47);
		gotoxy(99,i); printf("%c",47);
	}// fim da Box de menu Funcionaario ........................

	// cria as boxs ou caixas de dentro do menu contendo as opções case 1 .................
for(i=24; i<53; i++){
 	gotoxy(i,14); printf("-");
 	gotoxy(i,16); printf("-");
 }

	for(i=16; i<17; i++){
 	gotoxy(24, 15); printf("-");
 	gotoxy(52, 15); printf("-");
 }
 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(28, 15); printf("1-LISTA DE CARROS\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................

for(i=58; i<95; i++){
 	gotoxy(i,14); printf("-");
 	gotoxy(i,16); printf("-");
 }

	for(i=16; i<17; i++){
 	gotoxy(58, 15); printf("-");
 	gotoxy(94, 15); printf("-");
 }
 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(65, 15); printf("2-CADASTRAR CLIENTE\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 for(i=24; i<53; i++){
 	gotoxy(i,18); printf("-");
 	gotoxy(i,20); printf("-");
 }

	for(i=19; i<21; i++){
 	gotoxy(24, 19); printf("-");
 	gotoxy(52, 19); printf("-");
 }

 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(28, 19); printf("3-LOCAÇÃO DE CARROS\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 for(i=58; i<95; i++){
 	gotoxy(i,18); printf("-");
 	gotoxy(i,20); printf("-");
 }

	for(i=16; i<17; i++){
 	gotoxy(58, 19); printf("-");
 	gotoxy(94, 19); printf("-");
 }

 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(65, 19); printf("4-DEVOLUÇÃO DE CARROS\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 for(i=24; i<53; i++){
 	gotoxy(i,22); printf("-");
 	gotoxy(i,24); printf("-");
 }

for(i=23; i<25; i++){
 	gotoxy(24, 23); printf("-");
 	gotoxy(52, 23); printf("-");
 }

 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(28, 23); printf("5-VER RELATÓRIOS\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 for(i=58; i<95; i++){
 	gotoxy(i,22); printf("-");
 	gotoxy(i,24); printf("-");
 }

	for(i=16; i<17; i++){
 	gotoxy(58, 23); printf("-");
 	gotoxy(94, 23); printf("-");
 }

 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(65, 23); printf("6-DEVOLUÇÃO DE CARROS\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 for(i=24; i<53; i++){
 	gotoxy(i,26); printf("-");
 	gotoxy(i,28); printf("-");
 }

for(i=27; i<29; i++){
 	gotoxy(24, 27); printf("-");
 	gotoxy(52, 27); printf("-");
 }

 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
 gotoxy(28, 27); printf("7-ENCERRAR O PROGRAMA\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................

 // inicio da Box onde aparece o numero ou opção escolhida ...........
 for(i=68; i<84; i++){
 	gotoxy(i,26); printf("-");
 	gotoxy(i,31); printf("-");
 }

for(i=27; i<31; i++){
 	gotoxy(68, i); printf("-");
 	gotoxy(83, i); printf("-");
 }// fim da box
 
 				for(i=10; i<110; i++){
					gotoxy(i, 7); printf("%c",47);
					gotoxy(i, 32); printf("%c",47);
				}
				
				for(i=8; i<32; i++){
					gotoxy(10, i); printf("%c",47);
					gotoxy(109,i); printf("%c",47);
						
				} // fim da box .......................
				
				gotoxy(50, 9);printf("CADASTRO DE FUNCIONÁRIOS\n\n.");
				
				gotoxy(12, 11);printf("NOME COMPLETO:: ");
				fflush(stdin);
				gets(nome);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"NOME DO FUNCIONÁRIO:\t %s",(nome));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 13);printf("DATA DE NASCIMENTO:: ");
				fflush(stdin);
				gets(nascimento);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"DATA DE NASCIMENTO:\t %s",(nascimento));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 15);printf("NATURALIDADE:: ");
				fflush(stdin);
				scanf("%s",&naturalidade);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"NATURALIDADE:\t %s",(naturalidade));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 17);printf("CIDADE:: ");
				fflush(stdin);
				gets(cidade);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"CIDADE:\t %s",(cidade));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 19);printf("EMAIL:: ");
				fflush(stdin);
				gets(email);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"EMAIL:\t %s",(email));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 21);printf("NÚMERO DO RG:: ");
				fflush(stdin);
				gets(rg);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"NÚMERO DO RG:\t %s",(rg));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 23);printf("NÚMERO DO CPF:: ");
				fflush(stdin);
				gets(cpf);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"NÚMERO DO CPF:\t %s",(cpf));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 25);printf("NÚMERO DE TELEFONE:: ");
				fflush(stdin);
				gets(telefone);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"NÚMERO DE TELEFONE:\t %s",(telefone));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				
				gotoxy(12, 27);printf("FUNÇÃO:: ");
				fflush(stdin);
				gets(funcao);
				fflush(stdin);
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"FUNÇÃO:\t %s",(funcao));
				fprintf(cadastro_func,"\n");
				fclose(cadastro_func);
				gotoxy(12, 28);// coloca o cursor dentro da box ou caixa....
				cadastro_func=fopen("Arquivo_Admin\\cadastro_funcionario.txt", "a");
				fprintf(cadastro_func,"\nFim do Cadastro do Funcionário\n");
				fprintf(cadastro_func, "...............\t...............\t..................\t......................\n");
				fclose(cadastro_func);	
				
				Sleep(1000);
				gotoxy(12, 28);// coloca o cursor dentro da box ou caixa....
				gotoxy(50, 29);printf("Cadastro feito com Sucesso!\n");
				gotoxy(12, 28);// coloca o cursor dentro da box ou caixa....
				Sleep(1500);
	
				system("cls");			
			}
 }//////////// fim da box...........................
 
    
