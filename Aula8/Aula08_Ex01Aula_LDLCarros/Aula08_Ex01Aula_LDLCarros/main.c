#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct Carro {
	int codigo;
	char placa[7];

	int anterior;
	int proximo;	
};

struct Carro lista[TAM];
int primeiro;
int ultimo;
int quantidade;

int vazia() {
	if (quantidade == 0) {
		return 1;
	} else {
		return 0;
	}	
}

int cheia() {
	if (quantidade == TAM) {
		return 1;
	} else {
		return 0;
	}
}

void iniciarLista() {
	int i;
	
	primeiro = -1;
	ultimo = -1;
	quantidade = 0;
	
	for (i = 0; i < TAM; i++) {
		lista[i].codigo = 0;
		strcpy(lista[i].placa, "null");
	}
}

int obterPosicaoVazia() {
	int i = 0, pv = -1;
	
	for (i = 0; i < TAM; i++) {
		if (lista[i].codigo == 0) {
			pv = i;
			break;
		}
	}
	
	return pv;
}

void adicionarInicio() {
	int pv;
	
	if (cheia() == 1) {
		printf("Lista cheia!\n");
	} else {
		pv = obterPosicaoVazia();
		
		scanf("%i", &lista[pv].codigo);
		scanf("%s", &lista[pv].placa);
		
		if (quantidade == 0) {
			primeiro = pv;
			ultimo = pv;
			lista[pv].anterior = -1;
			lista[pv].proximo = -1;
		} else {
			lista[primeiro].anterior = pv;
			lista[pv].proximo = primeiro;
			lista[pv].anterior = -1;
			primeiro = pv;
		}
		
		quantidade++;		
	}	
}

void exibirInicioFinal() {
	int aux;
	
	if (vazia() == 1) {
		printf("Lista vazia!\n");
	} else {
		aux = primeiro;
		
		while (aux != -1) {
			printf("posv: %i | codigo: %i | placa: %s \n", aux, lista[aux].codigo, lista[aux].placa);
			aux = lista[aux].proximo;
		}
		
		printf("primeiro: %i\n", primeiro);
		printf("ultimo: %i\n", ultimo);
		printf("quantidade: %i\n", quantidade);
	}
}

void adicionarFinal() {
	int pv;
	
	if (cheia() == 1) {
		printf("Lista cheia!\n");
	} else {
		pv = obterPosicaoVazia();
		
		scanf("%i", &lista[pv].codigo);
		scanf("%s", &lista[pv].placa);
		
		if (quantidade == 0) {
			lista[pv].anterior = -1;
			lista[pv].proximo = -1;
			primeiro = pv;
			ultimo = pv;
		} else {
			lista[pv].anterior = ultimo;
			lista[pv].proximo = -1;
			lista[ultimo].proximo = pv;
			ultimo = pv;
		}
		quantidade++;
	}
}

void removerFinal() {
	int aux;
	
	if (vazia() == 1) {
		printf("Lista vazia!\n");
	} else {
		if (quantidade == 1) {
			lista[ultimo].codigo = 0;
			strcpy(lista[ultimo].placa, "null");
			lista[ultimo].anterior = -1;
			lista[ultimo].proximo = -1;
			
			primeiro = -1;
			ultimo = -1;
		} else {
			aux = ultimo;
			
			lista[lista[ultimo].anterior].proximo = -1;
			ultimo = lista[ultimo].anterior;
			
			lista[aux].codigo = 0;
			strcpy(lista[aux].placa, "null");
			lista[aux].anterior = -1;
			lista[aux].proximo = -1;
		}
		quantidade--;
	}
}

void menu() {
	int opc = 0;
	
	do {
		printf("\nLISTA DL CARROS\n");
		printf("1. Ad inic.      \n");
		printf("2. Ad final      \n");
		printf("3. Rem. inic.    \n");
		printf("4. Rem. final    \n");
		printf("5. Exibir I > F  \n");
		scanf("%i", &opc);
		
		if (opc == 1) {
			adicionarInicio();
		} else if (opc == 2) {
			adicionarFinal();
		} else if (opc == 3) {
		} else if (opc == 4) {
			removerFinal();
		} else if (opc == 5) {
			exibirInicioFinal();
			
		}
	} while (opc != 9);
}

int main(int argc, char *argv[]) {
	iniciarLista();
	menu();
	return 0;
}