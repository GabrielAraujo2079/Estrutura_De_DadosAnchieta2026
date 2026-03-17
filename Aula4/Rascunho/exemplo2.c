#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TAM 5

struct Aluno{
	int ra;
	float nota1;
	float nota2;
	float media;
};

struct Aluno vetorAlunos[TAM];

void inicializar(struct Aluno vetor[]){
	int i = 0;
	
	for(i = 0; i < TAM; i++){
		vetor[i].ra = 0;
	}
}

void carregar (struct Aluno vetor[]){
	int i = 0;
	
	for(i = 0; i < TAM; i++){
		printf("Digite as duas notas:\n", i + 1);
		scanf("%i", vetor[i].ra);
		scanf("%f", vetor[i].nota1);
		scanf("%f", vetor[i].nota2);
	}
}

void exibir (struct Aluno vetor[]){
	int i = 0;
	for(i = 0; i < TAM; i++){
		printf("RA: %i, Nota1: %f, nota2: %f, Média: %f\n", 
		vetor[i].ra,
		vetor[i].nota1,
		vetor[i].nota2,
		vetor[i].media
		);
	}
}

void menu(){
	int opc = 0;
	
	do{
		printf(":::MENU:::\n");
		printf(":: 1.Inicializar::\n");
		printf(":: 2.Carregar::\n");
		printf(":: 3.Exibir::\n");
		printf(":: 9.Sair::\n");
		scanf("%i", &opc);
	
		switch(opc){
			
			case 1:
				inicializar(vetorAlunos);
				break;
			case 2:
				carregar(vetorAlunos);
				break;
			case 3:
				exibir(vetorAlunos);
				break;	
		}
	} while(opc != 9);

}

int main() {
	menu();
	
	return 0;
}