#include <stdio.h>
#include <stdlib.h>

#define TAM 6

struct Livro {
	int codigo;
	char nome[10];
};

struct Livro pilha[TAM];
int topo = -1;

void empilhar(int cod, char nom[10], struct Livro vetor[]){
	if (topo == (TAM -1)){
		printf("Pilha cheia! Livro nao adicionado!\n");
	
	}else {
		topo++;
		vetor[topo].codigo = cod;
		strcpy(vetor[topo].nome, nom);
		printf("Livro empilhado!\n");
	}
}
void desempilhar(){
	if (topo == -1){
		printf("Pilha vazia! Nenhum elemento desempilhado!\n");
		
	}else {
		topo--;
	}
	
}

void imprimir(struct Livro vetor[]){
	int i = -1;
	if (topo == -1){
			printf("Pilha vazia!\n");
	}else {
		for (i = topo; i >=0; i--){
			printf("[%i] - %i - %s \n", i, vetor[i].codigo, vetor[i].nome);
			
		}
	}
}


void menu(){
	int opc = 0;
	int c;
	char n[10];
	
	
	do {
		printf("\n::PILHA LIVROS::\n");
		printf("1. Empilhar\n");
		printf("2. Desempilhar\n");
		printf("3. Imprimir\n");
		printf("Digite opcao\n");
		scanf("%i", &opc);
	
		if (opc == 1){
			scanf("i", &c);
			scanf("%s", &n);
			empilhar(c, n, pilha);
			
		}else if (opc == 2){
			desempilhar();
		}else if (opc == 3){
			imprimir(pilha);
		}
		
		
		
	}while(opc != 9);
	
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}