#include <stdio.h>
#include <string.h>


int main(){
	 
	FILE *arquivo;
	
	char b[20]; 
	printf("Digite o nome ");
	scanf("%s",&b);
	 
	sprintf("%s.txt", b);
}
