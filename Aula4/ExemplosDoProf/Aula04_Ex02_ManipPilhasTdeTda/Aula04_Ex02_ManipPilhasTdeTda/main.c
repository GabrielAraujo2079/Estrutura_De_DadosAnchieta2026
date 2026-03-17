#include <stdio.h>
#include <stdlib.h>

/* MARÇAL, J.                                                          */
/* Manipulação de Pilhas de Livros (tipos de dados estruturados - tde) */
/* de vetores e tipos de dados abstratos (tda)                         */


#define tam 5

/* Definindo a estrutura do elemento */
struct Livro {
	int codigo;
	char nome[10];
};

/* Definição do vetor que será utilizado para controle de pilha */
struct Livro vetorLivros[tam];
int topo = -1;

/* Metodo para zerar os elementos do vetor                      */
void iniciarVetor(struct Livro vetor[]) {
	int i;
	
	for (i = tam; i >= 0; i--) {
		vetor[i].codigo = 0;
		strcpy(vetor[i].nome, "NULL");
	}
}

/* Metodo para empilhar elementos, atenção como é manipulado o  */
/* atributo 'nome'.                                             */
void empilhar(int cod, char nom[10], struct Livro vetor[]) {
	if (topo == (tam - 1)) {
		printf("Pilha cheia! \n");
	} else {
		topo++;
		vetor[topo].codigo = cod;
		strcpy(vetor[topo].nome, nom);
		printf("Empilhado posicao: %i \n", topo);
	}
}

/* Metodo desempilhar, note que somente o ponteiro é manipulado */
void desempilhar() {
	if (topo == -1) {
		printf("Pilha vazia! \n");
	} else {
		topo--;
		printf("Desempilhada posicao: %i \n", topo + 1);
	}
}

void imprimir(struct Livro vetor[]) {
	int i = 0;
	
	if (topo == -1) {
		printf("Pilha vazia! \n");
	} else {
		for (i = topo; i >= 0; i--) {
			printf("[%i] - %i - %s; \n", i, vetor[i].codigo, vetor[i].nome);			
		}
	}
}


int main(int argc, char *argv[]) {
	int opc = 0;
	int c = 0;
	char n[10];
	
	iniciarVetor(vetorLivros);
	
	while (opc != 9) {
		printf(" \n");
		printf(":: PILHA DE LIVROS :: \n");
		printf("1. empilhar           \n");
		printf("2. desempilhar        \n");
		printf("3. imprimir           \n");
		printf("9. Sair               \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			printf("Digite o codigo: ");	
			scanf("%i", &c);
			printf("Digite o nome: ");	
			scanf("%s", &n);
			
			empilhar(c, n, vetorLivros);
			
		} else if (opc == 2) {
			desempilhar();

		} else if (opc == 3) {
			imprimir(vetorLivros);
			
		}		
	}
	
	return 0;
}