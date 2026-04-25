#include <stdio.h>
#include <stdlib.h>

#define TAM 4

struct Carro {
	int codigo;
	char placa[7];
	float valor;

	int anterior;
	int proximo;	
};

struct Carro lista[TAM];
int primeiro = -1;
int ultimo = -1;
int quantidade = 0;

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
		lista[i].valor = 0.00;
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

void adicionarAposCodigo(int pcod) {
	int pv = -1, pl = -1;
	
	if (cheia() == 1) {
		printf("Lista cheia!\n");
	} else {
		if (vazia() == 1) {
			printf("Lista vazia!\n");	
		} else {
			pl = pesquisarCodigo(pcod);
			
			if (pl == -1) {
				printf("Codigo %i nao localizado!\n", pcod);
			} else {
				if (quantidade == 1) {
					adicionarFinal();
				} else {
					pv = obterPosicaoVazia();
					scanf("%i", &lista[pv].codigo);
					scanf("%s", &lista[pv].placa);
					
					lista[pv].proximo = lista[pl].proximo;
					lista[pv].anterior = lista[lista[pl].proximo].anterior;
					lista[lista[pl].proximo].anterior = pv;
					lista[pl].proximo = pv;
					
					quantidade++;
				}
			}
		}
	}
}

void exibirInicioFinal() {
	int aux;
	
	if (vazia() == 1) {
		printf("Lista vazia!\n");
	} else {
		aux = primeiro;
		
		while (aux != -1) {	
			printf("posv: %i | codigo: %i | placa: %s \n", 
			aux, 
			lista[aux].codigo, 
			lista[aux].placa);
			
			aux = lista[aux].proximo;
		}
		
		printf("primeiro: %i\n", primeiro);
		printf("ultimo: %i\n", ultimo);
		printf("quantidade: %i\n", quantidade);
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

int pesquisarCodigo(int pcod) {
	int aux = -1, pl = -1;	
	
	if (vazia() == 1) {
		pl = -1;
	} else {
		aux = primeiro;
		
		while (aux != -1) {
			if (lista[aux].codigo == pcod) {
				pl = aux;
				break;
			}
			else {
				aux = lista[aux].proximo;
			}
		}
	}
	return pl;
}

void menu() {
	int opc = 0;
	int codigo = -1, posicao = -1;
	
	do {
		printf("\nLISTA DL CARROS  \n");
		printf("1. Ad inic.        \n");
		printf("2. Ad final        \n");
		printf("3. Rem. inic.      \n");
		printf("4. Rem. final      \n");
		printf("5. Exibir I > F    \n");
		printf("6. Exibir F > I    \n");
		printf("7. Pesq. (cod)     \n");
		printf("8. Ad. apos cod(x) \n");
		scanf("%i", &opc);
		
		if (opc == 1) {
			adicionarInicio();
		} else if (opc == 2) {
			adicionarFinal();
		} else if (opc == 3) {
			printf("Metodo nao implementado!\n");
		} else if (opc == 4) {
			removerFinal();
		} else if (opc == 5) {
			exibirInicioFinal();
		} else if (opc == 6) {
			printf("Metodo nao implementado!\n");
		} else if (opc == 7) {
			scanf("%i", &codigo);
			posicao = pesquisarCodigo(codigo);
			
			if (posicao == -1) {
				printf("Codigo %i nao localizado!\n", codigo);
			} else {
				printf("| %i | codigo: %i | placa: %s |\n", 
				  posicao,
				  lista[posicao].codigo,
				  lista[posicao].placa);
			}
			
		} else if (opc == 8) {
			scanf("%i", &codigo);
			adicionarAposCodigo(codigo);
		}
	} while (opc != 9);
}

int main(int argc, char *argv[]) {
	iniciarLista();
	menu();
	return 0;
}