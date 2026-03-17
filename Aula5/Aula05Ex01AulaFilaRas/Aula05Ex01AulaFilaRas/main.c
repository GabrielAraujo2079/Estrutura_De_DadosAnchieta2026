#include <stdio.h>
#include <stdlib.h>

#define tam 5
int filaRas[tam];
int ini = -1;
int fin = -1;
int con = 0;

void enfileirar(int ra, int fila[]) {
	if (con == tam) {
		printf("Fila cheia! Nenhum valor adicionado!\n");
	} else {
		if (fin == -1) {
			fin++;
			ini++;
			con++;
			fila[fin] = ra;
			printf("RA inserido!\n");
		} else {
			if (fin == (tam - 1)) {
				fin = 0;
				con++;
				fila[fin] = ra;
				printf("RA inserido!\n");
			} else {
				fin++;
				con++;
				fila[fin] = ra;
				printf("RA inserido!\n");
			}
		}
	}
}

void desenfileirar() {
	if (con == 0) {
		printf("Fila vazia! Nenhum RA removido!\n");
	} else {
		if (ini == (tam - 1)) {
			ini = 0;
			con--;
			printf("RA removido!\n");
		} else {
			ini++;
			con--;			
			printf("RA removido!\n");
		}
		
		if (con == 0) {
			ini = -1;
			fin = -1;
		}
	}
}

void exibir(int fila[]) {
	int p = 0;
	int i = 0;
	
	if (con == 0) {
		printf("Fila vazia!\n");
	} else {
		p = ini;
		
		for (i = 1; i <= con; i++) {
			printf("%i \n", fila[p]);
			
			if (p == (tam - 1)) {
				p = 0;
			} else {
				p++;
			}
		}
	}				
}

void menu () {
	int opc = 0;
	int r = 0;
	
	do {
		printf("\nFILA RAs\n");
		printf("1. Enfileirar\n");
		printf("2. Desenfileirar\n");
		printf("3. Exibir\n");
		printf("Digite opcao: ");
		scanf("%i", &opc);
		
		if (opc == 1) {
			scanf("%i", &r);
			enfileirar(r, filaRas);
			
		} else if (opc == 2) {
			desenfileirar();
			
		} else if (opc == 3) {
			exibir(filaRas);
			
		}
	} while (opc != 9);
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}