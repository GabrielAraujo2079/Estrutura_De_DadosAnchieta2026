/*EDORD-001
A ordenação de dados é uma das técnicas mais utilizadas no meio computacional, ordenar dados permite que a recuperação dos dados (pesquisa) sejam altamente eficientes. Existem várias 
técnicas e algoritmos responsáveis por ordenar dados, abaixo é solicitada a criação de programa que deverá:
  a) Carregar um vetor de inteiros a partir de arquivo texto com vários números inteiros;
  b) Ordenar os dados no vetor a partir de um algoritmo de ordenação;
  c) Armazenar o tempo de ordenação de cada algoritmo;
  d) Exibir o algoritmos que levou menor tempo para ser executado.

Desenvolva o menu a seguir:

************************
MENU ORDENACAO
************************
1 - Carregar vetor;
2 - Imprimir vetor;
3 - Ordenar Insertion;
4 - Ordenar Buble;
5 - Ordenar Selection;
6 - Ordenar Shell;
7 - Ordenar Merge;
8 - Ordenar Heap;
9 - Ordenar Quick;
10 - Imprimir resultados;
11 - Melhor algoritmo.
99 - Sair
*/
#define TAM 1000
#include <stdio.h>
void carregarVetor(int vetor[], int *quantidade){
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
void imprimirVetor(int vetor[], int quantidade){ 
    for(int i = 0; i < quantidade; i++){
        printf("%i\n",vetor[i]);
    }
}
void ordenarInsertion(int vetor[], int quantidade){
    int compara = 0, guarda = 0;
    for(int i = 1; i < quantidade; i++){
        guarda = vetor[i];
        
        compara = i -1; //Comparador começa 1 posição antes do valor guardado para verificar se tem alguem menor que ele antes dele
        while(compara >= 0 && vetor[compara] > guarda){
            vetor[compara + 1] = vetor[compara]; //Guarda ele uma posição acima ao qual estava
            compara--; //caça mais a esquerda
        }

        //guarda o numero guardado
        vetor[compara + 1] = guarda;
    }
}
void ordenarBubble(int vetor[], int quantidade){
    int compara = 0,aux = 0;
    for(int i = 0; i < quantidade - 1 ; i++){      
       
        for(compara = 0; compara <  quantidade - 1; compara++){   
            if(vetor[compara] > vetor[compara + 1]){
            
            aux = vetor[compara];
            vetor[compara] = vetor[compara + 1];
            vetor[compara + 1] = aux;
        }
    }
    }
}

void menu(){
    int opc = 0;
    do{
        printf("1 - Carregar vetor;\n");
        printf("2 - Imprimir vetor;\n");
        printf("3 - Ordenar Insertion;\n");
        printf("4 - Ordenar Buble;\n");
        printf("5 - Ordenar Selection;\n");
        printf("6 - Ordenar Shell;\n");
        printf("7 - Ordenar Merge;\n");
        printf("8 - Ordenar Heap;\n");
        printf("9 - Ordenar Quick;\n");
        printf("10 - Imprimir resultados;\n");
        printf("11 - Melhor algoritmo.\n");
        printf("99 - Sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%i", &opc);

        if(opc == 1){
            
        }   else if(opc == 2){
            
        }   else if(opc == 3){
            
        }   else if(opc == 4){
            
        }   else if(opc == 5){
            
        }   else if(opc == 6){
            
        }   else if(opc == 7){
            
        }   else if(opc == 8){
            
        }   else if(opc == 9){
            
        }   else if(opc == 10){
            
        }   else if(opc == 11){
            
        }
      
    }while(opc !=99);
}
int main(){

}