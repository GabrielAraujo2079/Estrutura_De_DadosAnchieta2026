#include <stdio.h>
#include <stdlib.h>

#define tam 5

struct Aluno {
	int ra;
	char nome[10];
};

struct Aluno fila[tam];
int ini = -1; 
int fin = -1; 
int con = 0;

void adicionar() {
	if (con == tam) {
		printf("Fila cheia!");
	} else {
		if (fin == -1) {
			fin++;
			ini++;
		} else {
			if (fin == (tam - 1)) {
				fin = 0;
			} else {
				fin++;
			}
		}

		con++;
		scanf("%i", &fila[fin].ra);
		scanf("%s", &fila[fin].nome);
		printf("Aluno inserido!\n");
	}
}

void remover() {
	if (con == 0) {
		printf("Fila vazia!\n");
	} else {
		if (ini == (tam - 1)) {
			ini = 0;
		} else {
			ini++;
		}
		con--;
		printf("Aluno removido!\n");
		
		if (con == 0) {
			ini = -1;
			fin = -1;
		}
	}
}
void exibir() {
	int p = 0;
	int i = 0;
	
	if (con == 0) {
		printf("Fila vazia!\n");
	} else {
		p = ini;
		
		for (i = 1; i <= con; i++) {
			printf("%i - %s \n", fila[p].ra, fila[p].nome);
			
			if (p == (tam - 1)) {
				p = 0;
			} else {
				p++;
			}
		}
	}					
}

void menu() {
	int opc = 0;
	int r = 0;
	
	do {
		printf("\nFILA ALUNOS\n");
		printf("1. Enfileirar\n");
		printf("2. Desenfileirar\n");
		printf("3. Exibir\n");
		printf("Digite opcao: ");
		scanf("%i", &opc);
		
		if (opc == 1) {
			adicionar();
			
		} else if (opc == 2) {
			remover();
			
		} else if (opc == 3) {
			exibir();
						
		}
	} while (opc != 9);	
}

int main(int argc, char *argv[]) {
	menu();
	
	return 0;
}