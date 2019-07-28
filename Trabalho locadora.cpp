#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define ENTER 13

char usuario[50], senha[50], receptor[]="login_func.txt", funcionario[50], senha_funcionario[50],receptor3[]="cadastro_clientes.txt";
char administrador[50], senha_administrador[50], receptor2[]="login_administrador.txt", lista_carros[1000];
char email[50], naturalidade[50], nome[100], rg[20], nascimento[20], cidade[30], telefone[20], cpf[20], registro_cliente[50],carteira_motorista[50];
char dias[20], receptor4[]="locacao.txt", data[20], datadevolucao[20], marcamatricula[50], pagamento[20];
char receptor5[]="devolucao.txt", relatorio_cadastro[1000], funcao[50], marca[50];
char relatorio_locacao[1000], relatorio_devolucao[1000], multas[500];
int contador=0, escolha=0, multadanos, multatransito, multatanque, multaatraso=600, total, dias_de_atraso, preco;


// função gotoxy, deixa o cursor nas coordenadas pretendidas em função dos eixos x e y............
	void gotoxy (int x, int y)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), 	(COORD) {x,y});	
	
	}

// função contendo o painel de login......................................

void painel_login(){
int i, a=1;
char ch;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

// Salvar estado atual 
GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
saved_attributes = consoleInfo.wAttributes;

setlocale(LC_ALL, "Portuguese");
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
 for(i=45; i<75; i++){
 	gotoxy(i,1); printf("%c",47);
 	gotoxy(i,5); printf("%c",47);
 }
 
 for(i=2; i<5; i++){
 	gotoxy(45, i); printf("%c",47);
 	gotoxy(74, i); printf("%c",47);
 }
 
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // coloca cor verde na string abaixo......
 gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

SetConsoleTextAttribute(hConsole, saved_attributes); // voltar para a cor padrão ..................

//cria a box ou caixa do login .................
for(i=30; i<90; i++){
		gotoxy(i, 7); printf("%c",47);
		gotoxy(i, 20); printf("%c",47);
	}

	for(i=8; i<20; i++){
		gotoxy(30, i); printf("%c",47);
		gotoxy(89,i); printf("%c", 47);
	}//fim da box ou caixa do login .................
   	  
SetConsoleTextAttribute(hConsole, saved_attributes); // voltar para a cor padrão ..................
gotoxy(32, 9); printf("\tDIGITE O SEU NOME DE USUÁRIO E SUA SENHA::\n\n");

SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); //coloca cor Verde na string usuario........
gotoxy(31, 11); printf("\tUSUÁRIO:: ");
fflush(stdin);
SetConsoleTextAttribute(hConsole, saved_attributes); // voltar para a cor padrão .....................
gets(usuario);
fflush(stdin);
gotoxy(31, 12); printf("\n");
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); //coloca cor Verde na string usuario........
gotoxy(31, 13); printf("\tSENHA::\t");
SetConsoleTextAttribute(hConsole, saved_attributes); // voltar para a cor padrão .....................
fflush(stdin);
gets(senha);
fflush(stdin);

// função ocultar senha  do usuario ..................
/*while(1){

	ch=getch();
	if(ch==ENTER){
		break;
	}
	
	else{
		senha[a]=ch;
		a++;
		printf("*");
	}	
} */ // fim da função ocultar senha .....................

system("cls");
}

//função contendo o painel de boas vindas...................................

void painel_bemvindo(){
int i, a;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Salvar estado atual 
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....	
for(i=45; i<75; i++){
 	gotoxy(i,1); printf("%c",47);
 	gotoxy(i,5); printf("%c",47);
 }
 
 for(i=2; i<5; i++){
 	gotoxy(45, i); printf("%c",47);
 	gotoxy(74, i); printf("%c",47);
 }
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

	SetConsoleTextAttribute(hConsole, saved_attributes); // volta a cor padrão...............
	
	printf("\n\n\n\n\n\n\t\t\t\t\t\tBem-vindo e Bom Trabalho!\n\n");
	printf("\n\t\t\tCarregando Sistema.\n\n");
	
	//cria a barra de carregamento ...........
	for(a=0; a<80; a++){
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // colocar cor Azul na string abaixo......	
	printf("|");
	Sleep(30);
	}
	system("cls"); 
	SetConsoleTextAttribute(hConsole, saved_attributes); // volta a cor padrão...............
} ///////// fim da funçaõ


//função pega a hora e data atual do sistema...........
void datahora(){
	
int mes, ano, dia, segundo, hora, minuto;

struct tm *local;
time_t t;
t= time(NULL);
local=localtime(&t);

dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;
hora=local->tm_hour;
minuto=local->tm_min;
segundo=local->tm_sec;

  gotoxy(36, 34);printf("Data Atual: %d/%d/%d",dia,mes,ano); // Retorna a data
  gotoxy(65, 34);printf("Hora Atual: %d: %d: %d", hora, minuto, segundo);// Retorna a hora
  
	
}//fim da função data  e hora  ..................


//função contendo o MENU do Funcionário........................

void menu_funcionario() {
a:
	int i;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	
	// Salvar estado atual 
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
for(i=45; i<75; i++){
 	gotoxy(i,1); printf("%c",47);
 	gotoxy(i,5); printf("%c",47);
 }
 
 for(i=2; i<5; i++){
 	gotoxy(45, i); printf("%c",47);
 	gotoxy(74, i); printf("%c",47);
 }
 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);

	// Essa Estrutura cria uma caixa ou box de Menu .........
	gotoxy(50, 9); printf("MENU FUNCIONARIO\n\n");
	gotoxy(21, 11); printf("\tEscolha pelo numero a opercação que quer realizar\n\n");
	
	// Cria a Box ou caixa de menu do Funcionario ..............................
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
}
//////////// fim da box...........................
 
     datahora(); //Chamada da função data e hora do sistema .....................
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
	gotoxy(75, 28);scanf("%d", &escolha); //coloca o cursor dentro da caixa de escolha
	
	SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
	system("cls");
	
	//opção de escolha das operação a serem realizadas com a base a escolha do usuário
	
	switch(escolha){
			 
		 // inicio da case 1 .........................................................
case 1: {
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		printf("\n\n\n\n\n\n\tLISTA DE CARROS DISPONIVEIS PARA LOCAÇÃO::\n");
		
		FILE*file;
		file=fopen("lista_carros.txt","r");
		
		if(file==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		break;
		}
		
		while(fgets(lista_carros, 1000,file)!=NULL){
			printf("\n\t%s",lista_carros);
		}
		fclose(file);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto a;
		break;
		}
		
		// inicio da casa 2....................................................................
case 2: { 
			system("cls");
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		for(i=10; i<110; i++){
					gotoxy(i, 7); printf("%c",47);
					gotoxy(i, 32); printf("%c",47);
				}
				
		for(i=8; i<32; i++){
					gotoxy(10, i); printf("%c",47);
					gotoxy(109,i); printf("%c",47);
				}
			
			
		gotoxy(50, 9);printf("\n\n\n\n\n\n\tCADASTRAR CLIENTES.\n");
			
		FILE*cadastro_clientes;
		cadastro_clientes = fopen(receptor3,"a");

		if(cadastro_clientes == NULL){
			printf("\nErro! O arquivo não existe e não pode ser aberto!.\n");
			Sleep(1500);
			system("cls");
		}
		else{
		gotoxy(12, 11);printf("NOME::");
		fflush(stdin);
		gets(nome);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"NOME:\t %s",(nome));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 13);printf("DATA DE NASCIMENTO::");
		fflush(stdin);
		gets(nascimento);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"DATA DE NASCIMENTO:\t %s",(nascimento));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 15);printf("NATURALIDADE::");
		fflush(stdin);
		scanf("%s",&naturalidade);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"NATURALIDADE:\t %s",(naturalidade));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 17);printf("CIDADE::");
		fflush(stdin);
		gets(cidade);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3, "a");
		fprintf(cadastro_clientes,"CIDADE:\t %s",(cidade));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 19);printf("EMAIL::");
		fflush(stdin);
		gets(email);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"EMAIL:\t %s",(email));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 21);printf("NÚMERO DO RG::");
		fflush(stdin);
		gets(rg);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"NÚMERO DO RG:\t %s",(rg));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 23);printf("NÚMERO DO CPF::");
		fflush(stdin);
		gets(cpf);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"NÚMERO DO CPF:\t %s",(cpf));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 25);printf("NÚMERO DE TELEFONE::");
		fflush(stdin);
		gets(telefone);
		fflush(stdin);
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes,"NÚMERO DE TELEFONE: %s",(telefone));
		fprintf(cadastro_clientes,"\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 27);printf("CARTEIRA DE MOTORISTA::");
		fflush(stdin);
		gets(carteira_motorista);
		cadastro_clientes=fopen(receptor3, "a");
		fprintf(cadastro_clientes, "CARTEIRA DE MOTORISTA:\t %s",(carteira_motorista));
		fprintf(cadastro_clientes, "\n");
		fclose(cadastro_clientes);
		
		gotoxy(12, 29);printf("Nº de REGISTRO DE CLIENTE (RC)::");
		fflush(stdin);
		gets(registro_cliente);
		cadastro_clientes=fopen(receptor3, "a");
		fprintf(cadastro_clientes, "Nº DE REGISTRO DE CLIENTE (RC):\t %s",(registro_cliente));
		fprintf(cadastro_clientes, "\n");
		fclose(cadastro_clientes);
		
		cadastro_clientes=fopen(receptor3,"a");
		fprintf(cadastro_clientes, "...............\t...............\t..................\t......................\n");
		fclose(cadastro_clientes);	
		
		system("cls"); 
		printf("\n\n\t\t\t\t\t\tCadastro Feito com Sucesso!\n");
		Sleep(1500);
		system("cls");
		}		
		
		printf("\n\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto a;
		break;
	} // fim da case 2 ................................................
		
		//inicio da case 3 ..................... 
	case 3:{
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
			
		printf("\n\n\n\n\n\n\tLOCAÇÃO DE CARROS::\n");
		
		FILE*locacao;
		locacao=fopen(receptor4, "a");
		
		if(locacao ==NULL){
		printf("\n\tErro! O arquivo não existe e não pode ser aberto!.\n");
		Sleep(1500);
		system("cls");
		}
		
		else{
		printf("\n\tNº de Registro de Cliente (RC)::\t");
		fflush(stdin);
		gets(registro_cliente);
		fflush(stdin);
		locacao=fopen(receptor4,"a");
		fprintf(locacao,"Nº de Registro de Cliente (RC):\t %s",(registro_cliente));
		fprintf(locacao,"\n");
		fclose(locacao);
		
		printf("\n\tQUANTIDADE DE DIAS::\t");
		fflush(stdin);
		gets(dias);
		fflush(stdin);
		locacao=fopen(receptor4, "a");
		fprintf(locacao, "QUANTIDADE DE DIAS::\t %s", (dias));	
		fprintf(locacao, "\n");
		fclose(locacao);
		
		printf("\n\tDATA DE LOCAÇÃO E HORA::\t");
		fflush(stdin);
		gets(data);
		fflush(stdin);
		locacao=fopen(receptor4, "a");
		fprintf(locacao, "DATA DE LOCAÇÃO E HORA::\t %s", (data));
		fprintf(locacao, "\n");
		fclose(locacao);
		
		printf("\n\tDATA PREVISTA DE DEVOLUÇÃO::\t");
		fflush(stdin);
		gets(datadevolucao);
		fflush(stdin);
		locacao=fopen(receptor4, "a");
		fprintf(locacao, "DATA DE PREVISTA DE DEVOLUÇÃO::\t %s", (datadevolucao));
		fprintf(locacao, "\n");
		fclose(locacao);
		
		printf("\n\tMARCA E MATRÍCULA DO CARRO::\t");
		fflush(stdin);
		gets(marcamatricula);
		fflush(stdin);
		locacao=fopen(receptor4, "a");
		fprintf(locacao, "MARCA E MATRÍCULA DO CARRO::\t %s", (marcamatricula));
		fprintf(locacao, "\n");
		fclose(locacao);
		
		printf("\n\tVALOR DO PAGAMENTO::\t");
		fflush(stdin);
		gets(pagamento);
		fflush(stdin);
		locacao=fopen(receptor4, "a");
		fprintf(locacao, "VALOR DO PAGAMENTO::\t %s", (pagamento));
		fprintf(locacao, "\n");
		fclose(locacao);
		
		locacao=fopen(receptor4,"a");
		fprintf(locacao, "...............\t...............\t..................\t......................\n");
		fclose(locacao);
	
		system("cls"); 
		printf("\n\n\t\t\t\t\t\tCadastro Feito com Sucesso!\n");
		Sleep(1500);
		system("cls");
		}		
		
		printf("\n\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto a;
		break;
		
	}// fim da case 3 .........................
		
	case 4:{
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(75, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		printf("\n\n\n\n\n\n\tDEVOLUÇÃO DE CARROS.\n\n");
		
		FILE*devolucao;
		devolucao=fopen(receptor5, "a");
		
		if(devolucao ==NULL){
		printf("\nErro! O arquivo não existe e não pode ser aberto!.\n");
		Sleep(1500);
		system("cls");
		}
		
		else{
			printf("\n\tNº de REGISTRO DE CLIENTE::\t");
			fflush(stdin);
			gets(registro_cliente);
			fflush(stdin);
			devolucao=fopen(receptor5, "a");
			fprintf(devolucao, "Nº de REGISTRO DE CLIENTE::\t %s\n",(registro_cliente));
			fprintf(devolucao, "\n");
			fclose(devolucao);
			
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); //coloca cor vermelha nas strings abaixo........
			printf("\n\nAtenção aos Seguintes Dados de Infração!\n");
			printf("\n\tPara 'SIM' Prima a tecla '1' e Para 'NÂO' prima a tecla '0'\n");
			Sleep(2500);
			system("cls");
			
			SetConsoleTextAttribute(hConsole, saved_attributes); //volta para a cor padrão..............
			printf("\n\tAtraso na Devolução?\n");
			scanf("%d", &escolha);
			
			if(escolha==1){
				//declaração de uma estrutura de repetição somadora da multa de atraso consoante os dias atrasados
				int a; 
				
				printf("\n\tMulta de atraso\n");
				printf("\n\tQuantos dias Atrasou?::\t");
				scanf("%d", &dias_de_atraso);
				
				for(a=0; a<=dias_de_atraso; a++){
					total=multaatraso*a;
				}// fim da estrutura de repetição somadora da multa de atraso consoante os dias atrasados
				
			}
				else if(escolha==0){
				printf("\n\tPrima Qualquer Tecla para Continuar!\n");
				getch();
				system("cls");
					
				}
					
			printf("\n\tHouve Danos?\n");
			scanf("%d", &escolha);
			if(escolha==1){
				printf("\n\tDigite o Valor da multa por Danos:: ");
				fflush(stdin);
				scanf("%d", &multadanos);
				fflush(stdin);
			}
			else if(escolha==0){
				printf("\n\tPrima Qualquer Tecla para Continuar!\n");
				getch();
				system("cls");
				}
				
			printf("\n\tHouve Multa de Trânsito?\n");
			scanf("%d", &escolha);
			if(escolha==1){
				printf("\n\tDigite o Valor da multa de Trânsito::");
				fflush(stdin);
				scanf("%d", &multatransito);
				fflush(stdin);	
			}
			else if(escolha==0){
				printf("\n\tPrima Qualquer Tecla para Continuar!\n");
				getch();
				system("cls");
				}
				
			printf("\n\tTanque de Combustível Vazio?\n");
			scanf("%d",&escolha);
			if(escolha==1){
				printf("\n\tDigite o Valor da multa de tanque Vazio::");
				fflush(stdin);
				scanf("%d", &multatanque);
				fflush(stdin);	
			}
			else if(escolha==0){
				printf("\n\tPrima Qualquer Tecla para Continuar!\n");
				getch();
				system("cls");
				}
				
			 if (escolha !=1 && escolha !=0) {
				printf("\n\tEscolha Entre '1 = SIM' ou '0= NAO'\n");
				}
			system("cls");
			
				// declaração da variavel total_juros que soma o valor de todas as multas e dá um valor  total
				int total_juros;
				char c[]="R$";
				
				total_juros=total+multadanos+multatransito+multatanque;
				// fim da declaração de total_juros
				
				devolucao=fopen(receptor5, "a");
				fprintf(devolucao, "MULTAS POR INFRAÇÕES::\n\n");
				fprintf(devolucao, "Multa por Atraso::\t %d\n", (total));
				fprintf(devolucao, "Multa por Danos::\t %d\n", (multadanos));
				fprintf(devolucao, "Multa por Atraso::\t %d\n", (multatransito));
				fprintf(devolucao, "Multa por Atraso::\t %d\n", (multatanque));
				fprintf(devolucao, "Total do Valor de Multas ou Juros::\t%d %s\n", (total_juros), (c));
				fprintf(devolucao, "\n\n");
				fclose(devolucao);
				
				printf("\n\tDATA E HORA DE DEVOLUÇÃO::\t");
				fflush(stdin);
				gets(datadevolucao);
				fflush(stdin);
				devolucao=fopen(receptor5, "a");
				fprintf(devolucao, "DATA E HORA DA DEVOLUÇAÕ:: %s\n", (datadevolucao));
				fprintf(devolucao, "\n");
				fclose(devolucao);
				
				devolucao=fopen(receptor5,"a");
				fprintf(devolucao, "Fim do Cadastro do Cliente\n");
				fprintf(devolucao, "...............\t...............\t..................\t......................\n\n");
				fclose(devolucao);		
			}
			
			system("cls"); 
			printf("\n\n\t\t\t\t\t\tCadastro Feito com Sucesso!\n");
			Sleep(1500);
			system("cls");
		}		
		
		printf("\n\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto a;
		break;	
		
	 // fim da case 4 ..........................
	
	//inicio da case  5 ..........................
case 5: {
b:
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		printf("\n\tRELATÓRIOS.\n\n");
		printf("\n\tEscolha pelo número o relatório que quer ver.\n");
		printf("\n\t1-Cadastro de Clientes\n2-Locação de Carros\n3-Devolução de Carros\n4-Sair\n\n");
	
		scanf("%d", &escolha);
		//inicio da escolha 1 .......
		if(escolha==1){

			FILE*relatorio1;
			relatorio1=fopen("cadastro_clientes.txt", "r");
			
		if(relatorio1==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			while(fgets(relatorio_cadastro, 1000, relatorio1) !=NULL){
				printf("\n\t%s",relatorio_cadastro);
			}
		fclose(relatorio1);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu.");
		getch();
		system("cls");
		goto b;
		break;
		}	
	
		}//fim da escolha 1........
	
	//inicio da escolha 2 ........
	else if(escolha==2){
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(75, i); printf("%c",47);
		 }
		
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		FILE*relatorio2;
		relatorio2=fopen("locacao.txt", "r");
			
		if(relatorio2==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			while(fgets(relatorio_locacao, 1000, relatorio2) !=NULL){
				printf("\n\t%s",relatorio_locacao);
			}
		fclose(relatorio2);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto b;
		break;
		}	
		
	}//fim da escolha 2 ......
	
	//inicio da escolha 3.......
	else if(escolha==3){
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(75, i); printf("%c",47);
		 }
		
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		FILE*relatorio3;
		relatorio3=fopen("devolucao.txt", "r");
			
		if(relatorio3==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			while(fgets(relatorio_devolucao, 1000, relatorio3) !=NULL){
				printf("\n\t%s",relatorio_devolucao);
			}
		fclose(relatorio3);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto b;
		break;
		}	
	}//fim da escolha 3 ..............
	
	else if(escolha==4){
		system("cls");
		goto a;
	}

	}//fim da case 5 .........	
	
	//inicio da case 6 :................
	case 6:{
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(75, i); printf("%c",47);
		 }
		 
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		printf("\n\n\n\n\n\n\tTABELA DE MULTAS POR INFRAÇÕES.\n\n");
		
		FILE*multa;
		multa=fopen("multas.txt","r");
		
		if(multa==NULL){
		printf("\n\tErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto a;
		break;
		}
		
		while(fgets(multas, 500,multa)!=NULL){
			printf("\n\t%s",multas);
		}
		fclose(multa);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto a;
		break;
		
	}// fim da case 6..............
	
	//inicio da case 7 ou case final .....
	case 7:{
		system("cls");
		printf("\n\n\n\n\n\t\tEncerrando o Programa.\n");
		Sleep(500);
		system("cls");
		break;
		
	}
		
} // fim do switch case ..................................................

}// fim da função menu funcionário .........

//Função Menu Administrador ...........
void menu_administrador (){
a:
int i, a=1;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

// Salvar estado atual 
GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....	
	 for(i=45; i<75; i++){
	 	gotoxy(i,1); printf("%c",47);
	 	gotoxy(i,5); printf("%c",47);
	 }
	
	 for(i=2; i<5; i++){
	 	gotoxy(45, i); printf("%c",47);
	 	gotoxy(74, i); printf("%c",47);
	 }

 
SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................

// Essa Estrutura cria uma caixa ou box de Menu .........
	gotoxy(50, 9); printf("MENU ADMINISTRADOR\n\n");
	gotoxy(21, 11); printf("\tEscolha pelo numero a opercação que quer realizar\n\n");
	
	// Cria a Box ou caixa de menu do administrador ..............................
	for(i=20; i<100; i++){
		gotoxy(i, 7); printf("%c",47);
		gotoxy(i, 32); printf("%c",47);
	}
	
	for(i=8; i<32; i++){
		gotoxy(20, i); printf("%c",47);
		gotoxy(99,i); printf("%c",47);
	}// fim da Box de menu administrador ........................

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
 gotoxy(26, 15); printf("1-Cadastrar Funcionários\n");
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
 gotoxy(60, 15); printf("2-Cadastrar Login do Funcionário\n");
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
 gotoxy(26, 19); printf("3-Cadastrar novos Carros\n");
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
 gotoxy(67, 19); printf("4-Ver Relatórios\n");
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
 gotoxy(30, 23); printf("5-Sair do Programa\n");
 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
 
 // fim das boxs ou caixas de dentro do menu contendo as opções .....................
 
 // inicio da Box onde aparece o numero ou opção escolhida ...........
 for(i=69; i<84; i++){
 	gotoxy(i,21); printf("-");
 	gotoxy(i,25); printf("-");
 }

for(i=22; i<26; i++){
 	gotoxy(69, i); printf("-");
 	gotoxy(83, i); printf("-");
 }

 //////////// fim da box...........................
 
	datahora(); //Chamada da função data e hora do sistema .....................
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
	gotoxy(76, 23);scanf("%d", &escolha); //coloca o cursor dentro da caixa de escolha
	
	SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
	system("cls");
	
	switch(escolha){
		
case 1:{// escolha 1..................
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		
		for(i=45; i<75; i++){
	 	gotoxy(i,1); printf("%c",47);
	 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }

		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
		
			FILE *cadastro_func;
			cadastro_func = fopen ("Arquivo_Admin\\cadastro_funcionario.txt", "a");
			
			if(cadastro_func == NULL){
				printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
				Sleep(2000);
				system("cls");
			}
			
			else{
				
					// Cria a Box ou caixa de menu da case 4 ..............................
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
			goto a;
			break;
		}// fim da case 1............
	
case 2:{// inicio da case 2 .....................
	system("cls");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........
		
	SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
	
	// Essa Estrutura cria uma caixa ou box  da case 2 .........
		for(i=20; i<100; i++){
			gotoxy(i, 7); printf("%c",47);
			gotoxy(i, 32); printf("%c",47);
		}
		
		for(i=8; i<32; i++){
			gotoxy(20, i); printf("%c",47);
			gotoxy(99,i); printf("%c",47);
		}// fim da Box de menu administrador ........................
			
		 
		gotoxy(45, 9);printf("CADASTRO DE LOGIN DO FUNCIONÁRIO\n\n");
		gotoxy(25, 12);printf("Digite o Novo Nome de Usuário:: ");
		fflush(stdin);
		gets(usuario);
		fflush(stdin);
		gotoxy(25, 14);printf("Digite a Nova Senha:: ");
		fflush(stdin);
		gets(senha);
		fflush(stdin);
		
		FILE*login_funcionario;
			login_funcionario=fopen(receptor, "w");
			
			if(login_funcionario == NULL){
			printf("\n\tErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
			Sleep(1500);
			system("cls");
			}
			
			else{
				fprintf(login_funcionario, "%s %s", (usuario), (senha));
			}
		fclose(login_funcionario);
		gotoxy(50, 20);printf("Cadastro feito Com Sucesso!\n");
		Sleep(1000);
		system("cls");
		goto a;
		break;
}// fim da case 2...............
		
case 3:{ //inicio da case 3................
c:	
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........
		
		SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
	
			char c[]="R$";	

			FILE*file;
		file=fopen("lista_carros.txt","a+");
		
		if(file==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		break;
		}
		
		// Essa Estrutura cria uma caixa ou box  da case 3 .........
		for(i=20; i<100; i++){
			gotoxy(i, 7); printf("%c",47);
			gotoxy(i, 32); printf("%c",47);
		}
		
		for(i=8; i<32; i++){
			gotoxy(20, i); printf("%c",47);
			gotoxy(99,i); printf("%c",47);
		}// fim da Box de menu administrador ........................
			
		gotoxy(50, 9); printf("CADASTRO DE NOVOS CARROS\n\n");
		
		gotoxy(25, 12);printf("Digite a Marca do Carro:: ");
		fflush(stdin);
		gets(marca);
		fflush(stdin);
		gotoxy(25, 14);printf("Digite o Preço do Carro:: ");
		fflush(stdin);
		gotoxy(51, 14);scanf("%d", &preco);
		fflush(stdin);
		
		fprintf(file,"%s %d %s",(marca), (preco), (c));
		fprintf(file,"\n");
		fclose(file);
		gotoxy(50, 18);printf("Cadastro Feito com Sucesso!\n\n");
		gotoxy(23, 20);printf("Para Continuar a Cadastrar Prime a Tecla '1' Caso Não Prime a Tecla '0'\n");
		
		// cria box ou caixa onde aparece o numero escolhido da case 3 cadastrar carros ........................	
		for(i=75; i<90; i++){
		 	gotoxy(i,24); printf("-");
		 	gotoxy(i,28); printf("-");
		 }
		
		for(i=25; i<28; i++){
		 	gotoxy(75, i); printf("-");
		 	gotoxy(89, i); printf("-");
		 }// fim da box ....................................
		 
		 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		 gotoxy(82, 26);scanf("%d", &escolha); // coloca o cursor dentro da caixinha .............
		 SetConsoleTextAttribute(hConsole, saved_attributes); // volta para cor padrão ..................
		 
		if(escolha==1){
			system("cls");
			goto c;
		}
		
		else if(escolha==0){
				system("cls");
				goto a;
				break;
			}
		
		}// fim da case 3...............
		
case 4:{//inicio da case ...............
b:
	 system("cls");
	 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_RED); // coloca a cor vermelha no retangulo .....
		 for(i=45; i<75; i++){
		 	gotoxy(i,1); printf("%c",47);
		 	gotoxy(i,5); printf("%c",47);
		 }
		 
		 for(i=2; i<5; i++){
		 	gotoxy(45, i); printf("%c",47);
		 	gotoxy(74, i); printf("%c",47);
		 }
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(51, 3); printf("ANGOLA LOCADORA-LTDA");  // coloca a string dentro do retangulo........

		SetConsoleTextAttribute(hConsole, saved_attributes); // coloca cor padrão ..................
	
		// Cria a Box ou caixa de menu da case 4 ..............................
		for(i=30; i<90; i++){
			gotoxy(i, 7); printf("%c",47);
			gotoxy(i, 22); printf("%c",47);
		}
		
		for(i=8; i<22; i++){
			gotoxy(30, i); printf("%c",47);
			gotoxy(89,i); printf("%c",47);
				
		} // fim da box .......................
	
	// cria box ou caixa onde aparece o numero escolhido da case 4 ver relatórios ........................	
		for(i=69; i<84; i++){
		 	gotoxy(i,16); printf("-");
		 	gotoxy(i,20); printf("-");
		 }
		
		for(i=17; i<20; i++){
		 	gotoxy(69, i); printf("-");
		 	gotoxy(83, i); printf("-");
		 }// fim da box ....................................
		 
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY|FOREGROUND_GREEN); // colocar cor verde na string abaixo......
		gotoxy(52, 9);printf("RELATÓRIOS.\n\n");
		gotoxy(36, 11);printf("Escolha pelo número o relatório que quer ver.\n\n");
		gotoxy(34, 13);printf("1-Cadastro de Clientes\n");
		gotoxy(34, 15);printf("2-Locação de Carros\n");
		gotoxy(34, 17);printf("3-Devolução de Carros\n");
		gotoxy(34, 19);printf("4-Voltar ao Menu Principal\n\n");
	
		gotoxy(76, 18);scanf("%d", &escolha);
		SetConsoleTextAttribute(hConsole, saved_attributes); // coloca cor padrão ..................
		//inicio da escolha 1 .......
		if(escolha==1){

			FILE*relatorio1;
			relatorio1=fopen("cadastro_clientes.txt", "r");
			
		if(relatorio1==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			system("cls");
			
			while(fgets(relatorio_cadastro, 1000, relatorio1) !=NULL){
				printf("\n\t%s",relatorio_cadastro);
			}
		fclose(relatorio1);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu.");
		getch();
		system("cls");
		goto b;
		break;
		}	
	
		}//fim da escolha 1........
	
	//inicio da escolha 2 ........
	else if(escolha==2){
		system("cls");
	
		FILE*relatorio2;
		relatorio2=fopen("locacao.txt", "r");
			
		if(relatorio2==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			system("cls");
			
			while(fgets(relatorio_locacao, 1000, relatorio2) !=NULL){
				printf("\n\t%s",relatorio_locacao);
			}
		fclose(relatorio2);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto b;
		break;
		}	
		
	}//fim da escolha 2 ......
	
	//inicio da escolha 3.......
	else if(escolha==3){
		system("cls");
	
		FILE*relatorio3;
		relatorio3=fopen("devolucao.txt", "r");
			
		if(relatorio3==NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
		goto b;
		}
		
		else{
			system("cls");
			
			while(fgets(relatorio_devolucao, 1000, relatorio3) !=NULL){
				printf("\n\t%s",relatorio_devolucao);
			}
		fclose(relatorio3);
		printf("\n\n");
		printf("\n\t\t\t\tPressione Qualquer tecla para voltar ao Menu Principal\n");
		getch();
		system("cls");
		goto b;
		break;
		}	
	}//fim da escolha 3 ..............
	
	else if(escolha==4){
		system("cls");
		goto a;
			}
		}//im da case 4.........

case 5:{//inicio da case 5.................
		system("cls");
		printf("\nEncerrando o Programa.\n");
		Sleep(700);
		system("cls");
		break;
		}//fim da case 5 ............

	}// fim do switch case..........
	
}// fim menu admin........

// função main ou principal do codigo...........................................
int main(){
// Inicio do Looping do código..........................

for(contador=0; escolha<7; contador++){
	
	painel_login(); // chamada da função painel login.........
	
FILE*login_funcionario;
login_funcionario=fopen(receptor, "r");

if(login_funcionario == NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
		Sleep(2000);
		system("cls");
	}
	
	else {
		while((fscanf(login_funcionario, "%s %s", &funcionario, &senha_funcionario)) !=EOF){
			
			if((strcmp(senha, senha_funcionario)==0) && (strcmp(usuario,funcionario))==0){
				painel_bemvindo();
				menu_funcionario();
				exit(0);
			}
			
		}
}
		FILE*login_administrador;
		login_administrador=fopen(receptor2, "r");	
			
	if(login_administrador == NULL){
	printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
	Sleep(2000);
	system("cls");
	}
	else{
		while((fscanf(login_administrador, "%s %s\n", &administrador, &senha_administrador)) !=EOF){
			if((strcmp(usuario, administrador)==0) && (strcmp(senha, senha_administrador)==0)){
				painel_bemvindo();
				menu_administrador();
				exit(0);
				}
				else{
				printf("\n\n\t\tUsuário ou Senha Digitadas estão Incorretas!\n");
				printf("\n\n\t\tDigite Novamente!\n");
				Sleep(1500);
				system("cls");
		}
			}
	}
			
			
	



}// fim do looping................	
}
