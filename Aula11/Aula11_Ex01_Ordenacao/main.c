#include <stdio.h>
#include <stdlib.h>

/* Definindo elementos globais */
#define numeroElementos 10
int vetorElementos[numeroElementos];

/* Carrega o vetor com valores informados pelo usuário */
void carregarVetor(int tamanho, int *vetor) {
	int i = 0;
	int j = 0;
	
	printf("Formas de carregar o vetor: \n");
	printf("0 - Automatica              \n");
	printf("1 - Valores usuario         \n");
	printf("Digite a opcao:             \n");
	scanf("%i", &j);
	
	if (j == 1) {
		for (i = 0; i < tamanho; i++) {
			printf("Digite um valor para a posicao [%i]: " , i);
			scanf("%i", &vetor[i]);
		}		
	} else {
		vetorElementos[0] = 45;
		vetorElementos[1] = 5;
		vetorElementos[2] = 9;
		vetorElementos[3] = 81;
		vetorElementos[4] = 18;
		vetorElementos[5] = 3;
		vetorElementos[6] = 1;
		vetorElementos[7] = 4;
		vetorElementos[8] = 7;
		vetorElementos[9] = 2;		
	}
}

/* Imprime os valores do vetor */
void imprimirVetor(int tamanho, int *vetor) {
	int i = 0;
	
	for (i = 0; i < tamanho; i++) {
		printf("[%i] - %i \n", i, vetor[i]);
	}
}

/* Ordenar Buble Sort          */
void ordenarBubleSort(int tamanho, int *vetor) {
	int i, j, aux = 0;
	
	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < (tamanho - 1); j++) {
			if (vetor[j] > vetor[j + 1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

/* Ordenar Insertion Sort      */
void ordenarInsertionSort(int tamanho, int *vetor) {
	int i, j, temp = 0;
	
	for (i = 1; i < tamanho; i++) {
		temp = vetor[i];
		j = (i - 1);
		
		while ((temp < vetor[j]) && (j >= 0)) {
			vetor[j+1] = vetor[j];
			j--;	
		}
		
		vetor[j+1] = temp;
	}	
}

int main(int argc, char *argv[]) {
	int opc = 0;
	
	while(opc != 9) {
		printf(" \n");
		printf(":: ORDENACAO ::..                  \n");
		printf("0. Carregar                        \n");
		printf("1. Ordenar buble sort              \n");
		printf("2. Ordenar insertion sort          \n");
		printf("3. Imprimir                        \n");
		printf("9. Sair                            \n");
		printf("Dig. opcao desejada:               \n");
		
		scanf("%d", &opc);
		
		if (opc == 0) {
			carregarVetor(numeroElementos, vetorElementos);

		} else if (opc == 1) {
			ordenarBubleSort(numeroElementos, vetorElementos);
			
		} else if (opc == 2) {
			ordenarInsertionSort(numeroElementos, vetorElementos);
			
		} else if (opc == 3) {			
			imprimirVetor(numeroElementos, vetorElementos);
		}
	}
	
	return 0;
}



