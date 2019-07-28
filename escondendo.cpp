#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define ENTER 13


int main (){
	
	char usuario[20], senha[20], ch[30], func[30], funcionario[50];
	int i;
	char recebe[]="login_funcionario.txt";
	
	printf("Digite o usuario\n");
	gets(usuario);
	printf("Digite a senha:: ");
	
	while(1){
		ch[30]=getch();
		
		if(ch==ENTER){
		break;
		}

		else{
			
			
			i++;
			printf("*");
		}
	}
	
	//senha[i]='';
	for(i=0; i<8; i++){
		printf("%c", ch);
	}
	

	FILE*login;
	login=fopen(recebe, "r");
	
		if(login == NULL){
		printf("\nErro! O Arquivo Não Existe e Não pode ser Aberto!\n");
	}
	
	else{
			while((fscanf(login, "%s %s", &funcionario, &func)) !=EOF){
			
			if((strcmp(senha,func)==0) && (strcmp(usuario, funcionario))==0){
				
				printf("Conseguiste!! Parabéns\n");
			}
			
			else{
			printf("\n\n\t\tUsuário ou Senha Digitadas estão Incorretas!\n");
			printf("\n\n\t\tDigite Novamente!\n");
			}
			
		}
	}

}


//(strcmp(usuario, funcionario) ==0)

	
	
	
