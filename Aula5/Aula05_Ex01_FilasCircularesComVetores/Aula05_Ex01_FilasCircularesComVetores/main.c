#include <stdio.h>
#include <stdlib.h>

/*  MARÇAL: Exemplo de Filas Circulares com Vetores em C */

int main(int argc, char *argv[]) {
	int opc = 0;
	
	// variáveis para manipulação da fila circular
	int vetorRas[4];
	int inicioFila = -1, finalFila = -1;
	int numeroValoresFila = 0;
	// variveis auxiliares para manipulação da fila
	// circular, não necessáriamente precisam serem
	// utilizadas.
	int i = 0;
	int tamanhoVetor = sizeof(vetorRas)/sizeof(int);
	int valor = 0;
	
	//inicioFilacializa o vetor.
	for (i = 0; i < tamanhoVetor; i++) {
		vetorRas[i] = -1;
	}
	
	
	while (opc != 9) {
		printf("\n");
		printf(":: FILA CIRCULAR RAs :: \n");
		printf("1. enfileirar           \n");
		printf("2. desenfileirar        \n");
		printf("3. exibir               \n");
		printf("9. Sair \n");
		printf("Digite a opcao desejada: ");
		
		scanf("%d", &opc);
		
		if (opc == 1) {
			if (numeroValoresFila == tamanhoVetor) {
				printf("Fila cheia! \n");
			} else {
				printf("Digite o ra: ");
				scanf("%d", &valor);
				
				if (finalFila == -1) {
					finalFila = 0;
					inicioFila = 0;
				} else {
					if (finalFila == (tamanhoVetor - 1)) {
						finalFila = 0;
					} else {
						finalFila = finalFila + 1;
					}
				}
				
				vetorRas[finalFila] = valor;
				numeroValoresFila = numeroValoresFila + 1;
				
				printf("RA enfileirado! \n");
			}
			
		} else if (opc == 2) {
			if (numeroValoresFila == 0) {
				printf("Fila vazia! \n");
			} else {
				if (inicioFila == (tamanhoVetor - 1)) {
					inicioFila = 0;
				} else {
					inicioFila = inicioFila + 1;
				}
				
				numeroValoresFila = numeroValoresFila -1;
				
				if (numeroValoresFila == 0) {
					inicioFila = -1;
					finalFila = -1;
				}
				
				printf("RA desenfileirado! \n");
			}
			
		} else if (opc == 3) {
			printf("Inicio fila   : %d; \n", inicioFila);
			printf("Final fila    : %d; \n", finalFila);
			printf("Numero valores: %d; \n", numeroValoresFila);
			
			int p = inicioFila;

			for (i = 0; i < tamanhoVetor; i++) {
				printf("POSICAO %d: VALOR: %d; \n", p, vetorRas[p]);
				
				if (p == (tamanhoVetor - 1)) {
					p = 0;
				} else {
					p = p + 1;
				}
			}
		}		
	}
		
	return 0;
}

