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
#include <time.h>

unsigned long long listaOriginal[MAX];
unsigned long long lista[MAX];
double tempos[7] = {0};
int quantidade = 0;

void carregar() {
    FILE *arq;
    int i = 0;

    arq = fopen("AC70000.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (i < MAX && fscanf(arq, "%llu", &listaOriginal[i]) == 1) {
        i++;
    }

    fclose(arq);
    quantidade = i;

    printf("Total encontrado: %d\n", quantidade);
}

void resetarLista(){

    // copia a lista original de volta pra lista de trabalho
    for(int i = 0; i < quantidade; i++){
        lista[i] = listaOriginal[i];
    }
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
void heapify(int filhosController, int indice){
    //Indice e o numero Atual do vetor (Posição)
    int maior = indice;
    //Pega o filho da esquerda fazendo uma conta simples posicão vezes o indice + 1
    int esq = 2 * indice + 1;
    //Mesma coisa que a esquerda, mas a direita ou seja + 2
    int dir = 2 * indice + 2;

    /*Verifica se o NUMERO a Esquerda e maior doq o maior numero ate o momento
    e ainda previne que o filho realmente exista (esq < filhosController )*/
    if (esq < filhosController && lista[esq] > lista[maior]){
        //AQUI Ò trocando o bagulho lá (Pelo numero maior)
        maior = esq;
    }
    
    /*Mesma coisa controla pra não estourar posição usando o controller e troca o numero da
    variavel maior caso o numero a Direita seja maior */
    if (dir < filhosController && lista[dir] > lista[maior]){
        maior = dir;
    }
    //se o indice for diferente de maior, quer dizer que a lista andou pó
    if (maior != indice) {
        //Temp e uma variavel feita pra ajudar no Troca Troca (são paulo estuda contratação)
                                    //recebe o indice ou seja a posição atual das passadas
        unsigned long long temp = lista[indice];
        //posição atual troca com maior
        lista[indice] = lista[maior];
        //maior troca com a posição atual
        lista[maior] = temp;
        //Conserta possiveis erros depois da modificação do topo
        heapify(filhosController, maior);
    }
}   
void heapSort() {
    int i;

   // Monta o heap garantindo que o maior sempre fique acima dos filhos
    //Começa do último elemento com filhos e vai até a raiz
    for (i = quantidade / 2 - 1; i >= 0; i--) {
    /*
    Para o índice atual:
    - calcula filho esquerdo e direito
    - compara valores
    - troca se necessário
    - ajusta a estrutura descendo na árvore até ficar consistente
    */
        heapify(quantidade, i);
    }

    // vai do ultimo elemento ate o numero 1 da lista (ou seja o segundo entre os primeiros)
    for (i = quantidade - 1; i > 0; i--) {
        //pega o primeiro valor da lista (o Maior)
        unsigned long long temp = lista[0];
        //Joga ele la pro final kkkkkkkkkk
        lista[0] = lista[i];
        //o final agora fica com o antigo primeiro
        lista[i] = temp;
        //ignora os ja ordenados(os maiores que foram pro final)
        //tbm ajeita tudinho pra não quebrar
        heapify(i, 0); 
    }
}

void ordenarInsertion(){
    int auxiliar, j;
    //Começa do 1 pq o 0 não tem ngm antes dele, esse daq percorre do segundo valor do vetor(1) ao ultimo
    for(int i = 1; i < quantidade; i++){
        j = i;
        //se tiver alguem maior que ele, antes dele, nois troca eles de lugar
        while(j> 0 && lista[j - 1] > lista[j]){
            auxiliar = lista[j];
            lista[j] = lista[j - 1];
            lista[j - 1] = auxiliar;
            j -= 1;
        }
    }
}
void merge(int inicio, int meio, int fim){
    
    int i = 0, j = 0, k = inicio;

    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    unsigned long long esquerda[tamanhoEsq], direita[tamanhoDireita];

    // Copia a parte da esquerda do vetor original
    for (i = 0; i < tamanhoEsq; i++){
        esquerda[i] = lista[inicio + i];
    }

    // Copia a parte da direita do vetor original
    for (j = 0; j < tamanhoDireita; j++){
        direita[j] = lista[meio + 1 + j];
    }

    // Reinicia os índices para começar a comparação
    i = 0;
    j = 0;

    // Enquanto ainda tiver elementos nos dois lados
    while (i < tamanhoEsq && j < tamanhoDireita) {

        // Compara os dois valores atuais e pega o menor
        if (esquerda[i] <= direita[j]) {
            lista[k] = esquerda[i];
            i++; // anda na esquerda
        } else {
            lista[k] = direita[j];
            j++; // anda na direita
        }

        k++; // sempre anda no vetor principal
    }

    // Se sobrou coisa na esquerda, copia tudo
    while (i < tamanhoEsq) {
        lista[k] = esquerda[i];
        i++;
        k++;
    }

    // Se sobrou coisa na direita, copia tudo
    while (j < tamanhoDireita) {
        lista[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;

        mergeSort(inicio, meio);       // divide lado esquerdo
        mergeSort(meio + 1, fim);      // divide lado direito

        merge(inicio, meio, fim);      // junta tudo ordenado
    }
}

void ordenarShell(){
    int j, auxiliar;
    
    // começa com um "pulo" grande e vai diminuindo
    for(int gap = quantidade / 2; gap > 0; gap /= 2){

        // percorre o vetor a partir do gap
        for(int i = gap; i < quantidade; i++){

            // guarda o valor atual
            auxiliar = lista[i];

            // compara com elementos anteriores, pulando de gap em gap
            // e vai deslocando eles pra frente se forem maiores
            for(j = i; j >= gap && auxiliar < lista[j - gap]; j -= gap){
                lista[j] = lista[j - gap];
            }

            // coloca o valor na posição correta
            lista[j] = auxiliar;
        }
    }
}

void ordenarSelection(){
    
    int menor, auxiliar;

    for(int i = 0; i < quantidade -1; i++){
        //salva o numero da vez
        menor = i;
        for(int j = i + 1; j < quantidade; j++){
            //Se tiver alguem menor q ele
            if(lista[j] < lista[menor]){
                menor = j;
            }
        }
        //Faz o troca troca
        auxiliar = lista[i];
        lista[i] = lista[menor];
        lista[menor] = auxiliar;
    }
}

void ordenarQuick(int inicio, int fim){
   
    // Caso base: se só tem 1 ou nenhum elemento, já está ordenado
    if (inicio >= fim){
        return;
    }

    int ponto_divisao, aux;
    
    // Escolhe o pivô (último elemento do vetor atual)
    ponto_divisao = lista[fim];

    // i marca a posição do "menor ou igual ao pivô"
    int i = inicio - 1;

    // Percorre do início até antes do pivô
    for(int j = inicio; j < fim; j++){
        
        // Se o elemento for menor ou igual ao pivô
        if(lista[j] <= ponto_divisao){
            i++;

            // troca para levar ele para o lado esquerdo
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }

    // Coloca o pivô na posição correta dele
    aux = lista[i + 1];
    lista[i + 1] = lista[fim];
    lista[fim] = aux;

    // posição final do pivô
    int posicao = i + 1;
    
    // ordena a parte da esquerda (menores que o pivô)
    ordenarQuick(inicio, posicao - 1);

    // ordena a parte da direita (maiores que o pivô)
    ordenarQuick(posicao + 1, fim);
}
void avaliarMelhorPior(){

    int menor = 0;
    int maior = 0;

    // 0 = Bubble
    // 1 = Heap
    // 2 = Insertion
    // 3 = Merge
    // 4 = Selection
    // 5 = Shell
    // 6 = Quick

    for(int i = 1; i < 7; i++){

        if(tempos[i] < tempos[menor]){
            menor = i;
        }

        if(tempos[i] > tempos[maior]){
            maior = i;
        }
    }

    printf("\n--- RESULTADO FINAL ---\n");

    printf("Menor tempo (melhor): algoritmo %d -> %f s\n", menor, tempos[menor]);
    printf("Maior tempo (pior):   algoritmo %d -> %f s\n", maior, tempos[maior]);
}

void menu(){
    int opc = -1;

    do{
        printf("0. Carregar\n");
        printf("1. Exibir\n");
        printf("2. Bubble\n");
        printf("3. Heap\n");
        printf("4. Insertion\n");
        printf("5. Merge\n");
        printf("6. Selection\n");
        printf("7. Shell\n");
        printf("8. Quick\n");
        printf("9. Exibir tempos\n");
        printf("10. Melhor/Pior\n");
        printf("19. Sair\n");
        printf("O que deseja fazer: ");

        scanf("%d", &opc);

        if(opc == 0){
            carregar();
        }

        else if(opc == 1){
            resetarLista();
            exibirDados();
        }

        else if(opc == 2){
            resetarLista();
            clock_t inicio = clock();
            ordenarBubble();
            clock_t fim = clock();
            tempos[0] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 3){
            resetarLista();
            clock_t inicio = clock();
            heapSort();
            clock_t fim = clock();
            tempos[1] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 4){
            resetarLista();
            clock_t inicio = clock();
            ordenarInsertion();
            clock_t fim = clock();
            tempos[2] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 5){
            resetarLista();
            clock_t inicio = clock();
            mergeSort(0, quantidade - 1); 
            clock_t fim = clock();
            tempos[3] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 6){
            resetarLista();
            clock_t inicio = clock();
            ordenarSelection();
            clock_t fim = clock();
            tempos[4] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 7){
            resetarLista();
            clock_t inicio = clock();
            ordenarShell();
            clock_t fim = clock();
            tempos[5] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }

        else if(opc == 8){
            resetarLista();
            clock_t inicio = clock();
            ordenarQuick(0, quantidade - 1);
            clock_t fim = clock();
            tempos[6] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        }
        else if(opc == 9){
            printf("\n--- TEMPOS ---\n");
            printf("Bubble:     %f\n", tempos[0]);
            printf("Heap:       %f\n", tempos[1]);
            printf("Insertion:  %f\n", tempos[2]);
            printf("Merge:      %f\n", tempos[3]);
            printf("Selection:  %f\n", tempos[4]);
            printf("Shell:      %f\n", tempos[5]);
            printf("Quick:      %f\n", tempos[6]);
        }

        else if(opc == 10){
        avaliarMelhorPior();
        }
    }while(opc != 19);
}

int main(){
    menu();
    return 0;
}