#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define VAZIO 0

struct Aluno {
	int ra;
	int idade;
	float nota1;
	float nota2;
};

struct Aluno vetorAlunos[TAM];


void carregar(struct Aluno vetor[]) {
	int i = 0;
	
	for (i = 0; i < TAM; i++) {
		printf("Digite o RA, IDADE, NOTA1 e NOTA2.\n");
		scanf("%i", &vetor[i].ra);
		scanf("%i", &vetor[i].idade);
		scanf("%f", &vetor[i].nota1);
		scanf("%f", &vetor[i].nota2);		
	}
}

void exibir(struct Aluno vetor[]) {
	int i = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i].ra > 0) {
			printf("Ra: %i; Idade: %i; Nota1: %.2f; Nota2: %.2f\n", 
			  vetor[i].ra, vetor[i].idade, vetor[i].nota1, vetor[i].nota2);			
		}		
	}
}

void remover(struct Aluno vetor[], int ra) {
	int i = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i].ra == ra) {
			vetor[i].ra = VAZIO;
		}
	}
}

void menu() {
	int opc = 0;
	int ra = 0;
	
	do {
		printf("\nSYSALUNOS\n");
		printf("1. Carregar\n");
		printf("2. Exibir\n");
		printf("3. Remover\n");
		printf("Digite a opcao: ");
		scanf("%i", &opc);
		
		if (opc == 1) {	
			carregar(vetorAlunos);
			
		} else if (opc == 2) {
			exibir(vetorAlunos);
			
		} else if (opc == 3) {	
			scanf("%i", &ra);
			remover(vetorAlunos, ra);
			
		}
	} while (opc != 9);
}

int main(int argc, char *argv[]) {
	menu();	
	
	return 0;
}