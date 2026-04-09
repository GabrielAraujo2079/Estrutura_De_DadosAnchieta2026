#include <stdio.h>
#include <stdlib.h>

/* MARÇAL, J. - Exemplo de Pilha com Ponteiros */

// Estrutura que representa cada nó (elemento) da pilha
typedef struct No {
    // atributos
	int codigo;
    float valor;
    
    // Ponteiro para o elemento abaixo deste na pilha
    struct No *proximo; 
} No;

// Função para Empilhar (Push)
No* empilhar(No *topo) {
    No *novo = (No*) malloc(sizeof(No));
    
    if (novo) {
        printf("Digite o codigo: ");
        scanf("%d", &novo->codigo);
        printf("Digite o valor: ");
        scanf("%f", &novo->valor);
        
        // O novo nó aponta para o antigo topo
        novo->proximo = topo; 
        // O novo nó passa a ser o novo topo
        return novo;          
    } else {
        printf("\nErro ao alocar memoria!\n");
        return topo;
    }
}


// Função para Desempilhar (Pop)
No* desempilhar(No *topo) {
    if (topo != NULL) {
        No *remover = topo;
        // O topo passa a ser o elemento de baixo
        topo = remover->proximo; 
        printf("\nElemento Codigo %d removido com sucesso.\n", remover->codigo);
        
		// Libera a memória do nó removido
		free(remover); 
    } else {
        printf("\nPilha vazia! Nada para desempilhar.\n");
    }
    return topo;
}


// Função para exibir o elemento do topo
void elementoTopo(No *topo) {
    if (topo != NULL) {
        printf("Codigo: %d | Valor: %.2f\n", topo->codigo, topo->valor);
    } else {
        printf("\nPilha vazia.\n");
    }
}


// Função para exibir todos os elementos
void exibirTodos(No *topo) {
    No *aux = topo;

    if (aux == NULL) {
		printf("Pilha vazia.\n");	
	}
    
    while (aux != NULL) {
        printf("Codigo: %d | Valor: %.2f\n", aux->codigo, aux->valor);
        aux = aux->proximo;
    }
}


int main(int argc, char *argv[]) {
	// Inicializa a pilha vazia
	No *topo = NULL; 
    int opcao;

    do {
        printf("\nPILHA DINAMICA\n");
        printf("1. Empilhar (Push)\n");
        printf("2. Desempilhar (Pop)\n");
        printf("3. Elemento Topo\n");
        printf("4. Exibir Todos\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                topo = desempilhar(topo);
                break;
            case 3:
                elementoTopo(topo);
                break;
            case 4:
                exibirTodos(topo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 9);

    return 0;
}