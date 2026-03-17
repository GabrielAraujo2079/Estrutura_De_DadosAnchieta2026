#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define VAZIO 0

int vetorRAs[TAM] = {VAZIO};

void carregarRAs(int vetor[]) {
    int i = 0;
    int randomNum = 0;
    
    srand((int)time(NULL));
    
    for (i = 0; i < TAM; i++) {
    	randomNum = rand() % 25;
    	vetor[i] = randomNum;
	}
}


void exibirRAs(int vetor[]) {
    int i = 0;
    
    for (i = 0; i < TAM; i++) {
    	printf("%i, \n", vetor[i]);
	}
}

void removerRA(int vetor[], int ra) {
	int i = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] == ra) {
			vetor[i] = VAZIO;
		}
	}   
}

int contarRAs(int vetor[]) {
	int i = 0, contador = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] != VAZIO) {
			contador = contador + 1;
		}
	}
	
    return contador;    
}

int maiorRA(int vetor[]) {
	int i = 0, maior = 0;
	
	for (i = 0; i < TAM; i++) {
		if (vetor[i] > maior) {
			maior = vetor[i];
		}
	}
	
    return maior;
}

void menu(){
    int opc = 0;
    int numero = 0;
    
    do{
        printf("\n--- SYS RA COLECTOR ---\n");
        printf("--- 1. Carregar ---\n");
        printf("--- 2. Exibir ---\n");
        printf("--- 3. Remover RA ---\n");
        printf("--- 4. Contar RA ---\n");
        printf("--- 5. Maior RA ---\n");
        printf("--- Digite a opcao: ---\n");
        scanf("%i", &opc);
        
        switch (opc) {
            case 1: {
            	carregarRAs(vetorRAs);
				break;
			}
			case 2: {
				printf("--- Esses sao os RA que estao armazenados ---\n");
				exibirRAs(vetorRAs);
				break;
			}
			case 3: {
				printf("--- Insira o RA que deseja remover ---\n");
				scanf("%i", &numero);
				removerRA(vetorRAs, numero);
				break;
			}
			case 4: {
				numero = contarRAs(vetorRAs);
				printf("Existe(m) %i RA(s) cadastrado(s)!", numero);
				break;
			}
			case 5: {
				numero = maiorRA(vetorRAs);
				printf("O maior RA e: %i\n", numero);
				break;
			}
        }
    } while (opc != 9);
}

int main(int argc, char *argv[]) {
	
	menu();
	return 0;
}