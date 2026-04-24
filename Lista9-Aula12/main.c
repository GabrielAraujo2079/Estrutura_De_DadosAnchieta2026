/*LISTA EXERCÍCIOS FILAS DINÂMICAS
EXERCÍCIOS
:: EDORD01 ::..
Baseado no conteúdo de Ordenação de Dados e utilizando algum dos arquivos .TXT que foram liberados, crie uma aplicação que contenha contenha as opções de 
ordenação abaixo, a aplicação deverá: 
a) Ler o arquivo .txt; 
b) Realize cada uma das diferentes ordenações; 
c) Calcule e exiba o tempo de ordenação de cada um dos algoritmos de ordenação (lembre-se de que cada ordenação deverá ser realizada sobre os dados desordenados);
d) Compare e exiba qual é o algoritmo mais e menos performático. 
:: ALGORITMOS DE ORDENAÇÃO ::..

0. Carregar dados;
1. Exibir dados (carregados);
2. Exibir dados (carregados);
3. Ordenar Buble;
4. Ordenar Heap;
5. Ordenar Insertion;
6. Ordenar Merge;
7. Ordenar Selection;
8. Ordenar Shell;
9. Ordenar Quick;
10. Exibir tempos ordenação;
11. Avaliar melhor/pior ordenação;
19. Sair*/

#define MAX 70000
#include <stdio.h>

unsigned long long lista[MAX];
int quantidade = 0;

void carregar() {
    FILE *arq;
    int i = 0;

    arq = fopen("AC70000.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (i < MAX && fscanf(arq, "%llu", &lista[i]) == 1) {
        i++;
    }

    fclose(arq);
    quantidade = i;

    printf("Total encontrado: %d\n", quantidade);
}

void exibirDados() {
    for (int i = 0; i < quantidade; i++) {
        printf("Posicao: [%d] - Codigo: %llu\n", i, lista[i]);
    }
}
void ordenarBubble(){
    int aux;
    for(int i = 0; i < quantidade - 1 ; i++){
        for(int j = 0; j < quantidade - 1 ; j ++){
            if(lista[j] > lista[j + 1]){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}
void menu(){
    int opc = -1;

    do{
        printf("0. Carregar\n");
        printf("1. Exibir\n");
        printf("2. Ordenar bubble\n");
        printf("3. Ordenar Heap;\n");
        printf("4. Ordenar Insertion;\n");
        printf("5. Ordenar Merge;\n");
        printf("6. Ordenar Selection;\n");
        printf("7. Ordenar Shell;\n");
        printf("8. Ordenar Quick;\n");
        printf("9. Exibir tempos ordenação;\n");
        printf("10. Avaliar melhor/pior ordenação;\n");
        printf("19. Sair\n");
        printf("OQue deseja fazer:\n");
        
        scanf("%d", &opc);


        if(opc == 0){

        }
        else if (opc == 1){

        }
        else if (opc == 2){
            
        }
        else if (opc == 3){
            
        }
        else if (opc == 4){
            
        }
        else if (opc == 5){
            
        }
        else if (opc == 6){    
        }
        else if (opc == 7){
            
        }
        else if (opc == 8){
            
        }
        else if (opc == 9){
            
        }
        else if (opc == 10){
            
        }
    }while(opc != 19);
}
int main(){
    return 0;
}