#include <stdio.h>
#include <stdlib.h>

/* MARCAL, J.                                                    */
/* O exemplo baixo corresponde a uma Lista de Alunos que utiliza */
/* Listas Duplamente Ligadas com Estruturas Lineares (Vetores)   */

// Tamanho máximo da lista
#define TAM 10

// Estrutura para permitir a implementação de Listas Duplamentes 
// Ligadas
struct Aluno {
	int ra;
	char nome[10];
	float mensalidade;
	
	// indices de controle dos elementos
	int anterior;
	int proximo;
};

// Variáveis globais para controle da lista duplamente ligada
struct Aluno lista[TAM];

int primeiro = -1;
int ultimo = -1;
int livre = -1;
int quantidade = 0;

// Método responsável pela inicilialização total da lista e suas 
// variáveis de controle
void iniciarLista() {
	int i; 
	
    primeiro = -1;
	ultimo = -1;
	livre = -1;
    quantidade = 0;
	
	for (i = 0; i < TAM; i++) {
		lista[i].ra = -1;
		strcpy(lista[i].nome, "null");
		lista[i].mensalidade = 0.00;
	}
}

// Método que verifica se a fila está cheia (1) ou se contém alguma
// posição disponível (0)
int listaCheia() {
	return (quantidade == TAM);
}

int listaVazia() {
	return (quantidade == 0);
}

// Método que retorna uma posição 
int obterPosicaoLivre() {
	int i = 0, p = -1;
	
	if (listaCheia() == 0) {
		for (i = 0; i < TAM; i++) {
			if (lista[i].ra == -1) {
				p = i;
				break;
			}
		}
	}
	
	return p;
}

// Método que adiciona um Aluno no início, note que o método não 
// está verificando internamente se a lista está cheia, ou seja,
// esta verificação deverá ser realizada antes de invoca-lo.
void inserirInicio(int ra, char nome[10], float mensal) {
	int pv = obterPosicaoLivre();
	
	lista[pv].ra = ra;
	strcpy(lista[pv].nome, nome);
	lista[pv].mensalidade = mensal;

	if (quantidade == 0) {
		primeiro = pv;
		ultimo = pv;
		lista[pv].proximo = -1;
		lista[pv].anterior = -1;
	} else {
		lista[pv].proximo = primeiro;
		lista[pv].anterior = -1;
		
		lista[primeiro].anterior = pv;
		primeiro = pv;
	}
	
	quantidade++;
}

void inserirFinal(int ra, char nome[10], float mensal) {
	printf("Metodo nao implementado!\n");
}

// Método responsável por remover um aluno do início, note que
// o método não está verificando se a lista está vazia,   esta 
// verificacao deve ocorrer antes do metodo ser invocado.
void removerInicio() {
	int tmp = -1;
	
	if (quantidade == 1) {
		lista[primeiro].ra = -1;
		lista[primeiro].proximo = -1;
		lista[primeiro].anterior = -1;
		
		primeiro = -1;
		ultimo = -1;
		livre = -1;
		quantidade = 0;		
	} else {
		tmp = primeiro;
		
		lista[lista[primeiro].proximo].anterior = -1;
		primeiro = lista[primeiro].proximo;
		
		lista[tmp].anterior	= -1;
		lista[tmp].proximo = -1;
		
		quantidade--;
	}
}


// Método responsável por remover um aluno do final.
void removerFinal() {
	printf("Metodo nao implementado!\n");
}

// Método responsável por exibir do início para o final.
void exibirInicioFinal() {
	int atual;
	
	if (listaVazia == 1) {
		printf("Lista vazia!\n");
	} else {
		atual = primeiro;
		
		while (atual != -1) {
			printf("ra: %d | nome: %s | mensalidade  R$ %.2f\n",
               lista[atual].ra, 
               lista[atual].nome,
			   lista[atual].mensalidade);
			   
        	atual = lista[atual].proximo;			
		}
	}
}

void menu() {
	int opc = 0;
	int r;
	char n[10];
	float m;
	
	iniciarLista();
	
	do {
		printf("\n LISTA DUPLAMENTE LIGADA COM VETOR \n");
        printf("1. Adicionar no inicio\n");
        printf("2. Adicionar no final\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do final\n");
        printf("5. Exibir do inicio para o final\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
		
		if (opc == 1) {
			if (listaCheia() == 1) {
				printf("Lista cheia!\n");
				
			} else {
				printf("Informe o ra: ");
				scanf("%i", &r);
				printf("Informe o nome: ");
				scanf("%s", &n);			
				printf("Informe a mensalidade: ");
				scanf("%f", &m);
				
				inserirInicio(r, n, m);
			}
			
		} else if (opc == 2) {
			
		} else if (opc == 3) {
			if (listaVazia() == 1) {
				printf("Lista vazia!\n");
				
			} else {
				removerInicio();
			}
			
		} else if (opc == 4) {
			
		} else if (opc == 5) {
			if (listaVazia() == 1) {
				printf("Lista vazia!\n");
				
			} else {
				exibirInicioFinal();
			}
			
		}				
	} while (opc != 9);
}




int main(int argc, char *argv[]) {
	menu();
	
	return 0;
}