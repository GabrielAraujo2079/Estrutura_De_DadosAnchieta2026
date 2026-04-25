#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // For time()

#define TAM 100
#define VAZIO 0

int vetorRas[TAM];

void inicializarVetor(int vetor[]) {
	int x = 0;
	
	for (x = 0; x < TAM; x++) {
		vetor[x] = VAZIO;
	}
}

void carregarVetor(int vetor[]) {
	int x = 0;
	int randomNum = 0;
	
	srand((unsigned int)time(NULL));
	
	for (x = 0; x < TAM; x++) {
		randomNum = rand() % 20;
		vetor[x] = randomNum;
		//scanf("%i", &vetor[x]);
	}
}

void exibirVetor(int vetor[]) {
	int y = 0;
	
	for (y = 0; y < TAM; y++) {
		printf("%i \n", vetor[y]);
	}
}

int maiorRa(int vetor[]) {
	int i = 0;
	int m = -1;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] > m) {
			m = vetor[i];
		}
	}
	
	return m;
}

int contarRas(int vetor[]) {
	int i = 0;
	int c = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] > 0) {
			c = c + 1;
		}
	}
	
	return c;
}

void removerRa(int vetor[], int ra) {
	int i = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] == ra) {
			vetor[i] = VAZIO;
		}
	}
}

void menu() {
	int opc = 0;
	int ra = 0;
	
	do {
		printf("\n::SYSRAs::..\n");
		printf("1. Inicializar\n");
		printf("2. Carregar\n");
		printf("3. Exibir\n");
		printf("4. Maior RA\n");
		printf("5. Contar RAs\n");
		printf("6. Remover RA\n");
		printf("Digite opcao:");
		scanf("%i", &opc);
		
		if (opc == 1) {	
			inicializarVetor(vetorRas);
			
		} else if (opc == 2) {
			carregarVetor(vetorRas);
			
		} else if (opc == 3) {
			exibirVetor(vetorRas);
			
		} else if (opc == 4) {
			ra = maiorRa(vetorRas);
			printf("O maior RA e: %i.\n", ra);
			
		} else if (opc == 5) {
			//ra = contarRas(vetorRas);
			//printf("Exite(m) %i RA(s) cadastrados!", ra);
			
			printf(
			  "Exite(m) %i RA(s) cadastrado(s)!\n", 
			  contarRas(vetorRas));
			
		} else if (opc == 6) {			
			scanf("%i", &ra);
			removerRa(vetorRas, ra);
		}
		
	} while (opc != 9);	
}
 
int main(int argc, char *argv[]) {

	menu();
	
	return 0;
}