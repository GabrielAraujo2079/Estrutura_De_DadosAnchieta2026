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
#include <time.h>

clock_t inicio, fim;
double tempo;

void copiarVetor(int origem[], int destino[], int n){
    for(int i = 0; i < n; i++){
        destino[i] = origem[i];
    }
}

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
    int compara = 0, aux = 0;
    for(int i = 0; i < quantidade - 1; i++){
        // a cada passagem, os últimos i elementos já estão no lugar
        for(compara = 0; compara < quantidade - 1 - i; compara++){
            if(vetor[compara] > vetor[compara + 1]){
                aux = vetor[compara];
                vetor[compara] = vetor[compara + 1];
                vetor[compara + 1] = aux;
            }
        }
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
        aux = vetor[i]; //armazena a posição antiga
        vetor[i] = vetor[menor]; //menor valor vai para esquerda do vetor
        vetor[menor] = aux; //antiga posição do menor e ocupada pelo numero maior que ele
    }
}

void ordenarShell(int vetor[], int quantidade){
    int aux, j; // aux guarda o valor atual, j vai andar no vetor

    // define o "gap" (salto), começando pela metade e diminuindo até 1
    for(int gap = quantidade / 2; gap > 0; gap /= 2){

        // percorre o vetor a partir do gap
        for(int i = gap; i < quantidade; i++){
            aux = vetor[i]; // guarda o valor atual
            j = i; // começa a comparar a partir da posição atual
            
            // enquanto houver elementos atrás (respeitando o gap)
            // e eles forem maiores que o valor guardado
            while(j >= gap && vetor[j - gap] > aux){
                vetor[j] = vetor[j - gap]; // empurra o maior pra frente
                j -= gap; // anda pra trás pulando de gap em gap
            }

            vetor[j] = aux; // coloca o valor guardado na posição correta
        }
    }
}

// [NOVO] função auxiliar do Merge Sort — junta dois subvetores já ordenados
void merge(int vetor[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esq[n1], dir[n2];

    for(int i = 0; i < n1; i++)
        esq[i] = vetor[inicio + i];
    for(int j = 0; j < n2; j++)
        dir[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while(i < n1 && j < n2){
        if(esq[i] <= dir[j])
            vetor[k++] = esq[i++];
        else
            vetor[k++] = dir[j++];
    }
    while(i < n1) vetor[k++] = esq[i++];
    while(j < n2) vetor[k++] = dir[j++];
}

void ordenarMerge(int vetor[], int inicio, int fim){

    // se tiver mais de 1 elemento, continua
    if(inicio < fim){

        // pega o meio do vetor
        int meio = (inicio + fim) / 2;

        // ordena a parte da esquerda
        ordenarMerge(vetor, inicio, meio);

        // ordena a parte da direita
        ordenarMerge(vetor, meio + 1, fim);

        // junta as duas partes já ordenadas em outra função
        merge(vetor, inicio, meio, fim);
    }
}

void heapify(int vetor[], int n, int i){
    int maior = i;        // assume que a raiz é o maior
    int esquerda = 2*i + 1; // filho da esquerda
    int direita = 2*i + 2;   // filho da direita
    int aux;

    // se o filho da esquerda for maior que o atual maior
    if(esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    // se o filho da direita for maior que o atual maior
    if(direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    // se o maior não for a raiz, troca
    if(maior != i){
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;

        // continua ajustando a subárvore
        heapify(vetor, n, maior);
    }
}

void ordenarHeap(int vetor[], int n){
    int aux;

    // monta o heap (organiza o vetor como árvore)
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(vetor, n, i);
    }

    // vai retirando o maior e colocando no final
    for(int i = n - 1; i > 0; i--){

        // troca o maior (raiz) com o último elemento
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        // reorganiza o heap com o tamanho reduzido
        heapify(vetor, i, 0);
    }
}

void quickSort(int vetor[], int inicio, int fim){
    int i = inicio, j = fim;
    int pivo = vetor[(inicio + fim) / 2]; // escolhe o pivô
    int aux;

    // enquanto não cruzar os ponteiros
    while(i <= j){

        // anda pela esquerda até achar valor maior que o pivô
        while(vetor[i] < pivo)
            i++;

        // anda pela direita até achar valor menor que o pivô
        while(vetor[j] > pivo)
            j--;

        // se ainda não cruzaram, troca
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;

            i++;
            j--;
        }
    }

    // chama recursão para a parte esquerda
    if(inicio < j)
        quickSort(vetor, inicio, j);

    // chama recursão para a parte direita
    if(i < fim)
        quickSort(vetor, i, fim);
}

void menu(int vetor[], int *quantidade){
    int opc;

    do{
        printf("\n===== MENU ORDENACAO =====\n");
        printf("1 - Carregar vetor;\n");
        printf("2 - Imprimir vetor;\n");
        printf("3 - Ordenar Insertion;\n");
        printf("4 - Ordenar Bubble;\n");
        printf("5 - Ordenar Selection;\n");
        printf("6 - Ordenar Shell;\n");
        printf("7 - Ordenar Merge;\n");
        printf("8 - Ordenar Heap;\n");
        printf("9 - Ordenar Quick;\n");
        printf("10 - Imprimir resultados;\n");
        printf("11 - Melhor algoritmo.\n");
        printf("99 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        if(opc == 1){
            carregarVetor(vetor, quantidade);
        }
        else if(opc == 2){
            imprimirVetor(vetor, *quantidade);
        }
        else if(opc == 3){
            ordenarInsertion(vetor, *quantidade);
        }
        else if(opc == 4){
            ordenarBubble(vetor, *quantidade);
        }
        else if(opc == 5){
            ordenarSelection(vetor, *quantidade);
        }
        else if(opc == 6){
            ordenarShell(vetor, *quantidade);
        }
        else if(opc == 7){
            ordenarMerge(vetor, 0, *quantidade - 1);
        }
        else if(opc == 8){
            ordenarHeap(vetor, *quantidade);
        }
        else if(opc == 9){
            quickSort(vetor, 0, *quantidade - 1); // [CORREÇÃO] nome era ordenarQuick, correto é quickSort
        }
        else if(opc == 10){
            printf("\n===== TEMPOS =====\n");

            int copia[TAM];

            // INSERTION
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarInsertion(copia, *quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Insertion: %f s\n", tempo);

            // BUBBLE
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarBubble(copia, *quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Bubble: %f s\n", tempo);

            // SELECTION
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarSelection(copia, *quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Selection: %f s\n", tempo);

            // SHELL
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarShell(copia, *quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Shell: %f s\n", tempo);

            // MERGE
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarMerge(copia, 0, *quantidade - 1);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Merge: %f s\n", tempo);

            // HEAP
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            ordenarHeap(copia, *quantidade);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Heap: %f s\n", tempo);

            // QUICK
            copiarVetor(vetor, copia, *quantidade);
            inicio = clock();
            quickSort(copia, 0, *quantidade - 1); 
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Quick: %f s\n", tempo);
        }
        else if(opc == 11){
            printf("\nAinda nao implementado: comparar menor tempo\n");
        }

    }while(opc != 99);
}

int main(){
    int vetor[TAM];
    int quantidade = 0;

    menu(vetor, &quantidade);

    return 0;
}