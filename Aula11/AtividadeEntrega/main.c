/*Cada aluno deverá implementar e postar o código fonte de um programa que: 
a) Carregue os dados do arquivo CP em um vetor; b) Que imprima na tela todos os valores do vetor; 
c) Que contenha no programa ao menos 4 opções de ordenação (podem existir mais que quatro, o professor ficará feliz!).

ORDENAÇÃO DE DADOS
1. Carregar CP
2. Imprimir CP carregado
3. Ordenacao [Nome da ordenção]
4. Ordenacao [Nome da ordenção]
5. Ordenacao [Nome da ordenção]
6. Ordenacao [Nome da ordenção]
9. Sair*/
#define TAM 1000
#include <stdio.h>

void carregar(int vetor[], int *quantidade){
    FILE *arq;
    int i = 0;

    arq = fopen("Cp1000.txt", "r");
    if (arq == NULL){
        printf("Ocorreu algum errro ao abrir o arquivo\n");
        return;
    }
    while (fscanf(arq, "%i", &vetor[i]) != EOF && i< TAM){
        i++;
    }
    fclose(arq);
    *quantidade = i;
    printf("Total encontrado: %i\n", i);
}
void imprimir(int vetor[], int quantidade){ 
    for(int i = 0; i < quantidade; i++){
        printf("%i\n",vetor[i]);
    }
}
void ordenarShell(int vetor[], int quantidade){
    int aux, j;
    for(int gap = quantidade / 2; gap > 0; gap /= 2){
        for(int i = gap; i < quantidade; i++){
            aux = vetor[i];
            j = i;
            while(j >= gap && vetor[j - gap] > aux){
                vetor[j] = vetor[j - gap];
                j -= gap;
            }
            vetor[j] = aux;
        }
    }
}
void ordenarBubble(int vetor[], int quantidade){
    int compara = 0, aux = 0;
    for(int i = 0; i < quantidade - 1; i++){
        for(compara = 0; compara < quantidade - 1 - i; compara++){
            if(vetor[compara] > vetor[compara + 1]){
                aux = vetor[compara];
                vetor[compara] = vetor[compara + 1];
                vetor[compara + 1] = aux;
            }
        }
    }
}
void ordenarInsertion(int vetor[], int quantidade){
    int compara = 0, guarda = 0;
    for(int i = 1; i < quantidade; i++){
        guarda = vetor[i];
        
        compara = i -1; 
        while(compara >= 0 && vetor[compara] > guarda){
            vetor[compara + 1] = vetor[compara]; 
            compara--; 
        }

      
        vetor[compara + 1] = guarda;
    }
}
void ordenarSelection(int vetor[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        int menor = i, aux = 0;
        for(int j = i + 1; j < quantidade; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        aux = vetor[i]; 
        vetor[i] = vetor[menor]; 
        vetor[menor] = aux;
    }
}
void menu(int vetor[], int *quantidade){
    int opc = 0;
    do {
        printf("1. Carregar\n");
        printf("2. Imprimir\n");
        printf("3. Ordenar shell\n");
        printf("4. Ordenacao Bubble\n");
        printf("5. Ordenacao Insertion\n");
        printf("6. Ordenacao Selection\n");
        printf("99. Sair\n");
        printf("Escola uma opcao:\n");
        scanf("%d", &opc);
        
        if(opc == 1){
            carregar(vetor, quantidade);   
        }
        else if(opc == 2){
            imprimir(vetor, *quantidade);
        }
        else if(opc == 3){     
            ordenarShell(vetor, *quantidade);
        }
        else if(opc == 4){
            ordenarBubble(vetor, *quantidade);

        }
        else if(opc == 5){
            ordenarInsertion(vetor, *quantidade);
        }
        else if(opc == 6){
            ordenarSelection(vetor, *quantidade);
        }
        
    }while(opc != 99);
}

int main(){
    int vetor[TAM];
    int quantidade = 0;
    menu(vetor, &quantidade);
    return 0;
}