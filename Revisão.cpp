#include<stdio.h>
#include<math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
int main(){
	
	int n1, n2, soma, subt,  mult, fator, expo, rad, ch, n, vescolha, resultado, num, contador=0;
	float div;
	setlocale(LC_ALL, "Portuguese");
	a:
	printf("\t\t\t=======MENU DE OP��ES=======\n\n\n");
	printf("1-Soma::\n");
	printf("2-Subtra��o:\n");
	printf("3-Multiplica�a�::\n");
	printf("4-Divis�o::\n");
	printf("5-Fatorial::\n");
	printf("6-Exponencial::\n");
	printf("7-Radiacia��o::\n");
	printf("8-encerrar o Programa::\n\n");
	printf("Op��es::\n\n");
	scanf("%d", &vescolha);
	
	for(contador=0; vescolha<8; contador++){
	
	switch(vescolha){
		case 1: printf("A op��o que o usuario escolheu foi soma.\n\n");
				printf("Digite o primeiro Valor.\n");
				scanf("%d", &n1);
				printf("Digite o segundo Valor.\n");
				scanf("%d", &n2);
				soma=n1+n2;
				printf("O valor da soma eh :: %d\n\n ",soma);
				system("cls");
				break;
				
		case 2: printf("A op��o que o usuario escolheu foi Subtra��o.\n\n");
				printf("Digite o primeiro valor.\n");
				scanf("%d", &n1);
				printf("Digite o segundo Valor.\n");
				scanf("%d", &n2);
				subt=n1-n2;
				printf("O valor da Subtra��o eh:: %d\n\n", subt);
				system("cls");
				break;
				
		case 3: printf("A op��o que o usuario escolheu foi Multiplica��o.\n\n");
				printf("Digite o primeiro Valor:\n");
				scanf("%d", &n1);
				printf("Digite o Segundo Valor:\n");
				scanf("%d",&n2);
				mult=n1*n2;
				printf("O valor da Multiplica��o eh:: %d\n\n", mult);
				system("cls");
				break;
				
		case 4: printf("A op��o que o usuario escolheu foi Divis�o.\n\n");
				printf("Digite o primeiro Valor:\n");
				scanf("%f", &n1);
				printf("Digite o Segundo Valor:\n");
				scanf("%f",&n2);
				div=((float)n1/n2);
				printf("O valor da Divis�o eh:: %f\n\n", div);
				system("cls");
				break;
				
		case 5: printf("A op��o que o usuario escolheu foi Fatorial.\n\n");
				printf("Digite o numero:\n");
				scanf("%d", &ch);
				n=1;
				while(ch>0){
					n=n*ch;
					ch=ch-1;
				}
				printf("O valo da fatoria eh:: %i \n\n",n);
				system("cls");
				break;
				
		case 6: printf("A op��o que o usuario escolheu foi Exponencial.\n\n");
				printf(" Digite o Primeiro Numero:\n");
				scanf("%d",&n1);
				printf("Digite o Segundo Numero:\n");
				scanf("%d",&n2);
				expo=n1^n2;
				printf("o valor da Exponencal eh: %d\n\n", exp);
				system("cls");
				
		case 7: printf("A op��o que o usuario escolheu foi Radiacia��o.\n\n");
				printf("Digite um Numero:\n");
				scanf("%d", &num);
				rad=sqrt(num);
				printf("A Raiz do numero eh: %d \n\n", rad);
				printf("Precione Qualquer tecla pra sair do programa");
				getch();
				system("cls");
				
				
		case 8: printf("Encerrando o programa.");
				Sleep(2000);
				system("cls");
				goto a;
				}
		
}
		
}
