#include <stdio.h>
#include <stdlib.h>

/**************************************************************************************
 MARÇAL, J.
 Código fonte de exemplo para demonstração de Pesquisa Sequencial e Pesquisa Binária.
 **************************************************************************************/

#define MAX 1000
unsigned long long lista[MAX];

// Método responsável pela leitura de um arquivo .TXT contendo códigos e armazenando-os 
// em um array. Caso o número de registros do arquivo seja alterado é importante alterar
// o tamanho da variável MAX.
void carregar(unsigned long long codigos[MAX]) {
    FILE *fp;
    
    char nomeArquivo[100];
    int i = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
	    while (fscanf(fp, "%llu", &codigos[i]) == 1 && i < MAX) {
	        i++;
	    }    	
	    printf("%d codigos carregados com sucesso.\n", i);	
	}

    fclose(fp);
}

// Método responsável por exibir todos os códigos existentes no array.
void exibir(unsigned long long codigos[MAX]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d: %013llu\n", i + 1, codigos[i]);
    }
}

// Método de ordenação de dados.
void ordenarBubbleSort(unsigned long long codigos[MAX]) {
    unsigned long long temp;

    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (codigos[j] > codigos[j + 1]) {
                temp = codigos[j];
                codigos[j] = codigos[j + 1];
                codigos[j + 1] = temp;
            }
        }
    }
}

// Método de busca sequencial, não requer que os dados estejam ordenados.
void buscaSequencial(unsigned long long codigos[MAX], unsigned long long chave) {
	int posicao = -1;
	
	for (int i = 0; i < MAX; i++) {
		if (codigos[i] == chave) {
			posicao = i;
			break;
		}
	}	
	
	if (posicao == -1) {
		printf("A chave: %013llu nao foi localizada!\n", chave);
	} else {
		printf("A chave: %013llu foi localizada na posicao %d!\n", chave, posicao);
	}
}

// Métodos de busca binária, requer que os dados estejam ordenados, é importante compreender
// que o método não valida se os dados estão ordenados (e não faria sentido), ele apenas 
// executa o algoritmo de busca binária.
int buscaBinaria(unsigned long long lista[MAX], unsigned long long chave) {
    int inicio = 0, fim = MAX - 1, meio, posicao = -1;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (lista[meio] == chave) {
        	posicao = meio;
        	break;
        } else if (lista[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

	if (posicao == -1) {
		printf("A chave: %013llu nao foi localizada!\n", chave);
	} else {
		printf("A chave: %013llu foi localizada na posicao %d!\n", chave, posicao);
	}
}

void menu() {
    int opcao;
    unsigned long long chave;

    do {
        printf("\n:: BUSCA SEQUENCIAL E BINARIA ::..\n");
        printf("1 - Carregar\n");
        printf("2 - Exibir\n");
        printf("3 - Ordenar (BubbleSort)\n");
        printf("4 - Pesquisa sequencial\n");
        printf("5 - Pesquisa binaria\n");
        printf("9 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                carregar(lista);
                break;
                
            case 2:
                exibir(lista);
                break;
                
            case 3:
                if (MAX > 0) {
                    ordenarBubbleSort(lista);
                    printf("Codigos ordenados com sucesso.\n");
                } else {
                    printf("Nenhum dado carregado.\n");
                }
                break;
                
            case 4:
                printf("Digite o codigo para pesquisa: ");
                scanf("%llu", &chave);
                buscaSequencial(lista, chave);
            	break;
            	
            case 5:
                printf("Digite o codigo para pesquisa: ");
                scanf("%llu", &chave);
                buscaBinaria(lista, chave);
            	
            	break;
            	
            case 9:
                printf("Encerrando...\n");
                break;
                
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 9);	
}

int main(int argc, char *argv[]) {
	menu();
	
	return 0;
}